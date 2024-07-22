# ifndef _LISTA_H
# define _LISTA_H

typedef struct{

    char nome[30];
    int ra;
    int frequencia;
    float notas[3];

}Item;

typedef struct no{

    Item item;
    struct no* proximoNo;

}No;

typedef struct{

    No* inicioLista;
    No* fimLista;
    int tamanhoLista;

}Lista;

No* R_Final(Lista*);
int ReceberRA();
void InserirMeioLista(Lista*);
void I_fim(Lista*);
No* R_inicio(Lista*);
No* R_Meio(Lista*, int);
No* RemoverPeloRA(Lista*);
void I_lista(Lista**);
int Menu();
bool Void_L(Lista*);
void Print(Lista*);
Item Get();
void I_Inicio(Lista*);
int Get_P(Lista*);

# endif