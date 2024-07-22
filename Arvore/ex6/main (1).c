// Arquivao

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_S 100

typedef struct Arvore Arvore;

struct Arvore{
    char letra;
    struct Arvore* esq;
    struct Arvore* dir;
};

typedef struct Node Node;
typedef struct Queue Queue;

struct Node{
    Arvore tree;
    struct Node* next;
};
struct Queue{
    struct Node* head;
    int size;
};

char* RemoveParentheses(char* string){
       int qtt_non_parentheses = 0;
    int qtt_parentheses = 0;
    int cont;
    for(cont=0; string[cont] != '\0'; cont++){
        if(string[cont] == ')')
            qtt_parentheses--;
        if(qtt_parentheses>0){
            string[qtt_non_parentheses] = string[cont];
            qtt_non_parentheses++;
        }
        if(string[cont] == '(')
            qtt_parentheses++;
    }
    string[qtt_non_parentheses] = '\0';
    return string;
}
// Remove espacos em braco da string

char* RemoveWhitespace(char* string){
    // Incrementa ao achar um elemento que não é whitespace
    int qtt_non_whitespace = 0;
    int cont;
    for(cont=0; string[cont] != '\0'; cont++){
        if(string[cont] != ' '){
            string[qtt_non_whitespace] = string[cont];
            qtt_non_whitespace++;
        }
    }
    string[qtt_non_whitespace] = '\0';
    return string;
}

// Retorna Nivel de Precedencia dos operadores
/*  Maior    () = 3
          * e / = 2
    Menor + e - = 1
*/
int DefinePrecedence(char letra){
    int precedence;
    switch(letra){
        case '(':
            precedence = 3;
            break;
        case ')':
            precedence = 3;
            break;
        case '*':
            precedence = 2;
            break;
        case '/':
            precedence = 2;
            break;
        case '+':
            precedence = 1;
            break;
        case '-':
            precedence = 1;
            break;
        default:
            precedence = 10; // Caso for um numero ou algo diferente de operador
    }
    return precedence;
}

// Retorna índice do operador com menor precedência na string

int FindLowerPrecedence(char *string){
     int cont, indice = 0;
    for(cont = 0; string[cont] != '\0'; cont++){
        if(DefinePrecedence(string[cont]) <= DefinePrecedence(string[indice])) // Compara a precedencia do string[indice] com os proximos caracteres da string
            indice = cont;
        if(string[cont] == '('){ // "Pula" oque ta dentro dos parenteses // Ta com problema
            int qtt_parentheses = 1;
            while(qtt_parentheses){
                cont++;
                if(string[cont] == '(')
                    qtt_parentheses++;
                if(string[cont] == ')')
                    qtt_parentheses--;
                }
        }
    }
    return indice;
}

// Dada uma expressao e um indice retorna a expressao a esquerda do indice na string

char* ExpressionLeft(char *expression, int index){
    char* new_string = (char*) malloc(100*sizeof(char));
    strcpy(new_string, expression);
    new_string[index] = '\0';
    return new_string;
}

char* ExpressionRight(char *expression, int index){
    char* expression_right = (char*) malloc(100* sizeof(char));
    int cont;
    for(cont=0; expression[index+1] != '\0'; cont++, index++)
        expression_right[cont] = expression[index+1];
    return expression_right;
}

// Inicia Árvore como Null;

Arvore* InitTree(){
    return NULL;
}

// Retorna uma Nova Árvore que possui {letra, NULL, NULL};

Arvore* InstantiateTree(char* expression){
    Arvore* new_tree = (Arvore*) malloc(sizeof(Arvore)); // Malloca a arvore

    int index = FindLowerPrecedence(expression); // adiciona na arvore o operador com menor precedencia
    while(expression[index] == '('){
        RemoveParentheses(expression);
        index = FindLowerPrecedence(expression);
    }
    new_tree->letra = expression[index];
    
    char* expression_left, expression_right;
    int precedence = DefinePrecedence(expression[index]);
    if(precedence != 10){
    new_tree->esq = InstantiateTree(ExpressionLeft(expression, index)); // Cria a expressão da esquerda
    new_tree->dir = InstantiateTree(ExpressionRight(expression, index));
    }
    else
        new_tree->esq = new_tree->dir = NULL;
    return new_tree;
}



Node* InstantiateNode(Arvore tree){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->tree = tree;
    new_node->next = NULL;
    return new_node;
}
Queue* InstantiateQueue(Node* node){
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));
    new_queue->head = node;
    new_queue->size = 1;
    return new_queue;
}
void Enqueue(Queue* queue, Node* new_node){
    new_node->next = queue->head;
    queue->head = new_node;
    queue->size++;
}
void Dequeue(Queue*queue){
    Node* tracker = queue->head;
    if(tracker == NULL) return;
    Node* tracker2 = tracker->next;
    if(tracker2 == NULL){
        queue->head = NULL;
        queue->size--;
        free(tracker);
        return;
    }
    while(tracker2->next != NULL){
        tracker = tracker->next;
        tracker2 = tracker->next;
    }
    tracker->next = NULL;
    queue->size--;
    free(tracker2);
}

void PrintNivel(Queue* queue){
    int  cont = 0;
    Node* end = queue->head;
    Node* start = queue->head;
    while(queue->size > 0){
        // começo e final do nivel
        Node* tail = queue->head;
        while(tail->next != NULL)
            tail = tail->next;
        if(tail == start){
            printf("Nivel %d: ", cont);
            cont++;
        }
        printf("%c", tail->tree.letra);
        if(tail->tree.esq)
            Enqueue(queue, InstantiateNode(*tail->tree.esq));
        if(tail->tree.dir)
            Enqueue(queue, InstantiateNode(*tail->tree.dir));
        if(tail == end){
            Node*aux = queue->head;
            if(aux->next != NULL){
                while(aux->next != end)
                    aux = aux->next;
            }
            start = aux;
            end = queue->head;
            printf("\n");
            }
        Dequeue(queue);
       } 
    }

int main(void){    
    char expressao[TAM_S];
    while(scanf("%[^\n]%*c", &expressao) != EOF){
    
    RemoveWhitespace(expressao);

    Arvore* tree;
    tree = InitTree();
    tree = InstantiateTree(expressao);


    Node* root_node = NULL;
    root_node = InstantiateNode(*tree);
    Queue* queue = NULL;
    queue = InstantiateQueue(root_node);
    PrintNivel(queue);
    printf("\n");
    }
    return 0;
}