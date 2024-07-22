#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Arvore{
    char letra;
    struct Arvore *dir;
    struct Arvore *esq;
}Arvore;

Arvore *InstArv(char letra){
    Arvore *novaArv;
    novaArv = (Arvore*)malloc(sizeof(Arvore));
    novaArv->letra = letra;
    novaArv->dir = NULL;
    novaArv->esq = NULL;
    return novaArv;
}

int EncontrarLetra(char a, char *string){
    int cont = 0;
    while(string[cont] != 0){
        if(string[cont] == a){
            return cont;
        }
        cont++;
    }
    return -1;  
}

char *InsString(char novo, char *string){
    int cont = 0;
    while(string[cont] != 0){
        cont++;
    }
    string[cont] = novo;
    return string;
}

Arvore *ConstruirArv(Arvore* raiz, Arvore *arvatual, char *inordem, char *preordem, char **inseridos){
    int indice = EncontrarLetra(arvatual->letra, preordem);
    int indiceprox = indice+1;
    while(EncontrarLetra(preordem[indiceprox], *inseridos) != -1){
        indiceprox++;
    }
    while(preordem[indiceprox] != 0){
        int valor1, valor2;
        valor2 = EncontrarLetra(preordem[indiceprox], inordem);
        valor1 = EncontrarLetra(arvatual->letra, inordem);
        //esquerda
        if(valor1 > valor2){
            if(arvatual->esq == NULL){
                arvatual->esq = InstArv(preordem[indiceprox]);
                *inseridos =  InsString(preordem[indiceprox], *inseridos);
                if(arvatual != raiz){
                    return arvatual;
                }    
            }
            else{
                arvatual->esq = ConstruirArv(raiz, arvatual->esq, inordem, preordem, inseridos);
                if(arvatual != raiz){
                    return arvatual;
                }
            }

        }
        else if(valor1 < valor2){
             if(arvatual->dir == NULL){
                arvatual->dir = InstArv(preordem[indiceprox]);
                *inseridos =  InsString(preordem[indiceprox], *inseridos); 
                if(arvatual != raiz){
                    return arvatual;
                }    
            }
            else{
                arvatual->dir = ConstruirArv(raiz, arvatual->dir, inordem, preordem, inseridos);
                if(arvatual != raiz){
                    return arvatual;
                }
            }

        }
        indiceprox++;
    }
    return arvatual;
}

void PrintArv(Arvore *arv){
    printf("%c",  arv->letra);
    return;
}

void PrintPosfixo(Arvore *arv){
    if(arv->esq != NULL){
        PrintPosfixo(arv->esq);
    }
    if(arv->dir != NULL){
        PrintPosfixo(arv->dir);
    }
    PrintArv(arv);  
}

int main(void){ 
    Arvore *arv = NULL;
    int floresta, cont = 0, i;
    scanf("%d", &floresta);
    char *inordem, *preordem, **inseridos;
    inordem = NULL;
    preordem = NULL;
    while(cont != floresta){
        int valor;
        scanf("%d", &valor);
        inordem = (char*)malloc(valor*sizeof(char));
        preordem = (char*)malloc(valor*sizeof(char));
        inseridos = (char**)malloc(sizeof(char*));
        *inseridos = (char*)malloc(valor*sizeof(char));
        scanf("%s%*c", preordem);
        scanf("%s%*c", inordem);
        arv = InstArv(preordem[0]);
        *inseridos[0] = preordem[0];
        arv = ConstruirArv(arv, arv, inordem, preordem, inseridos);
        //printf("%c", arv->letra);
        //printf("%c", arv->dir->letra);
        //printf("%c", arv->esq->letra);
        PrintPosfixo(arv);
        cont++;
    }
    return 0;
}