#include <stdio.h>
#include <stdlib.h>

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

int main(void){

    FILE * entrada, * saida;
    char nome[20];
    float nota1, nota2, nota3, media;


    entrada = Verificacao("entrada_q3.txt", "r");
    saida = Verificacao("saida_q3.txt", "w");

    while(!feof(entrada)){
        fscanf(entrada, "%20[^\t]\t%f\t%f\t%f", nome, &nota1, &nota2, &nota3);

        media = (nota1 + nota2 + nota3)/3.0;

        if(media >= 7){
            fprintf(saida, "%s\t%.1f\tAprovado", nome, media);
        }
        else{
            fprintf(saida, "%s\t%.1f\tReprovado", nome, media);
        }
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}