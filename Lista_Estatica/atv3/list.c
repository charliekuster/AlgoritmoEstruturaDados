#include "list.h"

void Iniciar(List *lista){
    lista->prim = NULL;
    lista->tam = 0;
    lista->quant_velhos = 0;
}

void AddPac(Pac *paciente){
    printf("\n  Insira os dados do paciente: \n");
    printf("\tNome: ");
    fflush(stdin);
    fgets(paciente->nome, 50, stdin);
    printf("\tIdade: ");
    scanf("%d", &paciente->idade);
    return;
}

void Print(List lista){
    No *aux = lista.prim;
    if(aux != NULL){
        while(aux != NULL){
            printf("\t  Lugar = %04d\n", aux->paciente.lugar);
            printf("\t%s", aux->paciente.nome);
            printf("\t%d\n\n", aux->paciente.idade);
            aux = aux->prox;
        }
    }
    else{
        printf("\tErro, lista vazia\n");
    }
    return;
}

void Add(List *lista, int *cont, int *cont2, Pac paciente){
    No *novoNo = (No*)malloc(sizeof(No));
    if(novoNo){
        if(paciente.idade >= 60){
            if(lista->prim == NULL){
                novoNo->prox = lista->prim;
                lista->prim = novoNo;
                novoNo->paciente = paciente; 
                (*cont2)++;
                novoNo->paciente.lugar = *cont2;
                lista->quant_velhos++;                 
                return;
            }
            No *aux = lista->prim;
            No *aux2 = aux->prox;
            while(aux2 != NULL && aux2->paciente.ehvelho != 1){
                aux = aux->prox;
                aux2 = aux2->prox;
            }  
            if(aux2 == NULL){
                aux->prox = novoNo;
                novoNo->prox = NULL;     
            }
            else{ 
                aux->prox = novoNo;
                novoNo->prox = aux2;
            }
            novoNo->paciente = paciente;
            (*cont2)++;
            novoNo->paciente.lugar = *cont2;
            lista->quant_velhos++;
        }
        else{
            novoNo->prox = lista->prim;
            lista->prim = novoNo;
            novoNo->paciente = paciente;
            (*cont)++;
            novoNo->paciente.lugar = *cont;
            novoNo->paciente.ehvelho = 0;
        }
    }
    else{
        printf("Erro, tente novamente\n");
    }
    return;
}

void RemoverVelho(List *lista){
    if(lista->prim != NULL){
        No *aux = lista->prim; 
        No *aux2 = aux->prox;        
        if(lista->prim->prox == NULL){
            lista->prim = NULL;
        }
        while(aux2->prox != NULL){
            aux = aux->prox;
            aux2 = aux2->prox;
        }
        free(aux2);
        aux->prox = NULL;
        lista->tam--;
        lista->quant_velhos--;
    }
    else{
        printf("Erro, tente novamente\n");   
    }
    return;
}

void RemoverJovem(List *lista){
    No *aux = lista->prim;
    No *aux2 = aux->prox;
    while(aux2->prox->paciente.ehvelho != 1){
        aux = aux->prox;
        aux2 = aux2->prox;
    }
    aux->prox = aux2->prox;
    free(aux2);
}

void Remover(List *lista){
    srand(time(NULL));
    int probabilidade = rand() %100;
    if(probabilidade < 40 && lista->quant_velhos > 0 ){
        RemoverJovem(lista);
    }
    else{
        RemoverVelho(lista);
    }
    return;
}

void Delete(List *lista){
    No *aux = lista->prim;
    No *aux2 = aux->prox;
    if(lista->prim != NULL){
        while(aux2->prox != NULL){
            free(aux);
            aux = aux2->prox;
            aux2 = aux2->prox;
        }
        free(aux);
        lista->tam = 0;
        lista->prim = NULL;
    }
}