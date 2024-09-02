#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

//Função para abrir/criar arquivo e retornar este arquivo
FILE * Verificacao(char * nome, char * modo){
    FILE * arquivo = fopen(nome, modo);
    if(arquivo == NULL){
        printf("Can't open the file\n");
        exit(1);
    }
    else{
        printf("File open!\n");
    }

    return arquivo;
}

//Função para alocar um vetor dinamicamente
int * Aloca_Vetor(int tamanho){
    int * vet = (int*)malloc(tamanho * sizeof(int));
    if(vet == NULL){
        printf("Memoria Indisponivel!");
        exit(1);
    }
    return vet;
}

int main(void){

    FILE * entrada = Verificacao("entrada_q2.txt", "r");
    FILE * saida = Verificacao("saida_q2.txt", "w");
    int maior = 0, menor = 100, count = 0;
    float media, elementos = 0;
    int * vet = Aloca_Vetor(TAMANHO);

    while(!feof(entrada)){
        fscanf(entrada, "%d\n", &vet[count]);
        count++;
    }

    for(int i = 0; i < count; i++){
        if(vet[i] > maior){
            maior = vet[i];
        }
        else if(vet[i] < menor){
            menor = vet[i];
        }
        elementos += vet[i];
    }
    
    media = (elementos / TAMANHO);

    fprintf(saida, "menor elemento: %d\nmaior elemento:%d\nmedia dos elementos: %f\n", menor, maior, media);

    fclose(entrada);
    fclose(saida);
    free(vet);

    return 0;
}