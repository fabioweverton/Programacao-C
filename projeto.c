#include <stdio.h>
#include <string.h>
#define TAM 100

typedef struct usuario
{
    char nome[50];
    char curso[20];
    int matricula;
    float notas;
} Usuario;

void carregarDados(Usuario usuarios[], int *qtd)
{
    FILE *arquivo = fopen("projeto.txt", "r");

    if (arquivo == NULL)
    {
        printf("Arquivo não encontrado!\n");
        return;
    }

    while (fscanf(arquivo, "%49[^\n] %19[^\n]%d%f ", usuarios[*qtd].nome, usuarios[*qtd].curso, &usuarios[*qtd].matricula, &usuarios[*qtd].notas) != EOF)
    {
        (*qtd)++;
    }

    fclose(arquivo);
}

void salvarDados(Usuario usuarios[], int *qtd)
{
    FILE *arquivo = fopen("projeto.txt", "w");

    if (arquivo == NULL)
    {
        printf("Error.\n");
        return;
    }

    for (int i = 0; i < *qtd; i++)
    {
        fprintf(arquivo, "%s\n%s\n%d\n%.2f\n", usuarios[i].nome, usuarios[i].curso, usuarios[i].matricula, usuarios[i].notas);
    }

    fclose(arquivo);
}

void matriculeSe(Usuario usuarios[], int *qtd)
{
    if (*qtd > TAM)
    {
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
    printf("Digite a nota: ");
    scanf("%f", &usuarios[*qtd].notas);
    printf("\n");

    printf("Seja Bem Vindo a nossa Escola!!\n\n");
    (*qtd)++;
}

void exebirAlunos(Usuario usuarios[], int *qtd)
{
    printf("\n");
    for (int i = 0; i < *qtd; i++)
    {
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Curso: %s\n", usuarios[i].curso);
        printf("Matriicula: %d\n", usuarios[i].matricula);
        printf("Nota: %.2f\n\n", usuarios[i].notas);
    }
}
void buscarAlunos(Usuario usuarios[], int *qtd)
{
    int matriculaBusca;
    int encontrado = 0;
    
    printf("\nDigite a matricula do aluno(a) que deseja buscar: ");
    scanf("%d", &matriculaBusca);
    getchar();
    
    for (int i = 0; i < *qtd; i++)
    {
        if (usuarios[i].matricula == matriculaBusca)
        {
            printf("\nAluno encontrado:\n");
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Curso: %s\n", usuarios[i].curso);
            printf("Matricula: %d\n", usuarios[i].matricula);
            printf("Nota: %.2f\n\n", usuarios[i].notas);
            encontrado = 1;
            break; 
        }
    }
    
    if (!encontrado)
    {
        printf("\nAluno com matricula %d nao encontrado!\n\n", matriculaBusca);
    }
}
void atualizarInfo(Usuario usuarios[], int *qtd)
{
    int matriculaBusca;
    
    printf("\nDigite a matricula do aluno(a) que deseja atualizar: ");
    scanf("%d", &matriculaBusca);
    getchar();
    
    for (int i = 0; i < *qtd; i++)
    {
        if (usuarios[i].matricula == matriculaBusca)
        {
            printf("\nAluno encontrado. Informe os novos dados:\n");
            
            printf("Nome atual: %s\n", usuarios[i].nome);
            printf("Novo nome: ");
            scanf("%49[^\n]", usuarios[i].nome);
            getchar();
            
            printf("Curso atual: %s\n", usuarios[i].curso);
            printf("Novo curso: ");
            scanf("%19[^\n]", usuarios[i].curso);
            getchar();
            
            printf("Matricula atual: %d\n", usuarios[i].matricula);
            printf("Nova matricula: ");
            scanf("%d", &usuarios[i].matricula);
            getchar();
            
            printf("Nota atual: %.2f\n", usuarios[i].notas);
            printf("Nova nota: ");
            scanf("%f", &usuarios[i].notas);
            getchar();
            
            printf("\nDados do aluno atualizados com sucesso!\n\n");
            
            salvarDados(usuarios, qtd);
            break;
        }
    }
}
void removerAluno(Usuario usuarios[], int *qtd)
{
    int matriculaBusca;
    
    printf("\nDigite a matricula do aluno que deseja remover: ");
    scanf("%d", &matriculaBusca);
    getchar();
    
    for (int i = 0; i < *qtd; i++)
    {
        if (usuarios[i].matricula == matriculaBusca)
        {
            printf("\nAluno encontrado:\n");
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Curso: %s\n", usuarios[i].curso);
            printf("Matricula: %d\n", usuarios[i].matricula);
            printf("Nota: %.2f\n\n", usuarios[i].notas);
            
            char confirma;
            printf("Confirma a remoção deste aluno? (S/N): ");
            scanf("%c", &confirma);
            getchar();
            
            if (confirma == 'S' || confirma == 's')
            {
                // Movendo os elementos seguintes uma posição para trás
                for (int j = i; j < (*qtd - 1); j++)
                {
                    strcpy(usuarios[j].nome, usuarios[j + 1].nome);
                    strcpy(usuarios[j].curso, usuarios[j + 1].curso);
                    usuarios[j].matricula = usuarios[j + 1].matricula;
                    usuarios[j].notas = usuarios[j + 1].notas;
                }
                
                (*qtd)--; // Diminui o contador de alunos
                printf("Aluno removido com sucesso!\n\n");
                
                // Salva as alterações no arquivo
                salvarDados(usuarios, qtd);
            }
            else
            {
                printf("Operação cancelada.\n\n");
            }
            break;
        }
    }
}

int main()
{

    Usuario usuarios[TAM];
    int qtdUsarios = 0;

    carregarDados(usuarios, &qtdUsarios);

    while (1)
    {
        printf("================= HOME =================\n");
        printf("\t1 - Matricule-se\n");
        printf("\t2 - Exibir Alunos(a)\n");
        printf("\t3 - Buscar Aluno(a)\n");
        printf("\t4 - Atualizar informacoes do Aluno(a)\n");
        printf("\t5 - Remover Aluno(a)\n");
        printf("\t6 - Salvar e carregar dados.\n");
        printf("\t7 - Finalizar Programa\n");
        printf("========================================\n\n");

        int opcao;
        printf("Qual sua escolha: ");
        scanf("%d", &opcao);

        if (opcao == 7)
        {
            printf("Salvando os dados...\n");
            salvarDados(usuarios, &qtdUsarios);
            printf("Fizalinado...\n");
            break;
        }

        switch (opcao)
        {
        case 1:
            getchar();
            matriculeSe(usuarios, &qtdUsarios);
            break;
        case 2:
            exebirAlunos(usuarios, &qtdUsarios);
            break;

        case 3:
            buscarAlunos(usuarios, &qtdUsarios);
            break;

        case 4:
            atualizarInfo(usuarios, &qtdUsarios);
            break;

        case 5:
            removerAluno(usuarios, &qtdUsarios);

        case 6:
            printf("\nSalvando e recarregando dados...\n");
            salvarDados(usuarios, &qtdUsarios);
            qtdUsarios = 0;
            carregarDados(usuarios, &qtdUsarios);
            printf("Dados salvos e recarregados com sucesso!\n");
            printf("Total de alunos: %d\n\n", qtdUsarios);
            break;
        }
        
    }

    return 0;
}