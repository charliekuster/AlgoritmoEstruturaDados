#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"
#define TAM 400

int main(void){    
    char expre[TAM];
    while(scanf("%[^\n]%*c", &expre) != EOF){
        RemoveEspace(expre);
        Arvore *arv;
        arv = IniciarArvore();
        arv = InstArv(expre);
        No* noRaiz = NULL;
        noRaiz = InstNo(*arv);
        Fila *fila = NULL;
        fila = InstFila(noRaiz);
        PrintNivel(fila);
        printf("\n");
    }
    return 0;
}
