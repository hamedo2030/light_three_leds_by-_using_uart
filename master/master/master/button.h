/*
 * button.h
 *
 * Created: 8/11/2022 6:40:53 PM
 *  Author: happy
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

void button_init(char portname ,char pinnumber  );
unsigned char button_read(char portname,char pinnumber);


#endif /* BUTTON_H_ */