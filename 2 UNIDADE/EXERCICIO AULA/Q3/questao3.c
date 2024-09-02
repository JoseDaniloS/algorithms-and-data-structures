#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char nome[20];
    int idade;
    float nota1, nota2, nota3, media;
}Aluno;

FILE *Verificacao(char *nome, char *modo) {
    FILE *arquivo = fopen(nome, modo);
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo");
        exit(1);
    } else {
        printf("Arquivo aberto!\n");
    }
    return arquivo;
}

int contarLinhas(FILE *arquivo) {
    char caracter;
    int linhas = 0;
    while ((caracter = fgetc(arquivo)) != EOF) {
        if (caracter == '\n') {
            linhas++;
        }
    }
    fseek(arquivo, 0, SEEK_SET);  // Volta o ponteiro para o início do arquivo
    return linhas;
}

Aluno *vetorAlunos(int linhas) {
    Aluno *alunos = (Aluno *)malloc(linhas * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Memoria Insuficiente!");
        exit(1);
    }
    return alunos;
}

void CalculaMedia(Aluno * alunos, FILE * arquivo, int linhas){
    for(int i = 0; i < linhas;i ++){
        fscanf(arquivo, "%[^,],%d,%f,%f,%f\n", alunos[i].nome, &alunos[i].idade, &alunos[i].nota1, &alunos[i].nota2, &alunos[i].nota3);
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
    }
}

int comparaAlunos(const void * a, const void * b){
    float mediaA = ((Aluno*)a)->media;
    float mediaB = ((Aluno*)b)->media;
    if(mediaA < mediaB){
        return 1;
    }
    if(mediaA > mediaB){
        return -1;
    }
    return 0;
}

void ExibeAlunos(Aluno * alunos, int linhas){
    for(int i = 0; i < linhas; i++){
        printf("Nome:%s Idade:%d Media:%.1f\n", alunos[i].nome, alunos[i].idade, alunos[i].media);
    }
}

void ArmazenaAlunos(FILE * saida, int linhas, Aluno * alunos){
    for(int i = 0; i < linhas; i++){
        fprintf(saida, "%s\t%.1f\n", alunos[i].nome, alunos[i].media);
    }
}

int main(void){
    FILE * arquivo = Verificacao("estudantes.txt","r");
    FILE * saida = Verificacao("resultados.txt","w");
    int linhas = contarLinhas(arquivo);
    Aluno * alunos = vetorAlunos(linhas);
    CalculaMedia(alunos, arquivo, linhas);
    qsort(alunos,linhas, sizeof(Aluno), comparaAlunos);
    ExibeAlunos(alunos, linhas);
    ArmazenaAlunos(saida, linhas, alunos);
    fclose(saida);
    fclose(arquivo);
    free(alunos);

    return 0;
}