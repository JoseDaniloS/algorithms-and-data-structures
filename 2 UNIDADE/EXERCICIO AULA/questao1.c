#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 99999

// Função para encontrar o maior elemento usando busca sequencial
int busca_sequencial(int *entrada, int tamanho) {
    int maior = entrada[0];
    for (int index = 1; index < tamanho; index++) {
        if (maior < entrada[index]) {
            maior = entrada[index];
        }
    }
    return maior;
}

// Função de comparação para qsort (ordem crescente)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Função para buscar um elemento em um vetor ordenado usando busca binária
int busca_binaria(int vet[], int valor, int tamanho) {
    int inicio = 0, final = tamanho - 1;
    while (inicio <= final) {
        int meio = inicio + (final - inicio) / 2;
        if (vet[meio] == valor) {
            return vet[meio];
        } else if (vet[meio] < valor) {
            inicio = meio + 1;
        } else {
            final = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    int entrada[TAMANHO];

    // Preenche o vetor com números aleatórios 
    for (int index = 0; index < TAMANHO; index++) {
        entrada[index] = rand();
    }

    // Mede o tempo para busca sequencial
    clock_t tempo_inicial = clock();
    int maior = busca_sequencial(entrada, TAMANHO);
    clock_t tempo_final = clock();
    double tempo_execucao = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC * 1000;
    printf("Maior elemento (busca sequencial): %d \nTempo de execucao: %.6f (ms)\n", maior, tempo_execucao);

    // Ordena o vetor
    qsort(entrada, TAMANHO, sizeof(int), compare);

    // Mede o tempo para busca binária
    clock_t tempo_inicial2 = clock();
    int maior2 = busca_binaria(entrada, maior, TAMANHO);
    clock_t tempo_final2 = clock();
    double tempo_execucao2 = (double)(tempo_final2 - tempo_inicial2) / CLOCKS_PER_SEC * 1000;
    printf("Maior elemento (busca binaria): %d \nTempo de execucao: %.6f (ms)\n", maior2, tempo_execucao2);

    return 0;
}
