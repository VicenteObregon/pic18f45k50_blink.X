/*
 * File:   main.c
 * Author: vicente
 *
 * Created on May 28, 2016, 3:13 AM
 */

#include <xc.h>

#pragma config PLLSEL   = PLL3X
#pragma config FOSC     = INTOSCIO
#pragma config nPWRTEN  = OFF
#pragma config WDTEN    = OFF
#pragma config CCP2MX   = RB3
#pragma config STVREN   = OFF
#pragma config CP0      = OFF
#pragma config CPB      = OFF
#pragma config WRT0     = OFF
#pragma config WRTC     = OFF
#pragma config EBTR0    = OFF
#pragma config EBTRB    = OFF

void interrupt isr(void) {
    if (TMR0IF) {
        LATDbits.LATD1 = ~LATDbits.LATD1;
        TMR0IF = 0;
        return;
    }
}

void main(void) {
    TRISD = 0;
    GIEH = 1;
    TMR0IE = 1;
    T0CON = 0b10000000;
    LATDbits.LATD1 = 0;
    while (1) {
    }
}
