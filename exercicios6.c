#include <stdio.h>

int calculaImc(int altura, int peso) {
  int imc = peso * 10000 / altura * altura;
  return imc;
}

int main() {
  int altura, peso, imc;
  printf("Por favor digite sua altura em m\n");
  scanf("%d", &altura);

  printf("Por favor digite seu peso em kg\n");
  scanf("%d", &peso);

  imc = calculaImc(altura, peso);

  printf("O seu imc é: %d", imc);
}
