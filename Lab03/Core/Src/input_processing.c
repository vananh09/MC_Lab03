/*
 * input_processing.c
 *
 *  Created on: Nov 12, 2021
 *      Author: Dell
 */


#include "main.h"
#include "input_reading.h"
int TIMER_CYCLE = 10;
int timer0_counter = 0;
int timer0_flag = 0;
void setTimer0 (int duration){
	timer0_counter = duration/TIMER_CYCLE;
	timer0_flag = 0;
}
void timer_run0(){
	if(timer0_counter > 0){
		timer0_counter --;
		if( timer0_counter == 0)
			timer0_flag = 1;
	}
}
void resettrafficLed(){
	HAL_GPIO_WritePin(GPIOA, LED0_Pin|LED1_Pin|LED2_Pin|LED3_Pin
	                          |LED4_Pin|LED5_Pin, GPIO_PIN_RESET);
}
void displaytrafficLed(int number){
	switch (number) {
	case 0: // Red led in the Col, Green led in the Row
		HAL_GPIO_WritePin(GPIOA, LED0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOA, LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_RESET);
		break;
	case 1: // Red led in the Col, Yellow led in the Row
		HAL_GPIO_WritePin(GPIOA, LED0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOA, LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_SET);
		break;
	case 2: // Red led in the Row, Green led in the Col
		HAL_GPIO_WritePin(GPIOA, LED0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOA, LED3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_SET);
		break;
	case 3: // Red led in the Col, Yellow led in the Row
		HAL_GPIO_WritePin(GPIOA, LED0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOA, LED3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_SET);
		break;
	case 4: // Toggle Red led
		if(timer0_flag){
			setTimer0(500);
			HAL_GPIO_TogglePin(GPIOA, LED0_Pin);
			HAL_GPIO_TogglePin(GPIOA, LED3_Pin);
		}
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_SET);
		break;
	case 5: // Toggle Yellow led
		if(timer0_flag){
			setTimer0(500);
			HAL_GPIO_TogglePin(GPIOA, LED1_Pin);
			HAL_GPIO_TogglePin(GPIOA, LED4_Pin);
		}
		HAL_GPIO_WritePin(GPIOA, LED0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED2_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOA, LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_SET);
		break;
	case 6: // Toggle Green led
		if(timer0_flag){
			setTimer0(500);
			HAL_GPIO_TogglePin(GPIOA, LED2_Pin);
			HAL_GPIO_TogglePin(GPIOA, LED5_Pin);
		}
		HAL_GPIO_WritePin(GPIOA, LED0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOA, LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_SET);
		break;
	default:
		break;
	}
}

void display7segMode(int num){
	uint8_t a = num%10;
	uint8_t b = num/10;

	HAL_GPIO_WritePin(GPIOB, MODE0_Pin, ((a>>3)&0x01));
	HAL_GPIO_WritePin(GPIOB, MODE1_Pin, ((a>>2)&0x01));
	HAL_GPIO_WritePin(GPIOB, MODE2_Pin, ((a>>1)&0x01));
	HAL_GPIO_WritePin(GPIOB, MODE3_Pin, ((a>>0)&0x01));

	HAL_GPIO_WritePin(GPIOB, MODE4_Pin, ((b>>3)&0x01));
	HAL_GPIO_WritePin(GPIOB, MODE5_Pin, ((b>>2)&0x01));
	HAL_GPIO_WritePin(GPIOB, MODE6_Pin, ((b>>1)&0x01));
	HAL_GPIO_WritePin(GPIOB, MODE7_Pin, ((b>>0)&0x01));
}
void display7segValue(int num){
	uint8_t a = num%10;
	uint8_t b = num/10;

	HAL_GPIO_WritePin(GPIOB, VAL0_Pin, ((a>>3)&0x01));
	HAL_GPIO_WritePin(GPIOB, VAL1_Pin, ((a>>2)&0x01));
	HAL_GPIO_WritePin(GPIOB, VAL2_Pin, ((a>>1)&0x01));
	HAL_GPIO_WritePin(GPIOB, VAL3_Pin, ((a>>0)&0x01));

	HAL_GPIO_WritePin(GPIOB, VAL4_Pin, ((b>>3)&0x01));
	HAL_GPIO_WritePin(GPIOB, VAL5_Pin, ((b>>2)&0x01));
	HAL_GPIO_WritePin(GPIOB, VAL6_Pin, ((b>>1)&0x01));
	HAL_GPIO_WritePin(GPIOB, VAL7_Pin, ((b>>0)&0x01));

}
void Mode1(){
	if(timer0_flag){
		setTimer0(1000);
		if(state_mode == 0){
			if(timeTotal > 0){
				display7segMode(timeTotal);
				if((timeTotal - timeAmber) > 0){
					display7segValue(timeTotal - timeAmber);
					displaytrafficLed(0);
				} else{
					displaytrafficLed(1);
					display7segValue(timeTotal);
				}
				timeTotal --;
			} else {
				state_mode = 1;
				timeTotal = timeRed;
			}
		}
		if(state_mode == 1){
			if(timeTotal > 0){
				display7segValue(timeTotal);
				if((timeTotal - timeAmber) > 0){
					display7segMode(timeTotal - timeAmber);
					displaytrafficLed(2);
				} else{
					displaytrafficLed(3);
					display7segMode(timeTotal);
				}
				timeTotal --;
			} else {
				state_mode = 0;
				timeTotal = timeRed;
			}
		}
	}
}
void Mode2(){
	display7segMode(02);
	displaytrafficLed(4);
	if(is_button_pressed(1)){
		if(press[1]){
			timeRed ++;
			if(timeRed>99) timeRed = 0;
			press[1] = 0;
		}
	} else press[1] = 1;
	display7segValue(timeRed);

	if(is_button_pressed(2)){
		if(press[2]){
			timeGreen += timeRed - time_buffer[0];
			time_buffer[0] = timeRed;
			resettrafficLed();
			flagPressButton3 = 1;
			press[2] = 0;
		}
	} else{
		press[2] = 1;
	}
}

