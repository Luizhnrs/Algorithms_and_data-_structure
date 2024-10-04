#include <stdio.h>
#include <stdlib.h>

void func(int *px, int *py) {
    px = py;
    *px = (*py) * (*px);
    *px = *px + 2;
}

int main() {
    int x,y;

    scanf("%d %d", &x, &y);
    printf("%d %d", x, y);


    func(&x, &y);
    printf("%d %d", x, y);
    return 0;
}