#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extern.h"

typedef struct{
    char nome[TAMC];
    int preco;
    int cod; 
}Item;

typedef struct No{
    Item prod;
    struct No *prox;
}No;

typedef struct{
    No *prim;
    int tam;
}List;

void Ini(List *);

void Get(Item *);

void Menu();

void LidarMenu(int, List *, Item *);

void Print(List);

void AddCom(List *, Item);

void AddFin(List *, Item);

void RemoverPrim(List *);

void RemoverEspc(List *);

void RemoverFin(List *);




