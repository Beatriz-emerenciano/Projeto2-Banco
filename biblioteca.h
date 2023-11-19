//
// Created by Beatriz on 02/10/2023.
//

#ifndef PROJETOBANCO_BIBLIOTECA_H
#define PROJETOBANCO_BIBLIOTECA_H

//funções


typedef struct   {
    char nome[100];
    long long int cpf;
    char conta[20];
    char senha[10];
    float saldo;
    char extrato[1000];

} Cliente;

void menu();
void cadastro(Cliente *cliente);
void listarClientes(Cliente *clientes, int numClientes);
void limparBufferEntrada();
void apagarCliente(Cliente *clientes, int *numCliente, long long int cpf);
void Debito(Cliente *clientes, int numClientes, long long int cpf, char *senha, float debito);
void Deposito(Cliente * clientes, int numClientes, long long int cpf, float dinheiro);
void transferencia(Cliente *clientes, int numClientes, long long int cpfOrigem,long long int cpfDestino,float transferencia);
void funcaoExtrato(Cliente *clientes, int numClientes, long long int cpf,char *senha);
void salvar(Cliente *clientes, int numClientes);
void carregar(Cliente *clientes,int *numClientes);






















#endif //PROJETOBANCO_BIBLIOTECA_H
