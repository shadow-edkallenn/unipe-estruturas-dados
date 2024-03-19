#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
typedef struct aluno{
    int matricula;
    char nome_aluno[50];
    char curso[40];
    float valor_parcela;
} Aluno;
 
 
Aluno lerDadosdoAluno();  
void inserirAluno(Aluno **banco_alunos, int *n, Aluno novo_aluno);
void exibirAlunos(Aluno *banco_alunos, int n); 
void removerAluno(Aluno *banco_alunos, int *n, int matricula);
void editarAluno(Aluno *banco_alunos, int n, int matricula);
 
int main() {    
    // Inicializando variáveis
    int n = 0; // Número de alunos cadastrados
    Aluno *banco_alunos = NULL; // Ponteiro para o banco de alunos

    // Loop principal do programa
    int opcao;
    do {
        // Exibindo o menu
        system("clear");  // para Windows é system("cls");
        printf("## Gerenciamento de Alunos\n\n");
        printf("Opções:\n");
        printf("1. Inserir Aluno\n");
        printf("2. Exibir Alunos\n");
        printf("3. Remover Aluno\n");
        printf("4. Editar Aluno\n");
        printf("5. Sair\n\n");
        printf("Digite a opção desejada: ");
        scanf(" %d", &opcao);

        // Chamando a função de acordo com a opção escolhida
        switch (opcao) {
        case 1:
            // Inserir aluno
            Aluno novo_aluno = lerDadosdoAluno();
            inserirAluno(&banco_alunos, &n, novo_aluno);
            break;
        case 2:
            // Exibir alunos
            exibirAlunos(banco_alunos, n);
            break;
        case 3:
            // Remover aluno
            int matricula_remover;
            printf("Digite a matrícula do aluno a ser removido: ");
            scanf("%d", &matricula_remover);
            removerAluno(&banco_alunos, &n, matricula_remover);
            break;
        case 4:
            // Editar aluno
            int matricula_editar;
            printf("Digite a matrícula do aluno a ser editado: ");
            scanf("%d", &matricula_editar);
            editarAluno(banco_alunos, n, matricula_editar);
            break;
        case 5:
            // Sair do programa
            printf("Saindo do programa...\n");
            break;
        default:
            // Opção inválida
            printf("Opção inválida! Digite um número entre 1 e 5.\n");
        }

        // Aguarda o usuário pressionar qualquer tecla para continuar
        printf("\nPressione qualquer tecla para continuar...");
        getchar();
        
    } while (opcao != 5);

    // Liberando memória alocada
    free(banco_alunos);

    return 0;
}
 
 
Aluno lerDadosdoAluno() {
    Aluno aluno;
    printf("Digite a matrícula: ");
    scanf(" %d", &aluno.matricula);
    printf("Digite o nome do aluno: ");
    fgets(aluno.nome_aluno, 49, stdin);
    printf("Digite o curso: ");
    fgets(aluno.curso, 39, stdin);
    printf("Digite o valor da parcela: ");
    scanf(" %f", &aluno.valor_parcela);
    return aluno;
}
 

// Função para inserir um novo aluno no banco de alunos
void inserirAluno(Aluno **banco_alunos, int *n, Aluno novo_aluno) {
    // Realocando memória para o banco de alunos
    *banco_alunos = realloc(*banco_alunos, (*n + 1) * sizeof(Aluno));
    if (*banco_alunos == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    // Inserindo o novo aluno no final do banco de alunos
    (*banco_alunos)[*n] = novo_aluno;
    (*n)++;

    printf("Aluno inserido com sucesso!\n");
}

/*
void inserirAluno(Aluno *banco_alunos, int *n, Aluno novo_aluno) {
    banco_alunos = realloc(banco_alunos, (*n + 1) * sizeof(Aluno));
    if(banco_alunos == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    banco_alunos[*n] = novo_aluno;
    (*n)++;
}
*/ 
 
void exibirAlunos(Aluno *banco_alunos, int n) {
    if (n == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("--------------------\n");
        printf("Matricula: %d\n", banco_alunos[i].matricula);
        printf("Nome: %s", banco_alunos[i].nome_aluno);
        printf("Curso: %s", banco_alunos[i].curso);
        printf("Valor da Parcela: R$ %.2f\n", banco_alunos[i].valor_parcela);
    }
}

void removerAluno(Aluno *banco_alunos, int *n, int matricula) {
    int posicao_aluno = -1;
    // Procurando a posição do aluno no banco de alunos
    for (int i = 0; i < *n; i++) {
        if (banco_alunos[i].matricula == matricula) {
            posicao_aluno = i;
            break;
        }
    }

    if (posicao_aluno == -1) {
        printf("Aluno com a matrícula %d não encontrado.\n", matricula);
        return;
    }

    // Removendo o aluno do banco de alunos
    for (int i = posicao_aluno; i < *n - 1; i++) {
        banco_alunos[i] = banco_alunos[i + 1];
    }

    (*n)--;

    printf("Aluno removido com sucesso!\n");
}

void editarAluno(Aluno *banco_alunos, int n, int matricula) {
    int posicao_aluno = -1;

    // Procurando a posição do aluno no banco de alunos
    for (int i = 0; i < n; i++) {
        if (banco_alunos[i].matricula == matricula) {
            posicao_aluno = i;
            break;
        }
    }

    if (posicao_aluno == -1) {
        printf("Aluno com a matrícula %d não encontrado.\n", matricula);
        return;
    }

    // Editando os dados do aluno
    printf("Digite o novo nome do aluno: ");
    fgets(banco_alunos[posicao_aluno].nome_aluno, 49, stdin);
    printf("Digite o novo curso: ");
    fgets(banco_alunos[posicao_aluno].curso, 39, stdin);
    printf("Digite o novo valor da parcela: ");
    scanf(" %f", &banco_alunos[posicao_aluno].valor_parcela);

    printf("Aluno editado com sucesso!\n");
}

