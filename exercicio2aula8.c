#include <stdio.h>

int calcularQuadrado(int valor){
    return valor * valor;
}

int main(){
    int contador = 0;
    
    for (contador = 0; contador <= 10; contador++){
        int quadradoContador = calcularQuadrado(contador);
        printf("%d %d \n", contador, quadradoContador);
    }
}
