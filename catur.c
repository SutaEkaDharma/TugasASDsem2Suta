#include <stdio.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    // Menginisialisasi semua elemen array dengan nilai 0
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            *(chessBoard + x * size + y) = 0;
        }
    }

    // Menghitung kemungkinan posisi yang dapat dilalui oleh bidak kuda
    int moves[8][2] = { {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2} };
    for (int k = 0; k < 8; k++) {
        int newX = i + moves[k][0];
        int newY = j + moves[k][1];
        if (newX >= 0 && newX < size && newY >= 0 && newY < size) {
            *(chessBoard + newX * size + newY) = 1;
        }
    }

    // Menampilkan output array
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            printf("%d ", *(chessBoard + x * size + y));
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    scanf("%d %d", &i, &j);
    int chessBoard[8][8];
    koboImaginaryChess(i, j, 8, (int *)chessBoard);
    return 0;
}
