#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{//ESTRUTURA PARA ARMAZENAR OS DADOS DAS PESSOAS
    char nome[20];
    long int documento;
    int idade;
}Pessoa;

Pessoa * AlocaVetor(int Quantidade);//ALOCANDO VETOR
void PreenchePessoa(Pessoa * pessoas, int Quantidade);//CADASTRANDO OS DADOS DE "x" PESSOAS
void ImprimePessoa(Pessoa * pessoas, int Quantidade);//EXIBINDO OS DADOS DA PESSOA
void AtualizaIdade(Pessoa * pessoas);//ATUALIZANDO A IDADE DA PESSOA "x"
void ComparaIdade(Pessoa * pessoas, int Quantidade);//COMPARA A IDADE DE TODAS AS PESSOAS CADASTRADAS


int main(void){

    int Quantidade;

    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &Quantidade);

    Pessoa * pessoas = AlocaVetor(Quantidade);

    PreenchePessoa(pessoas,Quantidade);

    ImprimePessoa(pessoas,Quantidade);

    AtualizaIdade(pessoas);

    ComparaIdade(pessoas, Quantidade);

    free(pessoas);

    return 0;

}

Pessoa * AlocaVetor(int Quantidade){
    Pessoa * pessoas = (Pessoa*)malloc(Quantidade*sizeof(Pessoa));
    if(pessoas == NULL){
        printf("Memoria Ram Insuficiente!\nEncerrando o Programa!");
        exit(1);
    }

    return(pessoas);
}

void PreenchePessoa(Pessoa * pessoas, int Quantidade){
    for(int i = 0; i < Quantidade; i++){
        printf("%d PESSOA:\n\n", i + 1);
        printf("Digite o Nome:");
        scanf(" %[^\n]", pessoas[i].nome);
        printf("Digite o Documento: ");
        scanf("%li", &pessoas[i].documento);
        printf("Digite a Idade:");
        scanf("%d", &pessoas[i].idade);
    }        
}

void ImprimePessoa(Pessoa * pessoas, int Quantidade){
    for(int i = 0; i < Quantidade; i++){
        printf("%d PESSOA:\n", i + 1);
        printf("NOME: %s\n", pessoas[i].nome);
        printf("DOCUMENTO: %li\n", pessoas[i].documento);
        printf("IDADE: %d\n\n", pessoas[i].idade);
    }
}

void AtualizaIdade(Pessoa * pessoas){
    int posicao;

    printf("Qual usuario deseja alterar a idade?");
    scanf("%d",&posicao);

    printf("Digite a idade:");
    scanf("%d", &pessoas[posicao - 1].idade);
}

void ComparaIdade(Pessoa * pessoas, int Quantidade){

    int MaiorIdade, MenorIdade, PosicaoMaior, PosicaoMenor;

    for(int i = 0; i < Quantidade; i++){
        if(pessoas[i].idade > MaiorIdade){
            MaiorIdade = pessoas[i].idade;
            PosicaoMaior = i;
        }
        else if(pessoas[i].idade < MenorIdade){
            MenorIdade = pessoas[i].idade;
            PosicaoMenor = i;
        }
    }

    printf("%s é o mais velho com %d anos\n", pessoas[PosicaoMaior].nome, pessoas[PosicaoMaior].idade);
    printf("%s é o mais novo com %d anos", pessoas[PosicaoMenor].nome, pessoas[PosicaoMenor].idade);
}