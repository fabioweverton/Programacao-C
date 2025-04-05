#include <stdio.h>

int main() {
  int numero;

  printf("Digite um número inteiro:\n");
  scanf("%d", &numero);

  if (numero % 4 == 0 && numero % 7 == 0 && numero % 5 != 0) {
    printf("sim\n");
  } else {
    printf("nao\n");
  }

  return 0;
}