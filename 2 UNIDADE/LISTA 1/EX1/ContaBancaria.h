

typedef struct ContaBancaria ContaBancaria;

/*Função que aloca memoria para uma struct conta e retorna seu endereço
Parms:
    char * titular: nome do titular a conta
    float saldo: saldo disponivel na conta
    int numero:  número da conta
*/
ContaBancaria * Cria_Conta(char * titular, float saldo, int numero);

/*Função que simula a operação de deposita
Parms: 
    ContaBancaria * conta: representa conta bancaria
    float deposito: saldo para ser adicionado na conta
*/
void Deposita(ContaBancaria * conta, float deposito);

/*Função que simula a operação de saque
Parms:
    ContaBancaria * conta: representa conta bancaria
    float saque: saldo a ser retirado da conta
*/
void Saca(ContaBancaria * conta, float saque);

/*Funçao que simula uma operação de Transferencia
Parms:
    ContaBancaria * conta: representa conta bancaria 1
    ContaBancaria * conta2: representa conta bancaria 2
    float transferencia: representa o valor que conta1 vai transferir para conta2
*/
void Transfere(ContaBancaria * conta1, ContaBancaria * conta2, float transferencia);

/*Função que simula uma operação de verificar saldo disponivel na conta
Parms:
    ContaBancaria * conta: representa conta bancaria
*/
void Verifica_Saldo(ContaBancaria * conta);

/*Função que simula uma operação de deletar conta
Parms:
    ContaBancaria * conta: representa conta bancaria
*/
void DeletaConta(ContaBancaria * conta, ContaBancaria * conta2);