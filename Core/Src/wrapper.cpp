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

}

void loop(void){

}

/* Function Body Begin */
