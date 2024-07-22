#include "list.h"

void Inic(Lista *list){
    list->ult = 0;
    list->prim = 0;
}

void Get(Lista *list, int produto){

    printf("Insira as seguintes informações do produto:\n");
    printf("Nome: ");
    scanf("%s", list->prod[produto].nome);
    printf("Código: ");
    scanf("%d", &list->prod[produto].chave);
    printf("Preço:");
    scanf("%f", &list->prod[produto].preco);

}

void Get_F(Lista *list){

    printf("Insira as seguintes informações do produto:\n");
    printf("Nome: ");
    scanf("%s", list->prod[list->ult].nome);
    printf("Código: ");
    scanf("%d", &list->prod[list->ult].chave);
    scanf("%f", &list->prod[list->ult].preco);
    
}

void Rem_F(Lista *list){
    if(list->ult != list->prim){
        printf("item: %d\n", list->ult);
        list->ult--;
    }
    else{
        printf("Erro :(\n");
    }
}

void Rem_C(Lista *list){
    if(list->prim != list->ult){
        list->prim++;
    }
    else{
        printf("Erro :(\n");
    }
}

void Add_Pos(Lista* list){
    int p_des, i, j, ultimo;
    ultimo = list->ult;

    printf("Digite a posição desejada:");
    scanf("%d", &p_des);

    while(ultimo > p_des){
        list->prod[ultimo] = list->prod[ultimo-1];
        ultimo--;
    }
    Get(list, ultimo);
    list->ult++;
}

void Ret_Pos(Lista *list){

    int p_des, i, j, ultimo;
    ultimo = list->ult;

    printf("Digite a posição desejada:");
    scanf("%d", &p_des);

    while(ultimo > p_des){
        list->prod[ultimo-2] = list->prod[ultimo-1];
        ultimo--;
    }

    list->ult--;
}

void Print(Lista *list){
    int i;
    if(list->ult == 0){
        printf("Lista vazia");
        return;
    }
    for(i = list->prim; i< list->ult; i++){
        printf("Nome do produto: %s\n", list->prod[i].nome);
        printf("Código: %d\n", list->prod[i].chave);
        printf("Preço: %.2f\n\n", list->prod[i].preco);
    }
}