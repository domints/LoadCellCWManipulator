/*
 * Peripherals.h
 *
 *  Created on: Nov 7, 2021
 *      Author: domin
 */

#ifndef INC_PERIPHERALS_H_
#define INC_PERIPHERALS_H_

#include "ADS1115.h"

void InitializePripherals(I2C_HandleTypeDef* i2cHandle);
extern ADS1115 adc;

#endif /* INC_PERIPHERALS_H_ */
