#include <stdio.h>
#include "biblioteca.h"
#include "stdbool.h"
#include <string.h>
int main() {

    Cliente clientes[1000]; // aqui é criado um vetor para armazenar todos os clientes cadastrados
    int numClientes = 0; // essa variavel serve para armazenar e controlar  o número de clientes cadastrados
    int opcao;


    printf("----------Ola, bem vindo ao banco Quem Poupa Tem!----------\n");

    bool menuexibido = false;

    do {

        //if(!menuexibido){
        menu();
        // menuexibido = true;

        // }


        //menu();
        printf("Digite uma opcao\n");
        scanf("%d", &opcao);
        limparBufferEntrada();
        switch (opcao) {
            case 1:
                if(numClientes < 100){
                    cadastro(&clientes[numClientes]);
                    numClientes++;
                }

                break;

            case 2:
                listarClientes(clientes, numClientes);
                break;

            case 3:
          if(numClientes > 0){
            long long int cpf;
            printf("Digite o cliente o CPF do cliente que deseja apagar");
            scanf("%lld",&cpf);
            limparBufferEntrada();
            apagarCliente(clientes,&numClientes,cpf);
          }else{
            printf("Cliente não encontado!");
          }
          break;    

           case 4:

          if(numClientes > 0){
            long long int cpf;
            char senha[10];
            float debito;
            printf("Digite o CPF do cliente:\n");
            scanf("%lld", &cpf);
            printf("Digite a senha:\n ");
            limparBufferEntrada();
            fgets(senha,sizeof(senha),stdin);
            senha[strcspn(senha, "\n")] = '\0';
            printf("Digite o valor de debito: \n");
            scanf("%f",&debito);
            limparBufferEntrada();
            Debito(clientes,numClientes,cpf,senha,debito);
          } else{
            printf("Nenhum cliente cadastrado!");
          }
          break;
          case 5:

          if(numClientes > 0){
            long long int cpf;
            float dinheiro;
            printf("Digite o cpf:");
            scanf("%lld",&cpf);
            printf("Digite o valor do Deposito: ");
            scanf("%f",&dinheiro);
            limparBufferEntrada();
            Deposito(clientes,numClientes,cpf,dinheiro);
          }   else{
            printf("Cliente nao cadastrado");
          }       
            break;
          case 6:
          if(numClientes > 1){
            long long int cpfOrigem, cpfDestino;
            float transfere;
            printf("Digite o CPF do cliente remetente: ");
            scanf("%lld",&cpfOrigem);
            printf("Digite o CPF do cliente destinario: ");
            scanf("%lld",&cpfDestino);
            printf("Digite o valor da transferencia: ");
            scanf("%f",&transfere);
            limparBufferEntrada();
      transferencia(clientes,numClientes,cpfOrigem,cpfDestino,transfere);
          } else{
            printf("não foi possivel realizar a transferencia, pois é necessário dois clientes");
          }
            break;



            case 0:
                printf("obrigada por usar o sistema Quem Poupa Tem! ");



        }





    }while (opcao!= 0);

    return 0;

}
