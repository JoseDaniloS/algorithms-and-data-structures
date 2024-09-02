// funcionario.h

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Definição de um valor máximo para o vetor de funcionários

// Definição da estrutura Funcionario
typedef struct funcionario Funcionario;

// Declaração das funções
Funcionario **aloca_funcionarios();
void libera_funcionario(Funcionario **funcionarios, int qnt);
Funcionario *busca_funcionario(Funcionario **funcionarios, int id, int qnt);
Funcionario **adiciona_funcionario(Funcionario **funcionarios, char *nome, int id, float salario, int *qnt);
Funcionario **remover_funcionario(Funcionario **funcionarios, int id, int *qnt);
void listar_funcionarios(Funcionario **funcionarios, int qnt);

#endif // FUNCIONARIO_H
