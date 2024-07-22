# include <stdio.h>
# include <stdbool.h>
# include "lista.h"

int main(){

    Lista *lista;
    No *removido;
    bool fimPrograma = false;

    I_lista(&lista);
    while(fimPrograma == false){
        switch(Menu()){
            case 1:
                Print(lista);
                break;
            case 2:
                I_Inicio(lista);
                break;
            case 3:
                InserirMeioLista(lista);
                break;
            case 4:
                I_fim(lista);
                break;
            case 5:
                removido = R_inicio(lista);
        
                break;
            case 6:
                removido = R_Meio(lista, -1);
          
                break;
            case 7:
                removido = R_Final(lista);
              
                break;
            case 8:
                removido = RemoverPeloRA(lista);
               
                break;
            case 0:
                fimPrograma = true;
                printf("Programa finalizado\n");
                break;
        }
    }

    return(0);
}