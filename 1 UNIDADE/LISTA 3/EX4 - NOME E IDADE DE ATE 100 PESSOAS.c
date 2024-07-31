/*ENTRADA:
    -NUMERO DE PESSOAS(MAXIMO = 100)
    -NOME COMPLETO
    -IDADE
  SAIDA:
    Pessoa Nª:
    -NOME COMPLETO: José Danilo
    -IDADE: 19
*/


#include <stdio.h>
#include <stdlib.h>

//VARIAVEL GLOBAL PARA O MAXIMO DE CARACTERES DE UM NOME
#define MAX_NOME 100

//PROTOTIPO DE FUNÇÕES UTILIZADAS
void VerificaPessoas(int Pessoas);
char **AlocaNomes(int Pessoas);
int *AlocaIdade(int Pessoas);
void RecebeDados(char ** nomes,int * idades, int Pessoas);
void ExibeDados(char ** nomes, int * idades, int Pessoas);

//FUNÇÃO PRINCIPAL
int main(void){

    int Pessoas = NULL;

    //SOLICITA AO USUARIO O NUMERO DE PESSOAS QUE SERÃO CADASTRADAS
    printf("Quantas Pessoas serao cadastradas?(MAX: 100)");
    scanf("%d", &Pessoas);
    //PARA CONSUMIR O \N DEIXADO PELO SCANF

    //FUNÇAO PARA VERIFICAR A QUANTIDADE DE PESSOAS
    VerificaPessoas(Pessoas);

    //ALOCA MEMORIA DINAMICAMENTE PARA NOMES
    char ** nomes = AlocaNomes(Pessoas);

    //ALOCA IDADE DINAMICAMENTE PARA IDADES
    int * idade = AlocaIdade(Pessoas);

    //FUNÇÃO QUE RECEBE OS DADOS DAS PESSOAS
    RecebeDados(nomes,idade,Pessoas);

    //FUNÇÃO QUE EXIBE OS DADOS DAS PESSOAS
    ExibeDados(nomes,idade,Pessoas);

    //LIBERANDO MEMORIA DA MATRIZ E DO VETOR
    free(idade);
    for(int i = 0; i < Pessoas; i++){
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}

void VerificaPessoas(int Pessoas){
    do{
        if(Pessoas > 100){
            do{

                printf("Numero Maximo Excedido!\nDigite Novamente!");
                scanf("%d", &Pessoas);
                

            }while(Pessoas > 100);
        }
        else if(Pessoas <= 0){
            do{

                printf("Numero Invalido!\nDigite Novamente!");
                scanf("%d", &Pessoas);
                

            }while(Pessoas <= 0);
        }

    }while(Pessoas <= 0 || Pessoas > 100);
}

char ** AlocaNomes(int Pessoas){

    char ** nomes = (char**)malloc(Pessoas * sizeof(char*));
    if(nomes == NULL){
        printf("Erro ao alocar memorias para nomes!");
        exit(1);
    }
    for(int i = 0; i < Pessoas; i++){
        nomes[i] = (char*)malloc((MAX_NOME) * sizeof(char));
        if(nomes[i] == NULL){
            printf("Erro ao alocar memoria para nome!");
            exit(1);
        }
    }
    return(nomes);
}

int * AlocaIdade(int Pessoas){
    int * idade = (int*)malloc(Pessoas * sizeof(int));
    if(idade == NULL){
        printf("Erro ao alocar memoria para idade");
        exit(1);
    }
    return(idade);
}

void RecebeDados(char ** nomes, int * idade, int Pessoas){
    for(int i = 0; i < Pessoas; i++){
        printf("\n%d PESSOA\nDigite o nome:", i + 1);
        scanf(" %[^\n]", nomes[i]);

        printf("Digite a idade:");
        scanf("%d", &idade[i]);
    }
}

void ExibeDados(char ** nomes, int * idade, int Pessoas){
     for(int i = 0; i < Pessoas; i++){
        printf("\n%d Pessoa:\n", i + 1);
        printf("Nome: %s\n",nomes[i]);
        printf("Idade: %d\n\n", idade[i]);
    }
}