#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "list.h"

void Menu(){
    printf("\n");
    printf("\t\t\t LISTA DE PRODUTOS\n");
    printf("\t\t\t ------------------\n\n");
    printf("\t (1) Mostrar produtos registrados\n");
    printf("\t (2) Adicioar produto no comeco\n");
    printf("\t (3) Adicionar prodito no final\n");
    printf("\t (4) Remover da primeira posição\n");
    printf("\t (5) Remover do fim\n");
    printf("\t (6) Remover de uma pasição espcifica\n");
    printf("\t (0) Sair do programa\n\n");
}

void LidarMenu(int escolha, List *lista, Item *prod){
    switch(escolha){
        case 1:
            Print(*lista);
        break;
        case 2:
            Get(prod);
            AddCom(lista, *prod);
        break;
        case 3:
            Get(prod);
            AddFin(lista, *prod);
        break;
        case 4:
            RemoverPrim(lista);
        break;
        case 5:
            RemoverFin(lista);
        break;
        case 6:
            RemoverEspc(lista); 
        break;
        case 0:
            exit(0);
        break;
        default:
            printf("Erro\n");
        break;
    }
}



int main(void){
    int escolha;
    List lista;
    Item prod;

    for(;;){
        Menu();
        scanf("%d", &escolha);
        system("clear");
        LidarMenu(escolha, &lista, &prod); 
    }
    return 0;
}