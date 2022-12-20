/*
 * master.c
 *
 * Created: 12/19/2022 
 *  Author: mostafa_hamedo
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"
#include "button.h"

int main(void)
{
	UART_vInit(9600) ; //Initialized UART
	_delay_ms(350); //Wait LCD Initialized AT Receiver controller 
	
	
	button_init('c',0);		// button_1
	button_init('c',1);		// button_2	
	button_init('c',2);		// button_3
	button_init('c',3);		// button_4     off 
	
	DIO_connect_pull_up('c',0,1);
	DIO_connect_pull_up('c',1,1);
	DIO_connect_pull_up('c',2,1);
	DIO_connect_pull_up('c',3,1);
    while(1)
    {
         // light led_1
		 if(button_read('c',0)==0)
		 {
			 _delay_ms(100);           // to solve bouncing switch problem
			 if (button_read('c',0)==0) // i used delay and double check
			 {
				 UART_vsend_data('A');
			 }
		 }
		 // light led_2
		 if(button_read('c',1)==0)
		 {
			 _delay_ms(100);          
			 if (button_read('c',1)==0) 
			 {
				 UART_vsend_data('B');
			 }
		 }
		 // light led_3
		if(button_read('c',2)==0)
		{
			_delay_ms(100);           
			if (button_read('c',2)==0) 
			{
				UART_vsend_data('C');
			}
		}
		// off all leds
		if(button_read('c',3)==0)
		{
			_delay_ms(100);           
			if (button_read('c',3)==0) 
			{
				UART_vsend_data('O');  // off all leds 
			}
		}
		
    }
}