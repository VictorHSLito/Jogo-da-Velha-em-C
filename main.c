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

void registra_jogadores (struct jogadores *p) {
    p[0].simbolo = 'X';
    p[1].simbolo = 'O';

    for (int i = 0; i < 2; i++) {
        printf("Digite o nome do %dº jogador: ", i+1);
        scanf(" %s", p[i].nome);
    }

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

void registra_jogada (struct tabuleiro *t, struct jogadores *p, int turno) {
    int i, j;

    printf("%s, selecione uma linha e uma coluna para sua jogada [linha coluna]: ", p[turno].nome);
    scanf("%d %d", &i, &j);

    if (t->matriz[i][j] != ' ') {
        printf("Posicao invalida, tente novamente!\n");
        registra_jogada(t, p, turno);
    }
    else {
        t->matriz[i][j] = p[turno].simbolo;
    }
}

int main () {
    int turno = 0;
    struct tabuleiro t;
    struct jogadores player[2];
    
    inicia_tabuleiro(&t);
    registra_jogadores(player);

    for (int i = 0; i < 9; i++) {
    registra_jogada(&t, player, turno);
    mostra_tabuleiro(&t);
    turno = (turno + 1) % 2;
    }

}