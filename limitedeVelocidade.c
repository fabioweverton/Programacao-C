#include <stdio.h>

float CalculaMulta(int velocidade)
{
    float multa;
    if (velocidade > 50 && velocidade <= 50 * 1.10)
    {
        multa = 230.00;
    }
    else if (velocidade > 50 * 1.10 && velocidade <= 50 * 1.20)
    {
        multa = 340.00;
    }
    else if (velocidade > 50 * 1.20)
    {
        multa = (velocidade - 50) * 19.28;
    }
    return multa;
}
int main()
{
    int velocidade;
    scanf("%d", &velocidade);
    if (velocidade > 50)
    {
        printf("%.2f\n", CalculaMulta(velocidade));
    }
    else
    {
        printf("0.00\n");
    }
}