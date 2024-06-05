#include <stdio.h> // printf, scanf
#include <stdlib.h>// malloc, exit, free

//FUNÇÃO QUE SOLICITA OS VALORES DE UM VETOR
void ler_vetor(float *vetor, int tamanho){

    int x;

    printf("Digite os valores para o vetor!\n");
    for(x = 0; x < tamanho; x++){
        printf("Digite o %d Valor: ", x +1);
        scanf("%f", &vetor[x]);
    }

}
//FUNÇÃO QUE IMPRIME OS VALORES DE UM VETOR
void imprimir_vetor(float *vetor, int tamanho){

    int x;

    for(x = 0; x < tamanho; x++){
        printf("%.2f ", vetor[x]);
    }
}

//FUNÇÃO QUE CRIA UM VETOR
float * cria_vetor(int tamanho){

    float *vetor = (float*) calloc(tamanho , sizeof(float));

    //VERIFICANDO SE TEM ESPAÇO LIVRE NA MEMORIA DO COMPUTADOR
    if(vetor == NULL){
        printf("Nao tem Memoria Suficiente.\n Encerrando o Programa.");
        exit(1);
    }
    else{
        printf("Vetor Alocado!\n");
    }

    return vetor;
}

//FUNÇÃO PRINCIPAL
int main(void){

    int tamanho = 5;

    //CHAMANDO A FUNÇÃO cria_vetor()
    float * vetor = cria_vetor(tamanho);
    
    //CHAMANDO A FUNÇÃO ler_vetor()
    ler_vetor(vetor, tamanho);

    //CHAMANDO A FUNÇÃO imprimir_vetor()
    imprimir_vetor(vetor, tamanho);

    //LIBERA A MEMORIA DO VETOR
    free(vetor);

    return 0;
}