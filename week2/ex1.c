#include<stdio.h>

void main(){
  int a;
  float b;
  double c;
  a = __INT_MAX__;
  b = __FLT_MAX__;
  c = __DBL_MAX__;
  printf("Length of int: %ld\n", sizeof(a));
  printf("Length of float: %ld\n", sizeof(b));
  printf("Length of double: %ld\n", sizeof(c));
  printf("Value of int: %d\n", a);
  printf("Value of float: %f\n", b);
  printf("Value of double: %lf\n", c);
}
