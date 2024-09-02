#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct disciplina{
    char nome[100];
    int codigo;
};

Disciplina * cria_disciplina(char nome[], int codigo){
    Disciplina * materia = (Disciplina*)malloc(sizeof(Disciplina));
    if(materia == NULL){
        printf("Memoria Indisponivel!\n");
        exit(1);
    }
    
    strcpy(materia->nome, nome);
    materia->codigo = codigo;

    return materia;
}

void exclui_disciplina(Disciplina * disciplina){
    free(disciplina);
    printf("Materia excluida com sucesso!\n");
}