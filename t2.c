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

bool verificaDiagonalEsquerda(int tamanhoTabuleiro, int numero, char tabuleiro[]) {
    int numeroRainhas;
    int inicioDiagonais[numero];
    int comprimentoDiagonais[numero];

    for (int diagonal = 0; diagonal < numero; diagonal++) {
        numeroRainhas = 0;
        for (int i = 0; i < comprimentoDiagonais[diagonal]; i++) {
            int limiteTabuleiro = inicioDiagonais[diagonal] + (i * (numero+1));
            if (limiteTabuleiro < tamanhoTabuleiro && tabuleiro[limiteTabuleiro] == 'x') {
                numeroRainhas++;
            }
        }

        if (numeroRainhas > 1) {
            return false;
        }
    }
    return true;
}

bool verificaDiagonalDireita(int tamanhoTabuleiro, int numero, char tabuleiro[]) {
    int numeroRainhas; 
    int inicioDiagonais[numero];
    int comprimentoDiagonais[numero];

    for (int diagonal = 0; diagonal < numero; diagonal++) {
        numeroRainhas = 0;
        for (int i = 0; i < comprimentoDiagonais[diagonal]; i++) {
            int limiteTabuleiro = inicioDiagonais[diagonal] + (i * numero);
            if (limiteTabuleiro < tamanhoTabuleiro && tabuleiro[limiteTabuleiro] == 'x') {
                numeroRainhas++;
            }
        }
        if (numeroRainhas > 1) {
            return false;
        }
    }
    return true;
}

bool verificaTabuleiro(int numero, int tamanhoTabuleiro, char tabuleiro[]) {
    return verificaLinhas(tamanhoTabuleiro, numero, tabuleiro), verificaColunas(tamanhoTabuleiro, numero, tabuleiro), verificaDiagonalEsquerda(tamanhoTabuleiro, numero, tabuleiro),  verificaDiagonalDireita(tamanhoTabuleiro, numero, tabuleiro);
}

void recebePosicoes(int tamanhoTabuleiro, char tabuleiro[]) {
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
    int numeroRainhas;
    scanf("%d", &numeroRainhas);
    return numeroRainhas;
}

int main() {
    int numeroRainhas = recebeNumeroRainhas();
    int tamanhoTabuleiro = numeroRainhas * numeroRainhas;
    char tabuleiro[tamanhoTabuleiro];
    
    printf("Insira as posicoes do tabuleiro, sendo que x sao as rainhas e . os espacos vazios: \n");
    recebePosicoes(tamanhoTabuleiro, tabuleiro);
    printf("pq nao chega aq veinho");
    if (verificaTabuleiro(numeroRainhas, tamanhoTabuleiro, tabuleiro)) {
        printf("As posicoes das rainhas no tabuleiro sao validas!\n");
    } else {
        printf("As posicoes das rainhas sao invalida, verifique e tente novamente");
    }
    return 0;
}
//.X.....XX.....X.
//.X....X..X....X.
//.X..X.X........X
