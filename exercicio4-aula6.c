////*****Faça um programa que lê a 
///largura, o comprimento e a profundidade de uma piscina em metros, 
//e imprime sua capacidade em litros. A piscina tem o formato de um paralelepípedo.****////


#include <stdio.h>

float largura, comp, prof, capacidadeL;
float capacidade() {
	capacidadeL= largura * comp * prof;
	return capacidadeL;
}
int main()
{
    
	printf("insira o comprimento da sua piscina:");
	scanf("%f", &largura);
	printf("insira a largura da sua piscina:");
	scanf("%f", &comp);
	printf("insira profundidade:");
	scanf("%f", &prof);
	
	
	capacidadeL= capacidade();
	printf("capacidade:%.2f", capacidadeL);


	return 0;
}

