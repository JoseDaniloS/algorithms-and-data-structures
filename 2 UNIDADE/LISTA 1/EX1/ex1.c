#include "ContaBancaria.h"
#include <stdio.h>

int main(void){

    ContaBancaria * conta = Cria_Conta("Danilo",550.00,20041223);

    Deposita(conta, 100.00);

    Saca(conta, 50.00);

    ContaBancaria * conta2 = Cria_Conta("Alice",200.00,10005);
    Transfere(conta, conta2, 300.00);

    Verifica_Saldo(conta);
    Verifica_Saldo(conta2);

    DeletaConta(conta, conta2);

    return 0;
}