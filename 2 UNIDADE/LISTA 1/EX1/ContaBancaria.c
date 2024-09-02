#include <stdio.h>
#include <stdlib.h>
#include "ContaBancaria.h"
#include <string.h> // para usar o strcpy
struct ContaBancaria{
    char titular[20];
    float saldo;
    int numero;
};

ContaBancaria * Cria_Conta(char * titular, float saldo, int numero){
    ContaBancaria * conta = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    if(conta == NULL){
        printf("Memoria Insuficiente!\n");
    }
    else{
        printf("Conta Criada com Sucesso!\n");
    }
    //Inicializar conta
    conta->numero = numero;
    conta->saldo = saldo;
    strcpy(conta->titular, titular);
    return(conta);
}

void Deposita(ContaBancaria * conta, float deposito){
    conta->saldo += deposito;
    printf("%.2fReais Adicionado a conta!\n", deposito);
}

void Saca(ContaBancaria * conta, float saque){
    if(conta->saldo >= saque){
        conta->saldo -= saque;
        printf("Saque de %.2f Efetuado com Sucesso\n", saque);
    }
    else{
        printf("Valor nao disponivel na conta!\n");
    }
}

void Transfere(ContaBancaria * conta1, ContaBancaria * conta2, float transferencia){
    if(conta1->saldo >= transferencia){
        conta2->saldo += transferencia;
        conta1->saldo -= transferencia;
    }
    else{
        printf("Saldo Invalido!");
    }
}

void Verifica_Saldo(ContaBancaria * conta){
    printf("Saldo Disponivel: %.2f\n", conta->saldo);
}

void DeletaConta(ContaBancaria * conta, ContaBancaria * conta2){
    free(conta);
    free(conta2);
}