void Mode3(){
	display7segMode(03);
	displaytrafficLed(5);
	if(is_button_pressed(1)){
		if(press[1]){
			timeAmber ++;
			if(timeAmber>99) timeAmber = 0;
			press[1] = 0;
		}
	} else press[1] = 1;

	display7segValue(timeAmber);

	if(is_button_pressed(2)){
		if(press[2]){
			timeRed += timeAmber - time_buffer[1];
			time_buffer[1] = timeAmber;
			resettrafficLed();
			flagPressButton3 = 1;
			press[2] = 0;
		}
	} else{
		press[2] = 1;
	}
}
void Mode4(){
	display7segMode(04);
	displaytrafficLed(6);
	if(is_button_pressed(1)){
		if(press[1]){
			timeGreen ++;
			if(timeGreen>99) timeGreen = 0;
			press[1] = 0;
		}
	} else press[1] = 1;

	display7segValue(timeGreen);

	if(is_button_pressed(2)){
		if(press[2]){
			timeRed += timeGreen - time_buffer[2];
			time_buffer[2] = timeGreen;
			resettrafficLed();
			flagPressButton3 = 1;
			press[2] = 0;
		}
	} else{
		press[2] = 1;
	}
}
enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND} ;
enum ButtonState buttonState = BUTTON_RELEASED;
enum Mode {MODE1, MODE2, MODE3, MODE4};
enum Mode mode = MODE1;

void fsm_for_input_processing(void){
	switch (mode){
	case MODE1:
		if(is_button_pressed(0)){
			if(press[0] == 1){
				mode = MODE2;
				resettrafficLed();
				press[0] = 0;
			}
		} else{
			press[0] = 1;
		}
		Mode1();
		break;
	case MODE2:
		if(is_button_pressed(0)){
			if(press[0] == 1){
				mode = MODE3;
				resettrafficLed();
				if(flagPressButton3 == 0){
					timeRed = time_buffer[0];
				} else flagPressButton3 = 0;
				press[0] = 0;
			}
		} else{
			press[0] = 1;
		}
		Mode2();
		break;
	case MODE3:
		if(is_button_pressed(0)){
			if(press[0] == 1){
				mode = MODE4;
				resettrafficLed();
				if(flagPressButton3 == 0){
					timeAmber = time_buffer[1];
				} else flagPressButton3 = 0;
				press[0] = 0;
			}
		} else{
			press[0] = 1;
		}
		Mode3();
		break;
	case MODE4:
		if(is_button_pressed(0)){
			if(press[0] == 1){
				mode = MODE1;
				resettrafficLed();
				if(flagPressButton3 == 0){
					timeGreen = time_buffer[2];
				} else flagPressButton3 = 0;
				timeTotal = timeRed;
				press[0] = 0;
			}
		} else{
			press[0] = 1;
		}
		Mode4();
		break;
	}
}
