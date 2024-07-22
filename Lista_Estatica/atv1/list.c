#include "list.h"

void InitList(List *listp){
    listp->first = 0;
    listp->last = 0; 
}
int EmptyList(List *listp){
    if(listp->first == listp->last){
        return 1;
    }
    else{
        return 0;
    }
}

void GetPat(Patient *new_patient){
    printf("Insert patient's name: ");
    fflush(stdin);
    fgets(new_patient->name, SIZE, stdin);
    printf("Insert patient's birth date.\n");
    printf(" Day: ");
    scanf("%d", &new_patient->date.day);
    printf(" Month: ");
    scanf("%d", &new_patient->date.month);
    printf(" Year: ");
    scanf("%d", &new_patient->date.year);
    printf("Insert patient's city: ");
    fflush(stdin);
    fgets(new_patient->city, SIZE, stdin); 
    printf("Insert patient's phone: ");
    scanf("%ld", &new_patient->phone);
    printf("Insert patient's cpf: ");
    scanf("%ld", &new_patient->cpf);
}

void PrintList(List listp){
    int i;
    if(EmptyList(&listp)){
        printf(WARNINGEMPTY);
        return;
    }
    else{
        for(i=listp.first ; i < listp.last; i++){
            printf("\tPatient[%d]\n", i);
            PrintPat(listp.patient_f[i]);
        }
    }
}

void PrintPat(Patient patient_f){
    printf("  Nome: %s", patient_f.name);
    printf("  Data: %d/%d/%d\n", patient_f.date.day, patient_f.date.month, patient_f.date.year);
    printf("  City: %s", patient_f.city);
    printf("  Phone: %ld\n", patient_f.phone);
    printf("  CPF: %ld\n\n", patient_f.cpf);
}

void AddLast(List *listp, Patient new_patient){
    if(listp->last>=SIZE2){
        printf(WARNINGFULL);
        return;
    }
    else{
        printf("Antes add: listp->last = %d\n", listp->last);
        listp->patient_f[listp->last] = new_patient;
        listp->last++;
        printf("Depois add: listp->last = %d\n", listp->last);
    }
}

void AddBegin(List *listp, Patient new_patient){
    int i;
    int aux = listp->last;
    if(EmptyList(listp)){
        listp->patient_f[listp->first] = new_patient;
        listp->last++;
    }
    else{
        while(aux > listp->first){
            listp->patient_f[aux] = listp->patient_f[aux-1];
            aux--;
        }
        listp->patient_f[listp->first] = new_patient;
        listp->last++;
    }   
}

void RemoveLast(List *listp){
    if(EmptyList(listp)){
        printf(WARNINGEMPTY);
        return;
    }
    else{
        listp->last--; 
        printf("Remove sucess");
    }
}

void RomoveFirst(List *listp){
    if(EmptyList(listp)){
        printf(WARNINGEMPTY);
        return; 
    }
    else{
        listp->first++;
        printf("Remove sucess"); 
    }
}

void Add(List *listp, Patient *new_patient){
    int p, aux2 = listp->last;
    printf("Enter the position:");
    scanf("%d", &p);
    if(p == listp->last){
        printf("listp->last = %d\n", listp->last);
       GetPat(new_patient);  
       AddLast(listp, *new_patient); 
    }
    else if(listp->first == p){
        GetPat(new_patient);
        AddBegin(listp, *new_patient);

    }
    else if(p < listp->first || p > listp->last){
        printf(ERROR);
    }
    else{
        while(p < aux2){
            listp->patient_f[aux2] = listp->patient_f[aux2-1];
            aux2--;
        }
        GetPat(new_patient); 
        listp->patient_f[p] = *new_patient;
    }
}

void Remove(List *listp){
    int p, aux= listp->last;
    printf("Enter the position:");
    scanf("%d", &p);
    if(p < listp->first || p > listp->last){
        printf(ERROR);
    } 
    else if(listp->first == listp->last){
       printf(WARNINGEMPTY); 
    }
    while(p < aux){
        listp->patient_f[aux] = listp->patient_f[aux-1];
        aux--;
    }
    listp->last--;
    return;
}