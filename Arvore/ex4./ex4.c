#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Arvore{
    int valor;
    int quant;
    struct Arvore *dir;
    struct Arvore *esq;
}Arvore;

Arvore *InstArv(int i){
    Arvore *novaarv;
    novaarv = (Arvore*)malloc(sizeof(Arvore));
    novaarv->valor = i;
    novaarv->dir = NULL;
    novaarv->esq = NULL;
    return novaarv;
}

void InserirOrdenado(Arvore *arv, int i){
    Arvore *novaarv;
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
}

void PrintArv(Arvore arv, int *tam, int *tam2){
    (*tam)++;
    if(*tam != *tam2){
        printf("%d ", arv.valor);
    }
    else{
       printf("%d", arv.valor); 
       *tam = 0;
    }
}

void PrintInfixo(Arvore arv, int *tam, int *tam2){
    if(arv.esq != NULL){
        PrintInfixo(*(arv.esq), tam, tam2);
    }    
    PrintArv(arv, tam, tam2);
    if(arv.dir != NULL){
        PrintInfixo(*(arv.dir), tam, tam2);
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

void ProcuraArv(Arvore arv, int esc){
    if(arv.valor == esc){
        printf("%d existe\n", esc);
    }
    if(esc > arv.valor){
        if(arv.dir != NULL){
            ProcuraArv(*arv.dir, esc);
        }
        else{
            printf("%d nao existe\n", esc); 
        }
    }
    if(esc < arv.valor){
        if(arv.esq != NULL){
            ProcuraArv(*arv.esq, esc);
        }
        else{
            printf("%d nao existe\n", esc); 
        }
    }
}

Arvore *ProcEsq(Arvore *arv){
    Arvore *maior;
    maior = arv;
    if(arv->dir != NULL){
        maior = ProcEsq(arv->dir);
    }
    return maior;
}

Arvore *RetiraArv(Arvore *arv, int esc){
    if(arv->valor == esc){
        //retirar folha
        if(arv->dir == NULL && arv->esq == NULL){
            free(arv);
            return NULL;
        }
        //retirar arvore com 2 filhos
        else if(arv->dir != NULL && arv->esq != NULL){
            Arvore *auxmaior;
            int aux = arv->valor;
            auxmaior = ProcEsq(arv->esq);
            arv->valor = auxmaior->valor;
            auxmaior->valor = aux;
            arv->esq = RetiraArv(arv->esq, esc);
            return arv;
        }
        //retirar arvore com 1 filho
        else{
            if(arv->dir != NULL){
                return arv->dir;
            }
            if(arv->esq != NULL){
                return arv->esq;
            }
        }
        free(arv);
    }
    else if(esc < arv->valor){
        if(arv->esq != NULL){
            arv->esq = RetiraArv(arv->esq, esc); 
        }
    }
    else if(esc > arv->valor){
        if(arv->dir != NULL){
            arv->dir = RetiraArv(arv->dir, esc); 
        }
    }  
    return arv;
}

int main(void){
    Arvore *arv;
    arv = NULL;
    int n, esc, escr; 
    int *tam;
    int *tam2;
    tam = (int*)malloc(sizeof(int));
    *tam = 1; 
    tam2 = (int*)malloc(sizeof(int));
    *tam2 = 0; 
    char opc[100], i;
    while (scanf("%s%*c", opc) != EOF){
        if(strcmp(opc, "I") == 0){
            scanf("%d", &n);
            if(arv == NULL){
                (*tam2)++;
                arv = InstArv(n);
            }
            else{
               InserirOrdenado(arv, n);
               (*tam2)++; 
            }
        }
        else if(strcmp(opc, "P") == 0){
            scanf("%d", &esc);
            if(arv == NULL){
                printf("%d nao existe\n", esc);
            }
            else{
                ProcuraArv(*arv, esc);
            }    
        }
        else if(strcmp(opc, "R") == 0){
            scanf("%d", &escr);
            if(arv != NULL){
                arv = RetiraArv(arv, escr);
                (*tam2)--;
            if(arv == NULL){
                *tam2 = 1;
            }
            }
        }
        else if(strcmp(opc, "INFIXA") == 0){
            if(arv != NULL){
                PrintInfixo(*arv, tam, tam2);
                printf("\n");
            }
        }
        else if(strcmp(opc, "PREFIXA") == 0){
            if(arv != NULL){
                PrintPrefixa(*arv, tam, tam2);
               printf("\n");
            }
        }
        else if(strcmp(opc, "POSFIXA") == 0){
            if(arv != NULL){
                PrintPosfixo(*arv, tam, tam2);
               printf("\n");
            }
        }
        (*tam) = 0;
    }
    return 0;
}