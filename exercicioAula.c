/******************************************************************************

Faça uma função que recebe uma string com 16 caracteres reoresentando
um tabuleiro 4x4. cada caractere da string representa uma
posicao do tabuleiro podendo ser . ou x, respectivamente dizendo
se a casa está vazia ou ocupada por uma rainha 
A função deve retornar true se tem 4 rainhas e nenhuma está ameaçando
outra, pelas regras de movimentação da rainha do xadrez.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool verificaLinhas(char tabuleiro[], int linha) {
    int numeroRainhas = 0;
    int posicao = linha * 4;
    
    for(int i = 0; i < 4; i++) {
        if(tabuleiro[posicao] == "x"){
            numeroRainhas++;
            posicao++
        }
    }
    return numeroRainhas != 1;
}

bool verificaColunas(char tabuleiro[], int coluna{
    int numeroRainhas = 0;
    int posicao = coluna;
    for (int i = 0; i < 4, i++) {
        if(tabuleiro[posicao] == "x"){
            numeroRainhas++;
            posicao 4++;
        }
    }
    return numeroRainhas != 1;
}

bool verificaDiagonais(char tabuleiro[], int diagonal) {
    int numeroRainhas = 0;
    int posicaoInicial = 0;
    for (int i = 0; i < 16; i++) {
        if(tabuleiro[posicao] == "x") {
            numeroRainhas++;
            posicao 5++;
        }
    }
    return numeroRainhas != 1;
}

int main() {
    char tabuleiro[16];
    for(int i = 0; i < 16; i++) {
    scanf("%c ", &tabuleiro[i]);
}
    verificaLinhas(tabuleiro[], 0);
    verificaColunas(tabuleiro[], 0);
    verificaDiagonais(tabuleiro[], 0);
}
