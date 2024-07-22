#include "arv.h"

Arvore *InstArv(char letra){
    Arvore *novaarv;
    novaarv = (Arvore*)malloc(sizeof(Arvore));
    novaarv->carc = letra;
    novaarv->esq = NULL;
    novaarv->dir = NULL;
    return novaarv;
}

void InsOrd(Arvore *arv, char letra){
    Arvore *novaarv;
    novaarv = InstArv(letra);
    if(letra > arv->carc){
        if(arv->dir == NULL){
            arv->dir = novaarv;
        }
        else{
            InsOrd(arv->dir, letra);
           
        }
    }
    if(letra < arv->carc){
        if(arv->esq == NULL){
            arv->esq = novaarv;
        }
        else{
            InsOrd(arv->esq, letra);
           
        }
    }

    return;    
}

void PrintArv(Arvore arv, int *tam, int *tam2){
    (*tam)++;
    if(*tam != *tam2){
        printf("%c ", arv.carc);
    }
    else{
        printf("%c", arv.carc);
    }
}

void PrintInfixa(Arvore arv, int *tam, int *tam2){
    if(arv.esq != NULL){
        PrintInfixa(*(arv.esq), tam, tam2);
    }
    PrintArv(arv, tam, tam2);
    if(arv.dir != NULL){
        PrintInfixa(*(arv.dir), tam, tam2);
    }
}

void PrintPrefixa(Arvore arv, int *tam, int *tam2){
    PrintArv(arv, tam, tam2);
    if(arv.esq != NULL){
        PrintPrefixa(*(arv.esq), tam, tam2);
    }
    if(arv.dir != NULL){
        PrintPrefixa(*(arv.dir), tam, tam2);
    }
}

void PrintPosfixo(Arvore arv, int *tam, int *tam2){
    if(arv.esq != NULL){
        PrintPosfixo(*(arv.esq), tam, tam2);
    }
    if(arv.dir != NULL){
        PrintPosfixo((*arv.dir), tam, tam2);
    }
    PrintArv(arv, tam, tam2); 

}

void Buscar(Arvore arv, char c){
    if(arv.carc == c){
        printf("%c existe\n", c);
    }
    if(c > arv.carc){
        if(arv.dir == NULL){
            printf("%c nao existe\n", c);
        }
        else{
            Buscar(*(arv.dir), c);
        }
    }
    if(c < arv.carc){
        if(arv.esq == NULL){
            printf("%c nao existe\n", c);
        }
        else{
            Buscar(*(arv.esq), c);
        }
    }
}