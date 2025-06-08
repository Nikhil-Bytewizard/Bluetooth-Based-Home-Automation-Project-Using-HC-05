#include <LPC21xx.h>
#include "uart0.h"

#define LIGHT (1 << 10)
#define FAN   (1 << 11)
#define MODE_SWITCH (1 << 5)
#define BTN1 (1 << 6)
#define BTN2 (1 << 7)

void delay_ms(unsigned int ms) 
	{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 8000; j++);
	}

void GPIO_init(void) 
	{
    IO0DIR |= LIGHT | FAN;
    IO0DIR &= ~(MODE_SWITCH | BTN1 | BTN2);
    IO0CLR = LIGHT | FAN;
	}

void manual_mode(void) 
	{
    if (!(IO0PIN & BTN1)) IO0SET = LIGHT;
    else IO0CLR = LIGHT;

    if (!(IO0PIN & BTN2)) IO0SET = FAN;
    else IO0CLR = FAN;
}

void bluetooth_mode(void) 
	{
    char cmd = UART0_receive_char();
    switch (cmd) 
			{
        case 'A': IO0SET = LIGHT; break;
        case 'a': IO0CLR = LIGHT; break;
        case 'B': IO0SET = FAN; break;
        case 'b': IO0CLR = FAN; break;
        default: break;
			}
	}

int main(void) 
	{
    GPIO_init();
    UART0_init();

    while (1) 
			{
        if (IO0PIN & MODE_SWITCH)
            bluetooth_mode();
        else
            manual_mode();
        delay_ms(100);
			}
}
