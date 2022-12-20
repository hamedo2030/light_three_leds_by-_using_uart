/*
 * led.c
 *
 * Created: 8/11/2022 4:28:45 PM
 *  Author: eng_mostafa_hamedo
 */ 
#include"DIO_Drives.h"
void led_init(char portname,char pinnumber)
{
	DIO_set_pin_direction(portname,pinnumber,1)	;
}
//..........................................
void led_on(char portname,char pinnumber)
{
	DIO_write_pin(portname,pinnumber,1);
}
//..........................................
void led_off(char portname,char pinnumber)
{
	DIO_write_pin(portname,pinnumber,0);
}
//..........................................
void led_toggle(char portname,char pinnumber)
{
	DIO_toggle_pin(portname,pinnumber);
}
//..........................................
unsigned char led_read_status(char portname,char pinnumber)
{
	unsigned char status ;
	status=DIO_read_pin(portname,pinnumber);
	return status ;
}	
//..........................................