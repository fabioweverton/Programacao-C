#include <stdio.h>

int main() {
    int dias;
    int km;
    float total;

    printf("Digite o numero de dias com o carro: \n");
    scanf("%d", &dias);

    printf("Digite a quantidade de quilometros rodados: \n");
    scanf("%d", &km);

    total = (dias * 30.00) + (km * 0.01);

    total *= 0.9;

    printf("O valor total do aluguel com desconto e: R$ %.2f\n", total);

}