#include <stdio.h>
#include <stdlib.h>

int main(void){
    int linhas,colunas, costa = 0;

    printf("Informe Quantas Linhas: ");
    scanf("%d", &linhas);

    printf("Informe Quantas Colunas: ");
    scanf("%d", &colunas);

    char ** matriz = (char**)malloc(linhas * sizeof(char**));
    for(int i = 0; i < linhas;i++){
        matriz[i] = (char*)malloc(colunas*sizeof(char));
    }

    if(matriz == NULL){
        printf("Memoria Insuficiente!\nEncerrando o Programa!");
        exit(1);
    }

    for(int i = 0; i < linhas;i++){//RECEBE LINHA POR LINHA DO MAPA
       scanf("%s", matriz[i]);
    }

    for(int i = 0; i < linhas;i++){
        for(int j = 0; j < colunas; j++){
            //VERIFICA QUANTAS COSTAS EXISTEM NO MAPA
            if((matriz[i][j] == '#')&&((i == 0 || matriz[i-1][j] == '.')||( i == linhas - 1 || matriz[i+1][j] == '.')||(j == 0 || matriz[i][j-1] == ".")||(j == colunas -1 || matriz[i][j+1] == '.'))){
                costa++;
            }
        }
    }
    printf("%d", costa);//IMPRIME QUANTAS COSTAS TEM NA MATRIZ

    //LIBERA A MEMORIA ALOCADA
    for(int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);

    return 0;
    
}