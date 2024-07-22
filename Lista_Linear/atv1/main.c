#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void Menu(void){
    printf("\tEscolha uma das seguintes opções:\n\n");

    printf("\t1 = Adicionar em posição especifica\n");
    printf("\t2 = Adicionar no final\n");
    printf("\t3 = Mostrar produtos registrados\n");
    printf("\t4 = Remover do começo\n");
    printf("\t5 = Remover do final\n");
    printf("\t6 = Remover em posição especifica\n");
    printf("\t0 = Sair do programa\n");

}

int main(void){
    int opc;
    Lista list;
    Inic(&list);
    for(;;){
        Menu();
        scanf("%d", &opc);
        switch(opc){
            case 1:
                Add_Pos(&list);
            break;

            case 2:
                Get_F(&list);
            break;

            case 3:
                Print(&list);
            break;

            case 4:
                Rem_C(&list);
            break;

            case 5:
                Rem_F(&list);
            break;

            case 6:
                Ret_Pos(&list);
            break;

            case 0:
                printf("Tchau ;)");
                return 0;
            break;    
    }
    }
    
    return 0;
}

