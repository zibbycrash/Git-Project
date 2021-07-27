/**
 * @file initial_check.h
 * @author Gobikumaar Sivagnanam
 * @brief To Configure the pins to input switch status and output port for LED
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __INITIAL_CHECK_H__     /// Header Guard for initial_check.c
#define __INITIAL_CHECK_H__     /// Beginning of Definition

/**
 * @brief Include Files for referencing AVR atmega defined names 
 */

#include <avr/io.h>
#include <avr/interrupt.h>

/**
 * @brief Defining the F_CPU for using _delay function, setting clock frequency of MCU to 16Mhz
 *  Including the header for built-in delay function
 */
#define F_CPU 16000000UL
#include <util/delay.h>

/**
 * @brief Setting up Macros to switch on and off LED using PORT B0 
 *  Setting Macros to check if the switch is being pressed i.e. 0 V
 */
#define LED_ON PORTB |= (1<<PORTB0)        /// Setting PORT B0 to output 5V
#define LED_OFF PORTB &= ~(1<<PORTB0)      /// Setting PORT B0 to output 0V
#define SWITCH1 (!(PINB&(1<<PORTB3)))      /// Checking if PIN B1 is getting 0V
#define SWITCH2 (!(PINB&(1<<PORTB4)))      /// Checking if PIN B2 is getting 0V

/**
 * @brief Function to set the output ports and set them to provide 5V
 * 
 */
void initialize_port_func1();

/**
 * @brief Function to enable the Pin Change Interrupts and set the required masks 
 * 
 */
void intialize_interrupt_func1();

/**
 * @brief Function to call the initialize_port_func1() and intialize_interrupt_func1() functions
 * 
 */
void initial_check();

#endif  /// End of Definition 