/*Faça uma lista sequencial estatica que contenha data de nascimento cidade telefone nome e cpf e que coloque uma senha*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "extern.h"

typedef struct{
    int day;
    int month;
    int year;
}BirthDate;

typedef struct{
    char name[SIZE];
    BirthDate date;
    char city[SIZE];
    long int phone;
    long int cpf;
    int password; 
}Patient;

typedef struct{
    Patient patient_f[SIZE2];
    int first;
    int last;
}List;

int EmptyList(List*);

void InitList(List*);

void GetPat(Patient*);

void PrintList(List);

void PrintPat(Patient);

void AddBegin(List*, Patient);

void AddLast(List*, Patient);

void RemoveLast(List*);

void RomoveFirst(List*);

void Add(List *, Patient *);

void Remove(List *listp);