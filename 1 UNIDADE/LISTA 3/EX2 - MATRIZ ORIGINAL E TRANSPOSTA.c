#include <stdio.h>
#include <stdlib.h>

/*
ENTRADA:
    -LINHAS E COLUNAS (TAMANHO DA MATRIZ)
    -ELEMENTOS DA MATRIZ(MATRIZ)
SAIDA:
    -IMPRIMIR/MOSTRAR MATRIZ ORIGINAL E TRANSPOSTA
*/

int ** AlocaMatriz(int linhas, int colunas);
void ElementosMatriz(int ** matriz, int linhas, int colunas);

int main(void){

    int linhas, colunas;

    printf("Digite a quantidade de linhas e colunas da matriz:");
    scanf("%d %d", &linhas, &colunas);

    int ** matriz  = AlocaMatriz(linhas,colunas);//FUNÇÃO PARA ALOCAR MATRIZ

    ElementosMatriz(matriz, linhas, colunas);//FUNÇÃO PARA SOLICITAR OS ELEMENTOS DA MATRIZ

    MatrizOriginal(matriz, linhas, colunas);//FUNÇÃO QUE EXIBE A MATRIZ ORIGINAL

    MatrizTransposta(matriz, linhas, colunas);//FUNÇÃO QUE EXIBE A MATRIZ TRANSPOSTA

    for(int linha = 0; linha < linhas; linha++){
        free(matriz[linha]);//LIBERANDO A MEMORIA DA MATRIZ ALOCADA
    }
    free(matriz);
    
    return 0;
}

int ** AlocaMatriz(int linhas, int colunas){
    
    int ** matriz = (int**)malloc(linhas * sizeof(int));
    if(matriz == NULL){
        exit(1);
    }

    for(int linha = 0; linha < linhas; linha++){

        matriz[linha] = (int*)malloc(colunas * sizeof(int));
        if(matriz[linha] == NULL){
        exit(1);
        }
    }

    return(matriz);
}

void ElementosMatriz(int ** matriz, int linhas, int colunas){
    printf("Digite os elementos da matriz: ");
    for(int linha = 0; linha < linhas; linha++){
        for(int coluna = 0; coluna < colunas; coluna++){
            scanf("%d", &matriz[linha][coluna]);
        }
    }
}

void MatrizOriginal(int ** matriz, int linhas, int colunas){
    printf("MATRIZ ORIGINAL: ");
    for(int linha = 0; linha < linhas; linha++){
        printf("\n");
        for(int coluna = 0; coluna < colunas; coluna++){
            printf("[%d] ", matriz[linha][coluna]);
        }
    }
}

void MatrizTransposta(int ** matriz, int linhas, int colunas){
    printf("\n\nMATRIZ TRANSPOSTA:");
    for(int linha = 0; linha < linhas; linha++){
        printf("\n");
        for(int coluna = 0; coluna < colunas; coluna++){
            printf("[%d] ", matriz[coluna][linha]);
        }
    }
}