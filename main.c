#include <stdio.h>


struct tabuleiro {
    char matriz[3][3];
};


struct jogadores {
    char nome[30];
    char simbolo;
};

void inicia_tabuleiro (struct tabuleiro *tabuleiro) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro->matriz[i][j] = ' ';
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j != 2) {
                printf("%c |", tabuleiro->matriz[i][j]); // Correção do tabuleiro
            }
            else {
                printf("%c", tabuleiro->matriz[i][j]);
            }
        }
    printf("\n");
    }

}

void registra_jogadores (struct jogadores *jogadores) {
    printf("Digite o nome do %d° jogador: ", 1);
    scanf(" %s", jogadores[0].nome);
    jogadores[0].simbolo = 'X';
    printf("Agora digite o nome do %d° jogador: ", 2);
    scanf(" %s", jogadores[1].nome);
    jogadores[1].simbolo = 'O';

}


void mostra_tabuleiro (struct tabuleiro *t) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j != 2) {
                printf("%c|", t->matriz[i][j]); 
            }
            else {
                printf("%c", t->matriz[i][j]);
            }
        }
    printf("\n");
    }
}

void registra_jogada (struct tabuleiro *t, struct jogadores *p) {
    int i, j;
    printf("Onde gostaria que fosse sua jogada, jogador %d? ", 1);
    scanf("%d %d", &i, &j);

    t->matriz[i][j] = p[0].simbolo;
}

int main () {
    struct tabuleiro t;
    struct jogadores player[2];
    
    inicia_tabuleiro(&t);
    registra_jogadores(player);
    registra_jogada(&t, player);
    mostra_tabuleiro(&t);
}