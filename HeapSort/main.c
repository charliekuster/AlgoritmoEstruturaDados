#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Prioridade(char *vet, int x, int y, int n){
    int i;
    for(i=0; i<n; i ++){
        if(vet[i] == x){
            return x;
        }
        if(vet[i] == y){
            return y;
        }
    }
    return -1;
}

void MaxHeapfy2(char *vet, char **vet2, int n, int n2, int meio){
    int esq, dir, index_maior, i;
    //char *aux;
    esq = meio * 2 + 1;
    dir = meio * 2 + 2;
    index_maior = meio;
    int tam_pai = strlen(vet2[meio]);
    if(esq <= n2){
        int tam_palavra;
        tam_palavra = strlen(vet2[esq]);
        for(i=0; i<tam_palavra && i<tam_pai; i++){
            char aux;
            aux = Prioridade(vet, vet2[esq][i], vet2[index_maior][i], n);
            if(vet2[esq][i] != vet2[index_maior][i]){
                if(aux == vet2[esq][i]){
                    index_maior = esq;
                    tam_pai = tam_palavra;
                    break;
                }
                else if(aux == vet2[index_maior][i]){
                    break;
                }
            }
        }
        if(i == tam_palavra){
            index_maior = esq;
        }
    }
    if(dir <= n2){
        int tam_palavra;
        tam_palavra = strlen(vet2[dir]);
        for(i=0; i<tam_palavra && i<tam_pai; i++){
            char aux;
            aux = Prioridade(vet, vet2[dir][i], vet2[index_maior][i], n);
            if(vet2[dir][i] != vet2[index_maior][i]){
                if(aux == vet2[dir][i]){
                    index_maior = dir;
                    tam_pai = tam_palavra;
                    break;
                }
                else if(aux == vet2[index_maior][i]){
                    break;
                }
            }
        }
        if(i == tam_palavra){
            index_maior = esq;
        }
    }
        //swapw
        if(index_maior == meio){
            return;
        }    
        if(index_maior <= n2){
        int x = strlen(vet2[meio]);
        int y = strlen(vet2[index_maior]);
        char *aux = (char*)malloc(x * sizeof(char));
        char *aux2 = (char*)malloc(y * sizeof(char));
        strcpy(aux, vet2[meio]);
        strcpy(aux2, vet2[index_maior]);
        vet2[meio] = aux2;
        vet2[index_maior] = aux;
        MaxHeapfy2(vet, vet2, n, n2, index_maior);
    }
}

char *HeapExtractMax(char *vet, char **vet2, int n, int *n2){
    if(n2<0){
        return NULL;
    }
    char *max = (char*)malloc(strlen(vet2[0]) * sizeof(char));
    strcpy(max, vet2[0]);
    int x = strlen(vet2[0]);
    int y = strlen(vet2[*n2]);
    char *aux = (char*)malloc(x * sizeof(char));
    char *aux2 = (char*)malloc(y * sizeof(char));
    strcpy(aux, vet2[0]);
    strcpy(aux2, vet2[*n2]);
    vet2[0] = aux2;
    (*n2)--;
    MaxHeapfy2(vet, vet2, n, *n2, 0);
    return max;
}

void BuildMaxHeap(char *vet, char **vet2, int n, int n2){
    int meio;
    meio = n2/2;
    while(meio >= 0){
        MaxHeapfy2(vet, vet2, n, n2, meio);
        meio--;
    }
    return;
}

int main(void){
    int num_palavras, num_chaves;
    int i, j, cont=0;
    char *letras_ord, **palavras, *p_invalida, **aux;

    scanf("%d", &num_palavras);

    scanf("%d", &num_chaves);

    letras_ord = (char*)malloc(num_chaves+1 * sizeof(char)); 
    palavras = (char**)malloc(num_palavras * sizeof(char*));
    aux = (char**)malloc(num_palavras * sizeof(char*));
    p_invalida = (char*)malloc(256 * sizeof(char));


    for(i= 0; i<num_chaves; i++){
        scanf(" %c", &letras_ord[i]);
    }

    for(i=0; i<num_palavras; i++){
        char *p;
        p = (char*)malloc(256* sizeof(char));
        scanf(" %s", p);
        palavras[i] = (char*)malloc((strlen(p) + 1) * sizeof(char));
        strcpy(palavras[i], p);
        for(j=0; j<strlen(p); j++){
            if(Prioridade(letras_ord, p[j], p[j], num_chaves) == -1){
                cont++;
                strcpy(p_invalida, p);
                break;
            }
        }
    
        free(p);
    }

    if(cont != 0){
        printf("A palavra %s eh invalida\n", p_invalida);
        return 0;
    }


    BuildMaxHeap(letras_ord, palavras, num_chaves, num_palavras-1);

    // for(i=0; i<num_palavras; i++){
    //     printf("%s ", palavras[i]);
    // }
    // printf("\n");

    int copia = num_palavras-1;

    for(i=num_palavras-1; i>=1; i--){

        printf("%s ", HeapExtractMax(letras_ord, palavras, num_chaves, &copia));
    }
    printf("%s", HeapExtractMax(letras_ord, palavras, num_chaves, &copia));

    // for(i=0; i<num_palavras; i++){
    //     printf("%s ", aux[i]);
    // }
    free(letras_ord);
    free(palavras);
    free(aux);
    free(p_invalida);

    return 0;
}