#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao para determinar as chamadas recursivas
void EncontrarValor(int *array, int tam, int busca, int inicio, int fim, int *recursivo){
    int i;
    tam = (fim + inicio)/2;
    if(busca == array[tam]){
        return;
    }
    else if(busca > array[tam]){
        inicio = tam;
        EncontrarValor(array, tam+1, busca, inicio+1, fim, recursivo);
        (*recursivo)++;
    }
    else if (busca < array[tam]){
        fim = tam;
        EncontrarValor(array, tam, busca, inicio, fim-1, recursivo);
        (*recursivo)++;
    }
}

int main (void){
    int tam, i, valor, *array, busca, *recursivo, vf;
    int encontrado = 0;
    //arrey para armarzenar as chamadas 
    recursivo = (int*)malloc(sizeof(int));
    *recursivo = 0;
    scanf("%d", &tam);
    array = (int*)malloc(tam * sizeof(int));
    for(i=0; i<tam; i++){
        scanf("%d", &valor);
        array[i] = valor;
    }
    scanf("%d", &busca);
    //laco para verificar se o valor existe no array
    for(i=0; i<tam; i++){
        if(array[i] == busca){
            encontrado = 1;
        }   
    }
    if(encontrado == 0){
        printf("%d nao foi encontrado", busca);
    }
    else{
        EncontrarValor(array, tam, busca, 0, tam-1, recursivo);
        printf("%d", *recursivo);
        free(array);
        free(recursivo);
    }

    return 0;
}

