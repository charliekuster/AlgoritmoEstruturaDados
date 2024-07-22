#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Encontrar_max(int *array, int n){
    int i, max;
    for(i=0; i<n;i++)
        max = i == 0 ? array[i] : array[i] > max ? array[i] : max;
    return max;
}

void Col_esp(char* string, int max){
    while(strlen(string) < max)
        strcat(string, " ");
}

void Col_Minusculo(char* string, int n){
    int i;
    for(i=0; i< n; i++){
        if(string[i] >= 64 && string[i] <= 90)
            string[i] += 32;
    }
}

int *Inst_Array(int k){
    int *novoArray = calloc(k+1, sizeof *novoArray);
    return novoArray;
}
void ComplArray(int *array, int n, int *freq_array){
    int i;
    for(i=0; i<n; i++)
        freq_array[array[i]]++;
}
int *Inst_p_Array(int *freq_array, int k){
    int *novaPos = malloc((k+1) * sizeof *novaPos);
    int i;
    novaPos[0] = freq_array[0];
    for(i=1; i<k+1; i++)
        novaPos[i] = novaPos[i-1] + freq_array[i];
    return novaPos;
}


void Comp_Freq_string(char** array, int n, int d, int *freq_array){
    int i;
    for(i=0; i< n; i++){
        int indexC = array[i][d] == 32 ? 0 : array[i][d] - 96;
        freq_array[indexC]++;
    }
}
int *InstantiatePositionArrayString(int *freq_array, int k, char *key){
    int *novaPos = calloc((k+1), sizeof *novaPos);
    int i;
    int indexC = key[0] == 32 ? 0 : key[0] - 96;
    int indexCant;
    novaPos[indexC] = freq_array[indexC];
    for(i=1; i<=k; i++){
        indexCant = indexC;
        indexC = key[i] == 32 ? 0 : key[i] - 96;
        novaPos[indexC] = novaPos[indexCant] + freq_array[indexC];
    }
    return novaPos;
}

int *CountingSort(int* unsorted_array, int n){
    int *array2 = malloc(n* sizeof *array2);
    int k = Encontrar_max(unsorted_array, n); 
    int *freq_array = Inst_Array(k);
    int *pos_array = NULL;
    ComplArray(unsorted_array, n, freq_array);
    pos_array = Inst_p_Array(freq_array, k);
    free(freq_array);
    int i;
    for(i=n-1; i>=0; i--)
        array2[--pos_array[unsorted_array[i]]] = unsorted_array[i]; 
    free(pos_array);
    return array2;
}

char **CountingSortString(char** array_des, int n, int column, char *key, char**array2){
    int k = 26;
    int *freq_array = Inst_Array(k);

    int *pos_array = NULL;
    Comp_Freq_string(array_des, n, column, freq_array);

    int i;
    int *novoArray;

    pos_array = InstantiatePositionArrayString(freq_array, k, key);
    novoArray = CountingSort(pos_array, k+1);
    for(i=0; i<=k; i++)
       printf("%d ", novoArray[i]);
    for(i=n-1; i>=0; i--){
        int right_index = array_des[i][column] == 32 ? 0 : array_des[i][column] - 96;
        strcpy(array2[--pos_array[right_index]], array_des[i]);
    }
    free(pos_array);
    free(novoArray);
}

char** RadixSort(char** array, int n, int d, char *key, char**array2){
    int i, j;
    for(i=d-1; i>= 0; i--){
        CountingSortString(array, n, i, key, array2);
        for(j=0; j<n; j++){
            strcpy(array[j], array2[j]);
        }    
        printf("\n");
    }
}

int main(void){
    int quant_pal;
    scanf("%d", &quant_pal);
    char *chaves = malloc(28 * sizeof *chaves);
    chaves[0] = ' ';
    char *chave = malloc(27 * sizeof *chave);
    scanf("%s", chave);
    strcat(chaves, chave);
    free(chave); 
    int i, max;
    char **array = malloc(quant_pal * sizeof *array);
    char **array2 = malloc(quant_pal * sizeof *array2);

    for(i=0; i< quant_pal; i++){
         array[i] = malloc(21 * sizeof *array[i]);
         array2[i] = malloc(21 * sizeof *array2[i]);

         scanf("%s", array[i]);
         int string_size = strlen(array[i]);      


        max = i == 0 ? string_size : string_size > max ? string_size : max;

        Col_Minusculo(array[i], string_size);
        printf("%s.\n", array[i]);    
        
    }
    printf("%d\n", max);
    for(i=0; i< quant_pal; i++)
        Col_esp(array[i], max);
    RadixSort(array, quant_pal, max, chaves, array2);
    for(i=0; i<quant_pal; i++)
        printf("%s\n", array2[i]);
    free(array);
    free(array2);
    return 0;
}