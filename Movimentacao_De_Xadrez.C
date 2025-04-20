#include <stdio.h>
#include <string.h>

// 🔁 Protótipos das funções de movimento das peças
void moveTower(int numberMove, char *moverDirectionPart);              // Torre: movimento recursivo em linha reta
void moveBishop(int numberMove, char *moverDirectionPart);            // Bispo: movimento em diagonal
void moveHorse();                                                     // Cavalo: movimento em "L"
void moveQueen(int numberMove);                                       // Rainha: direciona entre movimento diagonal ou linha reta
void moveQueenHorizontalVertical(int numberMove, char *direction);    // Rainha: movimentação horizontal/vertical
void moveQueenDiagonal(int numberMove, char *direction);              // Rainha: movimentação diagonal
void directionHorizontalVertical(char *moverDirectionPart);           // Define direção vertical/horizontal
void directionDiagonal(char *moverDirectionPart);                     // Define direção diagonal
void moveHome(int *moveHomePart);                                     // Pergunta ao usuário o número de casas para movimentar

// 🏰 Torre: movimenta-se em linha reta com recursividade
void moveTower(int numberMove, char *moverDirectionPart) {
    if (numberMove > 0) {
        moveTower(numberMove - 1, moverDirectionPart);
        printf("A torre se movimentou %d casa(s) para a %s.\n", numberMove, moverDirectionPart);
    }
}

// ♝ Bispo: movimenta-se em diagonal usando laço for
void moveBishop(int numberMove, char *moverDirectionPart) {
    for (int i = 1; i <= numberMove; i++) {
        printf("O bispo se movimentou %d casa(s) na direçao %s.\n", i, moverDirectionPart);
    }
}

// ♞ Cavalo: simula movimento em “L” baseado na escolha do usuário
void moveHorse() {
    int opcao;
    int i, j;

    printf("= = = = = = = = = = = = = = = = = = =\n");
    printf("Quantas casas deseja mover o Cavalo?\n");
    printf("[1] Uma casa e em seguida duas | [2] Duas casa e em seguida uma\n");
    printf("-------------------------------------\n");

    printf("Escolha uma opçao: ");
    scanf("%d", &opcao);

    // Execução baseada na escolha
    if (opcao == 1) {
        printf("Movendo o cavalo: 1 casa e 2 casas...\n");
        for (i = 0; i < 1; i++) {
            for (j = 0; j < 2; j++) {
                printf("Movimento %d: Casa %d do cavalo.\n", i+1, j+1);
            }
        }
    } else if (opcao == 2) {
        printf("Movendo o cavalo: 2 casas e 1 casa...\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1; j++) {
                printf("Movimento %d: Casa %d do cavalo.\n", i+1, j+1);
            }
        }
    } else {
        printf("Opçao invalida. Movimento do cavalo cancelado.\n");
    }
}

// 👑 Rainha: movimenta-se em linha reta
void moveQueenHorizontalVertical(int numberMove, char *direction) {
    for (int i = 1; i <= numberMove; i++) {
        printf("A Rainha se movimentou %d casa(s) para a %s.\n", i, direction);
    }
}

// 👑 Rainha: movimenta-se em diagonal
void moveQueenDiagonal(int numberMove, char *direction) {
    for (int i = 1; i <= numberMove; i++) {
        printf("A Rainha se movimentou %d casa(s) na direcao %s.\n", i, direction);
    }
}

// 🔁 Direção para movimentos verticais/horizontais
void directionHorizontalVertical(char *moverDirectionPart) {
    int opcao;
    printf("= = = = = = = = = = = = = = = = = = =\n");
    printf("Qual direcao deseja movimentar? \n");
    printf("1. Cima | 2. Baixo | 3. Esquerda | 4. Direita\n");
    printf("-------------------------------------\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: strcpy(moverDirectionPart, "Cima"); break;
        case 2: strcpy(moverDirectionPart, "Baixo"); break;
        case 3: strcpy(moverDirectionPart, "Esquerda"); break;
        case 4: strcpy(moverDirectionPart, "Direita"); break;
        default: strcpy(moverDirectionPart, "Indefinido"); break;
    }
}

// 🔁 Direção para movimentos diagonais
void directionDiagonal(char *moverDirectionPart) {
    int opcao;
    printf("= = = = = = = = = = = = = = = = = = =\n");
    printf("Qual direçao deseja movimentar? \n");
    printf("1. Diagonal superior esquerda\n2. Diagonal superior direita\n");
    printf("3. Diagonal inferior esquerda\n4. Diagonal inferior direita\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: strcpy(moverDirectionPart, "Diagonal superior esquerda"); break;
        case 2: strcpy(moverDirectionPart, "Diagonal superior direita"); break;
        case 3: strcpy(moverDirectionPart, "Diagonal inferior esquerda"); break;
        case 4: strcpy(moverDirectionPart, "Diagonal inferior direita"); break;
        default: strcpy(moverDirectionPart, "Indefinido"); break;
    }
}

// 📏 Pergunta ao jogador quantas casas deseja mover
void moveHome(int *moveHomePart) {
    printf("= = = = = = = = = = = = = = = = = = =\n");
    printf("Quantas casas deseja movimentar? \n");
    printf("-------------------------------------\n");
    scanf("%d", moveHomePart);
}

// 👑 Chamada principal para movimentação da rainha (decide tipo de movimento)
void moveQueen(int numberMove) {
    int option;
    char direction[50];

    printf("= = = = = = = = = = = = = = = = = = =\n");
    printf("Qual direcao deseja movimentar a Rainha?\n");
    printf("[1] Vertical e horizontal\n[2] Diagonal\n");
    printf("-------------------------------------\n");
    scanf("%d", &option);

    if (option == 1) {
        directionHorizontalVertical(direction);
        moveQueenHorizontalVertical(numberMove, direction);
    } else if (option == 2) {
        directionDiagonal(direction);
        moveQueenDiagonal(numberMove, direction);
    } else {
        printf("Opcao invalida. Movimento cancelado.\n");
    }
}

// 🧩 Função principal: menu de seleção das peças e execução
int main() {
    int responseUser = 0, home = 0;
    char moverDirectionPart[50];

    printf("= = = = = = = = = = = = = = = = = = =\n");
    printf("Qual peea deseja movimentar? \n");
    printf("1. Torre | 2. Bispo | 3. Cavalo | 4. Rainha\n");
    printf("-------------------------------------\n");
    scanf("%d", &responseUser);

    switch (responseUser) {
        case 1: // 🏰 Torre
            directionHorizontalVertical(moverDirectionPart);
            moveHome(&home);
            moveTower(home, moverDirectionPart);
            break;
        case 2: // ♝ Bispo
            directionDiagonal(moverDirectionPart);
            moveHome(&home);
            moveBishop(home, moverDirectionPart);
            break;
        case 3: // ♞ Cavalo
            moveHorse();
            break;
        case 4: // 👑 Rainha
            moveHome(&home);
            moveQueen(home);
            break;
        default:
            printf("Por favor, digite um numero valido entre 1 e 4!\n");
    }

    return 0;
}
