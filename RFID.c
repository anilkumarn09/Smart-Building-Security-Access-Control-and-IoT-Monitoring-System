#include<LPC21xx.h>
#include"header.h"

int rfid_check()
{
  char RFID[13],s[13]="123456789012";
   int i=0;
   uart0_string("\r\nEnter RFID : ");
   lcd_cmd(0x01);
   lcd_string("Enter RFID");
         while(1)
         {
                for(i=0;i<12;i++)
                {
                        RFID[i]=uart0_rx();

                                  if(RFID[i]=='\0'||RFID[i]=='\n')
                                  break;

                }
                  RFID[i]=='\0';

                uart0_string("\r\nRFID : ");
        //      uart0_rx_string(RFID);
                uart0_string(RFID);


                for(i=0;s[i];i++)
                {
                 if(s[i]!=RFID[i])
                 break;
                }
                if(s[i]=='\0')
                return 1;
                else
                return 0;
        }
                //4900C8FDDCA0


}
