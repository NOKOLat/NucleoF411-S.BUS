/*
 * SBUS.hpp
 *
 *  Created on: Oct 10, 2023
 *      Author: ohya
 */

#ifndef INC_SBUS_HPP_
#define INC_SBUS_HPP_

#include <array>
#include <iterator>

#include "usart.h"

namespace nokolat {

class SBUS {
public:
	SBUS(UART_HandleTypeDef *husart = nullptr)
	:husart_(husart){}
	virtual ~SBUS(){};

	auto getBufferIterator(){
		return receiveBuffer.cbegin();
	}

	void enableReciveIT(){
		isNeedParse = true;
		HAL_UART_Receive_IT(husart_, receiveBuffer.data(), 25);
	}

	uint8_t *getReceveBufferPtr() {
		return (uint8_t*)receiveBuffer.data();
	}

	int16_t getData(const uint8_t channel){
		if(channel > 17 or channel < 1) return -1;
		if(isNeedParse){
			parse();
		}

		return data[channel-1];
	}

	constexpr uint8_t getDataLen(){
		return length;
	}

	void setIsNeedParse(bool arg=true){
		isNeedParse = arg;
	}

private:
	std::array<uint8_t,25> receiveBuffer;
	std::array<uint16_t,18> data;
	bool isNeedParse;
	UART_HandleTypeDef *husart_;
	const uint8_t length = 25;

	void parse();
};

} /* namespace nokolat */

#endif /* INC_SBUS_HPP_ */
