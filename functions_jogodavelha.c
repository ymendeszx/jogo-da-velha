#include <stdio.h>
#include <stdlib.h>

void inicializar_tabuleiro(char tab[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) tab[i][j] = ' ';
}

void exibir_tabuleiro(char tab[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++)
        printf(" | %c | %c | %c |\n", tab[i][0], tab[i][1], tab[i][2]);
    printf("\n");
}

int validar_jogada(char tab[3][3], int l, int c) {
    return (l >= 1 && l <= 3 && c >= 1 && c <= 3 && tab[l-1][c-1] == ' ');
}

void jogada_humana(char tab[3][3], int *l, int *c) {
    do {
        printf("Digite linha e coluna (1-3): ");
        if (scanf("%d %d", l, c) != 2) while (getchar() != '\n');
    } while (!validar_jogada(tab, *l, *c));
}

void jogada_computador(char tab[3][3], int *l, int *c) {
    do {
        *l = (rand() % 3) + 1;
        *c = (rand() % 3) + 1;
    } while (!validar_jogada(tab, *l, *c));
}

int verificar_vencedor(char tab[3][3], char j1, char j2) {
    for (int i = 0; i < 3; i++) {
        if (tab[i][0] != ' ' && tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2]) return (tab[i][0] == j1) ? 1 : 2;
        if (tab[0][i] != ' ' && tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i]) return (tab[0][i] == j1) ? 1 : 2;
    }
    if (tab[0][0] != ' ' && tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]) return (tab[0][0] == j1) ? 1 : 2;
    if (tab[0][2] != ' ' && tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]) return (tab[0][2] == j1) ? 1 : 2;
    return 0;
}

int tabuleiro_cheio(char tab[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) if (tab[i][j] == ' ') return 0;
    return 1;
}
