#include <stdio.h>
#include "disciplina.h"
#include "aluno.h"

int main(void){

    Disciplina * materia1 = cria_disciplina("Estrutura de Dados I", 1982);
    Disciplina * materia2 = cria_disciplina("Calculo II", 1970);
    Disciplina * materia3 = cria_disciplina("Arquitetura de Computadores", 1995);
    Disciplina * materia4 = cria_disciplina("Geometria Analitica", 1900);

    Aluno * aluno1 = cria_aluno("Jose Danilo", 344556);
    matricula_disciplina(aluno1, materia1);
    matricula_disciplina(aluno1, materia2);
    matricula_disciplina(aluno1, materia1);
    matricula_disciplina(aluno1, materia3);
    matricula_disciplina(aluno1, materia4);
    
    exclui_aluno(aluno1);
    exclui_disciplina(materia1);
    exclui_disciplina(materia2);
    exclui_disciplina(materia3);
    exclui_disciplina(materia4);
    return 0;
}