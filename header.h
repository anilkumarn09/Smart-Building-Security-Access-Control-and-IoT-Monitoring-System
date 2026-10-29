#include<lpc21xx.h>
   typedef unsigned int u32;
   typedef signed int s32;
   typedef unsigned char u8;
   typedef signed char s8;

  extern void delay_ms(u32 ms);
  extern void delay_sec(u32 sec);

  extern void uart0_string(char *ptr);
  extern u8 uart0_rx(void);
  extern u8 uart0_rx_timeout(u32 timeout_ms, char *out); // returns 1 + byte in *out, or 0 on timeout
  extern void uart0_tx(u8 data);
  extern void uart0_init(u32 baud);
  extern void  uart0_float(float num);
  extern void uart0_integer(int num);
  extern void uart0_rx_string(char *ptr);^M
  extern int str_cmp(const char *s1,const char *s2);

  extern void lcd_string(char *ptr);
  extern void lcd_init(void);
  extern void lcd_cmd(u32 cmd);
  extern void lcd_data(u8 data);

  extern void i2c_init(void);
  extern void i2c_write(u8 sa, u8 mr, u8 data);
  extern unsigned char i2c_read(u8 sa,u8 mr);

  extern void spi_init(void);
  extern u8 spi(u8 data);
  extern u32 mcp3204_adc_read(u8 ch_num);


  extern void rtc_init(void);
  extern void settime(u8 hr,u8 min,u8 sec);
  extern void setdate(u8 date,u8 month,u8 year);
  extern void gettime(void);
  extern void getdate(void);
  extern void displaydate(void);
  extern void displaytime(void);
  extern void displaytime_uart(void);^M
  extern void displaydate_uart(void);

   extern void PIR_Sensor(void);

  extern int rfid_check(void);

  extern char keypad_read(void);
  extern void keypad_init(void);
  extern int keypad_check(unsigned char *entered);

  extern void servo_init(void);
  extern void servo_0deg(void);
  extern void servo_90deg(void);
  extern void servo_180deg(void);

extern unsigned char hours;
extern unsigned char minutes;
extern unsigned char seconds;
extern unsigned char date;
extern unsigned char month;
extern unsigned char year;
extern void eeprom(void);

