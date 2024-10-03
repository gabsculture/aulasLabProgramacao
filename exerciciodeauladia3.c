#include <stdio.h>

float precoA, precoG, dist, consumoA, consumoG, custoG, custoA;

float custoReaisG() {
	custoG= precoG * dist * consumoG;
	return custoG;
}
float custoReaisA() {
	custoA= precoA * dist * consumoA;
	return custoA;
}
int main()
{
    
	printf("insira o preço de um litro de gasolina:");
	scanf("%f", &precoG);
	printf("insira o preço de um litro de álcool:");
	scanf("%f", &precoA);
	printf("insira o consumo de gasolina do veiculo em km/l:");
	scanf("%f", &consumoG);
	printf("insira o consumo de álcool do veiculo em km/l:");
	scanf("%f", &consumoA);
	printf("insira a distancia em km:");
	scanf("%f", &dist);
	
	
	custoG= custoReaisG();
	custoA=custoReaisA();
	
if(custoG > custoA){
    printf("Abasteça com álcool!");
}else{
    printf("Abasteça com gasolina!");
}

	return 0;
}
