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




            case 0:
                printf("obrigada por usar o sistema Quem Poupa Tem! ");



        }





    }while (opcao!= 0);

    return 0;

}
