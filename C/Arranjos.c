#include <stdio.h>
#include <stdlib.h>

void print(int* w){
    printf("w0: %i, w1: %i, w2: %i\n", w[0], w[1], w[2]);
    printf("&w: %p, w: %p, *w: %i\n", &w,w,*w);
}

int main(){
    int x[3];
    x[0] = 1;
    x[1] = 2;
    x[2] = 7;

    print(x);
    printf("X0: %i, x1: %i, x2: %i", x[0], x[1], x[2]);
    printf("&x: %p, w1: %p, w2: %i", &x, x, x);
}