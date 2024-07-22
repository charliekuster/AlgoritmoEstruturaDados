#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int Particao(int array[], int esq, int dir){
    int pivo = array[dir];
    int i = esq - 1;
    for (int j = esq; j < dir; j++) {
        if (array[j] < pivo) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[dir];
    array[dir] = temp;

    return i + 1;
}



int Mediana(int array[], int esq, int dir){
    int meio = (esq + dir)/2, aux;
    if(array[esq] > array[meio]){
        aux = array[esq];
        array[esq] = array[meio];
        array[meio] = aux;
    }
    if(array[meio] > array[dir]){
        aux = array[dir];
        array[dir] = array[meio];
        array[meio] = aux;        
    }
    if(array[esq] > array[meio]){
        aux = array[esq];
        array[esq] = array[meio];
        array[meio] = aux;
    }
    return meio;    
}

int ParticaoMediano(int array[], int esq, int dir){
    int meio = Mediana(array, esq, dir); 
    //printf("  mediana = %d", meio);
    int i = esq - 1, aux, pivo;
    aux = array[meio];
    array[meio] = array[dir - 1];
    array[dir - 1] = aux;
    pivo = dir - 1;
    for (int j = esq; j < dir-1; j++) {
        if (array[j] < array[pivo]) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[dir - 1];
    array[dir - 1] = temp;
    return i + 1;
}

int* QuickSort(int* array, int begin, int end){
    int *diferenca = malloc(2* sizeof *diferenca); 
    int *array_esq; 
    int *array_dir;
    diferenca[0] = diferenca[1] = 0; 

    if(begin < end){
    int pivo = Particao(array, begin, end); 
    
    array_esq = QuickSort(array, begin, pivo - 1);
    array_dir = QuickSort(array, pivo + 1, end);
    diferenca[0] = array_esq[0] > array_dir[0] ? array_esq[0] + 1 : array_dir[0] + 1;
    diferenca[1] = array_esq[1] < array_dir[1] ? array_esq[1] + 1 : array_dir[1] + 1;
    free(array_esq);
    free(array_dir);
    return diferenca;
    }
    else
        return diferenca;
}
int* QuickSortMediano(int* array, int begin, int end){
    int *diferenca = malloc(2* sizeof *diferenca); 
    int *array_esq; 
    int *array_dir; 

    diferenca[0] = diferenca[1] = 0; 

    if(begin < end){
    int pivo = ParticaoMediano(array, begin, end); 
    
    array_esq = QuickSortMediano(array, begin, pivo - 1);
    array_dir = QuickSortMediano(array, pivo + 1, end);
    diferenca[0] = array_esq[0] > array_dir[0] ? array_esq[0] + 1 : array_dir[0] + 1;
    diferenca[1] = array_esq[1] < array_dir[1] ? array_esq[1] + 1 : array_dir[1] + 1;
    free(array_esq);
    free(array_dir);
    return diferenca;

    }
    else
        return diferenca;
}

int main (void){
    int *array, *array2, tam, i, *diferenca;
    scanf("%d", &tam);
    array = (int*)malloc(tam * sizeof(int));
    array2 = (int*)malloc(tam * sizeof(int));
    diferenca = (int*)malloc(2 * sizeof(int));
    for(i=0; i<tam; i++){
        scanf("%d", &array[i]);
        array2[i] = array[i];
    }
    diferenca = QuickSort(array, 0, tam - 1); 
    printf("%d\n", diferenca[0] - diferenca[1]);
    diferenca = QuickSortMediano(array2, 0, tam - 1);
    printf("%d\n", diferenca[0] - diferenca[1]);
    free(array);
    free(array2);
    free(diferenca);
    return 0;
}