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
	HAL_DMA_RegisterCallback(huart1.hdmarx, HAL_DMA_XFER_CPLT_CB_ID, sbusReceiveCallback);
    HAL_UART_Receive_DMA(&huart1, sbus.getReceveBufferPtr(),sbus.getDataLen());
}

void loop(void){

}

void sbusReceiveCallback(DMA_HandleTypeDef *_hdma){
    HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
    HAL_UART_Receive_DMA(&huart1, sbus.getReceveBufferPtr(),sbus.getDataLen());
}
/* Function Body Begin */
