#include <stdio.h>

int leConverteValor() {
    int valor;
    int codigo;
    int unidade, dezena, centena;

    centena = getchar() - '0';
    dezena = getchar() - '0';
    unidade = getchar() - '0';
    getchar();

    valor = centena * 100 + dezena * 10 + unidade;

    return valor;
}

void imprimeValorBinario(int valor) {
    int centena, dezena, unidade;
    int codigo;

    centena = valor / 4 % 2;
    dezena = valor / 2 % 2;
    unidade = valor % 2;

    codigo = centena + '0';
    putchar(codigo);
    codigo = dezena + '0';
    putchar(codigo);
    codigo = unidade + '0';
    putchar(codigo);

}

void imprimeValorDecimal(int valor) {
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


int main() {
    int valor1 = leConverteValor();
    imprimeValorDecimal(valor1);
    imprimeValorBinario(valor1);
}
