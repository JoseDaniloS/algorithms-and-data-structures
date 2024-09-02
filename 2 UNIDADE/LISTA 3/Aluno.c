#include <stdlib.h>
#include <stdio.h>
#include "Aluno.h"
#include <string.h>

struct aluno{
    int matricula;
    char nome[20];
    float media;
};

Aluno * criarAluno(int matricula, char nome[], float media){
    Aluno * aluno = (Aluno*)malloc(sizeof(Aluno));

    aluno->matricula = matricula;
    strcpy(aluno->nome, nome);
    aluno->media = media;

    return(aluno);
}

void salvarAlunoEmArquivo(char * nome, Aluno * aluno){
    FILE * entrada = fopen(nome, "a");
    if(entrada == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    fprintf(entrada, "%d\t%s\t%.1f\n",aluno->matricula, aluno->nome, aluno->media);
    fclose(entrada);

}

void exibirAlunos(char * nome){
    Aluno aluno;
    int cont = 1;
    FILE * entrada = fopen(nome, "a");
    if(entrada == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    while(fscanf("%d\t%[^\t]\t%.1f\n",&aluno.matricula, aluno.nome, &aluno.media) != EOF){
        printf("Aluno %d: %d\t%s\t%.1f\n" , cont, aluno.matricula, aluno.nome, aluno.media);
        cont++;
    }
    fclose(entrada);

}