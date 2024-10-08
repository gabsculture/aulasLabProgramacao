#include <stdio.h>

int leConverteValor() {
    int valor;
    int codigo;
    int unidade, dezena, centena;

    centena = getchar() - '0';
    dezena = getchar() - '0';
    unidade = getchar() - '0';

    valor = centena * 100 + dezena * 10 + unidade;

    return valor;
}

void imprimeValor(int valor) {
    int centena, dezena, unidade;
    int codigo;
    centena = valor / 100 % 10;
    dezena = valor / 10 % 10;
    unidade = valor % 10;
    codigo = centena + '0';
    putchar(codigo);
    codigo = dezena + '0';
    putchar(codigo);
    codigo = unidade + '0';
    putchar(codigo);

}

int calculaMedia (int valor1, int valor2, int valor3) {
    int media = (valor1 + valor2 + valor3)/3;

    return media;
}

int main() {
    int valor1 = leConverteValor();
    int valor2 = leConverteValor();
    int valor3 = leConverteValor();
    imprimeValor(valor1);
    imprimeValor(valor2);
    imprimeValor(valor3);

    int media = calculaMedia(valor1, valor2, valor3);

    imprimeValor(media);
}
