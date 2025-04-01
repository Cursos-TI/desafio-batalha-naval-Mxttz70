#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define WATER 0
#define SHIP 3
#define SKILL_SIZE 5

void initializeBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = WATER;
        }
    }
}

int canPlaceHorizontal(int board[SIZE][SIZE], int row, int col, int length) {
    if (col + length > SIZE) return 0; // Verifica se cabe na linha
    for (int j = col; j < col + length; j++) {
        if (board[row][j] != WATER) return 0; // Verifica se já está ocupado
    }
    return 1;
}

int canPlaceVertical(int board[SIZE][SIZE], int row, int col, int length) {
    if (row + length > SIZE) return 0; // Verifica se cabe na coluna
    for (int i = row; i < row + length; i++) {
        if (board[i][col] != WATER) return 0; // Verifica se já está ocupado
    }
    return 1;
}

int canPlaceDiagonal(int board[SIZE][SIZE], int startRow, int startCol, int length, int direction) {
    for (int i = 0; i < length; i++) {
        int row = startRow + (direction == 1 ? i : -i);
        int col = startCol + i;
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != WATER) {
            return 0; // Verifica se está fora dos limites ou já ocupado
        }
    }
    return 1;
}

void placeHorizontal(int board[SIZE][SIZE], int row, int col, int length) {
    for (int j = col; j < col + length; j++) {
        board[row][j] = SHIP;
    }
}

void placeVertical(int board[SIZE][SIZE], int row, int col, int length) {
    for (int i = row; i < row + length; i++) {
        board[i][col] = SHIP;
    }
}

void placeDiagonal(int board[SIZE][SIZE], int startRow, int startCol, int length, int direction) {
    for (int i = 0; i < length; i++) {
        int row = startRow + (direction == 1 ? i : -i);
        int col = startCol + i;
        board[row][col] = SHIP;
    }
}

void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void createCone(int cone[SKILL_SIZE][SKILL_SIZE]) {
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            if (j >= (SKILL_SIZE - 1) / 2 - i && j <= (SKILL_SIZE - 1) / 2 + i) {
                cone[i][j] = 1; // Área afetada
            } else {
                cone[i][j] = 0; // Área não afetada
            }
        }
    }
}

void createCross(int cross[SKILL_SIZE][SKILL_SIZE]) {
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            if (i == (SKILL_SIZE - 1) / 2 || j == (SKILL_SIZE - 1) / 2) {
                cross[i][j] = 1; // Área afetada
            } else {
                cross[i][j] = 0; // Área não afetada
            }
        }
    }
}

void createOctahedron(int octahedron[SKILL_SIZE][SKILL_SIZE]) {
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0 ; j < SKILL_SIZE; j++) {
            if (i + j >= (SKILL_SIZE - 1) / 2 && i + (SKILL_SIZE - 1 - j) >= (SKILL_SIZE - 1) / 2 &&
                (SKILL_SIZE - 1 - i) + j >= (SKILL_SIZE - 1) / 2 && (SKILL_SIZE - 1 - i) + (SKILL_SIZE - 1 - j) >= (SKILL_SIZE - 1) / 2) {
                octahedron[i][j] = 1; // Área afetada
            } else {
                octahedron[i][j] = 0; // Área não afetada
            }
        }
    }
}

int main() {
    int board[SIZE][SIZE];
    initializeBoard(board);

    srand(time(NULL));

    // Posicionar 2 navios horizontalmente
    for (int i = 0; i < 2; i++) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        int length = 1; // Tamanho do navio (1 posição)
        if (canPlaceHorizontal(board, row, col, length)) {
            placeHorizontal(board, row, col, length);
        } else {
            i--; // Tentar novamente
        }
    }

    // Posicionar 2 navios verticalmente
    for (int i = 0; i < 2; i++) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        int length = 1; // Tamanho do navio (1 posição)
        if (canPlaceVertical(board, row, col, length)) {
            placeVertical(board, row, col, length);
        } else {
            i--; // Tentar novamente
        }
    }

    // Posicionar 2 navios diagonalmente
    for (int i = 0; i < 2; i++) {
        int startRow = rand() % SIZE;
        int startCol = rand() % SIZE;
        int length = 1; // Tamanho do navio (1 posição)
        int direction = (rand() % 2) ? 1 : -1; // Direção da diagonal (1 para baixo e -1 para cima)
        if (canPlaceDiagonal(board, startRow, startCol, length, direction)) {
            placeDiagonal(board, startRow, startCol, length, direction);
        } else {
            i--; // Tentar novamente
        }
    }

    printBoard(board);

    // Criar matrizes de habilidade
    int cone[SKILL_SIZE][SKILL_SIZE];
    int cross[SKILL_SIZE][SKILL_SIZE];
    int octahedron[SKILL_SIZE][SKILL_SIZE];

    createCone(cone);
    createCross(cross);
    createOctahedron(octahedron);

    // Imprimir matrizes de habilidade
    printf("\nCone:\n");
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }

    printf("\nCruz:\n");
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            printf("%d ", cross[i][j]);
        }
        printf("\n");
    }

    printf("\nOctaedro:\n");
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            printf("%d ", octahedron[i][j]);
        }
        printf("\n");
    }

    return 0;
}