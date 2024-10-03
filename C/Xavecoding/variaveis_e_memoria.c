#include <stdio.h>

int main(){
  int a = 10;
  int b,c;

  printf("&a = %p, a = %p", &a, a);
  printf("&b = %p, b = %p", &b, b);
  printf("&c = %p, c = %p", &c, c);

  b = 20;
  c = a + b;

  printf("&a = %p, a = %p", &a, a);
  printf("&b = %p, b = %p", &b, b);
  printf("&c = %p, c = %p", &c, c);
  return 0;
}