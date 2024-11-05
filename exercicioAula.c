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

bool verificaLinhas(char tabuleiro[]) {
    int numeroRainhas;
    for (int i = 0; i < 16; i += 4) {
        numeroRainhas = 0;
        for (int j = i; j < i + 4; j++) {
            if (tabuleiro[j] == 'x') {
                numeroRainhas++;
            }
        }
        if (numeroRainhas > 1) {
            return false;
        }
    }
    return true;
}

bool verificaColunas(char tabuleiro[]) {
    int numeroRainhas;
    for (int coluna = 0; coluna < 4; coluna++) {
        numeroRainhas = 0;
        for (int j = 0; j < 16; j += 4) {
            if (tabuleiro[j] == 'x') {
                numeroRainhas++;
            }
        }
        if (numeroRainhas > 1) {
            return false;
        }
    }
    return true;
}

bool verificaDiagonalEsquerda(char tabuleiro[]) {
    int numeroRainhas;
    int inicioDiagonais[4] = {0, 1, 2, 4};
    int comprimentoDiagonais[4] = {4, 3, 2, 2};

    for (int diagonal = 0; diagonal < 4; diagonal++) {
        numeroRainhas = 0;
        for (int i = 0; i < comprimentoDiagonais[diagonal]; i++) {
            int limiteTabuleiro = inicioDiagonais[diagonal] + (i * 5);
            if (limiteTabuleiro < 16 && tabuleiro[limiteTabuleiro] == 'x') {
                numeroRainhas++;
            }
        }

        if (numeroRainhas > 1) {
            return false;
        }
    }
    return true;
}

bool verificaDiagonalDireita(char tabuleiro[]) {
    int numeroRainhas; 
    int inicioDiagonais[4] = {3, 2, 1, 0};
    int comprimentoDiagonais[4] = {4, 3, 3, 2};

    for (int diagonal = 0; diagonal < 4; diagonal++) {
        numeroRainhas = 0;
        for (int i = 0; i < comprimentoDiagonais[diagonal]; i++) {
            int limiteTabuleiro = inicioDiagonais[diagonal] + (i * 4);
            if (limiteTabuleiro < 16 && tabuleiro[limiteTabuleiro] == 'x') {
                numeroRainhas++;
            }
        }
        if (numeroRainhas > 1) {
            return false;
        }
    }
    return true;
}

bool verificaTabuleiro(char tabuleiro[]) {
    return verificaLinhas(tabuleiro), verificaColunas(tabuleiro), verificaDiagonalEsquerda(tabuleiro),
           verificaDiagonalDireita(tabuleiro);
}

void recebePosicoes(char tabuleiro[]) {
    for (int i = 0; i < 16; i++) {
        char caractere;
        scanf(" %c", &caractere);
        while (caractere != 'x' && caractere != '.') {
            printf("Caractere invalido, insira novamente: \n");
            scanf(" %c", &caractere);
        }
        tabuleiro[i] = caractere;
    }
}


int main() {
    char tabuleiro[16];
    printf("Insira as posicoes do tabuleiro, sendo que x sao as rainhas e . os espacos vazios: \n");
    recebePosicoes(tabuleiro);

    if (verificaTabuleiro(tabuleiro)) {
        printf("As posicoes das rainhas no tabuleiro sao validas!\n");
    } else {
        printf("As posicoes das rainhas sao invalida, verifique e tente novamente");
    }
    return 0;
}
