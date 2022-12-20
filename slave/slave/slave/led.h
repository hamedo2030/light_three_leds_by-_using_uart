/*
 * led.h
 *
 * Created: 8/11/2022 4:48:27 PM
 *  Author: happy
 */ 


#ifndef LED_H_
#define LED_H_

void led_init(char portname,char pinnumber);
void led_on(char portname,char pinnumber);
void led_off(char portname,char pinnumber);
void led_toggle(char portname,char pinnumber);
unsigned char led_read_status(char portname,char pinnumber);



#endif /* LED_H_ */