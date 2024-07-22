#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int cont;
    struct No *esq, *dir;
}No;

typedef struct{
    No *raiz;
}Arv;

//funcoes arvores
void IncArv(Arv *);
void ArvVazia(Arv);
void Instaciar(Arv *);
void PrintArv(Arv, int);
