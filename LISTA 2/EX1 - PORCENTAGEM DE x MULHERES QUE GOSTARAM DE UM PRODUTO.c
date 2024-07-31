/*ENTRADA:
    -NUMERO DE PESSOAS
    -SEXO DAS PESSOAS
    -OPNIAO SOBRE O PRODUTO
  SAIDA:
    -PORCENTAGEM DE MULHERES QUE GOSTARAM DO PRODUTO
    -PORCENTAGEM DE HOMENS QUE NAO GOSTARAM DO PRODUTO
*/

#include <stdio.h>
#include <stdlib.h>

char *AlocaVetor(int Pessoas);
void Questionario(char * Sexo, char * Opniao, int Pessoas);
void CalculaPorcentagem(char * Sexo, char * Opniao, int Pessoas);

int main(void){

    int Pessoas;

    printf("Quantas pessoas avaliarao o produto?");
    scanf("%d", &Pessoas);

    char * Sexo = AlocaVetor(Pessoas);//FUNÇÃO QUE ALOCA OS VETORES
    char * Opniao = AlocaVetor(Pessoas);

    Questionario(Sexo, Opniao, Pessoas);//FUNÇÃO QUE OBTEM OS DADOS DAS PESSOAS

    CalculaPorcentagem(Sexo, Opniao, Pessoas);//FUNÇÃO QUE CALCULA A PORCENTAGEM DOS REQUISITOS SUGERIDOS

    free(Sexo);//LIBERANDO AS MEMORIAS DOS VETORES
    free(Opniao);
    return 0;
}

char * AlocaVetor(int Pessoas){//ALOCA OS VETORES
    char * vetor = (char*)malloc(Pessoas * sizeof(char));
    if(vetor == NULL){
        printf("O Vetor nao pode ser alocado!\nEncerrando o programa!");
        exit(1);
    }
    return(vetor);
}

void Questionario(char * Sexo, char * Opniao, int Pessoas){//SOLICITA UM QUESTIONARIO PARA "x" PESSOAS

        for(int i = 0; i < Pessoas; i ++){
        printf("\n%dª Pessoa: \n", i + 1);
        printf("Qual seu Sexo?[M/F]\n");
        scanf(" %c", &Sexo[i]);
        do{
            if(Sexo[i] != 'M' && Sexo[i] != 'F'){
                printf("Sexo Invalido!\nDigite Novamente!");
                scanf(" %c", &Sexo[i]);
            }
        }while(Sexo[i] != 'M' && Sexo[i] != 'F');

        printf("Qual Sua Opniao do Produto?\n[1- Gostou/ 2- Nao Gostou]\n");
        scanf(" %c", &Opniao[i]);
        do{
            if(Opniao[i] != '1' && Opniao[i] != '2'){
                printf("Opcao Invalida!\nDigite Novamente!");
                scanf(" %c", &Opniao[i]);
            }
        }while(Opniao[i] != '1' && Opniao[i] != '2');
    }

}

void CalculaPorcentagem(char * Sexo, char * Opniao, int Pessoas){//CALCULA A PORCENTAGEM DE PESSOAS DO SEXO [MAS] NÃO GOSTARAM
    float PorcentagemFem = 0, PorcentagemMas = 0;                //E A PORCENTAGEM DE PESSOAS DO SEXO [FEM] QUE GOSTARAM DO PRODUTO

    for(int i = 0; i < Pessoas; i++){
        if(Sexo[i] == 'F' && Opniao[i] == '1'){
            PorcentagemFem++;
        }
        if(Sexo[i] == 'M' && Opniao[i] == '2'){
            PorcentagemMas++;
        }
    }

    PorcentagemFem = (PorcentagemFem/Pessoas) * 100;
    PorcentagemMas = (PorcentagemMas/Pessoas) * 100;

    printf("%0.f%% Das Mulheres Gostaram do produto!\n", PorcentagemFem);
    printf("%0.f%% Dos Homens Nao Gostaram do produto!", PorcentagemMas);
}