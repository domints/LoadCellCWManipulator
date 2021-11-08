/*
 * ADS1115.cpp
 *
 *  Created on: Nov 6, 2021
 *      Author: domin
 */

#include <ADS1115.h>
#include <dbg.h>
#include "stm32f4xx_hal.h"

ADS1115::ADS1115() {
}

ADS1115::~ADS1115() {
	// TODO Auto-generated destructor stub
}

void ADS1115::Init(I2C_HandleTypeDef* i2cHandle, uint8_t address) {
	_i2c = i2cHandle;
	_address = address;

	readConfig();

#ifdef DEBUG
	_initialized = true;
#endif
}

void ADS1115::setMux(ADS1115_MUX_CFG config) {
	_config[0] = (_config[0] & MUX_CLEAR_MASK) | (config << 4);
}

void ADS1115::readConfig() {
	_writeBfr[0] = 0x01;

	HAL_I2C_Master_Transmit(_i2c, _address, _writeBfr, 1, 100);
	HAL_Delay(100);
	HAL_I2C_Master_Receive(_i2c, _address, _readBfr, 2, 100);
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
		  HAL_Delay(1000);
	_config[0] = _readBfr[0] & 0x7F; //ensure StartConversion bit is set to 0
	_config[1] = _readBfr[1];
}

void ADS1115::writeConfig() {
	_writeBfr[0] = 0x01;
	_writeBfr[1] = _config[0];
	_writeBfr[2] = _config[1];
	HAL_I2C_Master_Transmit(_i2c, _address, _writeBfr, 3, 100);
}

void ADS1115::singleConversion() {
	_writeBfr[0] = 0x01;
	_writeBfr[1] = _config[0] | 0x80; //set StartConversion bit
	_writeBfr[2] = _config[1];
	HAL_I2C_Master_Transmit(_i2c, _address, _writeBfr, 3, 100);
}

void ADS1115::singleConversion(ADS1115_MUX_CFG muxCfg) {
	setMux(muxCfg);
	singleConversion();
}

int16_t ADS1115::readConversion() {
	ensInit();

	_writeBfr[0] = 0x00;

	HAL_I2C_Master_Transmit(_i2c, _address, _writeBfr, 1, 100);
	HAL_I2C_Master_Receive(_i2c, _address, _readBfr, 2, 100);

	return _readBfr[0] << 8 | _readBfr[1];
}

