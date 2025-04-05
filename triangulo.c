#include <stdio.h>

int main() {
  float angulo1, angulo2, angulo3;
  
  scanf("%f", &angulo2);

  angulo3 = 180.0 - angulo1 - angulo2;

  printf("3o triangulo= %.2f graus\n", angulo3);

  return 0;
}