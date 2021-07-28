#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>//biblioteca para uso da funçao toupper
#define qtd 20
#define size 4

typedef struct produtos{
    char nome_produto[50];
    char pais_origem[50];
    int qtd_items;
    char codigo[9];
    char PP[3]; //dois primeiros caracteres do país de origem em Maiúsculo
    char DDD[size];//código de três dígitos variando de 000 a 999 de acordo com a ordem de registro de produtos.
}Produtos;
Produtos produto[qtd];

#endif
