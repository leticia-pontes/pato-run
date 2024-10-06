#define LENA  PORTEbits.RE1
#define LDAT  PORTEbits.RE0 

#define LPORT PORTD


#define L_ON	0x0F
#define L_OFF	0x08
#define L_CLR	0x01
#define L_L1	0x80
#define L_L2	0xC0
#define L_CR	0x0F		
#define L_NCR	0x0C	

#define L_CFG   0x38

// Definições para LCD de 4 linhas e 20 caracteres

// Definições para cgram_loc
#define CGRAM_START_ADDR 0x64 // Endereço inicial da CGRAM
#define CHAR_PER_LINE 20      // Número de caracteres por linha
#define CHAR_PER_CGRAM 8      // Número de caracteres na CGRAM
#define CGRAM_PER_LINE (CHAR_PER_LINE / CHAR_PER_CGRAM) // Número de endereços da CGRAM por linha

#define CGRAM_LINE_OFFSET(line) (line - 1) * CGRAM_PER_LINE // Offset de linha para CGRAM

// Definições para lcd_loc
#define LCD_LINE_OFFSET(line) ((line - 1) * CHAR_PER_LINE) // Offset de linha para lcd_loc

// Macro para calcular lcd_loc
#define LCD_LOC(line, col) (0x80 + LCD_LINE_OFFSET(line) + (col - 1))

// LCD
#define LCD_1_1 0x80
#define LCD_1_2 0x81
#define LCD_1_3 0x82
#define LCD_1_4 0x83
#define LCD_1_5 0x84
#define LCD_1_6 0x85
#define LCD_1_7 0x86
#define LCD_1_8 0x87
#define LCD_1_9 0x88
#define LCD_1_10 0x89
#define LCD_1_11 0x8A
#define LCD_1_12 0x8B
#define LCD_1_13 0x8C
#define LCD_1_14 0x8D
#define LCD_1_15 0x8E
#define LCD_1_16 0x8F
#define LCD_1_17 0x90
#define LCD_1_18 0x91
#define LCD_1_19 0x92
#define LCD_1_20 0x93
#define LCD_2_1 0xC0
#define LCD_2_2 0xC1
#define LCD_2_3 0xC2
#define LCD_2_4 0xC3
#define LCD_2_5 0xC4
#define LCD_2_6 0xC5
#define LCD_2_7 0xC6
#define LCD_2_8 0xC7
#define LCD_2_9 0xC8
#define LCD_2_10 0xC9
#define LCD_2_11 0xCA
#define LCD_2_12 0xCB
#define LCD_2_13 0xCC
#define LCD_2_14 0xCD
#define LCD_2_15 0xCE
#define LCD_2_16 0xCF
#define LCD_2_17 0xD0
#define LCD_2_18 0xD1
#define LCD_2_19 0xD2
#define LCD_2_20 0xD3
#define LCD_3_1 0x94
#define LCD_3_2 0x95
#define LCD_3_3 0x96
#define LCD_3_4 0x97
#define LCD_3_5 0x98
#define LCD_3_6 0x99
#define LCD_3_7 0x9A
#define LCD_3_8 0x9B
#define LCD_3_9 0x9C
#define LCD_3_10 0x9D
#define LCD_3_11 0x9E
#define LCD_3_12 0x9F
#define LCD_3_13 0xA0
#define LCD_3_14 0xA1
#define LCD_3_15 0xA2
#define LCD_3_16 0xA3
#define LCD_3_17 0xA4
#define LCD_3_18 0xA5
#define LCD_3_19 0xA6
#define LCD_3_20 0xA7
#define LCD_4_1 0xD4
#define LCD_4_2 0xD5
#define LCD_4_3 0xD6
#define LCD_4_4 0xD7
#define LCD_4_5 0xD8
#define LCD_4_6 0xD9
#define LCD_4_7 0xDA
#define LCD_4_8 0xDB
#define LCD_4_9 0xDC
#define LCD_4_10 0xDD
#define LCD_4_11 0xDE
#define LCD_4_12 0xDF
#define LCD_4_13 0xE0
#define LCD_4_14 0xE1
#define LCD_4_15 0xE2
#define LCD_4_16 0xE3
#define LCD_4_17 0xE4
#define LCD_4_18 0xE5
#define LCD_4_19 0xE6
#define LCD_4_20 0xE7


void lcd_init(void);
void lcd_cmd(unsigned char val); 
void lcd_dat(unsigned char val);
void lcd_str(const char* str);
void lcd_set_cursor(unsigned char col, unsigned char row);

