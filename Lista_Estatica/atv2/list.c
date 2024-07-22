#include "list.h"

void Ini(List *lista){
    lista->tam = 0;
    lista->prim = NULL;
}

void Get(Item *prod){
    printf("\nNome do produto: ");
    fflush(stdin);
    fgets(prod->nome, TAMC, stdin);
    printf("Preço: ");
    scanf("%d", &prod->preco); 
    printf("codigo: ");
    scanf("%d", &prod->cod);  
}

void Print(List lista){
    No *aux;
    aux = lista.prim;
    if(aux == NULL){
        printf("\nLista vazia\n");
    }
    else{
        while(aux != NULL){
            printf("Nome: %s", aux->prod.nome);
            printf("Preço: %d\n",aux->prod.preco);
            printf("codigo: %d\n\n", aux->prod.cod);
            aux = aux->prox;
        }
    }
}

void AddCom(List *lista, Item prod){
    No *novoNo = (No*)malloc(sizeof(No));
    if(novoNo){
        novoNo->prox =  lista->prim;
        lista->prim = novoNo;
        novoNo->prod = prod;
        lista->tam++;
        printf("\nProduto registrado\n");
    }
    else{
        printf("\nErro ao alocar memoria\n");
    }
    return;
}

void AddFin(List *lista, Item prod){
    No *novoNo = (No*)malloc(sizeof(No));
    No *aux;
    if(novoNo){
        aux = lista->prim;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novoNo;
        novoNo->prod = prod; 
        printf("\nProduto registrado\n");
        lista->tam++;
    }
    else{
        printf("\nErro ao alocar memoria\n");
    }
    return;    
}

void RemoverPrim(List *lista){
    No *aux;
    if(lista->prim == NULL){
        printf("\nf no chat n foi dessa vez\n");
    }
    else{
        aux = lista->prim;
        lista->prim = lista->prim->prox;
        lista->tam--;
        printf("\n Removido com sucesso");
    }    
}

void RemoverFin(List *lista){
    No *aux = lista->prim;
    No *aux2 = lista->prim->prox;
    if(lista->prim == NULL){
        printf("\nf no chat n foi dessa vez\n");
    }
    else{
        while(aux2->prox != NULL){
            aux = aux->prox;
            aux2 = aux2->prox;
        }
        free(aux2);
        aux->prox = NULL;
        printf("\n Removido com sucesso");
    }
}

void RemoverEspc(List *lista){
    int esc;
    No *aux = lista->prim; 
    No *aux2 = aux->prox;
    scanf("%d", &esc);
    if(lista->prim == NULL){

    }
    else{
        while(aux2->prod.cod != esc){
            aux = aux->prox;
            aux2 = aux2->prox;
        }
        printf("cod aux = %d\n", aux->prod.cod);
        printf("cod aux2 = %d\n", aux2->prod.cod);
        aux->prox = aux2->prox;
        free(aux2);
        printf("\n Removido com sucesso");
    }
}
