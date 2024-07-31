#include <stdio.h>

typedef enum genero{
    MASCULINO = 1,
    FEMININO
}Genero;


typedef struct pessoa{
    char nome[20];
    int idade;
    Genero gen;
}Pessoa;

void Preenche_Pessoa(Pessoa * pessoas){

    printf("Informe o Nome: ");
    scanf(" %[^\n]", pessoas->nome);

    printf("Informe a Idade: ");
    scanf("%d", &pessoas->idade);

    printf("Informe o Genero: \n1- Masculino \n2- Feminino\n");
    scanf("%d", &pessoas->gen);
}

void Imprime_Pessoa(Pessoa * pessoas){

    printf("Nome: %s\n", pessoas->nome);
    printf("Idade: %d\n", pessoas->idade);
    if(pessoas->gen == MASCULINO){
        printf("Genero: Masculino");
    }
    else if(pessoas->gen == FEMININO){
        printf("Genero: Feminino");
    }
}

int main(void){

    Pessoa * pessoas;

    Preenche_Pessoa(pessoas);
    Imprime_Pessoa(pessoas);

    return 0;
}