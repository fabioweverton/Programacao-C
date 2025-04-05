#include <stdio.h>

int main() {
  float nota1, nota2, nota3;
  float media_aritmetica, media_ponderada1, media_ponderada2;

  printf("Digite a primeira nota: ");
  scanf("%f", &nota1);

  printf("Digite a segunda nota: ");
  scanf("%f", &nota2);

  printf("Digite a terceira nota: ");
  scanf("%f", &nota3);

  media_aritmetica = (nota1 + nota2 + nota3) / 3.0;

  media_ponderada1 = (nota1 * 2 + nota2 * 2 + nota3 * 3) / (2 + 2 + 3);

  media_ponderada2 = (nota1 * 1 + nota2 * 2 + nota3 * 2) / (1 + 2 + 2);

  printf("\nResultados:\n");
  printf("Média Aritmética: %.2f\n", media_aritmetica);
  printf("Média Ponderada (pesos 2, 2, 3): %.2f\n", media_ponderada1);
  printf("Média Ponderada (pesos 1, 2, 2): %.2f\n", media_ponderada2);

  return 0;
}