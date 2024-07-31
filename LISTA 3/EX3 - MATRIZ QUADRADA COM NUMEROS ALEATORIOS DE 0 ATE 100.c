/*ENTRADA:
    -TAMANHO DA MATRIZ
  SAIDA:
    -NUMEROS ALEATORIOS DE 1 A 100
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ** AlocaMatriz(int colinhas);
void AleatorizaMatriz(int ** matriz, int colinhas);
void ExibeMatriz(int ** matriz, int colinhas);

int main(void){

    int colinhas;

    //SOLICITANDO O TAMANHO DA MATRIZ
    printf("MATRIZ QUADRADA, DIGITE O NUMERO DE COLUNAS E MATRIZES: ");
    scanf("%d", &colinhas);

    //ALOCANDO A MATRIZ DINAMICAMENTE
    int ** matriz = AlocaMatriz(colinhas);

    //ALEATORIZANDO OS NUMEROS DE 1 A 100 DENTRO DA MATRIZ
    AleatorizaMatriz(matriz, colinhas);

    //EXIBINDO OS ELEMENTOS DA MATRIZ
    ExibeMatriz(matriz, colinhas);

    return 0;
}

int ** AlocaMatriz(int colinhas){
    int ** matriz = (int**)malloc(colinhas * sizeof(int));
        for(int j = 0; j < colinhas; j++){
            matriz[j] = (int*)malloc(colinhas * sizeof(int));
        }
    return(matriz);
}

void AleatorizaMatriz(int ** matriz, int colinhas){
    for(int i = 0; i < colinhas; i++){
        for(int j = 0; j < colinhas; j++){
            matriz[i][j] = rand() % 100;
        }
    }
}

void ExibeMatriz(int ** matriz, int colinhas){
    for(int i = 0; i < colinhas; i++){
        printf("\n");
        for(int j = 0; j < colinhas; j++){
            printf("[%d]", matriz[i][j]);
        }
    }
}