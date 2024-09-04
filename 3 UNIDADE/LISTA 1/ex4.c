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

int buscar(int valor, Lista * lista){
    Lista * count = lista;
    int posicao = 0;
    do{
        if(count->info == valor){
            return posicao;
        }
        posicao++;
    }while(count != lista);
    printf("Posicao nao encontrada!\n");
}

// Função para remover o primeiro nó
Lista* remover_primeiro(Lista* lista) {
    if (lista == NULL) {
        printf("Lista vazia, nada a remover.\n");
        return NULL;
    }

    Lista* ultimo = lista;
    // Encontrar o último nó
    while (ultimo->prox != lista) {
        ultimo = ultimo->prox;
    }

    if (lista == lista->prox) { // Lista com um único elemento
        free(lista);
        return NULL;
    } else {
        Lista* novo_inicio = lista->prox;
        ultimo->prox = novo_inicio;
        free(lista);
        return novo_inicio;
    }
}

// Função para remover o último nó
Lista* remover_ultimo(Lista* lista) {
    if (lista == NULL) {
        printf("Lista vazia, nada a remover.\n");
        return NULL;
    }

    Lista* atual = lista;
    Lista* anterior = NULL;

    // Percorrer a lista para encontrar o penúltimo nó
    while (atual->prox != lista) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == lista) { // Lista com um único elemento
        free(lista);
        return NULL;
    } else {
        anterior->prox = lista;
        free(atual);
        return lista;
    }
}

// Função para remover um nó intermediário
Lista* remover_valor(int valor, Lista* lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return NULL;
    }

    Lista* atual = lista;
    Lista* anterior = NULL;

    do {
        if (atual->info == valor) {
            if (anterior == NULL) {
                    //remover o primeiro nó
                return remover_primeiro(lista);
            } 
            else {
                anterior->prox = atual->prox;
                if (atual->prox == lista) {
                    //remover o último nó
                    return remover_ultimo(lista);
                }
                free(atual);
                return lista;
            }
        }

        anterior = atual;
        atual = atual->prox;
    } while (atual != lista);

    printf("Valor %d nao encontrado na lista.\n", valor);
    return lista;
}

int main(void){
    Lista * lista = NULL;

    lista = inserir_no_inicio(10, lista);
    lista = inserir_no_inicio(20, lista);
    lista = inserir_no_inicio(30, lista);

    printf("Inseridos no Inicio:\n");
    exibir_lista(lista);

    lista = inserir_no_fim(40, lista);
    lista = inserir_no_fim(50, lista);
    lista = inserir_no_fim(60, lista);

    printf("Inseridos no Final: \n");
    exibir_lista(lista);

    
    lista = remover_valor(20, lista);
    printf("Lista apos remover 20:\n");
    exibir_lista(lista);

    lista = remover_primeiro(lista);
    printf("Lista apos remover o primeiro no:\n");
    exibir_lista(lista);

    lista = remover_ultimo(lista);
    printf("Lista apos remover o ultimo no:\n");
    exibir_lista(lista);

    return 0;
}