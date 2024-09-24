#include <stdio.h>

int leConverteValor() {
    int numero = getchar() - '0';
    return numero;
}

int calculaDobro(int numero) {
    int dobro = (numero * 2);

    return dobro;
}

int calculaQuadrado(int numero) {
    int quadrado = numero * numero;
    return quadrado;
}

void imprimeNumero(int numero) {
    int centena, dezena, unidade;
    int codigo;
    
    centena = numero / 100 % 10;
    dezena = numero / 10 % 10;
    unidade = numero % 10;
    
    codigo = centena + '0';
    putchar(codigo);
    codigo = dezena + '0';
    putchar(codigo);
    codigo = unidade + '0';
    putchar(codigo);

}

int main() {
    int numero = leConverteValor();

    int dobro = calculaDobro(numero);
    imprimeNumero(dobro);
    putchar('\n');

    int quadrado = calculaQuadrado(numero);
    imprimeNumero(quadrado);
    putchar('\n');

}
