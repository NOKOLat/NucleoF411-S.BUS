/*
 * SBUS.cpp
 *
 *  Created on: Oct 17, 2023
 *      Author: ohya
 */

#include "SBUS.hpp"


namespace nokolat{
void SBUS::parse(){
		data[0] = receiveBuffer[1];
		data[0] += ((int16_t)receiveBuffer[2] & 0b111)<<8;

		data[1] = receiveBuffer[2]>>3;
		data[1] += ((int16_t)receiveBuffer[3] & 0b111111)<<5;

		data[2] = receiveBuffer[3]>>6;
		data[2] += ((int16_t)receiveBuffer[4])<<2;
		data[2] += ((int16_t)receiveBuffer[5] & 0b1)<<10;

		data[3] = receiveBuffer[5]>>1;
		data[3] += ((int16_t)receiveBuffer[6] & 0b1111)<<7;

		data[4] = receiveBuffer[6]>>4;
		data[4] += ((int16_t)receiveBuffer[7] & 0b1111111)<<4;

		data[5] = receiveBuffer[7]>>7;
		data[5] += ((int16_t)receiveBuffer[8])<<1;
		data[5] += ((int16_t)receiveBuffer[9] & 0b11)<<9;

		data[6] = receiveBuffer[9]>>2;
		data[6] += ((int16_t)receiveBuffer[10] & 0b11111)<<6;

		data[7] = receiveBuffer[10]>>5;
		data[7] += ((int16_t)receiveBuffer[11])<<3;

		data[8] = receiveBuffer[12];
		data[8] += ((int16_t)receiveBuffer[13] & 0b111)<<8;

		data[9] = receiveBuffer[13]>>3;
		data[9] += ((int16_t)receiveBuffer[14] & 0b111111)<<8;

		data[10] = receiveBuffer[14]>>6;
		data[10] += ((int16_t)receiveBuffer[15])<<2;
		data[10] += ((int16_t)receiveBuffer[16] & 0b1)<<10;

		data[11] = receiveBuffer[16]>>1;
		data[11] += ((int16_t)receiveBuffer[17] & 0b1111)<<7;

		data[12] = receiveBuffer[17]>>4;
		data[12] += ((int16_t)receiveBuffer[18] & 0b1111111)<<4;

		data[13] = receiveBuffer[18]>>7;
		data[13] += ((int16_t)receiveBuffer[19])<<1;
		data[13] += ((int16_t)receiveBuffer[20] & 0b11)<<9;

		data[14] = receiveBuffer[20]>>2;
		data[14] += ((int16_t)receiveBuffer[21] & 0b11111)<<6;

		data[15] = receiveBuffer[21]>>5;
		data[15] += ((int16_t)receiveBuffer[22])<<3;

		data[16] = receiveBuffer[23] &0b1;
		data[17] = receiveBuffer[23] &0b10;

		isNeedParse = false;
	}
}
