#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arvore{
    char letra;
    struct Arvore* esq;
    struct Arvore* dir;
}Arvore;

typedef struct No{
    Arvore arv;
    struct No *prox;
}No;

typedef struct Fila{
    struct No *fim;
    int tam;
}Fila;

int EncontrarPrecedencia(char *);
char *ExpreEsq(char *, int);
char* ExpreDir(char *, int);
Arvore *IniciarArvore();
Arvore *InstArv(char*);
No *InstNo(Arvore);
Fila *InstFila(No *);
void InserirFila(Fila *, No*);
void Remove(Fila *);
void PrintNivel(Fila *);
int DefinePreced(char);
char *RemoveParenteses(char*);
char* RemoveEspace(char*);