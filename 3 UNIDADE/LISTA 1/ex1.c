#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
    int info;
    struct lista * prox;
}Lista;

Lista * inserir_no_inicio(int valor, Lista * lista){
    Lista * inicio = (Lista*)malloc(sizeof(Lista));
    if(inicio == NULL){
        exit(1);
    }
    inicio->info = valor;
    inicio->prox = lista;

    return inicio;
}

Lista * inserir_no_fim(int valor, Lista * lista){
    Lista * fim = (Lista*)malloc(sizeof(Lista));
    fim->info = valor;
    fim->prox = NULL;
    
    if(fim == NULL){
        exit(1);
    }
    
    if(lista == NULL){
        return fim;
    }

    Lista * count;
    for(count = lista; count->prox != NULL; count = count->prox){
        //percorrer a lista ate o final
    }
    count->prox = fim;

    return lista;

}

void exibir_lista(Lista * lista){
    Lista * count;
    for(count = lista; count != NULL; count = count->prox){
        printf("-> %d ", count->info);
    }
    printf("\n");
}

Lista * remover_primeiro(Lista * lista){
    Lista * nlista;
    if(lista == NULL){
        return NULL;
    }
    nlista = lista->prox;
    free(lista);
    return(nlista);
}

int main(void){
    Lista * lista = NULL;
    lista = inserir_no_inicio(10, lista);
    lista = inserir_no_inicio(20, lista);
    lista = inserir_no_inicio(30, lista);
    lista = inserir_no_inicio(40, lista);

    exibir_lista(lista);

    lista = inserir_no_fim(50, lista);
    lista = inserir_no_fim(60, lista);
    lista = inserir_no_fim(70, lista);
    lista = inserir_no_fim(80, lista);

    exibir_lista(lista);

    lista = remover_primeiro(lista);

    exibir_lista(lista);

    return 0;
}