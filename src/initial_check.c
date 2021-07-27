/**
 * @file initial_check.c
 * @author Zuber Ahmed
 * @brief Source code for performing the checking of initial conditions
 * @version 0.1
 * @date 2021-07-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "initial_check.h"

void intialize_interrupt_func1()
{
    PCICR |= (1<<PCIE0);                               /// Setting the PCINT0 corresponding to B PINS
    PCMSK0 |= (1<<PCINT3);                             /// Setting PIN B1 to enable interrupt PCINT0
    PCMSK0 |= (1<<PCINT4);                             /// Setting ping B1 to enable interrupt PCINT0
}

void initialize_port_func1()
{
    DDRB |= (1<<PORTB0);                                /// Set bit PB0 for output
    DDRB &= ~(1<<PORTB3);                               /// Clear bit PB1
    PORTB |= (1<<PORTB3);                               /// Set bit PB1 to provide high(5V)
    DDRB &= ~(1<<PORTB4);                               /// Clear bit PB2
    PORTB |= (1<<PORTB4);                               /// Set bit PB2 to provide high(5V)
}

void initial_check(){
    initialize_port_func1();                            /// Calling the function to Initialize Ports 
	intialize_interrupt_func1();                        /// Calling Function to intialize Pin Change interrupts 
}

