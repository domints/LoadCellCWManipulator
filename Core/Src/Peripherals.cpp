/*
 * Peripherals.cpp
 *
 *  Created on: Nov 7, 2021
 *      Author: domin
 */


#include <Peripherals.h>

ADS1115 adc;

void InitializePripherals(I2C_HandleTypeDef* i2cHandle)
{
	adc.Init(i2cHandle);
}
