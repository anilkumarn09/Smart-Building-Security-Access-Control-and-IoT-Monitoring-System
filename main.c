#include <lpc21xx.h>
#include "header.h"

#define PIR (1<<15)

int main(void)
{
    int i;
    int rfid_attempt;
    int key_attempt;
    int granted;

    unsigned char entered[4];

    IODIR0 &= ~PIR;

    uart0_init(9600);
    rtc_init();
    lcd_init();
    servo_init();
    keypad_init();

    uart0_string("\r\nSMART BUILDING SECURITY");

    lcd_cmd(0x01);
        lcd_cmd(0x80);
    lcd_string("Smart Building");
    delay_ms(500);

    lcd_cmd(0x01);
    lcd_string("System Ready");
    uart0_string("\r\nSystem Ready");

    while(1)
    {
        lcd_cmd(0x01);
        lcd_string("Monitoring");
        uart0_string("\r\nMonitoring...");

        while((IOPIN0 & PIR) == 0);
                PIR_Sensor();
        uart0_string("\r\nWelcome! Please proceed.");
        uart0_string("\r\nWaiting for RFID...");

        lcd_cmd(0x01);
        lcd_string("Welcome!");
        delay_ms(500);

        lcd_cmd(0x01);
        lcd_string("Waiting RFID");

        granted = 0;
        rfid_attempt = 0;

        while(rfid_attempt < 3)
        {
            if(rfid_check())
            {
                uart0_string("\r\nRFID Verified");
                lcd_cmd(0x01);
                lcd_string("RFID Verified");
                granted = 1;
                break;
            }

            rfid_attempt++;

            uart0_string("\r\nRFID Failed");
            lcd_cmd(0x01);
            lcd_string("RFID Failed");

            delay_ms(300);
        }

        if(granted == 0)
        {
          //  uart0_string("\r\nEnter Password");
       //     lcd_cmd(0x01);
       //     lcd_string("Enter Password");

            key_attempt = 0;

            while(key_attempt < 3)
            {

                         uart0_string("\r\nEnter Password : ");
            lcd_cmd(0x01);
            lcd_string("Enter Password");


                for(i = 0; i < 4; i++)
                {
                    entered[i] = uart0_rx();
                                        if(i==0)
                                        lcd_cmd(0x01);
                                        //keypad_read();
                                        //uart0_rx();
                                        uart0_tx('*');

                    lcd_data('*');
                }

                if(keypad_check(entered))
                {
                    uart0_string("\r\nPassword Verified");
                    lcd_cmd(0x01);
                    lcd_string("Pass Verified");
                    granted = 1;
                    break;
                }

                key_attempt++;

                if(key_attempt < 3)
                {
                    uart0_string("\r\nWrong Password, Try Again");
                    lcd_cmd(0x01);
                    lcd_string("Wrong, Retry");
                }
                else
                {
                    uart0_string("\r\nSorry, Access Denied");
                    lcd_cmd(0x01);
                    lcd_string("Sorry Denied");
                }

                delay_ms(300);
            }
        }

        if(granted)
        {
            uart0_string("\r\nACCESS GRANTED");
            lcd_cmd(0x01);
            lcd_string("ACCESS GRANTED");

            eeprom();

            servo_90deg();
                        uart0_string("\r\nOpening Door");
                           lcd_cmd(0x01);
                         lcd_string("Opening Door");
            delay_sec(2);
                        servo_0deg();

            uart0_string("\r\nDoor Closed\r\n");
            lcd_cmd(0x01);
            lcd_string("Door Closed");
        }
        else
        {
            uart0_string("\r\nACCESS DENIED\r\n");
            lcd_cmd(0x01);
            lcd_string("ACCESS DENIED");
                        servo_0deg();
            eeprom();

            delay_sec(2);
        }
        displaydate_uart();
        uart0_string("\r\n");
        displaytime_uart();
        displaydate();
        lcd_cmd(0xC0);
        displaytime();
        delay_sec(1);

        lcd_cmd(0x01);
        lcd_string("Monitoring");
    }
}

