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

char verifica_vencendor (struct tabuleiro t) {
    int i;

    for (i = 0; i < 3; i++) { // Verifica as linhas
        if (t.matriz[i][0] == t.matriz[i][1] && t.matriz[i][0] == t.matriz[i][2]) {
            return t.matriz[i][0];
        }
    }

    for (i = 0; i < 3; i++) { // Verifica as colunas
        if (t.matriz[0][i] == t.matriz[1][i] && t.matriz[0][i] == t.matriz[2][i]) {
            return t.matriz[0][i];
        }
    }

    if (t.matriz[0][0] == t.matriz[1][1] && t.matriz[1][1] == t.matriz[2][2]) { // Verifica a diagonal principal
        return t.matriz[0][0];
    }

    if (t.matriz[0][2] == t.matriz[1][1] && t.matriz[1][1] == t.matriz[2][0]) { // Verifica a diagonal secundária
        return t.matriz[0][2];
    }

    return ' ';
}

int main () {
    char final = ' ';
    int turno = 0;
    struct tabuleiro t;
    struct jogadores player[2];
    
    inicia_tabuleiro(&t);
    registra_jogadores(player);

    for (int i = 0; i < 9; i++) {
    registra_jogada(&t, player, turno);
    mostra_tabuleiro(&t);
    final = verifica_vencendor(t);
    if (final == 'X' || final == 'O') {
        printf("O jogador %s venceu!!\n", final == 'X' ? player[0].nome : player[1].nome);
        break;
    }
    turno = (turno + 1) % 2;
    }
    
    return 0;
}