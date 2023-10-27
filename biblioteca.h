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
} Cliente;

void menu();
void cadastro(Cliente *cliente);





#endif //PROJETOBANCO_BIBLIOTECA_H