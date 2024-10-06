#include <xc.h>
#include "config_4550.h"

#define _XTAL_FREQ 48000000
#define COL1 PORTBbits.RB0
#define COL2 PORTBbits.RB1
#define COL3 PORTBbits.RB2
#define COL4 PORTBbits.RB3
#define LIN1 PORTBbits.RB4
#define LIN2 PORTBbits.RB5
#define LIN3 PORTBbits.RB6
#define LIN4 PORTBbits.RB7

char tecla;
char tecla_pres;

char varre_teclas(void) {
    char key = ' ';

    // Configurar as colunas como saídas e as linhas como entradas

    COL4 = 1; COL3 = 1; COL2 = 1; COL1 = 0; // Ativa a primeira coluna
    __delay_us(10); // Pequeno atraso para garantir a estabilidade do sinal
    if (!LIN1) key = '1';
    if (!LIN2) key = '4';
    if (!LIN3) key = '7';
    if (!LIN4) key = '*';
    COL1 = 1; COL2 = 0; // Ativa a segunda coluna
    __delay_us(10); // Pequeno atraso para garantir a estabilidade do sinal
    if (!LIN1) key = '2';
    if (!LIN2) key = '5';
    if (!LIN3) key = '8';
    if (!LIN4) key = '0';
    COL2 = 1; COL3 = 0; // Ativa a terceira coluna
    __delay_us(10); // Pequeno atraso para garantir a estabilidade do sinal
    if (!LIN1) key = '3';
    if (!LIN2) key = '6';
    if (!LIN3) key = '9';
    if (!LIN4) key = '#';
    COL3 = 1; COL4 = 0; // Ativa a quarta coluna
    __delay_us(10); // Pequeno atraso para garantir a estabilidade do sinal
    if (!LIN1) key = 'A';
    if (!LIN2) key = 'B';
    if (!LIN3) key = 'C';
    if (!LIN4) key = 'D';
    COL4 = 1;

    return key;
}

char trata_teclas(void) {
    char t;

    t = varre_teclas(); // Verifica se há uma tecla pressionada
    if ((t != ' ') && (!tecla_pres)) { // Se há tecla pressionada e o flag está apagado
        tecla_pres = 1; // Ativa o flag
        if (t != tecla) {
            // Filtra o ruído de contato
            __delay_ms(10);
            // Lê novamente as teclas e verifica 
            // se a mesma tecla ainda está pressionada
            // caso positivo, retorna a tecla
            if (varre_teclas() == t) return t;
        }
    }
    tecla_pres = 0; // Se não há tecla, retorna 0
    return ' ';
}