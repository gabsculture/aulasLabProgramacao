////*****Faça um programa semelhante ao anterior, para um carro elétrico, em que pergunta o valor do kWh, 
//a capacidade da bateria em kWh, a autonomia do 
///veículo em km com bateria cheia e a distância a percorrer em km****////


#include <stdio.h>

float kwh, capBateria, aut, dist;
float custoReais() {
	custo= kwh * ;
	return custo;
}
int main()
{
    
	printf("insira o valor do kWh do seu carro:");
	scanf("%f", &kwh);
	printf("insira a capacidade da bateria em kWh:");
	scanf("%f", &capBateria);
	printf("insira a autonomia do veículo em km com bateria cheia:");
	scanf("%f", &aut);
	printf("insira a distância a percorrer em km:");
	scanf("%f", &dist);

	///***falta o calculo!!!!!!!!!!**///////
	
	custo= custoReais();
	printf("custo:%.2f", custo);


	return 0;
}
