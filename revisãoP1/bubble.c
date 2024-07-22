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

void BubbleSort(int *vet, int tam){
    int i, j, aux;
    for(i=tam-1; i>0; i--){
        for(j=0; j<i; j++)
            if(vet[j] > vet[j+1]){
                Swap(vet, j, j+1);
            }
    }
    return;

    for(i=0; i<tam; i++){
        printf("%d ", vet[i]);
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
    BubbleSort(vet, tam);

    for(i=0; i<tam; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}