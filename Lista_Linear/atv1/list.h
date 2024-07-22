#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10

typedef struct{
    char nome[30];
    int chave;
    float preco;
}No;

typedef struct{
    No prod[SIZE];
    int prim;
    int ult;
}Lista;

//função pra iniciar a lista
void Inic(Lista*);

//funcão para printar
void Print(Lista*);

//função para inserir no final 
void Get_F(Lista*);

//função para remover do final 
void Rem_F(Lista*);

//função para remover do comeco 
void Rem_C(Lista*);

//função para adicionar em uma posicao especifica
void Add_Pos(Lista*);

//função para remover de uma posicao especifica
void Ret_Pos(Lista*);

//função para retirar de uma posicao especifica
void Ret_Esp(Lista*, int x);