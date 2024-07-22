#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Arvore{
    char carc;
    struct Arvore *esq;
    struct Arvore *dir;
}Arvore;

Arvore *InstArv(char);
void InsOrd(Arvore*, char);
void PrintArv(Arvore, int *, int *);
void PrintInfixa(Arvore, int *, int *);
void PrintPrefixa(Arvore, int *, int *);
void PrintPosfixo(Arvore, int *, int *);
void Buscar(Arvore, char);