#include <stdio.h>

typedef enum mes{
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
}Mes_Ano;

typedef struct data{
    int dia;
    Mes_Ano mes;
    int ano;
}Data;
 
int main(void){
    Data datas;
    printf("Informe o Dia: ");
    scanf("%d", &datas.dia);

    printf("Informe o Mes: ");
    scanf("%d", &datas.mes);

    printf("Informe o Ano: ");
    scanf("%d", &datas.ano);

    printf("%d/%d/%d",datas.dia ,datas.mes, datas.ano);
}