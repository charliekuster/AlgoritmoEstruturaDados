#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "extern.h"
#include "list.h"

void Menu(){
    
    printf("\n\n\t\t\t Patient list\n");
    printf("\t\t\t_______________\n\n");
    printf("\t  Choose one of the options below:\n");
    printf("\t(1) Print list\n");
    printf("\t(2) Add at begin\n");
    printf("\t(3) Add last\n");
    printf("\t(4) Remove last\n");
    printf("\t(5) Remove first\n");
    printf("\t(6) Add at espicific\n");
    printf("\t(7) Remove at espicfic\n");
    printf("\t(0) Exit\n");
}

void HandleMenu(int choice, Patient *new_patient, List *listp){
    
    switch(choice){
        case 1:
        PrintList(*listp);
        break;
        case 2:
        GetPat(new_patient);
        AddBegin(listp, *new_patient);
        break;
        case 3:
        GetPat(new_patient); 
        AddLast(listp, *new_patient);
        break;
        case 4:
        RemoveLast(listp);
        break;
        case 5:
        RomoveFirst(listp);
        break;
        case 6:
        Add(listp, new_patient);
        break;
        case 7:
        Remove(listp);
        return;
        case 0:
        printf("Good bye :(\n");
        exit(0);
        break;
        default:
        printf(WARNINGTYPE);
        break;

    }

}

int main (void){
    Patient new_patient;
    List listp;
    int choice;
    for(;;){
        Menu();
        scanf("%d", &choice);
        system("clear");
        HandleMenu(choice, &new_patient, &listp);

    }
    return 0;
}

