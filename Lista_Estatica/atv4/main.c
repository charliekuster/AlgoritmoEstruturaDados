#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "list.h"

#define TAM 100

void menu(){
    printf("\t\t\t\tLista de banco\n\n");
    printf("\t\tEscolha uma das opcaoes abaixo:\n");
    printf("\t (1) Add no inicio.\n");
    printf("\t (2) Add no fim.\n");
    printf("\t (3) Add em posicao especifica.\n");
    printf("\t (4) Remover de posicao especifica.\n");
    printf("\t (5) Remover todos da lista.\n");
    printf("\t (6) Remover do inicio.\n");
    printf("\t (7) Remover do fim.\n");
    printf("\t (8) Mostrar lista.\n");
    printf("\t (0) Sair do programa.\n");
    return;
}

void LidarM(int esc, List *lista, Cliente *novo){

    switch(esc){
        case 1:
            AddPessoa(novo);
            AddFin(lista, *novo);
        break;
        case 2:
            AddPessoa(novo);
            AddFin(lista, *novo);
        break;
        case 3:
            AddEspecifico(lista, novo);
        break;
        case 4:
            Remover(lista);
        break;
        case 5:
            RemoverTodos(lista);
        break;
        case 6:
            RemCom(lista);
        break;
        case 7:
            RemFin(lista);
        break;
        case 8:
            Print(*lista);
        break;
        case 0:
        exit(0);
        default:
        printf("ERRO, opcao invalida.\n");
        break;
    }

}

int main(void){
    int esc;
    List lista;
    Cliente novo;
    Inc(&lista);
    for(;;){
        menu();
        scanf("%d", &esc);
        LidarM(esc, &lista, &novo);



    }
}