#include "list.h"

void Inc(List *lista){
    lista->prim = 0;
    lista->ult = 0;
}

int ListVazia(List *lista){
    if(lista->prim == lista->ult){
        return 1;
    }
    else{
        return 0;
    }
}

int ListaCheia(List *lista){
    if(lista->ult == TAM){
        return 0;
    }
    else{
        return 1;
    }
}

void AddPessoa(Cliente *novo){
    printf("Insira o nome: ");
    fflush(stdin);
    fgets(novo->nome, 50, stdin);
    printf("Insira a idade: ");
    scanf("%d", &novo->idade);
    return;
}

void Print(List lista){
    if(ListVazia(&lista)){
        printf("Lista vazia");
    }
    while(lista.prim < lista.ult){
        printf("Nome: %s", lista.Pessoa[lista.prim].nome);
        printf("Idede: %d\n\n", lista.Pessoa[lista.prim].idade);
        lista.prim++;
    }

}

void AddFin(List *lista, Cliente novo){
    if(ListaCheia(lista) != 0){
        lista->Pessoa[lista->ult] = novo;
        lista->ult++;
    }
    else{
        printf("A lista esta cheia.\n");
    }
}

void AddCom(List *lista, Cliente novo){
    if(ListVazia(lista)){
        AddFin(lista, novo);
        return;
    }
    else if(ListaCheia(lista) != 0){
        int aux = lista->ult;
        while(aux != lista->prim){
            lista->Pessoa[aux]= lista->Pessoa[aux-1];
            aux--;
        }
        lista->Pessoa[lista->prim] = novo;
        lista->ult++;
    }
    else{
        printf("A lista esta cheia.\n");
        printf("A lista esta cheia.\n");
    }
    return;
}

void AddEspecifico(List *lista, Cliente *novo){
    int pos;
    scanf("%d", &pos);
    int aux = lista->ult;
    if(pos < lista->prim || pos > lista->ult){
        printf("Erro, posicao invalida");
    }
    else if(ListaCheia(lista) == 0){
        printf("A lista esta cheia.\n");
    }
    else{
        AddPessoa(novo);
        if(pos == aux){
            AddFin(lista, *novo);
        }
        else if(pos == lista->prim){
            AddCom(lista, *novo);
        }
        else{
            while(aux != pos){
                lista->Pessoa[aux] = lista->Pessoa[aux-1];    
                aux--;
            }
            lista->Pessoa[aux] = *novo;
            lista->ult++;
        }
   }
    return;
}

void RemoverTodos(List *lista){
    lista->prim = 0;
    lista->ult = 0;
    return;
}

void RemFin(List *lista){
    if(ListVazia(lista)){
        printf("Erro, lista vazia\n");
        return;
    }
    else{
        lista->ult--;
    }
    return;
}

void RemCom(List *lista){
    if(ListVazia(lista)){
        printf("Erro, lista vazia\n");
        return;
    }
    else{
        int aux = lista->prim + 1;
        while(aux != lista->ult){
            lista->Pessoa[aux-1] = lista->Pessoa[aux];
            aux++;
        }
    }
    return;
}

void Remover(List *lista){
    int pos, aux = lista->ult;
    scanf("%d", &pos);
    if(pos < lista->prim || pos > lista->ult){
        printf("Erro, posicao invalida");
    }
    else{
        if(pos == aux){
            RemFin(lista);
        }
        else if(pos == lista->prim){
            RemCom(lista);
        }
        else{
            while(aux != pos){
                lista->Pessoa[aux] = lista->Pessoa[aux-1];    
                aux--;
            }
            lista->ult--;
        }
   }
    return;
}


