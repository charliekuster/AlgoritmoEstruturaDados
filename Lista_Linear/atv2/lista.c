# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include "lista.h"


void Print(Lista* lista){

    No* copia = lista->inicioLista;
    int contador = 1;

    if(Void_L(lista) == false){
        while(copia){
            printf("(%d) -> Nome: %s | RA: %d | Frequencia: %d%% | P1: %.2f | P2: %.2f | P3: %.2f\n", contador, copia->item.nome, copia->item.ra, copia->item.frequencia, copia->item.notas[0], copia->item.notas[1], copia->item.notas[2]);
            copia = copia->proximoNo;
            contador++;
        }
    } else {
        printf("Lista vazia\n");
    }

    return;
}

Item Get(){

    Item item;

    printf("\nDigite o nome: ");
    fflush(stdin);
    fgets(item.nome, 30, stdin);
    item.nome[strlen(item.nome) - 1] = '\0';
    printf("Digite o RA: ");
    scanf("%d", &item.ra);
    printf("Digite a frequencia: ");
    scanf("%d", &item.frequencia);
    for(int i = 1 ; i <= 3 ; i++){
        printf("Digite a nota da P%d: ", i);
        scanf("%f", &item.notas[i - 1]);
    }

    return(item);
}

void I_Inicio(Lista* lista){

    No* novoItem = (No*) malloc(sizeof(No));

    if(novoItem){
        novoItem->item = Get();
        novoItem->proximoNo = lista->inicioLista;
        if(Void_L(lista) == true){
            lista->fimLista = novoItem;
        }
        lista->inicioLista = novoItem;
        lista->tamanhoLista++;
        printf("Inserido\n");
    } else {
        printf("Erro\n");
    }

    return;
}

int Get_P(Lista* lista){

    int index;

    Print(lista);
    printf("Digite uma posicao do meio da lista: ");
    scanf("%d", &index);

    return(index - 1);
}

void InserirMeioLista(Lista* lista){

    No* novoItem = (No*) malloc(sizeof(No));
    No* copia = lista->inicioLista;
    int index = -1;

    if(novoItem){
        if(Void_L(lista) == true){
            printf("Lista Vazia! Insira no inicio.");
        } else {
            if(lista->tamanhoLista > 1){
                index = Get_P(lista);
            }
            if(index > 0 && index < lista->tamanhoLista){
                for(int i = 1 ; i < index ; i++){
                    copia = copia->proximoNo;
                }
                novoItem->item = Get();
                novoItem->proximoNo = copia->proximoNo;
                copia->proximoNo = novoItem;
                lista->tamanhoLista++;
                printf("Inserido\n");
            } else {
                printf("Erro\n");
            }
        }
    } else {
        printf("Erro.\n");
    }

    return;
}

void I_fim(Lista* lista){

    No* novoItem = (No*) malloc(sizeof(No));

    if(novoItem){
        if(Void_L(lista) == true){
            printf("Erro\n");
        } else {
            novoItem->item = Get();
            novoItem->proximoNo = NULL;
            lista->fimLista->proximoNo = novoItem;
            lista->fimLista = novoItem;
            lista->tamanhoLista++;
            printf("Inserido\n");
        }
    } else {
        printf("Erro\n");
    }

    return;
}


void I_lista(Lista** lista){

    (*lista) = (Lista*) malloc(sizeof(Lista));
    (*lista)->inicioLista = NULL;
    (*lista)->fimLista = NULL;
    (*lista)->tamanhoLista = 0;

    return;
}

int Menu(){

    int num;

    printf("Digite uma das opcoes: ");
    printf("1 = Imprimir lista");
    printf("2 = Inserir no inicio");
    printf("3 = Inserir no meio");
    printf("4 = Inserir no fim");
    printf("5 = Remover do inicio");
    printf("6 = Remover do meio");
    printf("7 = Remover do fim");
    printf("8 = Remover pelo RA do aluno");
    printf("0 = Fechar programa");
   
    scanf("%d", &num);

    return(num);
}


No* R_inicio(Lista* lista){

    No* removido = lista->inicioLista;

    if(Void_L(lista) == false){
        lista->inicioLista = lista->inicioLista->proximoNo;
        lista->tamanhoLista--;
        printf("Removido\n");
    } else {
        printf("Lista vazia\n");
    }

    return(removido);
}

No* R_Meio(Lista* lista, int constante){

    No* removido = NULL;
    No* copia = lista->inicioLista;
    int index = constante;

    if(Void_L(lista) == true){
        printf("Lista vazia.\n");
    } else {
        if(lista->tamanhoLista > 2){
            if(constante == -1){
                index = Get_P(lista);
            }
            if(index > 0 && index < lista->tamanhoLista - 1){
                for(int i = 1 ; i < index ; i++){
                    copia = copia->proximoNo;
                }
                removido = copia->proximoNo;
                copia->proximoNo = removido->proximoNo;
                lista->tamanhoLista--;
                printf("\n");
            } else {
                printf("Posicao invalida\n");
            }
        } else {
            printf("Erro.\n");
        }
    }

    return(removido);
}

No* R_Final(Lista* lista){

    No* removido = NULL;
    No* copia = lista->inicioLista;

    if(Void_L(lista) == true){
        printf("Lista vazia\n");
    } else {
        if(lista->tamanhoLista == 1){
            removido = lista->fimLista;
            lista->inicioLista = NULL;
            lista->fimLista = NULL;
        } else {
            removido = lista->fimLista;
            while(copia->proximoNo != removido){
                copia = copia->proximoNo;
            }
            copia->proximoNo = NULL;
            lista->fimLista = copia;
        }
        lista->tamanhoLista--;
        printf("Removido\n");
    }

    return(removido);
}

int ReceberRA(){

    int ra;

    printf("\nDigite o RA: ");
    scanf("%d", &ra);

    return(ra);
}

No* RemoverPeloRA(Lista* lista){

    No* copia = lista->inicioLista;
    No* removido;
    int ra, index;
    bool encontrado = false;

    if(Void_L(lista) == true){
        printf("Lista vazia\n");
    } else {
        ra = ReceberRA();
        for(int i = 0 ; i < lista->tamanhoLista ; i++){
            if(copia->item.ra == ra){
                encontrado = true;
                index = i;
                break;
            }
            if(encontrado == false){
                copia = copia->proximoNo;
            }
        }
    }

    if(encontrado == false){
        printf("RA nao encontrado!\n");
    } else {
        if(index == 0){
            removido = R_inicio(lista);
        } else if(index == lista->tamanhoLista - 1){
            removido = R_Final(lista);
        } else {
            removido = R_Meio(lista, index);
        }
    }

    return(removido);
}



bool Void_L(Lista* lista){

    bool vazia = true;

    if(lista->inicioLista != NULL){
        vazia = false;
    }

    return(vazia);
}

