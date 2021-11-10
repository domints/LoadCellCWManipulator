/*
 * Serial.h
 *
 *  Created on: Nov 7, 2021
 *      Author: domin
 */

#ifndef INC_USBSERIAL_H_
#define INC_USBSERIAL_H_

#include <stdint.h>

enum NUM_BASE {
	DEC,
	HEX
};

class USBSerial {
public:
	USBSerial();
	virtual ~USBSerial();

	void print(const char * msg, int size);
	void print(short value, NUM_BASE base = NUM_BASE::DEC);
	void print(int value, NUM_BASE base = NUM_BASE::DEC);
	void print(long value, NUM_BASE base = NUM_BASE::DEC);

	void println(const char * msg, int size);
	void println(short value, NUM_BASE base = NUM_BASE::DEC);
	void println(int value, NUM_BASE base = NUM_BASE::DEC);
	void println(long value, NUM_BASE base = NUM_BASE::DEC);
private:
	uint8_t newLine[2] = {0x0d, 0x0a};
	const char * DEC_FORMAT = "%d";
	const char * HEX_FORMAT = "%x";

	char * getFormat(NUM_BASE base);
	void send(uint8_t * buffer, uint16_t length);
};

#endif /* INC_USBSERIAL_H_ */
