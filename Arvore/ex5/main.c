#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arvore{
    int valor;
    struct Arvore *dir;
    struct Arvore *esq;
}Arvore;

typedef struct No{
    struct Arvore arv;
    struct No *prox;
}No;

typedef struct Fila{
    int tam;
    struct No *fim;
}Fila;

Arvore *InstArv(int i){
    Arvore *novaArv;
    novaArv = (Arvore*)malloc(sizeof(Arvore));
    novaArv->valor = i;
    novaArv->dir = NULL;
    novaArv->esq = NULL;
    return novaArv;
}

No *InstNo(Arvore arv){
    No* novoItem = (No*) malloc(sizeof(No));
    novoItem->arv = arv;
    novoItem->prox = NULL;
    return novoItem;
}

Fila *InstFila(No *no){
    Fila *novaFila;
    novaFila = (Fila*)malloc(sizeof(Fila)); 
    novaFila->fim = no;
    novaFila->tam = 1;
    return novaFila;
}

void Inserir_fim(Fila *fila, No *no){
    no->prox = fila->fim;
    fila->fim = no;
    fila->tam++;
    return;
}

void RemoverFila(Fila *fila){
    if(fila == NULL){
        return;
    }
    No *aux, *aux2;
    aux = fila->fim;
    aux2 = aux->prox;
    if(aux->prox == NULL){
        fila->fim = NULL;
        free(aux);
        fila->tam--;
        return;
    }
    else{
        while(aux2->prox != NULL){
            aux = aux2;
            aux2 = aux2->prox;
        }
        aux->prox = NULL;
        free(aux2);
        fila->tam--;
        return;
    }
}

void InserirOrdenado(Arvore *arv, int i){
    Arvore *novaarv;
    Fila *fila;
    novaarv = InstArv(i);
    if(i > arv->valor){
        if(arv->dir == NULL){
            arv->dir = novaarv; 
        }
        else{
            InserirOrdenado(arv->dir, i);
        }
    }
    if(i < arv->valor){
        if(arv->esq == NULL){
            arv->esq = novaarv;
        }
        else{
            InserirOrdenado(arv->esq, i);
        }
    }
    return;
}

void PrintNivel(Fila *fila){
    No *aux;
    No *novaEsq, *novaDir;
    while(fila->tam != 0){
        aux = fila->fim;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        printf("%d ", aux->arv.valor);
        if(aux->arv.esq != NULL){
            novaEsq = InstNo(*aux->arv.esq);
            Inserir_fim(fila, novaEsq);
        }
        if(aux->arv.dir != NULL){
            novaDir = InstNo(*aux->arv.dir);
            Inserir_fim(fila, novaDir);
        }
        RemoverFila(fila); 
    }
    return;
}

int main(void){
    Arvore *arv; 
    Fila *fila;
    No *no;
    int floresta, cont = 0, i;
    scanf("%d", &floresta);
    while(cont != floresta){
        arv = NULL;
        int va, cont1 = 0;
        scanf("%d", &va);
        printf("Case %d:\n", cont+1);
        while(cont1 != va){
            scanf("%d", &i);
            if(arv == NULL){
                arv = InstArv(i);
            }
            else{
                InserirOrdenado(arv, i);   
            }
            cont1++;
        }
        no = InstNo(*arv);
        fila = InstFila(no);
        cont++;
        PrintNivel(fila);
        printf("\n\n");
    }
    printf("\n");
    return 0;
}