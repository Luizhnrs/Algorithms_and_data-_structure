/*Exercício 1
Desenvolver um algoritmo que leia um número inteiro e verifique se o número é divisível por 5 e por 3 ao mesmo tempo. */

#include <stdio.h>

int main() {
    int num = 0;
    
    scanf("%d",&num);

    if(((num % 5) == 0) && ((num % 3 ) == 0)){
        printf("%d, e um numero divisivel por 5 e 3!\n", num);
    } else {
        printf("%d, NAO e um numero divisivel por 5 e 3!\n", num);
    }
    return 0;
}

