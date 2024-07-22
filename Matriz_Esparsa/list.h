#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char nome;
    int preço;
}Prod;

typedef struct No{
    int pos;
    Prod produto;
    struct No *proximo;
}No;

typedef struct{
    No *prim;
}List;