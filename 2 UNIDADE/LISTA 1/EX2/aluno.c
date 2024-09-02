#include "aluno.h"
#include "disciplina.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct aluno{
    char nome[100];
    int matricula;
    Disciplina * disciplinas[10];
    int num_disciplinas;
};

Aluno * cria_aluno(char nome[], int matricula){
    Aluno * alunos = (Aluno*)malloc(sizeof(Aluno));
    if(alunos == NULL){
        printf("Memoria Indisponivel!\n");
        exit(1);
    }
    strcpy(alunos->nome, nome);
    alunos->matricula = matricula;
    alunos->num_disciplinas = 0;
    return(alunos);
}

void matricula_disciplina(Aluno * aluno, Disciplina * disciplina){
    for(int i = 0; i < aluno->num_disciplinas; i++){
        if(aluno->disciplinas[i] == disciplina){
            printf("Aluno ja matriculado na disciplina!\n");
            return;
        }
    }
    if(aluno->num_disciplinas < 10){
        aluno->disciplinas[aluno->num_disciplinas] = disciplina;
        aluno->num_disciplinas+= 1;
        printf("Aluno Matriculado com Sucesso!\n");
    }
    else{
        printf("Numero Maximo de Disciplinas!\n");
    }
}

void exclui_aluno(Aluno * aluno){
    free(aluno);
    printf("Aluno excluido com sucesso!\n");
}