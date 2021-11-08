/*
 * Serial.cpp
 *
 *  Created on: Nov 7, 2021
 *      Author: domin
 */

#include <stdint.h>
#include <USBSerial.h>
#include "usbd_cdc_if.h"

USBSerial::USBSerial() {
	// TODO Auto-generated constructor stub

}

USBSerial::~USBSerial() {
	// TODO Auto-generated destructor stub
}

void USBSerial::print(const char *msg) {
	send((uint8_t*) msg, sizeof(msg));
}

void USBSerial::print(short value, NUM_BASE base) {
	char buffer[3];
	uint8_t len = sprintf(buffer, getFormat(base), value);
	send((uint8_t*) buffer, len);
}

void USBSerial::print(int value, NUM_BASE base) {
	char buffer[5];
	uint8_t len = sprintf(buffer, getFormat(base), value);
	send((uint8_t*) buffer, len);
}

void USBSerial::print(long value, NUM_BASE base) {
	char buffer[10];
	uint8_t len = sprintf(buffer, getFormat(base), value);
	send((uint8_t*) buffer, len);
}

void USBSerial::println(const char *msg) {
	send((uint8_t*) msg, sizeof(msg));
	send(newLine, 2);
}

void USBSerial::println(short value, NUM_BASE base) {
	char buffer[3];
	uint8_t len = sprintf(buffer, getFormat(base), value);
	send((uint8_t*) buffer, len);
	send(newLine, 2);
}

void USBSerial::println(int value, NUM_BASE base) {
	char buffer[5];
	uint8_t len = sprintf(buffer, getFormat(base), value);
	send((uint8_t*) buffer, len);
	send(newLine, 2);
}

void USBSerial::println(long value, NUM_BASE base) {
	char buffer[10];
	uint8_t len = sprintf(buffer, getFormat(base), value);
	send((uint8_t*) buffer, len);
	send(newLine, 2);
}

void USBSerial::send(uint8_t* buffer, uint16_t len) {
	uint8_t result = USBD_BUSY;
	while (result == USBD_BUSY) {
		result = CDC_Transmit_FS(buffer, len);
	}
}

char* USBSerial::getFormat(NUM_BASE base) {
	switch (base) {
	case DEC:
		return (char*) DEC_FORMAT;
	case HEX:
		return (char*) HEX_FORMAT;
	default:
		return (char*) "%s";
	}
}
