#include <LPC21xx.h>
#include "uart0.h"

void UART0_init(void) {
    PINSEL0 |= 0x00000005; // Enable UART0 on P0.0 (TXD0) and P0.1 (RXD0)
    U0LCR = 0x83;           // 8-bit, 1 stop bit, DLAB = 1
    U0DLL = 97;             // 9600 baud rate @ 15MHz
    U0DLM = 0;
    U0LCR = 0x03;           // DLAB = 0
}

void UART0_send_char(char c) {
    while (!(U0LSR & 0x20)); // Wait for empty THR
    U0THR = c;
}

void UART0_send_string(const char *str) {
    while (*str) {
        UART0_send_char(*str++);
    }
}

char UART0_receive_char(void) {
    while (!(U0LSR & 0x01)); // Wait for data to be received
    return U0RBR;
}
