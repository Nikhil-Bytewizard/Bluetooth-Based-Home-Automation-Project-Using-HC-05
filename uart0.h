#ifndef UART0_H
#define UART0_H

extern void UART0_init(void);
extern void UART0_send_char(char c);
extern void UART0_send_string(const char *str);
extern char UART0_receive_char(void);

#endif
