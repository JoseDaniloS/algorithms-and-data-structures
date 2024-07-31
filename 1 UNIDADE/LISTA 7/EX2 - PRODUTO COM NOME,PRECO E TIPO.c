#include <stdio.h>

typedef enum tipoproduto {
    ALIMENTO = 1,
    BEBIDA,
    ELETRONICOS
}TipoProduto;

typedef union tipos{
    TipoProduto tipo;
}Tipos;

typedef struct produto{
    char nome[20];
    float preco;
    Tipos tipos;
}Produto;

void Preenche_Produto(Produto * produtos, int * opcao){
    
    printf("Informe o Nome do Produto: ");
    scanf(" %[^\n]", produtos->nome);

    printf("Informe o Preco do produto: ");
    scanf("%f", &produtos->preco);

    printf("Informe o Tipo do Produto:\n1- Alimento\n2- Bebida\n3-Eletronicos\n");
    scanf("%d", opcao);
    produtos->tipos.tipo = *opcao;
}

void Imprime_Produto(Produto * produtos){
        printf("NOME DO PRODUTO: %s\n", produtos->nome);
    printf("PRECO DO PRODUTO: %.2f\n", produtos->preco);

    switch (produtos->tipos.tipo)
    {
    case ALIMENTO:
        printf("Tipo: Alimento");
        break;
    case BEBIDA:
        printf("Tipo: Bebida");
        break;
    case ELETRONICOS:
        printf("Tipo: Eletronicos");        
    
    default:
    printf("Tipo: Tipo Invalido!");
        break;
    }
}

int main(void){

    Produto  produtos;
    int opcao;

    Preenche_Produto(&produtos, &opcao);
    Imprime_Produto(&produtos);

    return 0;
}

