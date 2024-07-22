#include "list.h"

void Inc(List *lista){
    lista->prim = NULL;
    lista->tam = 0;
    lista->lugar = 0;
    lista->quant_ido = 0;
    return;
}

int ListVazia(List *lista){
    if(lista->prim == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void AddPessoa(Cliente *novo){
    printf("Nome: ");
    fflush(stdin);
    fgets(novo->nome, 50, stdin);
    printf("Idade: ");
    scanf("%d", &novo->idade);
    if(novo->idade >= 60){
        novo->idoso = 1;
    }
    else{ 
        novo->idoso = 0;
    }
    return;
}

void AddCom(List *lista, Cliente novo){
    No *novoNo = (No*)malloc(sizeof(No));
    if(novoNo){
    novoNo->prox = lista->prim;
    lista->prim = novoNo;
    novoNo->novo = novo; 
    lista->tam++;
    lista->lugar++;
    }
    else{
        printf("Erro, ao alocar memoria.\n");
    }
    return;
}

void AddFin(List *lista, Cliente novo){
    No *novoNo = (No*)malloc(sizeof(No));
    if(novoNo){
        No *aux = lista->prim;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novoNo;
        novoNo->prox = NULL;
        novoNo->novo = novo;
        lista->tam++;
        lista->lugar++;
    }
    return;
}

void Remover(List *lista){
    if(ListVazia(lista)){
        printf("Erro, lista ja vazia.\n");
    }
    else{
        No *aux = lista->prim;
        No *aus2 = aux->prox;
        char esc[50];
        fflush(strlen);
        fgets(esc, 50, strlen);
        while(strcmp(esc, aux->novo.nome) );
    }
}

void Print(List lista){
    if(ListVazia(&lista)){
        printf("Erro, lista vazia.\n");
    }
    else{
        No *aux = lista.prim;
        while(aux != NULL){
            printf("Senha = %04d\n", lista.lugar);
            printf("%s", aux->novo.nome);
            printf("%d\n\n", aux->novo.idade);
            aux = aux->prox;
        }
    }
    return;
}








