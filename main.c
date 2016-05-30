/*
 * File:   main.c
 * Author: vicente
 *
 * Created on May 28, 2016, 3:13 AM
 */

#include <xc.h>

#pragma config PLLSEL = PLL3X // 300000
#pragma config CFGPLLEN = ON
#pragma config CPUDIV = NOCLKDIV
#pragma config FOSC = INTOSCIO // 300001
#pragma config nPWRTEN = OFF // 300002
#pragma config BOREN = ON
#pragma config WDTEN = OFF // 300003
#pragma config MCLRE = OFF // 300005
#pragma config STVREN = ON // 300006
#pragma config CONFIG5L = 0x0F // 300008
#pragma config CONFIG5H = 0xC0 // 300009
#pragma config CONFIG6L = 0x0F // 30000A
#pragma config CONFIG6H = 0xE0 // 30000B
#pragma config CONFIG7L = 0x0F // 30000C
#pragma config CONFIG7H = 0x40 // 30000D

volatile unsigned long g_tick0 = 0;
volatile unsigned long g_tick1 = 0;
volatile unsigned long g_tick2 = 0;

void interrupt isr(void) {
    if (TMR0IE && TMR0IF) {
        ++g_tick0;
        TMR0IF = 0;
        return;
    }
    if (TMR1IE && TMR1IF) {
        ++g_tick1;
        TMR1IF = 0;
        return;
    }
    if (TMR2IE && TMR2IF) {
        ++g_tick2;
        TMR2IF = 0;
        return;
    }
}

void main(void) {
    TRISD = 0;
    LATD = 0;
    OSCCON = 0b11111100;
    GIEL = 1;
    GIEH = 1;
    T0CON = 0b10000000;
    TMR0IE = 1;
    T1CON = 0b00000001;
    TMR1IE = 1;
    PR2 = 250;
    T2CON = 0b01011101;
    TMR2IE = 1;
    while (1) {
        LATD0 = (g_tick0 / 1000) % 2;
        LATD1 = (g_tick1 / 1000) % 2;
        LATD2 = (g_tick2 / 1000) % 2;
    }
}
