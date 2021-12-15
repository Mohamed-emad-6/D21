//project

#include "LED.h"
#include "RELAY.h"
#include "P_B.h"
#include "S_SEG.h"
#include "LCD.h"
#include "KEY_PAD.h"
#include "EX_INT.h"
#include "TEMP_S.h"
#include "REG.h"
#include "TIMER.h"
#include "WDT.h"
#include "UART.h"
#include "SPI.h"
#include "EEPROM_24C16.h"
#include <avr/interrupt.h>
#define  F_CPU 16000000UL
#include "util/delay.h"

extern u32 num_of_ov;
extern u32 initial_value;
  extern int WATER_TEMP;
int main(void)
{ 
	int con_temp;
	S_SEG_INIT();
	EEPROM_24C16_INIT();
    P_B_INIT (P_B_0); //temp up button
	 P_B_INIT (P_B_1); //temp down button
    TEMP_S_INIT();
	 LED_INIT   (M_LED);// cooling element
     LED_INIT   (L_LED);// heating element
	TIMER_0_INIT();
	TIMER_0_START(1000);	
	
	
	
	
	while(1)
    {	
		if(EEPROM_24C16_READ(0x00) != 0xFF)     // check if there are no data in EEPROM (first time to use it)
	    { con_temp= 60;                         //the inital set temperature is 60 degree
		    con_temp = EEPROM_24C16_READ(0x00);       // read data from byte number 0 in external EEPROM IC
	    }
		
		
		if (P_B_INIT (P_B_0)=1 && con_temp<=75) //if up button is pressed
		{con_temp=con_temp+5;
			int i;
		for (int i=0; i<=5 ; i++)
		{
			 S_SEG_DISPLAY     (con_temp);
			 _delay_ms(1000);
			  S_SEG_DISPLAY     ();
			  _delay_ms(1000);
		}
		}
		if (P_B_INIT (P_B_1)=1 && con_temp>=35)  //if down button is pressed
		{con_temp=con_temp-5;
			for (int i=0; i<5 ; i++)
			{
				S_SEG_DISPLAY  (con_temp);
				_delay_ms(1000);
				S_SEG_DISPLAY  ();
				_delay_ms(1000);
			}
		}
		
		
		
		if (WATER_TEMP = con_temp) //if watter temp is normal
	{	
         LED_OFF    (M_LED); //turn off cooling element
         LED_OFF    (L_LED);//turn off heater element
	}
	  else if ( WATER_TEMP = con_temp) // if watter temp is cold
     {  LED_OFF    (M_LED); //turn off cooling element
        LED_ON    (L_LED);//turn on heater element
	 }
	  else //1f watter temp is hot
	  {  LED_ON   (M_LED); //turn on cooling element
	    LED_OFF    (L_LED);//turn off heater element
	  }
       //end control FAN&HEATER
		
		EEPROM_24C16_WRITE(0x00,con_temp);   // write data in byte number 0 in external EEPROM IC
	
	}// end while 
}// end main 


ISR(TIMER0_OVF_vect)
{
	static u32 counter;
	counter++;
	if (counter == num_of_ov)
	{  WATER_TEMP = TEMP_S_READ();
		
		counter = 0;
		TCNT0 = initial_value;
	}
	



