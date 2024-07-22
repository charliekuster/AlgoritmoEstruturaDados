#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 100

typedef struct{
    char nome[50];
    int idade;
    int idoso;
}Cliente;

typedef struct No{
    Cliente novo;
    struct No *prox;
}No;

typedef struct{
    No *prim;
    int tam;
    int lugar;
    int quant_ido;
}List;

void Inc(List *);
int ListVazia(List *);
void AddPessoa(Cliente *);
void AddCom(List *, Cliente);
void AddFin(List *, Cliente);
void AddEspecifico(List *, Cliente *);
void Print(List);
void RemFin(List *);
void RemCom(List *);
void RemoverTodos(List *);
void Remover(List *);