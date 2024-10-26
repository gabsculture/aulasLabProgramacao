//t1 l124b gabriela vitoria da rosa soares

#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>

//Função que recebe a quantidade de caracteres para desenhar e qual o caractere
void imprimeCaracteres(int quantidade, char caractere) {
    for (int i = 0; i < quantidade; i++) {
        printf("%c", caractere);
    }
    // if (caractere != ' ') {
    // printf("\n");
    // }
}

//Função que retorna a figura A: aumenta um caractere por linha
void imprimeFiguraA(char caractere, int altura) {
    for (int linha = 0; linha < altura; linha++) {
        int numeroCaracteres = linha + 1;
        imprimeCaracteres(numeroCaracteres, caractere);
    }
}

//Função que retorna a figura B: diminui um caractere por linha
void imprimeFiguraB(char caractere, int altura) {
    for (int linha = altura; linha >= 0; linha--) {
        int numeroCaracteres = linha - 1;
        imprimeCaracteres(numeroCaracteres, caractere);
    }
}

//Função que retorna a figura C: aumenta um espaço e um caractere por linha
void imprimeFiguraC(char caractere, int altura) {
    for (int linha = 0; linha < altura; linha++) {
        int numeroCaracteres = linha + 1;
        int numeroEspacos = altura - numeroCaracteres;
        imprimeCaracteres(numeroEspacos, ' ');
        imprimeCaracteres(numeroCaracteres, caractere);
    }
}

//Função que retorna a figura D: diminui um caractere e aumenta um espaço por linha
void imprimeFiguraD(char caractere, int altura) {
    for (int linha = altura; linha >= 1; linha--) {
        int numeroCaracteres = linha - 1;
        int numeroEspacos = altura - (numeroCaracteres + 1);
        imprimeCaracteres(numeroEspacos, ' ');
        imprimeCaracteres(numeroCaracteres, caractere);
    }
}

//Função que retorna a figura E: diminui um espaço e aumenta dois caracteres por linha
void imprimeFiguraE(char caractere, int altura) {
    for (int linha = 0; linha < altura; linha++) {
        int numeroEspacos = altura - linha - 1;
        int numeroCaracteres = 2 * linha + 1;
        imprimeCaracteres(numeroEspacos, ' ');
        imprimeCaracteres(numeroCaracteres, caractere);
    }
}

void imprimeFiguraF(char caractere, int altura) {
    for (int linha = 0; linha < altura; linha++) {
        int numeroEspacos = altura - linha - 1;
        int numeroCaracteres = 2 * linha + 1;
        imprimeCaracteres(numeroEspacos, ' ');
        imprimeCaracteres(numeroCaracteres, caractere);
    }
    for (int linha = altura - 2; linha >= 0; linha--) {
        int numeroEspacos = altura - linha - 1;
        int numeroCaracteres = 2 * linha + 1;
        imprimeCaracteres(numeroEspacos, ' ');
        imprimeCaracteres(numeroCaracteres, caractere);
    }
}

//"g": parecido, mas para uma linha de n caracteres é 1 caractere + n-2 espaços + 1 caractere;
void imprimeFiguraG(char caractere, int altura) {
    for (int linha = 0; linha < altura; linha++) {
        int numeroEspacos = altura - linha - 1;
        int numeroCaracteres = 2 * linha + 1;

        if (numeroCaracteres > 1) {
            int numeroEspacosEntreCaracteres = numeroCaracteres - 1;
            imprimeCaracteres(numeroEspacos, ' ');
            printf("%c", caractere);
            imprimeCaracteres(numeroEspacosEntreCaracteres, ' ');
            printf("%c", caractere);
            printf("\n");
        } else {
            imprimeCaracteres(numeroEspacos, ' ');
            imprimeCaracteres(numeroCaracteres, caractere);
        }
    }
    for (int linha = altura - 2; linha >= 0; linha--) {
        int numeroEspacos = altura - linha - 1;
        int numeroCaracteres = 2 * linha + 1;
        if (numeroCaracteres > 1) {
            int numeroEspacosEntreCaracteres = numeroCaracteres - 1;
            imprimeCaracteres(numeroEspacos, ' ');
            printf("%c", caractere);
            imprimeCaracteres(numeroEspacosEntreCaracteres, ' ');
            printf("%c", caractere);
            printf("\n");
        } else {
            imprimeCaracteres(numeroEspacos, ' ');
            imprimeCaracteres(numeroCaracteres, caractere);
        }
    }
}

