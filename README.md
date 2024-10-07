# PATO RUN - Jogo de Corrida no LCD

**PATO RUN** é um jogo acadêmico inspirado no jogo do dinossauro do Chrome, desenvolvido para microcontroladores PIC. O jogo utiliza um display LCD para exibir o personagem (pato) e os obstáculos (pedras), onde o objetivo é evitar as pedras por meio do controle do personagem nas diferentes linhas do display. Caso o pato colida com uma pedra, o jogo termina com a mensagem "Game Over".

## Requisitos
- Microcontrolador PIC18F4550
- Display LCD compatível com o driver `lcd.h`
- Biblioteca `xc.h` para microcontroladores PIC
- Teclado matricial 4x4 para controle de entrada

## Componentes do Projeto

### Arquivos Incluídos
- **config_4550.h**: Configuração inicial para o microcontrolador PIC18F4550.
- **atraso.h**: Funções de atraso para temporizações no microcontrolador.
- **lcd.h**: Funções para controle do display LCD.
- **16Keys.h**: Funções para leitura do teclado matricial 4x4.

### Principais Funções
- **special_char()**: Criação e armazenamento de caracteres especiais no LCD (como o pato e as pedras).
- **print_special_character()**: Exibição de caracteres especiais em uma posição específica do LCD.
- **lcd_pos()**: Cálculo da posição no LCD com base em coordenadas de linha e coluna.
- **get_random_line()**: Gera uma linha aleatória para o aparecimento das pedras no LCD.
- **init_pedras()**: Inicializa as posições e o estado das pedras (obstáculos) no jogo.
- **launch_pedra()**: Lança uma nova pedra em uma linha aleatória no canto direito do LCD.
- **move_pedras()**: Move as pedras da direita para a esquerda no display.

### Controle do Personagem
O pato (personagem) pode se mover entre as quatro linhas do LCD utilizando as teclas:
- **Tecla 'A'**: Move o pato para cima.
- **Tecla 'B'**: Move o pato para baixo.

### Detecção de Colisões
O jogo detecta colisões entre o pato e as pedras. Se uma pedra atingir a posição do pato, o jogo exibe a mensagem "Game Over!" e termina.

## Como Jogar
1. O personagem começa na linha 3 do display.
2. Use as teclas 'A' e 'B' no teclado matricial para mover o pato para cima e para baixo, respectivamente.
3. Pedras aparecem aleatoriamente e se movem da direita para a esquerda.
4. Evite as pedras! Caso uma pedra colida com o pato, o jogo acaba.

## Fluxo Principal do Jogo
- O jogo inicia com a exibição do pato na linha 3 do LCD.
- Pedras são geradas aleatoriamente e se movem a cada ciclo de 1 segundo.
- O jogador deve mover o pato entre as linhas do LCD para evitar as pedras.
- A cada ciclo de execução, o jogo verifica colisões. Se o pato colidir com uma pedra, o jogo termina.

## Melhorias Futuras
- Adicionar níveis de dificuldade com o aumento da velocidade das pedras.
- Incluir um sistema de pontuação que aumente a cada pedra evitada.

## Licença
Este projeto é destinado ao uso acadêmico e educacional.
