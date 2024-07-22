#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "list.h"


void Menu(){
    printf("\n\t----------Fila de prioridade----------\n");
    printf("\t(1) Mostrar a fila.\n");
    printf("\t(2) Add paciente.\n");
    printf("\t(3) Remover paciente da fila.\n");
    printf("\t(4) Remover todos os pacientes da fila.\n");
    printf("\t(0) Sair do programa.\n");
}

void LidarMenu(int escolha, int *cont, int *cont2, List *lista, Pac *paciente){
    switch(escolha){
        case 1:
           Print(*lista); 
        break;
        case 2:
            AddPac(paciente);
            Add(lista, cont, cont2, *paciente);
        break;
        case 3:
            RemoverVelho(lista);           
        break;
        case 4:
            Delete(lista);
        break;
        case 0:
            printf("Adeus");
            exit (0);
        break;
        default:
            printf("ERRO, digite um valor equivalente...\n");
    }
    return;
    }

int main(void){
    List lista;
    Pac paciente;
    int esc;
    int cont = 0, cont2 = 0;
    for(;;){
        Menu();
        scanf("%d", &esc);
        system("clear");
        LidarMenu(esc, &cont, &cont2, &lista, &paciente);
    }
    return 0;
}

