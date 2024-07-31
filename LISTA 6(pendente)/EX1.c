#include <stdio.h>
#include <stdlib.h>

#define MAX_VAGAS 2
#define MAX_TURMAS 2

struct aluno {
    int mat;
    char nome[81];
    float notas[3];
    float media;
};
typedef struct aluno Aluno;

struct turma {
    char id;
    int vagas;
    Aluno * alunos[MAX_VAGAS]
};
typedef struct turma Turma;

Turma ** Verifica_Turma(Turma ** turmas, int n, char id){

    int verificador = 0;

    for(int i = 0; i < n; i ++){
        if(turmas[i]->id == id){
            verificador = i;
        }
        if(verificador == 0){
            return NULL;
        }
        else{
            return turmas[verificador];
        }
    }

}

Turma * Criar_Turmas(char id){
    Turma * tur = malloc(sizeof(Turma));
    tur->id = id;
    tur->vagas = MAX_VAGAS;
    for(int i = 0; i < MAX_VAGAS;i++){
        tur->alunos[i] = NULL;
    }
    return tur;
}


int main(void){

    int opcao, n = 0;
    char id;

    Turma ** turmas = (Turma**)malloc(MAX_TURMAS * sizeof(Turma*));

    printf("Bem-Vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as \nfuncionalidades de matricula, lancamento de notas e listagem de \nalunos.");
    printf("Autor: Jose Danilo \t Versao: 1.0\n\n");

    while(opcao != 6){
        printf("MENU:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair");
        printf("\n\nDigite sua opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Criando nova turma...\n");
            printf("Digite um id: ");
            scanf(" %c", &id);
            if(n == MAX_TURMAS){
                printf("Numero Maximo de Turmas Cadastradas!");
            }
            else if(Verifica_Turma(turmas,n,id) != NULL){
                printf("Turma ja Existe!");
            }
            else{
                turmas[n] = malloc(sizeof(Turma));
                turmas[n] = Criar_Turmas(id);
                n++;
                printf("Turma %c criada com sucesso!", id);
            }
            break;
        
        default:
            break;
        }
    }
    

}