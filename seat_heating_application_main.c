/**
 * @file seat_heating_application_main.c
 * @author Zuber Ahmed
 * @brief Main Function to check if the passenger is sitting, and switched on the heating system. If both is true then switching 
 * on the LED actuator. Then getting input data from an ADC from the user. Displaying this data using PWM technique. Also sending
 * the temperature set with serial communication using USART Protocol
 * PIN B3 Takes the Passenger seating sensor input, PIN B4 takes the heating system ON input 
 * The switches are in Pin Change Interrupt Mode on PIN B3 and PIN B4, and only when both the switches are ON the Application starts 
 * in the PIN CHANGE interrupt service routine
 * The ADC Interrupt for Conversion Complete is Enabled based on the two switches. The rest of the functionality is implemented in 
 * this Interrpt Service Routine as we need output only if there is a an input from the ADC from PIN C0
 * The PWM output is set based on the input ADC value on PIN B1
 * The serial communication is also based on the ADC input and output is sent as temperature set
 * Handling the Functionalities using Interrupts to improve performace of the Microcontroller and avoid idling
 * @version 0.1
 * @date 2021-07-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "initial_check.h"					/// Header for Activity 1
#include "temperature_set.h"				/// Header for Activity 2 
#include "display_temperature.h"			/// Header for Activity 3
#include "send_data.h"						/// Header for Activity 4

volatile unsigned FLAG_1 = 0;				/// Flag to check if the both the sensors are ON

ISR(PCINT0_vect)							/// ISR for checking the inital check status of passenger seating and switching on system
{	
	if((SWITCH1)&&(SWITCH2))				/// Checking if both the switches are on to enable the LED actuator
	{
		LED_ON;									
		FLAG_1 = 1;							/// Setting flag to enable the Next function
	}
	else{
		LED_OFF;							/// Switching off LED Actuator
		FLAG_1 = 0;							/// Clearing flag to disable the Next function
		Output_pwm = 0;						/// Setting the PWM to 0
	}
}

ISR(ADC_vect)								/// ISR for the ADC Conversion Completion
{	
	if(FLAG_1 == 1)							/// Checking if the intial Flag is set
	{
		int option = 0;

		uint16_t buffer = 0;				/// To store the Temperature set Input (ADC Input)

		initialize_ADC(ADC_Input_Channel);	/// Starting the ADC Conversion
		initialize_timer1_pwm();			/// Initializing Timer 1 in FAST PWM Mode in 10-Bit
		
		buffer = get_temperature();			/// Getting Value from ADC to store in buffer
		if(buffer>=710 && buffer<=1023)		/// Logic to set PWM output based on the input value of ADC
		{	
			buffer = PWM_95_percent;		/// Setting PWM to 20%
			option = 4;						/// To select the option to Send Serial Data of '20 C'
		}
		if(buffer>=510 && buffer<=700)
		{
			buffer = PWM_70_percent;		/// Setting PWM to 40%
			option = 3;						/// To select the option to Send Serial Data of '25 C'
		}
		if(buffer>=210 && buffer<=500)
		{
			buffer = PWM_40_percent;		/// Setting PWM to 70%
			option = 2;						/// To select the option to Send Serial Data of '29 C'
		}
		if(buffer>=1 && buffer<=200)
		{
			buffer = PWM_20_percent;		/// Setting PWM to 95%
			option = 1;						/// To select the option to Send Serial Data of '33 C'
		}
		Output_pwm = buffer;				/// Setting the buffer to the PWM compare to obtain the PWM Wave
		_delay_ms(200);						/// Generating a Delay for PWM wave to settle
		Manage_display(option);				/// Sending the Serial Data based on option
	}
}

ISR(USART_TX_vect)
{
											/// Calling Interrupt Service Routine to clear the Interrupt Flag and Continue
}

int main()
{
	sei();										/// Enabling global interruts
	initial_check();							/// Function call to perform the inital check 
	 
	while(1)
	{	
		if(FLAG_1 == 1)							/// Checking if the intial Flag is set
		{
			initialize_ADC(ADC_Input_Channel);	/// Starting the ADC to begin Conversion 
		}
	}
	return 0;
}