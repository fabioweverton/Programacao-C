#include <stdio.h>

int main() {
    int minutosPorProcesso;
    int minutosTotaisTrabalhados = 8 * 60; // 8 horas * 60 minutos
    int totalProcessos;

    printf("Digite quantos minutos Betina leva para analisar cada processo: ");
    scanf("%d", &minutosPorProcesso);

    totalProcessos = minutosTotaisTrabalhados / minutosPorProcesso;

    printf("Betina revisou %d processos em um dia de trabalho.\n", totalProcessos);

    return 0;
}