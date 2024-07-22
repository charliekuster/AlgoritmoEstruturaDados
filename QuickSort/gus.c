#include <stdio.h>
#include <stdlib.h>

void swap(int*, int, int);
int MedianOfThree(int *, int, int);
int* OptimizedQuickSort(int*, int, int);
int* DefaultQuickSort(int*, int, int);
int Partition(int*, int, int);
int OptimizedPartition(int*, int, int);
int PartitionOptimized(int*, int, int);

void PrintArray(int*, int);
int main(void){
    int *array, *array_copy,*array_max_min, n, i, value, min_height = 0;
    scanf("%d", &n);
    array = malloc(n * sizeof *array);
    array_copy = malloc(n * sizeof *array_copy);

    for(i=0; i < n; i++){
        scanf("%d", &value);
        array_copy[i] = array[i] = value; 
        }
    array_max_min = DefaultQuickSort(array, 0, n-1); // Retorna a altura/tamanho máxima(o) da recursão
    //PrintArray(array, n);
    printf("max: %d min: %d\n", array_max_min[0], array_max_min[1]);
    printf("%d", array_max_min[0] - array_max_min[1]);
    printf("\n");
    free(array_max_min);
    free(array);
    array_max_min = OptimizedQuickSort(array_copy, 0, n-1); 
    //PrintArray(array_copy, n);
    printf("max: %d min: %d\n", array_max_min[0], array_max_min[1]);
    printf("%d", array_max_min[0] - array_max_min[1]);
    free(array_max_min);
    free(array_copy);
    //printf("%d", max_height);
    //PrintArray(array, n);

    return 0;
}
void PrintArray(int* array, int size){
    int i;
    for(i=0; i<size; i++)
        printf("%d ", array[i]);
}
void swap(int* array, int index_x, int index_y){ // Troca as keys dos índices do array
    int aux = array[index_x];
    array[index_x] = array[index_y];
    array[index_y] = aux;
}
int MedianOfThree(int *a, int begin , int end){
    int middle = (begin + end)/2;
    if(a[begin] > a[middle])
        swap(a, middle, begin);
    if(a[begin] > a[end])
        swap(a, begin, end);
    if(a[middle] > a[end])
        swap(a, middle, end);
    return middle;
}
int OptimizedPartition(int* array, int begin, int end){
    int index_middle  = MedianOfThree(array, begin, end);
    swap(array, index_middle, end-1);
     int i, j, pivot_key = array[end-1];
    i = begin - 1;
    for(j=begin; j<end; j++){
        if(array[j] < pivot_key)
            swap(array, ++i, j); // Agrupa no subarranjo [0:i] os elementos menores que o pivo
    }
    swap(array, ++i, end-1); // Troca array[i] com o índice do pivo
    return i; // Retorna o índice novo do pivô
}
int Partition(int* array, int begin, int end){
    int i, j, pivot_key = array[end];
    i = begin - 1;
    for(j=begin; j<end; j++){
        if(array[j] < pivot_key)
            swap(array, ++i, j); // Agrupa no subarranjo [0:i] os elementos menores que o pivo
    }
    swap(array, ++i, j); // Troca array[i] com o índice do pivo
    return i; // Retorna o índice novo do pivô
}


int* DefaultQuickSort(int* array, int begin, int end){
    int *array_max_min = malloc(2* sizeof *array_max_min); // {max_depth, min_depth}
    int *array_left; // {max_depth, min_depth} da parte esquerda
    int *array_right; // {max_depth, min_depth} da parte direita

    /*
    max serve para tirar o max() entre a direita e a esquerda (left_max, right_max)
    Desse jeito o final da recursão retorna a maior profundidade
    min serve para tirar o min() entre a direita e a esquerda (left_max, right_max)
    Desse jeito o final da recursão retorna a menor profundidade Minimum Depth
    */
    array_max_min[0] = array_max_min[1] = 0; // Inicia as recursões de max e mim com zero

    if(begin < end){
    int pivot_index = Partition(array, begin, end); // Ordena o array em que [begin:i-1] é menor que array[i] e array[i+1:end] é maior que array[i]
    
    array_left = DefaultQuickSort(array, begin, pivot_index - 1);
    array_right = DefaultQuickSort(array, pivot_index + 1, end);
    array_max_min[0] = array_left[0] > array_right[0] ? array_left[0] + 1 : array_right[0] + 1;
    array_max_min[1] = array_left[1] < array_right[1] ? array_left[1] + 1 : array_right[1] + 1;
    free(array_left);
    free(array_right);
    return array_max_min;

    }
    else
        return array_max_min;
}
int* OptimizedQuickSort(int* array, int begin, int end){
    int *array_max_min = malloc(2* sizeof *array_max_min); // {max_depth, min_depth}
    int *array_left; // {max_depth, min_depth} da parte esquerda
    int *array_right; // {max_depth, min_depth} da parte direita

    /*
    max serve para tirar o max() entre a direita e a esquerda (left_max, right_max)
    Desse jeito o final da recursão retorna a maior profundidade
    min serve para tirar o min() entre a direita e a esquerda (left_max, right_max)
    Desse jeito o final da recursão retorna a menor profundidade Minimum Depth
    */
    array_max_min[0] = array_max_min[1] = 0; // Inicia as recursões de max e mim com zero

    if(begin < end){
    int pivot_index = OptimizedPartition(array, begin, end); // Ordena o array em que [begin:i-1] é menor que array[i] e array[i+1:end] é maior que array[i]
    
    array_left = OptimizedQuickSort(array, begin, pivot_index - 1);
    array_right = OptimizedQuickSort(array, pivot_index + 1, end);
    array_max_min[0] = array_left[0] > array_right[0] ? array_left[0] + 1 : array_right[0] + 1;
    array_max_min[1] = array_left[1] < array_right[1] ? array_left[1] + 1 : array_right[1] + 1;
    free(array_left);
    free(array_right);
    return array_max_min;

    }
    else
        return array_max_min;
}