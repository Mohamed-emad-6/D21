/*
 * SERVO_MOTOR.c
 * Created: 24/09/2021 03:38:51 ص
 *  Author: MOHAMED_HELMY
 */ 

#include "DIO.h"
#include "TIMER.h"
#include "STD_TYPES.h"

void SERVO_INIT(void)
{
	PIN_MODE(PD5,OUTPUT);
	PWM_1_INIT();
	PWM_1_START();
}
void SERVO_MOVE(u8 duty_cycle)
{
	PWM_1_SET_DUTY_CYCLE(duty_cycle);
}