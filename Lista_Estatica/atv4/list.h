#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 100

typedef struct{
    char nome[50];
    int idade;
    int lugar;
}Cliente;

typedef struct{
    Cliente Pessoa[TAM];
    int prim;
    int ult;
}List;

void Inc(List *);
int ListVazia(List *);
int ListaCheia(List *);
void AddPessoa(Cliente *);
void AddFin(List *, Cliente);
void AddEspecifico(List *, Cliente *);
void Print(List);
void RemFin(List *);
void RemCom(List *);
void RemoverTodos(List *);
void Remover(List *);




