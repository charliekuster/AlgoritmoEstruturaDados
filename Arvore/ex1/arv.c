#include "arv.h"

Arvore *InstArv(int i){
    Arvore *novaArv;
    novaArv = (Arvore*)malloc(sizeof(Arvore));
    novaArv->valor = i;
    novaArv->direita = NULL;
    novaArv->esquerda = NULL;
    return novaArv;
}

void InserirOrdenado(Arvore *arv, int i){
    Arvore *novaarv;
    novaarv = InstArv(i);
    if(i>arv->valor){
        if(arv->direita == NULL){
            arv->direita = novaarv;
        }
        else{
            InserirOrdenado(arv->direita, i);
        }
    }
    else{
        if(arv->esquerda == NULL){
            arv->esquerda = novaarv;
        }   
        else{
            InserirOrdenado(arv->esquerda, i);
        }
    }
}

void PrintArv(Arvore arv, int *tam, int quantArv){
    if(*tam != quantArv){
        printf("%d ", arv.valor);
        (*tam)++;
    }
    else{
        printf("%d", arv.valor);
        *tam = 1;
    }

}

void ArvPrefixo(Arvore arv, int *tam, int quantArv){
    PrintArv(arv, tam, quantArv);
    if(arv.esquerda!= NULL){
        ArvPrefixo(*arv.esquerda, tam, quantArv);
    }
    if(arv.direita != NULL){
        ArvPrefixo(*arv.direita, tam, quantArv);
    }
}

void ArvInfixo(Arvore arv, int *tam, int quantArv){
    if(arv.esquerda != NULL){
        ArvInfixo(*arv.esquerda, tam, quantArv);
    }
    PrintArv(arv, tam, quantArv);
    if(arv.direita != NULL){
        ArvInfixo(*arv.direita, tam, quantArv);
    }
} 

void ArvPosfixo(Arvore arv, int *tam, int quantArv){
    if(arv.esquerda != NULL){
        ArvPosfixo(*arv.esquerda, tam, quantArv);
    }
    if(arv.direita != NULL){
        ArvPosfixo(*arv.direita, tam, quantArv);
    }
    PrintArv(arv, tam, quantArv);  
}