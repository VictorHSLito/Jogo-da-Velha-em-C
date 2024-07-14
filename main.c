#include <stdio.h>



struct tabuleiro {
    char matriz[3][3];
};


void inicia_tabuleiro (struct tabuleiro *tabuleiro) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro->matriz[i][j] = ' ';
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c |", tabuleiro->matriz[i][j]);
        }
    printf("\n");
    }

}

int main () {
    struct tabuleiro t;
    
    inicia_tabuleiro(&t);
}