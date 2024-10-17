/*
Imprime os nC:meros de 1 a 8 um por linha, cada um antecedido de tantos espaC'os quanto for o seu
quadrado. Use funC'C5es
*/
#include <stdio.h>
int calcularQuadrado(int valor) {
	return valor * valor;
}
void imprimeEspaco() {
    char espaco = '.' + 0;
    printf("%c", espaco);

}

int main() {
	int contador = 0;

	for (contador = 1; contador <= 8; contador++) {
		int quadradoContador = calcularQuadrado(contador);
		
		for(int i = 0; i < quadradoContador; i++){
		    imprimeEspaco(quadradoContador);
		}
		
		printf("%d\n", contador);

	}
}
