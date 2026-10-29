#include<lpc21xx.h>
#include"header.h"

// Assumes PCLK = 15,000,000 Hz (VPBDIV = 0), same assumption used in uart0_init.

void delay_ms(u32 ms)
{
                T0PR=15000-1;      // TC increments once per 1 ms
                T0PC=0;
                T0TC=0;
                T0TCR=1;
                while(T0TC<ms);
                T0TCR=0;
}

void delay_sec(u32 sec)
{
                T0PR=15000000-1;   // TC increments once per 1 sec (was wrongly using the ms prescaler)
                T0PC=0;
                T0TC=0;
                T0TCR=1;
                while(T0TC<sec);
                T0TCR=0;
}
