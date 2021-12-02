/*
 * input_reading.c
 *
 *  Created on: Dec 1, 2021
 *      Author: Dell
 */

/*
 * input_reading.c
 *
 *  Created on: Nov 12, 2021
 *      Author: Dell
 */


#include "main.h"
#define N0_OF_BUTTONS 				       3

////timer interrupt duration is 10ms, so to pass 1 second,
////we need to jump to the interrupt service routine 100 time
//#define DURATION_FOR_AUTO_INCREASING	   100

#define BUTTON_IS_PRESSED                  0
#define BUTTON_IS_RELEASED                 1

static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];

static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];

//we define a flag for a button pressed more than 1 second.
//static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];

//we define counter for automatically increasing the value
//after the button is pressed more than 1 second.
//static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];


void button_reading(void){
	for(int i = 0; i < N0_OF_BUTTONS; i ++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(GPIOA, 0x2000<<(uint16_t)i);

		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
			buttonBuffer[i] = debounceButtonBuffer1[i];
	}
}

unsigned char is_button_pressed(uint8_t index){
	if(index >= N0_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}



