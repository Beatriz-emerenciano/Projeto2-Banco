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

void Deposito(Cliente * clientes, int numClientes, long long int cpf, float dinheiro){
   int index = -1;
  for(int i = 0; i < numClientes; i++){
    if(clientes[i].cpf == cpf){
      index = i;
      break;
    }
  }

  if(index >=0){
    clientes[index].saldo += dinheiro;
    
     sprintf(clientes[index].extrato,"deposito de %.2f realizado com sucesso! do cliente %s",dinheiro,clientes[index].nome);
    printf("%s,saldo atual: %.2f",clientes[index].extrato,clientes[index].saldo);
    
    /*printf("Deposito  de %.2f realizado com sucesso para o cliente %s, saldo de %.2f.\n ",dinheiro,clientes[index].nome,clientes[index].saldo);*/
  } else {
    printf("Cliente com cpf %lld nao encontrado \n.", cpf);
  }
  
}

//função tranferencia
/*

as variáveis  index origem e index destino sao iniciadas em -1, esses indices indices são usados para rastrear a posição do cliente, é usado um for para percorrer todos os clientes cadastrados onde a váriável numCliente é a quantidade total de clientes, depois há uma verificação  de cpf com um if se o cliente[i].cpf for igual o do cliente origem e o destinário, a variárial indexorigem e indexDestino conterá os indices dos clientes com os cpf correspondem a eles para depois realizar a transferência.

*/

void transferencia(Cliente *clientes, int numClientes, long long int cpfOrigem,long long int cpfDestino,float transferencia){

  int indexOrigem = -1, indexDestino = -1; indexDestino = -1;
  for(int i = 0; i < numClientes; i++){
    if(clientes[i].cpf == cpfOrigem){
      indexOrigem = i;
    }
    if(clientes[i].cpf == cpfDestino){
      indexDestino = i;
    }
  }

  if(indexOrigem >= 0 && indexDestino >= 0){
    if(clientes[indexOrigem].saldo >= transferencia){
      clientes[indexOrigem].saldo -= transferencia;
      clientes[indexDestino].saldo += transferencia;

      // salvando a mensagem no dado extrato da estruct do cliente origem e destino

      sprintf(clientes[indexOrigem].extrato,"Transferencia de %.2f realizada com sucesso para o cliente %s",transferencia,clientes[indexDestino].nome);

      sprintf(clientes[indexDestino].extrato,"Transferencia recebida de %.2f do cliente %s",transferencia,clientes[indexOrigem].nome);

      printf("%s, saldo atual de:%.2f ", clientes[indexOrigem].extrato,clientes[indexOrigem].saldo);

      /*
      printf("Transferencia de %.2f realizada com sucesso do cliente %s para o cliente %s\n",transferencia,clientes[indexOrigem].nome,clientes[indexDestino].nome);*/
    }else{
      printf("Saldo insuficiente para realizar a transferencia\n");
    }
       
    }else{
    printf("Saldo insufuente para realizar a transferencia!\n");
    }
  
}

void funcaoExtrato(Cliente *clientes, int numClientes, long long int cpf,char *senha){

int index = -1;
  for(int i = 0; i < numClientes; i++){
    if(clientes[i].cpf == cpf && strcmp(clientes[i].senha,senha) == 0 ){
      index = i;
    }
  }

  if(index >= 0){
    printf("Extrato do cliente %s\n",clientes[index].nome);
    printf("%s",clientes[index].extrato);
  } else {
    printf("Cliente com cpf ou senha errado!\n");
  }
}

/*Função para salvar os dados do clientes em arquivo binário: essa função rece o vetor clientes e o numero de clientes cadastros(numClientes) e esqueve no arquivo binário*/

void salvar(Cliente *clientes, int numClientes){
    FILE *arquivo = fopen("clientes.bin","wb");
  if(arquivo == NULL){
    printf("Erro ao abrir o arquivo \n");
    return;
  }

  fwrite(clientes, sizeof(Cliente),numClientes,arquivo);
  fclose(arquivo);
}



/* a função carregar, le os dados do arquivo binário e os carrega de volta no vetor de clientes atualizando o numero de clientes cadastrados*/

void carregar(Cliente *clientes,int *numClientes){
  FILE *arquivo = fopen("clientes.bin","rb");
  if(arquivo == NULL){

    printf("arquivo não encontrado!");
    return;
    
  }

  *numClientes  = fread(clientes,sizeof(Cliente),1000, arquivo);
  fclose(arquivo);
  
}




