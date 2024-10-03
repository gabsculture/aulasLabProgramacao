/******************************************************************************
Faça um programa que lê o preço de um litro de combustível, o consumo do veículo em km/l e a distância a percorrer,
e calcula e imprime o custo em reais do combustível para percorrer essa distância. Use variáveis float;
imprima o valor em reais com 2 casas, para representar os centavos. Informe ao usuário o que é o valor que se espera que ele digite a cada vez 
(para não ficar só a tela preta e o usuário tendo que conhecer a ordem em que os dados devem ser digitados).

*******************************************************************************/



#include <stdio.h>

float preco, dist, consumoL, custo;

float custoReais() {
	custo= preco * dist * consumoL;
	return custo;
}
int main()
{
    
	printf("insira o preço de um litro do combustivel desejado:");
	scanf("%f", &preco);
	printf("insira o consumo do veiculo em km/l:");
	scanf("%f", &consumoL);
	printf("insira a distancia em km:");
	scanf("%f", &dist);
	
	
	custo= custoReais();
	printf("custo:%.2f", custo);


	return 0;
}

