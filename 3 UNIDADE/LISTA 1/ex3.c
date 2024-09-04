#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
    int info;
    struct lista * prox;
}Lista;

Lista * inserir_no_inicio(int valor, Lista * lista){
    Lista * novo = (Lista*)malloc(sizeof(Lista));
    if(novo == NULL){
        exit(1);
    }

    novo->info = valor;

    if(lista == NULL){
        novo->prox = novo; //aponta para si mesmo, formando um ciclo
        return novo;
    }

    Lista * count = lista;

    while(count->prox != lista){
        count = count->prox;
    }

    count->prox = novo;
    novo->prox = lista;//apontando para o primeiro nó, formando um ciclo
    return novo;
}

Lista * inserir_no_fim(int valor, Lista * lista){
        Lista * novo = (Lista*)malloc(sizeof(Lista));
    if(novo == NULL){
        exit(1);
    }

    novo->info = valor;

    if(lista == NULL){
        novo->prox = novo; //aponta para si mesmo, formando um ciclo
        return novo;
    }

    Lista * count = lista;

    while(count->prox != lista){
        count = count->prox;
    }

    count->prox = novo;
    novo->prox = lista;//apontando para o primeiro nó, formando um ciclo
    return lista;
}

void exibir_lista(Lista * lista){
    Lista * count = lista;
    do{
        printf("-> %d ", count->info);
        count = count->prox;
    }while(count != lista);
    printf("\n");
}

int main(void){
    Lista * lista = NULL;

    lista = inserir_no_inicio(10, lista);
    lista = inserir_no_inicio(20, lista);
    lista = inserir_no_inicio(30, lista);

    exibir_lista(lista);

    lista = inserir_no_fim(40, lista);
    lista = inserir_no_fim(50, lista);
    lista = inserir_no_fim(60, lista);

    exibir_lista(lista);

    return 0;
}