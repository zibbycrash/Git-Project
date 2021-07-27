/**
 * @file send_data.h
 * @author Gobikumaar Sivagnanam
 * @brief Function to intialize and send data serially using USART
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __SEND_DATA_H__             /// Header Guard
#define __SEND_DATA_H__             /// Beginning of Definition

/**
 * @brief Include Files for referencing AVR atmega defined names 
 */
#include <avr/io.h>
#include <avr/interrupt.h>

/**
 * @brief MACRO for checking if the Transmission is complete
 */
#define Transmission_check (!(UCSR0A & (1<<UDRE0)))

/**
 * @brief Function to Initalize the Registers for Transmission of Data using USART
 * 
 * @param baud_rate [in] To set the baud Rate
 */
void USART_initialization(uint16_t baud_rate);

/**
 * @brief Function to send the Data using UDR0 Register
 * 
 * @param [in] data The Character to be sent 
 */
void Write_char_usart(char data);

/**
 * @brief Function to Send Data using USART based on an option
 * 
 * @param [in] option To select the temperature to be displayed 
 */
void Manage_display(int option);

#endif                              /// End of Definition