# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include "lista.h"

void I_lista(Lista** lista){

    (*lista) = (Lista*) malloc(sizeof(Lista));
    (*lista)->inicioLista = NULL;
    (*lista)->fimLista = NULL;
    (*lista)->tamanhoLista = 0;

    return;
}

int Menu(){

    int opcao;

    printf("\n\t(1) -> Imprimir lista");
    printf("\n\t(2) -> Inserir no inicio");
    printf("\n\t(3) -> Inserir no meio");
    printf("\n\t(4) -> Inserir no fim");
    printf("\n\t(5) -> Remover do inicio");
    printf("\n\t(6) -> Remover do meio");
    printf("\n\t(7) -> Remover do fim");
    printf("\n\t(8) -> Remover pelo RA do aluno");
    printf("\n\t(0) -> Fechar programa");
    printf("\n\nDigite uma das opcoes: ");
    scanf("%d", &opcao);

    return(opcao);
}

bool Void_L(Lista* lista){

    bool vazia = true;

    if(lista->inicioLista != NULL){
        vazia = false;
    }

    return(vazia);
}

void Print(Lista* lista){

    No* copia = lista->inicioLista;
    int contador = 1;

    printf("\n----------------------------------------------------------------------------------------\n");
    printf("\nQuantidade de itens da lista: %d\n\n", lista->tamanhoLista);
    if(Void_L(lista) == false){
        while(copia){
            printf("\n(%d) -> Nome: %s | RA: %d | Frequencia: %d%% | P1: %.2f | P2: %.2f | P3: %.2f\n", contador, copia->item.nome, copia->item.ra, copia->item.frequencia, copia->item.notas[0], copia->item.notas[1], copia->item.notas[2]);
            copia = copia->proximoNo;
            contador++;
        }
    } else {
        printf("\n\t<<< Lista vazia! >>>\n");
    }
    printf("\n----------------------------------------------------------------------------------------\n");

    return;
}

Item Get(){

    Item item;

    printf("\nDigite o nome: ");
    fflush(stdin);
    fgets(item.nome, 30, stdin);
    item.nome[strlen(item.nome) - 1] = '\0';
    printf("Digite o RA: ");
    scanf("%d", &item.ra);
    printf("Digite a frequencia: ");
    scanf("%d", &item.frequencia);
    for(int i = 1 ; i <= 3 ; i++){
        printf("Digite a nota da P%d: ", i);
        scanf("%f", &item.notas[i - 1]);
    }

    return(item);
}

void I_Inicio(Lista* lista){

    No* novoItem = (No*) malloc(sizeof(No));

    if(novoItem){
        novoItem->item = Get();
        novoItem->proximoNo = lista->inicioLista;
        if(Void_L(lista) == true){
            lista->fimLista = novoItem;
        }
        lista->inicioLista = novoItem;
        lista->tamanhoLista++;
        printf("\n\t<<< Inserido na lista com sucesso! >>>\n");
    } else {
        printf("\n\t<<< Problema ao alocar memoria! >>>\n");
    }

    return;
}

int Get_P(Lista* lista){

    int index;

    Print(lista);
    printf("\nDigite uma posicao do meio da lista: ");
    scanf("%d", &index);

    return(index - 1);
}

void InserirMeioLista(Lista* lista){

    No* novoItem = (No*) malloc(sizeof(No));
    No* copia = lista->inicioLista;
    int index = -1;

    if(novoItem){
        if(Void_L(lista) == true){
            printf("\n\t<<< Lista Vazia! Insira no inicio!!!\n");
        } else {
            if(lista->tamanhoLista > 1){
                index = Get_P(lista);
            }
            if(index > 0 && index < lista->tamanhoLista){
                for(int i = 1 ; i < index ; i++){
                    copia = copia->proximoNo;
                }
                novoItem->item = Get();
                novoItem->proximoNo = copia->proximoNo;
                copia->proximoNo = novoItem;
                lista->tamanhoLista++;
                printf("\n\t<<< Inserido na lista com sucesso! >>>\n");
            } else {
                printf("\n\t<<< Posicao invalida ou tamanho da lista insuficiente para inserir no meio! >>>\n");
            }
        }
    } else {
        printf("\n\t<<< Problema ao alocar memoria! >>>\n");
    }

    return;
}

