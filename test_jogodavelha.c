#include <stdio.h>
#include <assert.h>
#include "functions_jogodavelha.c"

void inicializar_tabuleiro(char tab[3][3]);
int validar_jogada(char tab[3][3], int l, int c);
int verificar_vencedor(char tab[3][3], char j1, char j2);
int tabuleiro_cheio(char tab[3][3]);

int main() {
    char t[3][3];
    
    inicializar_tabuleiro(t);
    assert(t[0][0] == ' ');
    
    assert(validar_jogada(t, 1, 1) == 1);
    assert(validar_jogada(t, 4, 1) == 0);
    
    t[0][0] = 'X'; t[0][1] = 'X'; t[0][2] = 'X';
    assert(verificar_vencedor(t, 'X', 'O') == 1);
    
    assert(tabuleiro_cheio(t) == 0);

    printf("Todos os testes passaram com sucesso!\n");
    printf("Feito por Lara Fazani\n");
    return 0;
}
