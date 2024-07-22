#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "arv.h"

int main(void){
    int floresta, cont=0, cont2, quantArv;
    int *tam;
    tam = (int*) malloc(sizeof(int));
    *tam = 1;
    Arvore *arv;
    arv = NULL;
    scanf("%d", &floresta);
    while(cont != floresta){
        int quant, *vetor = NULL;
        scanf("%d", &quantArv);
        vetor = (int*)malloc(quantArv*sizeof(int));
        for(cont2=0; cont2<quantArv; cont2++){
            scanf("%d", &quant);
            *(vetor+cont2) = quant;
            if(arv == NULL){
                arv = InstArv(*(vetor+cont2));
            }
            else{
                InserirOrdenado(arv, *(vetor+cont2));
            }
        }
        printf("Case %d:\n", cont+1);
        printf("Pre.: ");
        ArvPrefixo(*arv, tam, quantArv);
        printf("\n");
        printf("In..: ");
        ArvInfixo(*arv, tam, quantArv);
        printf("\n");
        printf("Post: ");
        ArvPosfixo(*arv, tam, quantArv);
        cont++;
        arv = NULL;
        printf("\n\n");
    }
    return 0;
}





