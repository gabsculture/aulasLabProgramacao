//t1 l124b gabriela vitoria da rosa soares

#include <stdio.h>
#include <stdlib.h>

//Função que recebe a quantidade de caracteres para desenhar e qual o caractere
void imprimeCaracteres(int quantidade, char caractere) {
    for(int i = 0; i < quantidade; i++) {
        printf("%c", caractere);
    }
}

//Função que retorna a figura A: aumenta um caractere por linha
void imprimeFiguraA(char caractere, int altura) {
    for(int linha = 0; linha < altura; linha++) {
        int numeroCaracteres = linha + 1;
        imprimeCaracteres(numeroCaracteres, caractere);
    }
}

//Função que retorna a figura B: diminui um caractere por linha
void imprimeFiguraB(char caractere, int altura) {
    for(int linha = altura; linha = 1; linha--) {
        int numeroCaracteres = linha - 1;
        imprimeCaracteres(numeroCaracteres, caractere);
    }
}

//Função que retorna a figura C: aumenta um espaço e um caractere por linha
void imprimeFiguraC(char caractere, int altura) {
    for(int linha = 0; linha < altura; linha++) {
        int numeroCaracteres = linha + 1;
        int numeroEspacos = altura - numeroCaracteres;
        imprimeCaracteres(numeroEspacos, ' ');
        imprimeCaracteres(numeroCaracteres, caractere);
        }
}

//Função que retorna a figura D: diminui um caractere e aumenta um espaço por linha
void imprimeFiguraD(char caractere, int altura) {
    for(int linha = altura; linha = 1; linha--) {
        int numeroCaracteres = linha - 1;
        in numeroEspacos = altura - (numeroCaracteres + 1);
        imprimeCaracteres(numeroEspacos, ' ');
        imprimeCaracteres(numeroCaracteres, caractere);
    }
}

void imprimeFiguraE(char caractere, int altura) {
    
}

void imprimeFiguraG(char caractere, int altura) {
    
}

void imprimeFiguraH(char caractere, int altura) {
    
}

int main() {
    char opcaoFigura;
    char caractereDesenho;
    int quantidadeCaracteres;
    
    printf("Olá, usuário! Bem-vindo ao sistema de desenho de figuras!\n");
    printf("Por favor, selecione uma opção de figura para ser desenhada: \n");
    printf("A) \n B) \n C) \n D) \n E) \n F) \n G) \n H) \n Z) Encerra o programa");
    scanf("%c", &opcaoFigura);
    
    switch(opcaoFigura) {
        case 'a':
            printf("Escolha um caractere para desenhar a figura:");
            scanf("%c", &caractereDesenho);
            printf("Escolha a quantidade de caracteres para desenhar:")
            scanf("%d", &quantidadeCaracteres)
            imprimeFiguraA(caractereDesenho, quantidadeCaracteres);
            break;
        
        case 'b':
        
        case 'c':
            printf("Escolha um caractere para desenhar a figura:");
            scanf("%c", &caractereDesenho);
            printf("Escolha a quantidade de caracteres para desenhar:")
            scanf("%d", &quantidadeCaracteres)
            imprimeFiguraC(caractereDesenho, quantidadeCaracteres);
            break;
        
        case 'd':
        
        case 'e':
        
        case 'f':
        
        case 'g':
        
        case 'h':
        
        case 'z':
            exit();
    }
}
