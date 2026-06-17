#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void inicializar_tabuleiro(char tab[3][3]);
void exibir_tabuleiro(char tab[3][3]);
void jogada_humana(char tab[3][3], int *l, int *c);
void jogada_computador(char tab[3][3], int *l, int *c);
int verificar_vencedor(char tab[3][3], char j1, char j2);
int tabuleiro_cheio(char tab[3][3]);

int main(int argc, char *argv[]) {
    srand(time(NULL));
    char t[3][3], j1 = 'X', j2 = 'O';
    int auto_m = 0, turno = 1, venc = 0, l, c;

    if (argc > 1) j1 = argv[1][0];
    else { printf("Escolha X ou O: "); scanf(" %c", &j1); }
    j2 = (j1 == 'X' || j1 == 'x') ? 'O' : 'X';
    if (argc > 2 && strcmp(argv[2], "auto") == 0) auto_m = 1;

    inicializar_tabuleiro(t);

    while (venc == 0 && !tabuleiro_cheio(t)) {
        if (turno == 1) {
            if (auto_m) jogada_computador(t, &l, &c);
            else jogada_humana(t, &l, &c);
            t[l-1][c-1] = j1; turno = 2;
        } else {
            jogada_computador(t, &l, &c);
            t[l-1][c-1] = j2; turno = 1;
        }
        exibir_tabuleiro(t);
        venc = verificar_vencedor(t, j1, j2);
    }

    if (venc != 0) printf("O jogador %d ganhou\n", venc);
    else printf("O jogo terminou sem vencedores\n");

    printf("Feito por Lara Fazani\n");
    return 0;
}
