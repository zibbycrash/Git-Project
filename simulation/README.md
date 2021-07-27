# Application Operation

## Interrupt Service Routines

### PIN CHANGE INTERRPUT
```C
ISR(PCINT0_vect)							/// ISR for checking the Initial Conditions
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
```

### ADC CONVERSION COMPLETE INTERRUPT
```C
ISR(ADC_vect)								/// ISR for the ADC Conversion Completion
{	
	if(FLAG_1 == 1)							/// Checking if the intial Flag is set
	{
		int option = 0;

		uint16_t buffer = 0;				/// To store the Temperature set Input (ADC Input)

		initialize_ADC(0);					/// Starting the ADC Conversion
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
```

### TRANSMISSION COMPLETE INTERRPUT
```C
ISR(USART_TX_vect)
{
											/// Calling Interrupt Service Routine to clear the Interrupt Flag and Continue
}
```

### Main Function
```C
int main()
{
	sei();									/// Enabling global interruts
	initial_check();						/// Function call to perform the inital check 
	 
	while(1)
	{	
		if(FLAG_1 == 1)						/// Checking if the intial Flag is set
		{
			initialize_ADC(0);				/// Starting the ADC to begin Conversion 
		}
	}
	return 0;
}
```