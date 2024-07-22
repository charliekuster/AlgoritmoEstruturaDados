#include "arv.h"

int EncontrarPrecedencia(char *string){
     int cont, indice = 0;
    for(cont = 0; string[cont] != '\0'; cont++){
        if(DefinePreced(string[cont]) <= DefinePreced(string[indice])){
            indice = cont;
        }    
        if(string[cont] == '('){ 
            int qtt_parenteses = 1;
            while(qtt_parenteses){
                cont++;
                if(string[cont] == '(')
                    qtt_parenteses++;
                if(string[cont] == ')')
                    qtt_parenteses--;
                }
        }
    }
    return indice;
}


char *ExpreEsq(char *expre, int indice){
    char* novaString = (char*) malloc(100*sizeof(char));
    strcpy(novaString, expre);
    novaString[indice] = '\0';
    return novaString;
}

char* ExpreDir(char *expre, int indice){
    char* expre_dir = (char*) malloc(100* sizeof(char));
    int cont;
    for(cont=0; expre[indice+1] != '\0'; cont++, indice++)
        expre_dir[cont] = expre[indice+1];
    return expre_dir;
}


Arvore *IniciarArvore(){
    return NULL;
}


Arvore *InstArv(char* expre){
    Arvore *novaArv = (Arvore*) malloc(sizeof(Arvore)); 
    int indice = EncontrarPrecedencia(expre); 
    while(expre[indice] == '('){
        RemoveParenteses(expre);
        indice = EncontrarPrecedencia(expre);
    }
    novaArv->letra = expre[indice];
    char* expression_left, expre_dir;
    int precedence = DefinePreced(expre[indice]);
    if(precedence != 10){
    novaArv->esq = InstArv(ExpreEsq(expre, indice));
    novaArv->dir = InstArv(ExpreDir(expre, indice));
    }
    else{
        novaArv->esq = novaArv->dir = NULL;
    }    
    return novaArv;
}



No *InstNo(Arvore arv){
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->arv = arv;
    novoNo->prox = NULL;
    return novoNo;
}

Fila *InstFila(No *no){
    Fila* novaFila = (Fila*)malloc(sizeof(Fila));
    novaFila->fim = no;
    novaFila->tam = 1;
    return novaFila;
}
void InserirFila(Fila *fila, No* novoNo){
    novoNo->prox = fila->fim;
    fila->fim = novoNo;
    fila->tam++;
}
void Remove(Fila *fila){
    No* aux = fila->fim;
    if(aux == NULL) return;
    No* aux2 = aux->prox;
    if(aux2 == NULL){
        fila->fim = NULL;
        fila->tam--;
        free(aux);
        return;
    }
    while(aux2->prox != NULL){
        aux = aux->prox;
        aux2 = aux->prox;
    }
    aux->prox = NULL;
    fila->tam--;
    free(aux2);
}

void PrintNivel(Fila *fila){
    int  cont = 0;
    No *final = fila->fim;
    No *inicio = fila->fim;
    while(fila->tam > 0){
        No *aux2 = fila->fim;
        while(aux2->prox != NULL)
            aux2 = aux2->prox;
        if(aux2 == inicio){
            printf("Nivel %d: ", cont);
            cont++;
        }
        printf("%c", aux2->arv.letra);
        if(aux2->arv.esq)
            InserirFila(fila, InstNo(*aux2->arv.esq));
        if(aux2->arv.dir)
            InserirFila(fila, InstNo(*aux2->arv.dir));
        if(aux2 == final){
            No *aux = fila->fim;
            if(aux->prox != NULL){
                while(aux->prox != final)
                    aux = aux->prox;
            }
            inicio = aux;
            final = fila->fim;
            printf("\n");
            }
        Remove(fila);
       } 
    }

int DefinePreced(char letra){
    int precd;
    switch(letra){
        case '(':
            precd = 3;
            break;
        case ')':
            precd = 3;
            break;
        case '*':
            precd = 2;
            break;
        case '/':
            precd = 2;
            break;
        case '+':
            precd = 1;
            break;
        case '-':
            precd = 1;
            break;
        default:
            precd = 10; 
    }
    return precd;
}

char *RemoveParenteses(char* string){
    int contNaoParent = 0;
    int qtt_parenteses = 0;
    int cont;
    for(cont=0; string[cont] != '\0'; cont++){
        if(string[cont] == ')')
            qtt_parenteses--;
        if(qtt_parenteses>0){
            string[contNaoParent] = string[cont];
            contNaoParent++;
        }
        if(string[cont] == '(')
            qtt_parenteses++;
    }
    string[contNaoParent] = '\0';
    return string;
}

char* RemoveEspace(char* string){
    int contBranco = 0;
    int cont;
    for(cont=0; string[cont] != '\0'; cont++){
        if(string[cont] != ' '){
            string[contBranco] = string[cont];
            contBranco++;
        }
    }
    string[contBranco] = '\0';
    return string;
}

