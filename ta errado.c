#include <stdio.h>
#include <stdbool.h>

bool verificaNumeroGago(int primeiraMetade, int segundaMetade) {
	if (primeiraMetade != segundaMetade) {
		return false;
	}
	return true;
}

int main() {
	int primeiraMetade, segundaMetade;
	scanf("%d %d", &primeiraMetade, &segundaMetade);

	if(verificaNumeroGago(primeiraMetade, segundaMetade)) {
		printf("O número %d%d é gago", primeiraMetade, segundaMetade);
	}
}
