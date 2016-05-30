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
        LATD0 = ~LATD0;
        TMR0IF = 0;
        return;
    }
    if (TMR1IF) {
        LATD1 = ~LATD1;
        TMR1IF = 0;
        return;
    }
    if (TMR2IF) {
        LATD2 = ~LATD2;
        TMR2IF = 0;
        return;
    }
}

void main(void) {
    TRISD = 0;
    LATD = 0;
    GIEL = 1;
    GIEH = 1;
    T0CON = 0b10000000;
    TMR0IE = 1;
    T1CON = 0b00000001;
    TMR1IE = 1;
    T2CON = 0b00000100;
    TMR2IE = 1;
    while (1) {
    }
}
