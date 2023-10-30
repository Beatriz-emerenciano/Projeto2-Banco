//
// Created by Beatriz on 02/10/2023.
//

#include "biblioteca.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


Cliente listaClientes[100];
int tamanho = 0; /// variem para mante ro controle de clientes


void menu(){
    printf("\nDigite a operacao que deseja realizar:\n");
    printf("1- Cadastrar Cliente\n");
    printf("2- Listar cliente\n");
    printf("3- apagar Clientes\n");
    printf("4- Debito\n");
    printf("5- Deposito\n");
    printf("6- trasnferencia\n");
    printf("7- Extrato\n");
}

//função para limpar o buffer de entrada
void limparBufferEntrada(){
  int c;
  while((c = getchar()) != '\n' && c != EOF ){}
 
    
    }


// função cadastro

void cadastro(Cliente *cliente){

    printf("Digite o nome cliente: ");
    fgets(cliente->nome, sizeof(cliente->nome),stdin); 
    cliente->nome[strcspn(cliente->nome, "\n")] = '\0';
   

    printf("Digite o cpf:");
    scanf("%lld",&cliente->cpf);
    printf("cpf lido: %lld\n",cliente->cpf); //linha para debug
    limparBufferEntrada();

    printf("Digite o tipo de conta:");
    fgets(cliente->conta, sizeof(cliente->conta),stdin);
     cliente->conta[strcspn(cliente->conta, "\n")] = '\0';

    printf("Crie uma senha: ");
    fgets(cliente->senha, sizeof(cliente->senha),stdin);
     cliente->senha[strcspn(cliente->senha, "\n")] = '\0';

    printf("Saldo inicial: ");
    scanf("%f",&cliente->saldo);
    limparBufferEntrada();

   
  
}
void listarClientes(Cliente *clientes, int numClientes){
    printf("\nClientes cadastrados:\n");
    for(int i = 0; i < numClientes; i++){
        printf("Cliente %d\n", i+1);
        printf("Nome: %s\n",clientes[i].nome);
        printf("Cpf:  %lld\n",clientes[i].cpf);
        printf("Conta: %s \n",clientes[i].conta);
        printf("Senha: %s \n", clientes[i].senha);
        printf("Saldo: %.2f \n",clientes[i].saldo);
        printf("---------------------------------");

    }
}

 /*a função apagar cliente recebe como argumento uma matriz de clientes, o numero total de clientes e o cpf do cliente para apagar, ela inicializa a variável index -1 que será usada para armazenar a posição do cliente no vetor*/

void apagarCliente(Cliente *clientes, int *numClientes, long long int cpf){
  int index = -1;
  for(int i = 0; i <*numClientes; i++){
    if (clientes[i].cpf == cpf) {
      index = i;
      break;
    }
  }
  if(index >= 0){
    for(int i = index; i < *numClientes -1; i++){
      clientes[i] = clientes[ i + 1];
    }

    (*numClientes)--;
    printf("Cliente apagado com sucesso!\n");
  }else {
    printf("Cliente com cpf %lld não encontrado\n",cpf);
  }
  
}

/* a função débito inicializa como index -1 para armazenar a pocição do cliente e usala no código, se estiver validado o cpf e a senha, será descontaod do seu saldo o valor junto com o juros*/
void Debito(Cliente *clientes, int numClientes, long long int cpf, char *senha, float debito){
  int index = -1;
  for(int i = 0; i < numClientes; i++){
    if(clientes[i].cpf == cpf && strcmp(clientes[i].senha,senha) == 0){
      index = i;
      break;
    }
    
  }
  if(index >= 0){
   //verifica o tipo da conta do cliente para aplicar o desconto
    if(strcmp(clientes[index].conta,"corrente") == 0 ){
      float tarifa = 0.05;
      float valor = (debito * tarifa);
      float total = valor + debito;
      

      //verificando se há saldo negativo
      if (clientes[index].saldo - debito >=-1000){
          clientes[index].saldo -= total;

        sprintf(clientes[index].extrato,"Debito de %.2f,tarifa de: %.2f realizado com sucesso! do cliente %s",total,tarifa,clientes[index].nome);

        printf("%s, saldo atual: %.2f",clientes[index].extrato,clientes[index].saldo);


        
        /* printf("Debito de %.2f realizado com sucesso para o cliente %s (conta corrente), Saldo de %.2f.\n",total,clientes[index].nome,clientes[index].saldo);
        */
      }else {
    printf("Operação invalida!\n");
      }
  }else if (strcmp(clientes[index].conta,"plus") == 0){

      // desconta da conta plus
      float tarifa = 0.03;
      float valor = (debito * tarifa);
      float total = valor + debito;
       

      // verifica se ha saldo negativo
      if(clientes[index].saldo - debito >= -5000){
        clientes[index].saldo -= debito; 

        sprintf(clientes[index].extrato,"Debito de %.2f, tarifa: %.2f realizado com sucesso! do cliente %s",total,tarifa,clientes[index].nome);

        printf("%s, saldo atual: %.2f",clientes[index].extrato,clientes[index].saldo);
        
       /* printf("Debito %.2f realizado com sucesso para cliente %s (conta plus).\n ",debito,clientes[index].nome);*/
        
      } else{
        printf("Operacao invalida");
      }
    
  } else{
      printf("Cliente com CPF ou senha invalidos!\n");
  }
}

}

