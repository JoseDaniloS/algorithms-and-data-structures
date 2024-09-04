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

int buscar(int valor, Lista * lista){
    int posicao = 0;
    if(lista == NULL){
        printf("Lista Vazia!\n");
        return;
    }
    Lista * count;
    for(count = lista; count != NULL; count = count->prox){
        if(count->info == valor){
            return posicao;
        return;
        }
        posicao++;
    }

    printf("Valor %d nao encontrado!\n", valor);
}

Lista * remove_valor(int valor, Lista * lista){
    Lista * count = lista;
    Lista * ant = NULL;

    //buscando o valor a ser removido
    while(count->info != valor){
        if(count == NULL){
            return NULL;
        }
       ant = count;
       count = count->prox;
    }
    //caso o elemento para remover seja o primeiro
    if(ant == NULL){
        lista = lista->prox;
    }
    //caso o elemento para remover seja o do meio ou final
    else{
        ant->prox = count->prox;
    }
    
    free(count);
    return lista;
}

// Função para inserir um novo valor após um valor específico na lista
Lista * inserir_apos(int valor, int novo_valor, Lista * lista){
    Lista * count;

    Lista * novo = (Lista*)malloc(sizeof(Lista));

    if(novo == NULL){
        exit(1);
    }
    novo->info = novo_valor;

    for(count = lista; count != NULL; count = count->prox){
        if(count->info == valor){
            //valor encontrado, inserindo o novo nó
            novo->prox = count->prox;
            count->prox = novo;
            return lista;
        }
    }
   
   // Se o valor não for encontrado, o novo nó não é inserido
    free(novo);
    return lista;
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

    int posicao = buscar(70, lista);
    printf("esta na posicao: %d\n", posicao);
    posicao = buscar(100, lista);
    printf("esta na posicao: %d\n", posicao);

    lista = remove_valor(50, lista);
    lista = remove_valor(60, lista);

    exibir_lista(lista);

    lista = inserir_apos(70, 65, lista);
    lista = inserir_apos(65, 55, lista);

    exibir_lista(lista);

    return 0;
}