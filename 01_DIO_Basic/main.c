/*
 * main.c
 *
 *  Created on: May 10, 2022
 *      Author: Riad
 */
#include <avr/io.h>
#include <util/delay.h>
int main (void)
{


DDRA = 0xff;
DDRB = 0xff;
char arr[10]={0b10111111,0b10000110,0b11011011,0b11001111,0b11100110,0b11101101,0b11111101,0b10000111,0b11111111,0b11101111};
while(1)
{
for (int i=0;i<10;i++)
{
PORTA=arr[i];
_delay_ms(500);
}
for (signed int i=9;i>=0;i--)
{
PORTA=arr[i];
_delay_ms(500);
}


}



return 0;

}

