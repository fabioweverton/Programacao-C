#include <stdio.h>
#include <string.h>
#define TAM 100

typedef struct usuario {
    char nome[50];
    char curso[20];
    int matricula;
    float notas;
} Usuario;

void carregarDados(Usuario usuarios[], int *qtd) {
    FILE *arquivo = fopen("usuarios.txt", "r");

    if (arquivo == NULL) {
        printf("Arquivo não encontrado!\n");
        return;
    }

    while (fscanf(arquivo, "%49[^\n] %19[^\n]%d%f ", usuarios[*qtd].nome, usuarios[*qtd].curso, &usuarios[*qtd].matricula, &usuarios[*qtd].notas) != EOF) {
        (*qtd)++;
    }

    fclose(arquivo);
}

void salvarDados(Usuario usuarios[], int *qtd) {
    FILE *arquivo = fopen("usuarios.txt", "w");

    if (arquivo == NULL) {
        printf("Error.\n");
        return;
    }

    for (int i = 0; i < *qtd; i++) {
        fprintf(arquivo, "%s\n%s\n%d\n%.2f\n", usuarios[i].nome, usuarios[i].curso, usuarios[i].matricula, usuarios[i].notas);
    }

    fclose(arquivo);
}

void matriculeSe(Usuario usuarios[], int *qtd) {
    if (*qtd > TAM) {
        printf("Turmas Cheias.\n");
        return;
    }

    printf("Informe os dados: \n");
    printf("Digite seu nome: ");
    scanf("%49[^\n]", usuarios[*qtd].nome);
    getchar();
    printf("Digite o Curso: ");
    scanf("%19[^\n]", usuarios[*qtd].curso);
    printf("Digite a matricula: ");
    scanf("%d", &usuarios[*qtd].matricula);
    usuarios[*qtd].notas = 0.0;

    printf("Seja Bem Vindo a nossa Escola!!\n\n");
    (*qtd)++;
}

void exebirAlunos(Usuario usuarios[], int *qtd) {
    printf("\n");
    for (int i = 0; i < *qtd; i++) {
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Curso: %s\n", usuarios[i].curso);
        printf("Matriicula: %d\n", usuarios[i].matricula);
        printf("Nota: %.2f\n\n", usuarios[i].notas);
    }
}

int main() {

    Usuario usuarios[TAM];
    int qtdUsarios = 0;

    carregarDados(usuarios, &qtdUsarios);

    while (1) {
        printf("================= HOME =================\n");
        printf("\t1 - Matricule-se\n");
        printf("\t2 - Exibir Alunos(a)\n");
        printf("\t3 - Buscar Aluno(a)\n");
        printf("\t4 - Atualizar informações do Aluno(a)\n");
        printf("\t5 - Remover Aluno(a)\n");
        printf("\t6 - Salvar e carregar dados.\n");
        printf("\t7 - Finalizar Programa\n");
        printf("========================================\n\n");

        int opcao;
        printf("Qual sua escolha: ");
        scanf("%d", &opcao);

        if (opcao == 7) {
            printf("Salvando os dados...\n");
            salvarDados(usuarios, &qtdUsarios);
            printf("Fizalinado...\n");
            break;
        }

        switch (opcao) {
            case 1:
                getchar();
                matriculeSe(usuarios, &qtdUsarios);
                break;
            case 2:
                exebirAlunos(usuarios, &qtdUsarios);
                break;
        }
    }


    return 0;
}