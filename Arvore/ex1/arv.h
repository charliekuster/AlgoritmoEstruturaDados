#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Arvore{
    int valor;
    struct Arvore *direita;
    struct Arvore *esquerda;
}Arvore;

Arvore *InstArv(int);
void InserirOrdenado(Arvore *, int);
void PrintArv(Arvore, int*, int);
void ArvPrefixo(Arvore, int *, int);
void ArvInfixo(Arvore, int *, int);
void ArvPosfixo(Arvore, int *, int);