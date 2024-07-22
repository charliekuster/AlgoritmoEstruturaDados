#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct{
    char nome[50];
    int idade;
    int lugar;
    int ehvelho;
}Pac;

typedef struct No{
    Pac paciente;
    struct No *prox;
}No;

typedef struct{
    No *prim;
    int tam;
    int quant_velhos;
}List;

void Iniciar(List *);
void AddPac(Pac *);
void Print(List);
void Add(List *, int *, int*, Pac);
void Remover(List *);
void Delete(List *);
void RemoverJovem(List *);
void RemoverVelho(List *);