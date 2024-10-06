#include <xc.h>
#include "lcd.h"
#include "atraso.h"

void lcd_wr(unsigned char val)
{
  LPORT=val;
}

void lcd_cmd(unsigned char val)
{
	LENA=1;
        lcd_wr(val);
        LDAT=0;
        atraso_ms(4);
        LENA=0;
        atraso_ms(4);
	LENA=1;
}
 
void lcd_dat(unsigned char val)
{
	LENA=1;
        lcd_wr(val);
        LDAT=1;
        atraso_ms(4);
        LENA=0;
        atraso_ms(4);
	LENA=1;
}



void lcd_init(void)
{
	LENA=0;
	LDAT=0;
	atraso_ms(20);
	LENA=1;
	lcd_cmd(L_CFG);
	atraso_ms(5);
	lcd_cmd(L_CFG);
    atraso_ms(1);
	lcd_cmd(L_CFG); //configura
	lcd_cmd(L_OFF);
	lcd_cmd(L_ON); //liga
	lcd_cmd(L_CLR); //limpa
	lcd_cmd(L_CFG); //configura
    lcd_cmd(L_L1);
}

void lcd_str(const char* str)
{
 unsigned char i=0;
  
 while(str[i] != 0 )
 {
   lcd_dat(str[i]);
   i++;
 }  
}

void lcd_set_cursor(unsigned char col, unsigned char row)
{
    unsigned char address;
    
    switch(row)
    {
        case 1:
            address = 0x80;
            break;
        case 2:
            address = 0xC0;
            break;
        case 3:
            address = 0x94;
            break;
        case 4:
            address = 0xD4;
            break;
        default:
            address = 0x80;
            break;
    }
    address += (col - 1);
    lcd_cmd(address);
}

 
