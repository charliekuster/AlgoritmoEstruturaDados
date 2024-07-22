#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 8000
 
int get_index(char letter, char *lexic){
    int i;
    for(i=0; i < MAX; i++){
        if(letter == lexic[i]){
            // printf("letter %c index %d\n", letter, i);
            return i;
        } else if (lexic[i] == '\0'){
            break;
        }
    }
 
    return -1;
}
 
int verifica(char *vet, char *lexic){
    int i;
    for(i=0; i < MAX; i++){
        if(vet[i] == '\0'){
            return 0;
        }
        if(get_index(vet[i], lexic) == -1){
            printf("A palavra %s eh invalida", vet);
            return -1;
        }
    }
    return 0;
}
 
int compare_words(char *word1,  char *word2, char *lexic){
    int i, tempIdx1, tempIdx2;
    for(i=0; i < MAX; i++){
        if(word1[i] == '\0' || word2[i] == '\0') {
            // Se chegou ao final de uma das palavras, considera a menor
            return word2[i] == '\0';
        }
        tempIdx1 = get_index(word1[i], lexic);
        tempIdx2 = get_index(word2[i], lexic);
 
        if(tempIdx1 < tempIdx2){
            return 0;
        } else if(tempIdx1 > tempIdx2){
            return 1;
        }
    }
 
    return 0;
}
 
void max_heapify(char **vet, int i, int n, char *lexic){ // função que organiza o vetor como um heap
    int left = 2*i + 1;  // idx
    int right = 2*i + 2;  // idx
    int largest = i;  // idx
    if(left < n && compare_words(vet[left], vet[largest], lexic)){  // se o filho da esq for maior que o pai
        largest = left;  // auxiliar chamado largest recebe o idx do filho da esq
    }
    if(right < n && compare_words(vet[right], vet[largest], lexic)){  // se o filho da dir for maior que o pai
        largest = right;  // auxiliar chamado largest recebe o idx do filho da dir
    }
    if(largest != i){  // se o idx do maior filho for diferente do idx do pai
        char *aux = vet[i]; // aux recebe o valor do pai
        vet[i] = vet[largest]; // o pai recebe o valor do maior filho
        vet[largest] = aux; // o maior filho recebe o valor do pai
        max_heapify(vet, largest, n, lexic); // chama a função max_heapify novamente mas agora com o maior filho como pai
    }
}
 
void build_max_heap(char **vet, int n, char *lexic){ // função que organiza o vetor como um heap
    int i;
    for(i = n/2; i >= 0; i--){ // começa do meio do vetor e vai até o começo
        max_heapify(vet, i, n, lexic); // chama a função max_heapify para cada elemento do vetor
    }

    for(int k =  0; k < n; k++) printf("%s ", vet[k]);
    printf("\n");
}
 
char *heap_extract_max(char **vet, int *n, char *lexic){
    if(*n < 1){ // se o tamanho do vetor for menor que 1
        printf("Heap underflow");
        return NULL;
    }
    char *max = vet[0]; // auxiliar max recebe o primeiro elemento do vetor
    vet[0] = vet[*n-1]; // o primeiro elemento do vetor recebe o ultimo elemento
    (*n)--; // diminui o tamanho do vetor
    max_heapify(vet, 0, *n, lexic); // chama a função max_heapify para o primeiro elemento do vetor
    return max; // retorna o maior elemento do vetor
}
 
char **heap_sort(char **vet, int *n, char *lexic){
    build_max_heap(vet, *n, lexic); // chama a função build_max_heap para organizar o vetor como um heap
    int i;
    char **saida = (char**)malloc((*n)*sizeof(char*)); // cria o vetor saída
    for(i=(*n)-1; i>=0; i--){ // começa do ultimo elemento do vetor e vai até o segundo elemento
        saida[i] = (char*)malloc(MAX*sizeof(char)); // aloca espaço para cada elemento do vetor
        saida[i] = heap_extract_max(vet, n, lexic); // chama a função heap_extract_max para cada elemento do vetor
    }
    return saida; // retorna o vetor ordenado    
 
}
 
int main(){
    char **vetvet;
    int N, S; // N = número de palavras, S = tamanho do alfabeto
    scanf("%d %d", &N, &S);
    vetvet = (char**)malloc(N*sizeof(char*));
    int i;
    char *lexic = (char*)malloc(S*sizeof(char));
    scanf("%s", lexic);
    getchar();
    int tam = N;
    int res;
    for(i=0; i<tam; i++){
        vetvet[i] = (char*)malloc(MAX*sizeof(char));
        scanf("%s", vetvet[i]);
        getchar();
        res = verifica(vetvet[i], lexic);
        if(res == -1){
            return 0;
        }
    }
 
    char **ordenado = heap_sort(vetvet, &N, lexic);
    i = 0;
    if(tam != 1){
        for(i=0; i<tam-1; i++){
            printf("%s ", ordenado[i]);
            free(ordenado[i]);
        }
    }
    printf("%s\n", ordenado[i]);
    free(ordenado[i]);
 
    free(lexic);
    for(i=0; i<N; i++){
        free(vetvet[i]);
    }
}