/**
 * @file send_data.c
 * @author Zuber Ahmed
 * @brief Source code to send data serially using USART with a set BAUD rate
 * @version 0.1
 * @date 2021-07-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "send_data.h"

void USART_initialization(uint16_t baud_rate)
{
    UBRR0L = baud_rate;                                             /// Setting the Baud Rate for the Transmission
    UBRR0H = (baud_rate>>8)&(0x00FF);                               /// Setting the Baud Rate for the Transmission

    UCSR0C |= (1<<UMSEL00) | (1<<UCSZ01) | (1<<UCSZ00);             /// Setting Asynchronous USART, 8-bit Data

    UCSR0B |=  (1<<TXEN0) | (1<<TXCIE0);                            /// Enabling Transmitter, and it's respective interrupt
}

void Write_char_usart(char data)
{
    while(Transmission_check)                                       /// Checking if Transmission is complete
    {

    }
    UDR0 = data;                                                    /// Sending the data to the UDR0 register
}

void Manage_display(int option){
    USART_initialization(103);                                      /// Intializing with 9600 Baud, Baud Rate = 103
    if(option == 1)                                                 /// Logic to Display the Temperature 20 °C
    {
        Write_char_usart('2');
        Write_char_usart('0');
        Write_char_usart(' ');
        Write_char_usart('C');
        Write_char_usart(' ');
    }
    if(option == 2)                                                  /// Logic to Display the Temperature 25 °C
    {
        Write_char_usart('2');
        Write_char_usart('5');
        Write_char_usart(' ');
        Write_char_usart('C');
        Write_char_usart(' ');
    }
    if(option == 3)                                                   /// Logic to Display the Temperature 29 °C
    {
        Write_char_usart('2');
        Write_char_usart('9');
        Write_char_usart(' ');
        Write_char_usart('C');
        Write_char_usart(' ');
    }
    if(option == 4)                                                    /// Logic to Display the Temperature 33 °C
    {
        Write_char_usart('3');
        Write_char_usart('3');
        Write_char_usart(' ');
        Write_char_usart('C');
        Write_char_usart(' ');
    }
}