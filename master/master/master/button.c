/*
 * CFile1.c
 *
 * Created: 8/11/2022 5:42:31 PM
 *  Author: happy
 */ 
#include "DIO_Drives.h"
void button_init(char portname ,char pinnumber  )
{
	DIO_set_pin_direction(portname,pinnumber,0);
}
//----------------------------------------------

unsigned char button_read(char portname,char pinnumber)
{
	unsigned char z=0 ;
	z= DIO_read_pin(portname,pinnumber);
	return z;
}