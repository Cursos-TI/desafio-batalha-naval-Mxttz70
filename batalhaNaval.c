#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializar_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // Inicializa todas as posições com 0 (água)
        }
    }
}

// Função para posicionar um navio horizontalmente
void posicionar_navio_horizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3; // Posiciona o navio horizontalmente
    }
}

// Função para posicionar um navio verticalmente
void posicionar_navio_vertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; // Posiciona o navio verticalmente
    }
}

// Função para exibir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe cada posição do tabuleiro
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro
    inicializar_tabuleiro(tabuleiro);

    // Posiciona os navios
    // Navio horizontal na linha 2, coluna 3
    posicionar_navio_horizontal(tabuleiro, 2, 3);
    // Navio vertical na linha 5, coluna 6
    posicionar_navio_vertical(tabuleiro, 5, 6);

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    exibir_tabuleiro(tabuleiro);

    return 0;
}