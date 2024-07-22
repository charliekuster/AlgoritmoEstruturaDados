#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(int *vet, int x, int y){
    int aux;
    aux = vet[x];
    vet[x] = vet[y];
    vet[y] = aux;
    return;
}

void SelecSort(int tam, int *vet){
    int i, j, aux_min = 0;
    for(i=0; i<tam; i++){
        aux_min = i;
        for(j = i+1; j<tam; j++){
            if(vet[j] < vet[aux_min]){
                aux_min=j;
            }
        }
        Swap(vet, aux_min, i);
    }
    return;
}

int main(void){
    int *vet, tam, i;
    scanf("%d", &tam);
    vet = (int*)malloc(tam * sizeof(int));
    for(i=0; i<tam; i++){
        scanf("%d", &vet[i]);
    }
    SelecSort(tam, vet);

    for(i=0; i<tam; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}