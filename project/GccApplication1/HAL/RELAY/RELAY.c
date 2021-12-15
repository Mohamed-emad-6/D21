/*
 * RELAY.c
 * Created: 8/30/2021 11:03:11 PM
 *  Author: MOHAMED_HELMY
 */ 

#include "RELAY_CFG.h"
#include "DIO.h"

void RELAY_INIT (void)
{
	PIN_MODE(RELAY_PIN,OUTPUT);
}
void RELAY_ON   (void)
{
	PIN_WRITE(RELAY_PIN,HIGH);
}
void RELAY_OFF  (void)
{
	PIN_WRITE(RELAY_PIN,LOW);
}