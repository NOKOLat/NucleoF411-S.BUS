/*
 * wrapper.cpp
 *
 *  Created on: Oct 10, 2023
 *      Author: ohya
 */

#include "wrapper.hpp"
/* Pre-Processor Begin */
#include "SBUS.hpp"
#include <functional>
#include <string>

#include <usart.h>
#include <gpio.h>
/* Pre-Processor End */

/* Enum, Struct Begin */

/* Enum, Struct End */

/* Function Prototype Begin */

/* Function Prototype End */

/* Variable Begin */
nokolat::SBUS sbus(&huart1);

std::array<int16_t, 8> buffer;
/* Variable End */

void init(void){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5, GPIO_PIN_SET);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5, GPIO_PIN_RESET);
//	HAL_DMA_RegisterCallback(huart1.hdmarx, HAL_DMA_XFER_CPLT_CB_ID, sbusReceiveCallback);
    HAL_UART_Receive_DMA(&huart1, sbus.getReceveBufferPtr(),sbus.getDataLen());
}

void loop(void){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5, GPIO_PIN_RESET);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
    HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
    sbus.setIsNeedParse();

	std::string str;
//    for(uint8_t n=0; n<25; n++){
//    	str = std::to_string(*(sbus.getReceveBufferPtr()+n)) + " ";
	for(uint8_t n=0; n<18; n++){
		str = std::to_string(sbus.getData(n+1)) + " ";
    	HAL_UART_Transmit(&huart2, (uint8_t *)str.c_str(), str.length(), 10);
    }
	str = "\n";
	HAL_UART_Transmit(&huart2, (uint8_t *)str.c_str(), str.length(), 10);

	HAL_UART_Receive_DMA(&huart1, sbus.getReceveBufferPtr(),sbus.getDataLen());

}
/* Function Body Begin */
