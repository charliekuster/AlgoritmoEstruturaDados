#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int Particao(int array[], int esq, int dir, int recur[], int flag, int min[]){
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
    (*recur) += 1;
    if(flag == 0){
        (*min)++;
    }
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

int ParticaoMediana(int array2[], int esq, int dir, int recur[], int flag, int min[]){
    int meio = Mediana(array2, esq, dir); // indice do meio
    //printf("  mediana = %d", meio);
    int i = esq - 1, aux, pivo;
    aux = array2[meio];
    array2[meio] = array2[dir - 1];
    array2[dir - 1] = aux;
    pivo = dir - 1;
    for (int j = esq; j < dir-1; j++) {
        if (array2[j] < array2[pivo]) {
            i++;
            int temp = array2[i];
            array2[i] = array2[j];
            array2[j] = temp;
        }
    }
    int temp = array2[i + 1];
    array2[i + 1] = array2[dir - 1];
    array2[dir - 1] = temp;
    (*recur) += 1;
    if(flag == 0){
        (*min)++;
    }
    return i + 1;
}

void QuickSortMediana(int array2[], int esq, int dir, int recur[], int *flag, int min[]){
    if(esq >= dir){
        (*flag) += 1;
        return;
    }
    int pivo = ParticaoMediana(array2, esq, dir, recur, *flag, min);
    QuickSortMediana(array2, esq, pivo - 1, recur, flag, min);
    QuickSortMediana(array2, pivo + 1, dir, recur, flag, min);
}


void QuickSort(int array[], int esq, int dir, int recur[], int *flag, int min[]){
    if(esq >= dir){
        (*flag) = 1;
        return;
    }
    int pivo = Particao(array, esq, dir, recur, *flag, min);
    QuickSort(array, esq, pivo - 1, recur, flag, min);
    QuickSort(array, pivo + 1, dir, recur, flag, min);
}

int main (void){
    int *array, *array2, tam, i, *recur, *min, flag = 0;
    scanf("%d", &tam);
    array = (int*)malloc(tam * sizeof(int));
    array2 = (int*)malloc(tam * sizeof(int));
    recur = (int*)malloc(sizeof(int));
    *recur = 0;
    min = (int*)malloc(sizeof(int));
    for(i=0; i<tam; i++){
        scanf("%d", &array[i]);
        array2[i] = array[i];

    }
    QuickSort(array, 0, tam - 1, recur, &flag, min);
    printf("%d\n", *recur - flag);   
    *recur = 0;
    flag = 0;
    *min = 0;
    QuickSortMediana(array2, 0, tam - 1, recur, &flag, min);
    printf("%d", flag - *recur); 
    
    return 0;
}

// int QuickSortMediana(int array[], int esq, int dir, int recur[], int *flag, int min[]){
//     int minesq, mindir;
//     if(esq >= dir){
//         (*flag) += 1;
//         return 0;
//     }
//     (*recur)++;
//     int pivo = ParticaoMediana(array, esq, dir, recur, *flag, min);
//     minesq = QuickSortMediana(array, esq, pivo - 1, recur, flag, min);
//     mindir = QuickSortMediana(array, pivo + 1, dir, recur, flag, min);
    
//     if(minesq > mindir){
//         return mindir +1;
//     }
//     else{
//         return minesq +1;
//     }
// }


// int QuickSort(int array[], int esq, int dir, int recur[], int *flag, int min[]){
//     int minesq, mindir;
//     if(esq >= dir){
//         (*flag) += 1;
//         return 0;
//     }
//     (*recur)++;
//     int pivo = Particao(array, esq, dir, recur, *flag, min);
//     minesq = QuickSort(array, esq, pivo - 1, recur, flag, min);
//     mindir = QuickSort(array, pivo + 1, dir, recur, flag, min);
//     if(minesq > mindir){
//         return mindir +1;
//     }
//     else{
//         return minesq +1;
//     }
// }