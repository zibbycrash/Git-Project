# Embedded-C

## Badges
| Badge Name | Status |
|----|----|
| Build | [![Compile-Linux](https://github.com/Gobikumaar-Sivagnanam/Embedded-C/actions/workflows/compile_linux.yml/badge.svg)](https://github.com/Gobikumaar-Sivagnanam/Embedded-C/actions/workflows/compile_linux.yml) |
| Static Analysis Cppcheck | [![Cppcheck](https://github.com/Gobikumaar-Sivagnanam/Embedded-C/actions/workflows/cppcheck.yml/badge.svg)](https://github.com/Gobikumaar-Sivagnanam/Embedded-C/actions/workflows/cppcheck.yml) |
| Codeacy Code Quality | [![Codacy Badge](https://app.codacy.com/project/badge/Grade/62503da33ec14a23a99c2461e483673a)](https://www.codacy.com/gh/Gobikumaar-Sivagnanam/Embedded-C/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Gobikumaar-Sivagnanam/Embedded-C&amp;utm_campaign=Badge_Grade) |

## Design Approach
| Requirement | My Implementation Idea |
|-------------|------------------------|
| Considering the design specifications, it's clear that the application runs only based on the Passenger sitting on the seat and switching on the heater system | Connecting the sensors of the two condtions to the Microcontroller. Implemented this using a `PIN CHANGE Interrput` to check if there is any change in these two sensor readings as they drive rest of the functionalities, and setting a flag to TRUE if both are satisfied |    
| Taking the ADC input Continuously as the user can opt to set the temperature at any time | Starting the ADC based on the set flag condition being TRUE. Then Handling rest of the features in `ADC Conversion Complete Interrupt` as if there is an ADC Conversion we need to perform the display and send data functions |
| Displaying the Input ADC values as PWM to the Oscilloscope | Intiazling the  Fast PWM Generation in 10-bit mode using Timer 1 inside the `ADC Conversion Complete Interrupt` as we need to display continuously. Setting the PWM Duty based on the range of ADC value |  
| Sending the Temperature set data serially | Implementing a USART protocol to serially transmit data based on the set temperature range done in the `ADC Conversion Complete Interrupt` as we need to display continuously based on user input | 

## Operation 

### Pin Configuration 

*   Using Atmega328 as the Microcontroller for implementing the Functionalities.
*   Pins and the peripherals connected to it

| PIN | Connected Peripheral | Direction of PIN |
|-----|----------------------|------|
| PIN B0 | LED Actuator (Indicator LED) | Output |
| PIN B1 | Pulse Width Modulation Wave | Output |
| PIN B3 | Sensor for Passenger Seated | Input |
| PIN B4 | Switch for Heating System | Input |
| PIN C0 | Set Temperature using ADC | Input |

### Simulation Circuit
<img src="/simulation/Circuit_Configuration.JPG">

### Requirements Check 

*   Passenger is not Seated and Heating System is OFF
<img src="/simulation/Operation_No_Switch.JPG">

*   Passenger is Seated and Heating System is OFF
<img src="/simulation/Operation_One_Switch_2.JPG">

*   Passenger is not Seated and Heating System is ON
<img src="/simulation/Operation_One_Switch_1.JPG">

*   Passenger is Seated and Heating System is ON
<img src="/simulation/Operation_Two_Switch.JPG">

*   System is running and suddenly one of the Condition Fails
<img src="/simulation/Operation_Start_Switch_Off.JPG">

### Functionality Check

*   **CASE-1 :** Initial Conditions are True and ADC Input is in the range \[1 - 200\]

| Expected Output | Simulation Output |
|-----------------|-------------------|
| LED Actuator- ON, PWM Output - 20%, Temperature - 20 C | <img src="/simulation/Operation_Two_Switch_Case1.JPG"> |

*   **CASE-2 :** Initial Conditions are True and ADC Input is in the range \[210 - 500\]

| Expected Output | Simulation Output |
|-----------------|-------------------|
| LED Actuator- ON, PWM Output - 40%, Temperature - 25 C | <img src="/simulation/Operation_Two_Switch_Case2.JPG"> |

*   **CASE-3 :** Initial Conditions are True and ADC Input is in the range \[510 - 700\]

| Expected Output | Simulation Output |
|-----------------|-------------------|
| LED Actuator- ON, PWM Output - 70%, Temperature - 29 C | <img src="/simulation/Operation_Two_Switch_Case3.JPG"> |

*   **CASE-4 :** Initial Conditions are True and ADC Input is in the range \[710 - 1023\]

| Expected Output | Simulation Output |
|-----------------|-------------------|
| LED Actuator- ON, PWM Output - 95%, Temperature - 33 C | <img src="/simulation/Operation_Two_Switch_Case4.JPG"> |