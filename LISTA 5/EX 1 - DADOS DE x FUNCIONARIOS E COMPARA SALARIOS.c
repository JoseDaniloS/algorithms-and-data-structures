#include <stdio.h>
#include <stdlib.h>

typedef struct Empresa{//ESTRUTURA COM DADOS DOS FUNCIONAIROS DA EMPRESA
    char nome[20];
    float salario;
    char identificador[10];
    char cargo[20];
}DadosFunc;

DadosFunc * AlocaVetor(int Quantidade);
void PreencheDados(DadosFunc * Servidor, int Quantidade);
void ImprimeDados(DadosFunc * Servidor, int Quantidade);
void AlteraSalario(DadosFunc * Servidor);
void ComparaSalario(DadosFunc * Servidor, int Quantidade);


int main(void){
    int Quantidade;

    printf("Digite a quantidade de Servidor que deseja cadastrar: \n");
    scanf("%d", &Quantidade);

    DadosFunc * Servidor = AlocaVetor(Quantidade);

    PreencheDados(Servidor, Quantidade);
    ImprimeDados(Servidor, Quantidade);
    AlteraSalario(Servidor);
    ComparaSalario(Servidor, Quantidade);

    free(Servidor);

    return 0;
}

DadosFunc * AlocaVetor(int Quantidade){
    DadosFunc * Servidor = (DadosFunc*) malloc(Quantidade*sizeof(DadosFunc));
    if(Servidor == NULL){
        printf("Memoria RAM Insuficiente!\n Encerrando o Programa!");
        exit(1);
    } 

    return(Servidor);
}

//FUNÇÃO QUE SOLICITA OS DADOS AOS USUARIOS
void PreencheDados(DadosFunc * Servidor, int Quantidade){

    for(int i = 0; i < Quantidade; i++){
    printf("%d FUNCIONARIO:\n", i + 1);
    printf("Digite o nome:\t");
    scanf(" %[^\n]", Servidor[i].nome);

    printf("Digite o Salario:\t");
    scanf("%f",&Servidor[i].salario);

    printf("Digite o Identificador:\t");
    scanf(" %[^\n]", Servidor[i].identificador);

    printf("Digite o Cargo:\t");
    scanf(" %[^\n]", Servidor[i].cargo);
    
    }
}

//FUNÇÃO QUE IMPRIME OS DADOS DOS USUARIOS
void ImprimeDados(DadosFunc * Servidor, int Quantidade){

    for(int i = 0; i < Quantidade; i++){
        printf("%d FUNCIONARIO:\n",i + 1);

        printf("NOME: %s\n", Servidor[i].nome);
        printf("SALARIO: %.2f\n", Servidor[i].salario);
        printf("IDENTIFICADOR: %s\n", Servidor[i].identificador);
        printf("CARGO: %s\n\n", Servidor[i].cargo);

    }
}

//FUNÇAO QUE ALTERA O SALARIO DE QUALQUER USUARIO
void AlteraSalario(DadosFunc * Servidor){
    int Posicao;

    printf("Qual funcionario voce deseja alterar o salario?");
    scanf("%d", &Posicao);

    printf("Digite o Novo Salario:\t");
    scanf("%f", &Servidor[Posicao - 1].salario);
}

//FUNÇÃO QUE COMPARA O SALARIO DE CADA USUARIO E IMPRIME QUAL MAIOR E MENOR DELES
void ComparaSalario(DadosFunc * Servidor, int Quantidade){

    int MaiorFuncionario, MenorFuncionario, MaiorSalario, MenorSalario;

    for(int i = 0; i < Quantidade; i++){
        if(Servidor[i].salario > MaiorSalario){
            MaiorSalario = Servidor[i].salario;
            MaiorFuncionario = i;

        }
        else if(Servidor[i].salario < MenorSalario){
            MenorSalario = Servidor[i].salario;
            MenorFuncionario = i;

        }
    }

    printf("O Funcionario com maior salario tem o Cargo: %s  , e o Salario: %.2f", Servidor[MaiorFuncionario].cargo, Servidor[MaiorFuncionario].salario);
    printf("\nO Funcionario com menor salario tem o Cargo: %s  , e o Salario: %.2f", Servidor[MenorFuncionario].cargo, Servidor[MenorFuncionario].salario);

}

