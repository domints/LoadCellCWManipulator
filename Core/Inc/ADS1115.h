/*
 * ADS1115.h
 *
 *  Created on: Nov 6, 2021
 *      Author: domin
 */

#ifndef INC_ADS1115_H_
#define INC_ADS1115_H_

#include "stm32f4xx_hal.h"

enum ADS1115_MUX_CFG {
	DIFF_P0_N1,
	DIFF_P0_N3,
	DIFF_P1_N3,
	DIFF_P2_N3,
	SINGLE_P0,
	SINGLE_P1,
	SINGLE_P2,
	SINGLE_P3
};

enum ADS1115_DR_CFG {
	_8SPS,
	_16SPS,
	_32SPS,
	_64SPS,
	_128SPS,
	_250SPS,
	_475SPS,
	_860SPS
};

class ADS1115 {
public:
	ADS1115();
	virtual ~ADS1115();
	void Init(I2C_HandleTypeDef* i2cHandle, uint8_t address = 0x48);
	void readConfig();
	void writeConfig();
	void setMux(ADS1115_MUX_CFG config);
	void singleConversion();
	void singleConversion(ADS1115_MUX_CFG muxCfg);
	int16_t readConversion();

private:
	uint8_t _writeBfr[3];
	uint8_t _readBfr[2];
	I2C_HandleTypeDef* _i2c;
	uint8_t _address;
	uint8_t _config[2];

	const uint8_t MUX_CLEAR_MASK = 0x8F;
	const uint8_t DR_CLEAR_MASK = 0x8F;

#ifdef DEBUG
	bool _initialized;
#endif
};

#endif /* INC_ADS1115_H_ */
