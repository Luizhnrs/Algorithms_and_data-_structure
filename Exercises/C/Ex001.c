#include <stdio.h>
// 1- Faça um programa que leia um número inteiro e o imprima.

int main(){
    int num;
    
    printf("Digite um número inteiro: ");
    scanf("%d", &num); // Lê um número inteiro da entrada do usuário
    
    printf("O número digitado foi: %d\n", num); // Imprime o número lido
    
    return 0;
}