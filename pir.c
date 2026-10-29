#include<lpc21xx.h>
#include"header.h"
#define Pir_sens ((IOPIN0 >> 15 ) & 1)
void PIR_Sensor(void)
{
        if(Pir_sens == 0)
        {
           uart0_string("Motion Status : CLEAR \r\n");
                 uart0_string("Security : NORMAL \r\n");

                 lcd_cmd(0x01);
                 lcd_cmd(0x80);
                 lcd_string("Field :SAFE");
                 lcd_cmd(0xC0);
                 lcd_string("No Motion");
        }
        else
        {
           uart0_string("Motion Status : DETECTED\r\n");
                 uart0_string("Security : ALERT\r\n");

                 lcd_cmd(0x01);
                 lcd_cmd(0x80);
                 lcd_string("Motion Found");
                 lcd_cmd(0xC0);
                 lcd_string("Check Field");
        }^M
        delay_sec(1);

        uart0_string("-----------------------------------\r\n");

        delay_ms(100);
}
