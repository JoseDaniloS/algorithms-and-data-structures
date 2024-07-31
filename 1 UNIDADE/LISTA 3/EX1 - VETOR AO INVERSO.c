/*Entrada:  Tamanho do vetor
            Elementos do vetor
  Saida: Elementos ao inverso do vetor
*/


#include <stdio.h>
#include <stdlib.h>

void PreencheVetor (int * vetor, int tamanho);
void InverteVetor(int * vetor, int tamanho);
int * AlocaVetor(int tamanho);

int main(void){

    int tamanho;
    printf("Digite o Tamanho que deseja no Vetor: ");
    scanf("%d", &tamanho);

    int* vetor = AlocaVetor(tamanho);
    PreencheVetor(vetor, tamanho);

    InverteVetor(vetor, tamanho);

    free(vetor);

    return 0;
}

void PreencheVetor(int * vetor, int tamanho){
//FUNÇÃO QUE SOLICITA OS ELEMENTOS DO VETOR AO USUARIO
    printf("Digite os elementos do vetor:\n");
    for(int count = 0; count < tamanho; count++){
        scanf("%d", &vetor[count]);
    }
}

void InverteVetor(int * vetor, int tamanho){
//FUNÇÃO QUE IMPRIME OS VALORES AO INVERSO DO VETOR
    printf("Valores ao Inverso:\n");
    for(int count = tamanho-1; count >= 0; count--){
        printf("%d ", vetor[count]);
    }
}

int * AlocaVetor(int tamanho){
    //FUNÇÃO QUE ALOCA DINAMICAMENTE O VETOR
    int * vetor = (int*) malloc(tamanho * sizeof(int));

    if(vetor == NULL){
        printf("Nao ha memoria suficiente.");
        exit(1);
    }
    else{
        printf("Vetor alocado com sucesso!\n");
    }
    return(vetor);
}