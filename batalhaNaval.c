#include <stdio.h>
#include <stdbool.h>

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

// Função para verificar se o navio pode ser posicionado
bool pode_posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, bool horizontal) {
    if (horizontal) {
        if (coluna + tamanho > TAMANHO_TABULEIRO) return false; // Verifica se o navio sai do tabuleiro
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return false; // Verifica se há sobreposição
        }
    } else {
        if (linha + tamanho > TAMANHO_TABULEIRO) return false; // Verifica se o navio sai do tabuleiro
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return false; // Verifica se há sobreposição
        }
    }
    return true;
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

// Função para posicionar um navio diagonalmente (cima direita ou baixo direita)
void posicionar_navio_diagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, bool descendo) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + (descendo ? i : -i)][coluna + i] = 3; // Posiciona o navio diagonalmente
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
    // Navio horizontal na linha 1, coluna 1
    if (pode_posicionar_navio(tabuleiro, 1, 1, TAMANHO_NAVIO, true)) {
        posicionar_navio_horizontal(tabuleiro, 1, 1);
    }

    // Navio vertical na linha 4, coluna 4
    if (pode_posicionar_navio(tabuleiro, 4, 4, TAMANHO_NAVIO, false)) {
        posicionar_navio_vertical(tabuleiro, 4, 4);
    }

    // Navio diagonal descendo na linha 6, coluna 0
    if (pode_posicionar_navio(tabuleiro, 6, 0, TAMANHO_NAVIO, true)) {
        posicionar_navio_diagonal(tabuleiro, 6, 0, true);
    }

    // Navio diagonal subindo na linha 3, coluna 6
    if(pode_posicionar_navio(tabuleiro, 3, 6, TAMANHO_NAVIO, false)) {
        posicionar_navio_diagonal(tabuleiro, 3, 6, false);
    }

    //Exibir o tabuleiro
    printf("Tabuleiro batalha naval:\n");
    exibir_tabuleiro(tabuleiro);

    return 0;
}