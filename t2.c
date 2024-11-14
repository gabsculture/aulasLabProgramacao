/******************************************************************************
1. Faça uma função que recebe um tabuleiro contendo rainhas e retorna true se o tabuleiro
contiver uma configuração n-rainhas, conforme descrito no final da aula 15. A função deve
suportar tabuleiro de qualquer tamanho, diferente do que está descrito na aula 15.
Para isso, recebe 2 argumentos: um inteiro com o tamanho do tabuleiro e um vetor
de char que codifica o tabuleiro.
2. Faça uma função para desenhar o tabuleiro. A função deve receber o tamanho do tabuleiro
e o vetor de char que o codifica. Use as funções abaixo, que permitem posicionar o
cursor e alterar a cor do que será escrito na tela.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "terminal.h"

void desenha_tela(int l_alvo, int c_alvo, int l_cursor, int c_cursor)
{
    t_cor_normal();
    t_limpa();
    // desenha o cursor
    t_cor_letra(20, 150, 80);
    t_lincol(l_cursor - 1, c_cursor);
    putchar('|');
    t_lincol(l_cursor + 1, c_cursor);
    putchar('|');
    t_lincol(l_cursor, c_cursor - 2);
    puts("-- --");
    // desenha o alvo
    t_cor_letra(200, 20, 20);
    t_lincol(l_alvo, c_alvo);
    putchar('+');

    t_atualiza();
}


bool verificaLinhas(int tamanhoTabuleiro, int numero, char tabuleiro[]) {
    int numeroRainhas;
    for (int i = 0; i < tamanhoTabuleiro; i += numero) {
        numeroRainhas = 0;
        for (int j = i; j < i + numero; j++) {
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

bool verificaColunas(int tamanhoTabuleiro, int numero, char tabuleiro[]) {
    int numeroRainhas;
    for (int coluna = 0; coluna < numero; coluna++) {
        numeroRainhas = 0;
        for (int j = 0; j < tamanhoTabuleiro; j += numero) {
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

bool verificaDiagonal(int tamanhoTabuleiro, int numero, char tabuleiro[]) {
    int numeroRainhas;
    for(int i = 0; i < tamanhoTabuleiro; i++) {
        numeroRainhas = 0;
        for(int posicaoInicial = i; posicaoInicial < tamanhoTabuleiro; posicaoInicial += numero + 1) {
            if(tabuleiro[posicaoInicial] == 'x') {
                numeroRainhas++;
            }
        }
        if (numeroRainhas > 1) {
            return false;
        }
    }

    for(int j = 0; j < tamanhoTabuleiro; j += numero) {
        numeroRainhas = 0;
        for(int posicaoInicial = j; posicaoInicial < tamanhoTabuleiro; tamanhoTabuleiro += numero - 1) {
            if (tabuleiro[posicaoInicial] == 'x') {
                numeroRainhas++;
            }
            if (numeroRainhas > 1) {
                return false;
            }
        }
        return true;
    }
}

bool verificaTabuleiro(int numero, int tamanhoTabuleiro, char tabuleiro[]) {
    return verificaLinhas(tamanhoTabuleiro, numero, tabuleiro) &&
           verificaColunas(tamanhoTabuleiro, numero, tabuleiro) &&
               verificaDiagonal(tamanhoTabuleiro, numero, tabuleiro);
}

void recebePosicoes(int tamanhoTabuleiro, char tabuleiro[]) {
    printf("Insira as posicoes do tabuleiro, sendo que x sao as rainhas e . os espacos vazios: \n");
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        char caractere;
        scanf(" %c", &caractere);
        while (caractere != 'x' && caractere != '.') {
            printf("Caractere invalido, insira novamente: \n");
            scanf(" %c", &caractere);
        }
        tabuleiro[i] = caractere;
    }

}

int recebeNumeroRainhas() {
    printf("Insira o número de rainhas:");
    int numeroRainhas;
    scanf("%d", &numeroRainhas);
    return numeroRainhas;
}

int main() {
    t_inicializa();
    int numeroRainhas = recebeNumeroRainhas();
    int tamanhoTabuleiro = numeroRainhas * numeroRainhas;
    char tabuleiro[tamanhoTabuleiro];

    recebePosicoes(tamanhoTabuleiro, tabuleiro);
    if(verificaTabuleiro(numeroRainhas, tamanhoTabuleiro, tabuleiro)) {
        printf("deu certo");
    } else {
        printf("nao deu certo");
    }

    t_finaliza();
}
