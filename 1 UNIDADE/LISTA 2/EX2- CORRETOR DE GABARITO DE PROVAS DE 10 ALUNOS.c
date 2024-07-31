/*ENTRADA:
    -NUMERO DE QUESTÕES
    -GABARITO DA PROVA
    -RESPOSTA DE TODOS OS ALUNOS
  SAIDA:
    -NOTA OBTIDA DE CADA ALUNO
    -QUAL ALUNO FOI APROVADO
    -PORCENTAGEM DE APROVAÇÃO DA SALA
*/

#include <stdio.h>
#include <stdlib.h>

#define ALUNOS 10

char * AlocaVetorChar(int Questoes);
int * AlocaVetorInt();
char ** AlocaMatriz(int Questoes);
void GabaritoProva(char * Gabarito, int Questoes);
void Resposta(int Questoes, char** RespostaAlunos);
void VerificaQuestoes(char * Gabarito, char ** RespostaAlunos,int * Notas, int Questoes);
void VerificaAprovacao(int * Notas);


int main(void){

    int Questoes;
    printf("Quantas questoes a avaliacao tera? ");
    scanf("%d", &Questoes);

    char * Gabarito = AlocaVetorChar(Questoes);//CRIA O VETOR QUE ARMAZENA O GABARITO

    GabaritoProva(Gabarito,Questoes);//SOLICITA O GABARITO DA PROVA
    
    char ** RespostaAlunos = AlocaMatriz(Questoes);//CRIA A MATRIZ PARA ARMAZENAR A RESPOSTA DE CADA QUESTAO DE CADA ALUNO

    Resposta(Questoes, RespostaAlunos);//RECEBE A RESPOSTA DE CADA ALUNO

    int * Notas = AlocaVetorInt();//CRIA O VETOR PARA ARMAZENAR A NOTA DE CADA ALUNO

    VerificaQuestoes(Gabarito,RespostaAlunos,Notas,Questoes);//VERIFICA QUAL QUESTAO TA CERTA E QUAL TA ERRADA

    VerificaAprovacao(Notas);//VERIFICA QUAL ALUNO FOI APROVADO E QUAL FOI REPROVADO  

    free(Gabarito);//LIBERA MEMORIA ALOCADA DOS VETORES/MATRIZES
    free(Notas);
    for(int i = 0; i < ALUNOS; i++){
        free(RespostaAlunos[i]);
    }
    free(RespostaAlunos);

    return 0;
}

char * AlocaVetorChar(int Questoes){//PARA ARMAZENAR O GABARITO DA PROVA
    char * vetor = (char*)malloc(Questoes * sizeof(char));
    if(vetor == NULL){
        printf("Nao foi Possivel Alocar o Vetor!\nEncerrando o Programa!");
        exit(1);
    }
    return(vetor);
}

int * AlocaVetorInt(){//PARA ARMAZENAR A QUANTIDADE DE ACERTOS DE CADA ALUNO
    int * vetor = (int*)calloc(ALUNOS, sizeof(int));
    if(vetor == NULL){
        printf("Nao foi Possivel Alocar o Vetor!\nEncerrando o Programa!");
        exit(1);
    }
    return(vetor);
}

char ** AlocaMatriz(int Questoes){//PARA ARMAZENAR A RESPOSTA DE CADA ALUNO
    char ** matriz = (char**)malloc(ALUNOS * sizeof(char*));
    for(int i = 0; i < ALUNOS; i++){
        matriz[i] = (char*)malloc(Questoes * sizeof(char));
    }
    return(matriz);
}

void GabaritoProva(char * Gabarito, int Questoes){//SOLICITA UMA RESPOSTA DE "x" QUESTOES COM 4 POSSIVEIS OPÇÕES
    printf("Digite o Gabarito da prova: \nOpcoes Disponiveis: [A-B-C-D]\n");
    for(int i = 0; i < Questoes; i++){
        printf("%dª Questao: ", i+1);
        scanf(" %c", &Gabarito[i]);
        do{
            if(Gabarito[i] != 'A' && Gabarito[i] != 'B' && Gabarito[i] != 'C' && Gabarito[i] != 'D'){
                printf("Opcao Indisponivel!\nDigite Novamente!");
                scanf(" %c", &Gabarito[i]);
            }
        }while(Gabarito[i] != 'A' && Gabarito[i] != 'B' && Gabarito[i] != 'C' && Gabarito[i] != 'D');
    }
}

void Resposta(int Questoes, char ** RespostaAlunos){//SOLICITA UMA RESPOSTA DE "x" QUESTOES COM 4 POSSIVEIS OPÇÕES
    printf("RESPOSTA DOS ALUNOS:\nOpcoes Disponiveis: [A-B-C-D]\n");

    for(int i = 0; i < ALUNOS; i++){
        printf("%dª Aluno:\n", i + 1);

        for(int j = 0; j < Questoes; j++){

            printf("%dª Questao: ", j + 1);
            scanf(" %c", &RespostaAlunos[i][j]);
            do{
                if(RespostaAlunos[i][j] != 'A' && RespostaAlunos[i][j] != 'B' && RespostaAlunos[i][j] != 'C' && RespostaAlunos[i][j] != 'D'){
                    printf("Opcao Indisponivel!\nDigite Novamente!");
                    scanf(" %c", &RespostaAlunos[i][j]);        
                }
            }while(RespostaAlunos[i][j] != 'A' && RespostaAlunos[i][j] != 'B' && RespostaAlunos[i][j] != 'C' && RespostaAlunos[i][j] != 'D');

        }
    }
}

void VerificaQuestoes(char * Gabarito, char ** RespostaAlunos,int * Notas, int Questoes){//VERIFICA QUAL QUESTÃO ESTA CORRETA COM BASE NO GABARITO
    for(int i = 0; i < ALUNOS; i++){
        for(int j = 0; j < Questoes; j++){
            if(RespostaAlunos[i][j] == Gabarito[j]){
                Notas[i] += 10.0/Questoes;
            }
        }
    }
}

void VerificaAprovacao(int * Notas){//VERIFICA QUAL ALUNO OBTEVE A NOTA PARA APROVAÇÃO

    float Aprovacao = 0, Reprovacao = 0;

    for(int i = 0; i < ALUNOS; i++){
        if(Notas[i] >= 6){
            printf("O Aluno Nª %d Foi Aprovado!\nNota Obtida: %d\n\n", i + 1, Notas[i]);
            Aprovacao++;
        }
        else{
            printf("O Aluno Nª %d Foi Reprovado!\nNota Obtida: %d\n\n", i + 1, Notas[i]);
            Reprovacao++;
        }
    }
    Aprovacao = (Aprovacao/ALUNOS)*100;
    printf("%0.f%% Da Sala Foi Aprovada!", Aprovacao);
    printf("%0.f%% Da Sala Foi Reprovada!", Reprovacao);
}