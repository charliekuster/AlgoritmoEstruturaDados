#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct List{
    No *comeco;
} List;

List *InstList(void){
    List *list;
    list = (List*)malloc(sizeof(List));
    list->comeco = NULL;
    return list;
}

No *InstNo(int num){
    No *novoNo;
    novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = num;
    return novoNo;
}

void PrintNo(No No){
    printf("%d ", No.valor);
}

void PrintList(List list){
    No *noAux = list.comeco;
    while(noAux != NULL){
        PrintNo(*noAux);
        noAux = noAux->prox;
    }

}

void InsList(List *list, No *no){
    No *noAux = list->comeco;
    while(noAux->prox != NULL){
        noAux = noAux->prox;
    }
    noAux->prox = no;    
}

void DividirList(No *no, No **noDir, No **noEsq){
    No *devagar, *rapido;
    devagar = no;
    rapido = no->prox;
    while (rapido != NULL){
        rapido = rapido->prox;
        if(rapido != NULL){
            devagar = devagar->prox;
            rapido = rapido->prox;
        }
    }
    *noDir = devagar->prox;
    *noEsq = no;
    devagar->prox = NULL;
    return;
}

No *Mesclagem(No *noEsq, No *noDir);

No *MergeSort(No *no, int *recur){
    int recurdir = 0, recuresq = 0;
    No *noDir, *noEsq;
    noDir = NULL;
    noEsq = NULL;
    if(no->prox == NULL){
        return no;
    }
    DividirList(no, &noDir, &noEsq);
    *recur += 1;
    noEsq = MergeSort(noEsq, &recuresq);
    noDir = MergeSort(noDir, &recurdir);
    if(recurdir > recuresq){
        (*recur) += recurdir;
    }
    else{
        (*recur) += recuresq;
    }
    // Mesclar
    return Mesclagem(noEsq, noDir);
}

No *Mesclagem(No *a, No *b){
    No *ans = NULL;
    No *end = NULL;

    while (a != NULL && b != NULL)
    {
        No *new_node;
        if (a->valor <= b->valor)
        {
            new_node = a;
            a = a->prox;
        }
        else
        {
            new_node = b;
            b = b->prox;
        }

        new_node->prox = NULL;

        if (end != NULL)
        {
            end->prox = new_node;
        }
        else
        {
            ans = new_node;
        }
        end = new_node;
    }

    if (a != NULL)
        end->prox = a;
    else if (b != NULL)
        end->prox = b;

    return ans;
}

int main(void){
    int tam, i, num, cont; 
    List *list;
    No *no;
    scanf("%d", &tam);
    list = InstList();
    for(i=0; i<tam; i++){
        scanf("%d", &num);
        no = InstNo(num);
        if(list->comeco == NULL){
            list->comeco = no;
        }
        else{
           InsList(list, no); 
        }
    }
    list->comeco = MergeSort(list->comeco, &cont);
    PrintList(*list);
    printf("\n%d", cont);
    
    return 0;
}