void I_fim(Lista* lista){

    No* novoItem = (No*) malloc(sizeof(No));

    if(novoItem){
        if(Void_L(lista) == true){
            printf("\n\t<<< Lista Vazia! Insira no inicio!!!\n");
        } else {
            novoItem->item = Get();
            novoItem->proximoNo = NULL;
            lista->fimLista->proximoNo = novoItem;
            lista->fimLista = novoItem;
            lista->tamanhoLista++;
            printf("\n\t<<< Inserido na lista com sucesso! >>>\n");
        }
    } else {
        printf("\n\t<<< Problema ao alocar memoria! >>>\n");
    }

    return;
}

void ImprimirItemRemovido(No* removido){

    if(removido){
        printf("\n\tUsuario removido -> Nome: %s | RA: %d | Frequencia: %d%%\n", removido->item.nome, removido->item.ra, removido->item.frequencia);
    }

    return;
}

No* R_inicio(Lista* lista){

    No* removido = lista->inicioLista;

    if(Void_L(lista) == false){
        lista->inicioLista = lista->inicioLista->proximoNo;
        lista->tamanhoLista--;
        printf("\n<<< Removido da lista com sucesso! >>>\n");
    } else {
        printf("\n\t<<< Lista vazia! >>>\n");
    }

    return(removido);
}

No* R_Meio(Lista* lista, int constante){

    No* removido = NULL;
    No* copia = lista->inicioLista;
    int index = constante;

    if(Void_L(lista) == true){
        printf("\n\t<<< Lista vazia! >>>\n");
    } else {
        if(lista->tamanhoLista > 2){
            if(constante == -1){
                index = Get_P(lista);
            }
            if(index > 0 && index < lista->tamanhoLista - 1){
                for(int i = 1 ; i < index ; i++){
                    copia = copia->proximoNo;
                }
                removido = copia->proximoNo;
                copia->proximoNo = removido->proximoNo;
                lista->tamanhoLista--;
                printf("\n<<< Removido da lista com sucesso! >>>\n");
            } else {
                printf("\n\t<<< Posicao invalida !>>>\n");
            }
        } else {
            printf("\n\t<<< tamanho da lista insuficiente para remover do meio! >>>\n");
        }
    }

    return(removido);
}

No* R_Final(Lista* lista){

    No* removido = NULL;
    No* copia = lista->inicioLista;

    if(Void_L(lista) == true){
        printf("\n\t<<< Lista vazia! >>>\n");
    } else {
        if(lista->tamanhoLista == 1){
            removido = lista->fimLista;
            lista->inicioLista = NULL;
            lista->fimLista = NULL;
        } else {
            removido = lista->fimLista;
            while(copia->proximoNo != removido){
                copia = copia->proximoNo;
            }
            copia->proximoNo = NULL;
            lista->fimLista = copia;
        }
        lista->tamanhoLista--;
        printf("\n<<< Removido da lista com sucesso! >>>\n");
    }

    return(removido);
}

int ReceberRA(){

    int ra;

    printf("\nDigite o RA: ");
    scanf("%d", &ra);

    return(ra);
}

No* RemoverPeloRA(Lista* lista){

    No* copia = lista->inicioLista;
    No* removido;
    int ra, index;
    bool encontrado = false;

    if(Void_L(lista) == true){
        printf("\n\t<<< Lista vazia! >>>\n");
    } else {
        ra = ReceberRA();
        for(int i = 0 ; i < lista->tamanhoLista ; i++){
            if(copia->item.ra == ra){
                encontrado = true;
                index = i;
                break;
            }
            if(encontrado == false){
                copia = copia->proximoNo;
            }
        }
    }

    if(encontrado == false){
        printf("\n\t<<< RA nao encontrado! >>>\n");
    } else {
        if(index == 0){
            removido = R_inicio(lista);
        } else if(index == lista->tamanhoLista - 1){
            removido = R_Final(lista);
        } else {
            removido = R_Meio(lista, index);
        }
    }

    return(removido);
}