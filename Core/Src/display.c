/*
 * display.c
 *
 *  Created on: Nov 29, 2020
 *      Author: Frixys
 */
#include "display.h"

//global variables
char curStr[NUM_DIG];
char complStr[] = "Samuel_Kostur_92610";
uint8_t complStrLen = 19;

//functions to handle multiplexing of the currently displaying alphanum char
void updAlphanumChar(char* seg_Val);
void setDigit(uint8_t pos);
void resAllSegments();
void resAllDigits();

//functions to handle shifting of the currently displaying string
void updCurPos(uint8_t *prevPos, uint8_t shiftDir);
void updShiftDir(uint8_t curPos, uint8_t *shiftDir);
void setCurStr(uint8_t curPos);

void DISPLAY_displayCurStr(){
	static int curActDig = 1;
	resAllDigits();

	switch (curStr[curActDig]){
		case 'A':
			updAlphanumChar(A_segVal);
			break;
		default:
			resAllDigits();
	}

	setDigit(curActDig);
	curActDig++;
	if(curActDig>=4){
		curActDig = 0;
	}
}

void updAlphanumChar(char* segmentValues){
	resAllSegments();
	if(segmentValues[0] == '1') LL_GPIO_SetOutputPin(seg_A_Port, seg_A_Pin);
	if(segmentValues[1] == '1') LL_GPIO_SetOutputPin(seg_B_Port, seg_B_Pin);
	if(segmentValues[2] == '1') LL_GPIO_SetOutputPin(seg_C_Port, seg_C_Pin);
	if(segmentValues[3] == '1') LL_GPIO_SetOutputPin(seg_D_Port, seg_D_Pin);
	if(segmentValues[4] == '1') LL_GPIO_SetOutputPin(seg_E_Port, seg_E_Pin);
	if(segmentValues[5] == '1') LL_GPIO_SetOutputPin(seg_F_Port, seg_F_Pin);
	if(segmentValues[6] == '1') LL_GPIO_SetOutputPin(seg_G_Port, seg_G_Pin);
	if(segmentValues[7] == '1') LL_GPIO_SetOutputPin(seg_DP_Port, seg_DP_Pin);
}

//Turns required digit ON
void setDigit(uint8_t pos){
	switch(pos){
		case 0:
			DIGIT_4_ON;
			break;
		case 1:
			DIGIT_3_ON;
			break;
		case 2:
			DIGIT_2_ON;
			break;
		case 3:
			DIGIT_1_ON;
			break;
	}
}

/*Reset (turn-off) all the segments of display*/
void resAllSegments(){
	LL_GPIO_SetOutputPin(seg_A_Port, seg_A_Pin);
	LL_GPIO_SetOutputPin(seg_B_Port, seg_B_Pin);
	LL_GPIO_SetOutputPin(seg_C_Port, seg_C_Pin);
	LL_GPIO_SetOutputPin(seg_D_Port, seg_D_Pin);
	LL_GPIO_SetOutputPin(seg_E_Port, seg_E_Pin);
	LL_GPIO_SetOutputPin(seg_F_Port, seg_F_Pin);
	LL_GPIO_SetOutputPin(seg_G_Port, seg_G_Pin);
	LL_GPIO_SetOutputPin(seg_DP_Port, seg_DP_Pin);
}

/* Reset (turn-off) all digits*/
void resAllDigits(void)
{
	LL_GPIO_ResetOutputPin(dig_1_Port, dig_1_Pin);
	LL_GPIO_ResetOutputPin(dig_2_Port, dig_2_Pin);
	LL_GPIO_ResetOutputPin(dig_3_Port, dig_3_Pin);
	LL_GPIO_ResetOutputPin(dig_4_Port, dig_4_Pin);
}

//Functions to handle shifting of the currently displaying string
void DISPLAY_shiftCurStr(){
	static uint8_t curPos = 0;
	static uint8_t shiftDir = LEFT_TO_RIGHT;

	updCurPos(&curPos, shiftDir);
	updShiftDir(curPos, &shiftDir);
	setCurStr(curPos);
}

void updCurPos(uint8_t *prevPos, uint8_t shiftDir){
	shiftDir == LEFT_TO_RIGHT ? (*prevPos)++ : (*prevPos)--;
}

void updShiftDir(uint8_t curPos, uint8_t *shiftDir){
	if(curPos >= (complStrLen - NUM_DIG)){
		*shiftDir =  LEFT_TO_RIGHT;
	}

	if(curPos <= 0){
		*shiftDir = RIGHT_TO_LEFT;
	}
}

void setCurStr(uint8_t curPos){
	for(uint8_t i = 0; i<NUM_DIG; i++){
		curStr[i] = complStr[curPos + i];
	}
}

//Function to change the complete string which is continuously being displayed on the display
void DISPLAY_setCompStr(char *newComplStr){
	//TODO
}

