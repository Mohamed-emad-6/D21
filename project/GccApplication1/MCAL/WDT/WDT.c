/*
 * WDT.c
 *
 * Created: 25/09/2021 07:40:06 ص
 *  Author: dell
 */ 
#include "BIT_MATH.h"
#include "REG.h"

void WDT_INIT(void)
{
	SET_BIT(WDTCR,3);

	SET_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);

}

void WDT_REFRESH(void)
{
	asm("WDR");
}