void imprimeFiguraH(char caractere, int altura) {
    for (int linha = 0; linha <= altura; linha++) {
        int numeroEspacos = 2 * linha + 1;
        int numeroCaracteres = altura * 2;
        if (linha == 0) {
            numeroCaracteres = altura * 2 + 1;
            imprimeCaracteres(numeroCaracteres, caractere);
            printf("\n");
        } else if (numeroEspacos >= 1 && linha != altura - 1) {
            int numeroEspacosEntreCaracteres = altura - linha - 1;
            int numeroCaracteresPorLado = numeroCaracteres / 2;
            if ((numeroCaracteres - 1) % 2 != 0 && linha == altura) {
                numeroEspacosEntreCaracteres = altura - linha + 1;
                imprimeCaracteres(1, caractere);
                imprimeCaracteres(numeroEspacosEntreCaracteres, ' ');
                imprimeCaracteres(numeroCaracteresPorLado, caractere);
                imprimeCaracteres(numeroEspacosEntreCaracteres, ' ');
                imprimeCaracteres(1, caractere);
                printf("\n");
            } else {
                imprimeCaracteres(numeroCaracteresPorLado, caractere);
                imprimeCaracteres(numeroEspacosEntreCaracteres, ' ');
                imprimeCaracteres(numeroCaracteresPorLado, caractere);
                printf("\n");
            }
        } else if ((numeroCaracteres - 1) % 2 != 0) {
            int numeroCaracteresPorLado = (numeroCaracteres - 1) / 2;
            int numeroEspacosEntreCaracteres = altura - linha;
            imprimeCaracteres(numeroCaracteresPorLado, caractere);
            imprimeCaracteres(numeroEspacosEntreCaracteres, ' ');
            imprimeCaracteres(1, caractere);
            imprimeCaracteres(numeroEspacosEntreCaracteres, ' ');
            imprimeCaracteres(numeroCaracteresPorLado, caractere);
            printf("\n");
        } else {
            imprimeCaracteres(numeroEspacos, ' ');
            imprimeCaracteres(numeroCaracteres, caractere);
            printf("\n");
        }
    }
    for (int linha = altura - 2; linha >= 0; linha--) {
        int numeroEspacos = 2 * linha + 1;
        int numeroCaracteres = altura * 2;
        if (linha == 0) {
            numeroCaracteres = altura * 2 + 1;
            imprimeCaracteres(numeroCaracteres, caractere);
            printf("\n");
        } else if (numeroEspacos >= 1 && linha != altura - 1) {
            int numeroEspacosEntreCaracteres = altura - linha - 1;
            int numeroCaracteresPorLado = numeroCaracteres / 2;
            if ((numeroCaracteres - 1) % 2 != 0 && linha == altura) {
                numeroEspacosEntreCaracteres = altura - linha + 1;
                imprimeCaracteres(1, caractere);
                imprimeCaracteres(numeroEspacosEntreCaracteres, ' ');
                imprimeCaracteres(numeroCaracteresPorLado, caractere);
                imprimeCaracteres(numeroEspacosEntreCaracteres, ' ');
                imprimeCaracteres(1, caractere);
                printf("\n");
            } else {
                imprimeCaracteres(numeroCaracteresPorLado, caractere);
                imprimeCaracteres(numeroEspacosEntreCaracteres, ' ');
                imprimeCaracteres(numeroCaracteresPorLado, caractere);
                printf("\n");
            }
        } else if ((numeroCaracteres - 1) % 2 != 0) {
            int numeroCaracteresPorLado = (numeroCaracteres - 1) / 2;
            int numeroEspacosEntreCaracteres = altura - linha;
            imprimeCaracteres(numeroCaracteresPorLado, caractere);
            imprimeCaracteres(numeroEspacosEntreCaracteres, ' ');
            imprimeCaracteres(1, caractere);
            imprimeCaracteres(numeroEspacosEntreCaracteres, ' ');
            imprimeCaracteres(numeroCaracteresPorLado, caractere);
            printf("\n");
        } else {
            imprimeCaracteres(numeroEspacos, ' ');
            imprimeCaracteres(numeroCaracteres, caractere);
            printf("\n");
        }
    }
}

char escolheCaractere() {
    char caractereDesenho;
    printf("Escolha um caractere para desenhar a figura:\n");
    scanf("%c", &caractereDesenho);
    return caractereDesenho;
}

int escolheQuantidadeLinhas() {
    int quantidadeLinhas;
    printf("Escolha a quantidade de linhas para desenhar:\n");
    scanf("%d", &quantidadeLinhas);
    return quantidadeLinhas;
}

int main() {
    char opcaoFigura;
    char caractereDesenho;
    int quantidadeLinhas;

    printf("Ola, usuario! Bem-vindo ao sistema de desenho de figuras!\n");

    printf("Por favor, selecione uma opção de figura para ser desenhada: \n");
    printf(" A) \n B) \n C) \n D) \n E) \n F) \n G) \n H) \n Z) Encerra o programa \n");
    scanf("%c", &opcaoFigura);

    switch (opcaoFigura) {
        case 'a':
            caractereDesenho = escolheCaractere();
            quantidadeLinhas = escolheQuantidadeLinhas();
            imprimeFiguraA(caractereDesenho, quantidadeLinhas);
            break;

        case 'b':
            caractereDesenho = escolheCaractere();
            quantidadeLinhas = escolheQuantidadeLinhas();
            imprimeFiguraB(caractereDesenho, quantidadeLinhas);
            break;

        case 'c':
            caractereDesenho = escolheCaractere();
            quantidadeLinhas = escolheQuantidadeLinhas();
            imprimeFiguraC(caractereDesenho, quantidadeLinhas);
            break;

        case 'd':
            caractereDesenho = escolheCaractere();
            quantidadeLinhas = escolheQuantidadeLinhas();
            imprimeFiguraD(caractereDesenho, quantidadeLinhas);
            break;

        case 'e':
            caractereDesenho = escolheCaractere();
            quantidadeLinhas = escolheQuantidadeLinhas();
            imprimeFiguraE(caractereDesenho, quantidadeLinhas);
            break;

        case 'f':
            caractereDesenho = escolheCaractere();
            quantidadeLinhas = escolheQuantidadeLinhas();
            imprimeFiguraF(caractereDesenho, quantidadeLinhas);
            break;

        case 'g':
            caractereDesenho = escolheCaractere();
            quantidadeLinhas = escolheQuantidadeLinhas();
            imprimeFiguraG(caractereDesenho, quantidadeLinhas);
            break;

        case 'h':
            caractereDesenho = escolheCaractere();
            quantidadeLinhas = escolheQuantidadeLinhas();
            imprimeFiguraH(caractereDesenho, quantidadeLinhas);
            break;

        case 'z':
            exit(0);
    }
}
