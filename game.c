#include <xc.h>
#include <stdlib.h>
#include "config_4550.h"
#include "atraso.h"
#include "lcd.h"
#include "16Keys.h"

#define _XTAL_FREQ 48000000

// Caracteres especiais
unsigned char pato[] = {3, 3, 6, 15, 30, 12, 10, 4}; // ????
unsigned char pedra[] = {0, 14, 31, 31, 31, 14, 0, 0}; // ????

// Converte o caractere especial
void special_char(unsigned char cgram_loc, unsigned char *data) {
    unsigned int j = 0;
    lcd_cmd(cgram_loc); // Envia a localização da CGRAM
    while (j < 8) {
        lcd_dat(data[j]); // Envia os valores bitmap do caractere
        j++;
    }
}

// Exibe o caractere especial no LCD
void print_special_character(unsigned char cgram_loc, unsigned char lcd_loc) {
    lcd_cmd(lcd_loc);               // Envia a localização no LCD onde o caractere será exibido
    lcd_dat((cgram_loc - 64) / 8);  // Valor ASCII do endereço base correspondente
}

// Função para retornar o valor hexadecimal de uma posição específica
unsigned char lcd_pos(int col, int line) {
    return (line == 1) ? 0x80 + col - 1 :
           (line == 2) ? 0xC0 + col - 1 :
           (line == 3) ? 0x94 + col - 1 :
           (line == 4) ? 0xD4 + col - 1 : 0;
}

int get_random_line() {
    int N = 4; // Permite números entre 1 e 4 (representam as linhas do LCD)
    int linha = rand() % N + 1; // Calcula o valor da linha
    return linha;
}

// Estrutura para armazenar o estado de uma pedra
typedef struct {
    int linha;
    int coluna;
    int ativa; // 0: inativa, 1: ativa
} Pedra;

// Variável global para posição do personagem
volatile int character_line = 3; // Começa na terceira linha

// Número máximo de pedras
#define MAX_PEDRAS 5

// Função para inicializar pedras
void init_pedras(Pedra pedras[], int size) {
    for (int i = 0; i < size; i++) {
        pedras[i].ativa = 0;
    }
}

// Função para lançar uma nova pedra
void launch_pedra(Pedra pedras[], int size) {
    for (int i = 0; i < size; i++) {
        if (!pedras[i].ativa) {
            pedras[i].linha = get_random_line();
            pedras[i].coluna = 20;
            pedras[i].ativa = 1;
            break;
        }
    }
}

// Função para mover pedras
void move_pedras(Pedra pedras[], int size) {
    for (int i = 0; i < size; i++) {
        if (pedras[i].ativa) {
            if (pedras[i].coluna > 0) {
                pedras[i].coluna--;
            } else {
                pedras[i].ativa = 0; // Pedra sai da tela
            }
        }
    }
}

void main(void) {
    TRISAbits.TRISA4 = 1; // Configura o pino 4 da porta A como entrada
    TRISCbits.TRISC0 = 1; // Configura o pino 0 da porta C como entrada
    TRISB = 0xF0;  // 0b11110000: RB4-RB7 como entradas, RB0-RB3 como saídas
    PORTB = 0x00;  // Limpa todas as saídas
    TRISD = 0x00;  // Pinos de dados do LCD
    TRISE = 0x00;  // Pinos de controle do LCD
    ADCON1 = 0x0F; // Desabilita todos os canais A/D
    lcd_init();
    lcd_cmd(L_NCR);
    lcd_cmd(L_CLR);
    
    special_char(64, pato);
    special_char(72, pedra);

    // Inicializa as pedras
    Pedra pedras[MAX_PEDRAS];
    init_pedras(pedras, MAX_PEDRAS);
    
    // Variável para contar o tempo entre lançamentos de pedras
    int launch_counter = 0;
    
    while (1) {
        lcd_cmd(L_CLR);

        // Exibe o personagem fixo na coluna 10
        print_special_character(64, lcd_pos(10, character_line));

        // Move e exibe as pedras
        move_pedras(pedras, MAX_PEDRAS);
        for (int i = 0; i < MAX_PEDRAS; i++) {
            if (pedras[i].ativa) {
                print_special_character(72, lcd_pos(pedras[i].coluna, pedras[i].linha));
            }
        }

        // Lança uma nova pedra a cada segundo
        if (launch_counter >= 3) { // Aproximadamente 1 segundo (300ms * 3)
            launch_pedra(pedras, MAX_PEDRAS);
            launch_counter = 0;
        }
        launch_counter++;

        // Verifica entrada do usuário para mover o personagem
        char tecla_atual = trata_teclas();
        if (tecla_atual != ' ') {
            switch (tecla_atual) {
                case 'A': // Botão A
                    if (character_line > 1) {
                        character_line--; // Move para cima
                    }
                    break;
                case 'B': // Botão B
                    if (character_line < 4) {
                        character_line++; // Move para baixo
                    }
                    break;
                default:  
                    break;
            }
        }

        // Verifica colisões
        for (int i = 0; i < MAX_PEDRAS; i++) {
            if (pedras[i].ativa && pedras[i].linha == character_line && pedras[i].coluna == 10) {
                lcd_cmd(L_CLR);
                lcd_str("Game Over!");
                while (1);
            }
        }

        __delay_ms(1000);
    }
}
