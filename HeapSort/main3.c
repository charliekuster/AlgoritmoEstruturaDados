#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char Prioridade(char *vet, char x, char y, int n){
    int i;
    for(i=0; i<n; i ++){
        if(vet[i] == x){
            return x;
        }
        if(vet[i] == y){
            return y;
        }
    }
    return '\0';
}

void MaxHeapfy2(char *vet, char **vet2, int n, int n2, int meio){
    int esq, dir, index_maior, i;
    esq = meio * 2 + 1;
    dir = meio * 2 + 2;
    index_maior = meio;
    
    int tam_pai = strlen(vet2[meio]);
    if(esq < n2){
        int tam_palavra;
        tam_palavra = strlen(vet2[esq]);
        for(i=0; i<tam_palavra && i<tam_pai; i++){
            char aux;
            aux = Prioridade(vet, vet2[esq][i], vet2[index_maior][i], n);
            if(aux){
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
        }

    }
    if(dir < n2){
        int tam_palavra;
        tam_palavra = strlen(vet2[dir]);
        for(i=0; i<tam_palavra && i<tam_pai; i++){
            char aux;
            aux = Prioridade(vet, vet2[dir][i], vet2[index_maior][i], n);
            if(aux){

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
        }
    }
    
    if(index_maior != meio){
        char *aux = vet2[meio];
        vet2[meio] = vet2[index_maior];
        vet2[index_maior] = aux;
        MaxHeapfy2(vet, vet2, n, n2, index_maior);

    }    
        
    return;
}

char *HeapExtractMax(char *vet, char **vet2, int n, int *n2){
    if((*n2)<0){
        return NULL;
    }
    char *max = vet2[0];
    vet2[0] = vet2[*n2];
    (*n2)--;
    // printf("\n%d\n", *n2);
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
    letras_ord = (char*)malloc(num_chaves * sizeof(char)); 
    palavras = (char**)malloc(num_palavras * sizeof(char*));
    aux = (char**)malloc(num_palavras * sizeof(char*));
    p_invalida = (char*)malloc(256 * sizeof(char));
    scanf("%s", letras_ord);
    getchar();

    for(i=0; i<num_palavras; i++){
        char *p;
        p = (char*)malloc(256* sizeof(char));
        scanf("%s", p);
        getchar();
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


    BuildMaxHeap(letras_ord, palavras, num_chaves, num_palavras);

    // for(i=0; i<num_palavras; i++){
        // printf("%s ", palavras[i]);
    // }
    // printf("\n");

    int copia = num_palavras-1;
    for(i=num_palavras-1; i>=0; i--){
        // printf("\n %d %d \n", i, copia);
        printf("%s ", HeapExtractMax(letras_ord, palavras, num_chaves, &copia));
    }

    // for(i=0; i<num_palavras; i++){
    //     printf("%s ", aux[i]);
    // }

    return 0;
}
