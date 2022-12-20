/*
 * slave.c
 *
 * Created: 12/19/2022 
 *  Author: mostafa_hamedo
 */ 

#include <avr/io.h>
#define  F_CPU 8000000
#include <util/delay.h>
#include "UART.h"
#include "std_macros.h"
#include "led.h"
int main(void)
{
	led_init('b',0);
	led_init('b',1);
	led_init('b',2);
	Lcd_Init();
	UART_vInit(9600);
	
	Lcd_send_string("led1:OFFled2:OFF");
	Lcd_move_cursor(2,1) ;
	Lcd_send_string("led3:OFF    ");
	
	
	char data  ;
	while(1)
	{
		
		// Receive data and display on LCD
		data=UART_u8receive_data();
		//Lcd_send_char(data);
		
		if (data=='A')
		{
			led_on('B',0) ;
			Lcd_move_cursor(1,6);
			Lcd_send_string("ON ");
		} 
		else if(data=='B')
		{
			led_on('B',1) ;
			Lcd_move_cursor(1,14);
			Lcd_send_string("ON ");
		}
		else if(data=='C')
		{
			led_on('B',2) ;
			Lcd_move_cursor(2,6);
			Lcd_send_string("ON ");
		}
		else if(data=='O')
		{
			
			led_off('B',0) ;
			led_off('B',1) ;
			led_off('B',2) ;
			Lcd_move_cursor(1,6);
			Lcd_send_string("OFF");
			Lcd_move_cursor(1,14);
			Lcd_send_string("OFF");
			Lcd_move_cursor(2,6);
			Lcd_send_string("OFF");
			
		}
		
		
		
	}
}