#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "arv.h"

int main(void){
    Arvore *arv;
    int cont=0;
    int *tam;
    int *tam2;
    tam = (int*)malloc(sizeof(int));
    tam2 = (int*)malloc(sizeof(int));
    *tam = 0;
    *tam2 = 0;
    char opc[20], letra, c;
    arv = NULL;
    while (scanf("%s%*c", opc) != EOF){
        if(strcmp(opc, "I") == 0){
            scanf(" %c", &letra);
            if(arv == NULL){
                arv = InstArv(letra);
            }
            else{
                InsOrd(arv, letra);
            }
            (*tam2)++;            
        }
        else if(strcmp(opc, "INFIXA") == 0){
            PrintInfixa(*arv, tam, tam2);
            printf("\n");
        }
        else if(strcmp(opc, "PREFIXA") == 0){
            PrintPrefixa(*arv, tam, tam2);
            printf("\n");
        }
        else if(strcmp(opc, "POSFIXA") == 0){
            PrintPosfixo(*arv, tam, tam2);
            printf("\n");
        }
        else if(strcmp(opc, "P") == 0){
            scanf(" %c", &c);
            Buscar(*arv, c);
        }
        *tam = 0;
        cont++;
    }
    return 0;
}