#include <stdio.h>

int main() {
    int minutosPorProcesso;
    int minutosTrabalhados = 8 * 60;
    int totalProcessos; 

    printf("Digite quantos minutos Betina leva para analisar cada processo: ");
    scanf("%d", minutosPorProcesso);

    if(minutosPorProcesso <= 0) {
        printf("Tempo por processo inválido. Por favor, insira um valor positivo.\n");
        return 0;
    }
}