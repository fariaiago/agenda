#include "contato.h"

struct noTele{
    char numeros[160];
    node2* nextNumber;
};

struct telefones{
    node2 *inicio;
};

// struct email{
//     char email[160];
//     email* nextEmail;
// };

struct agenda{
    node *inicio;
};

struct no{
    char nome[160];
    char cpf[160];
    numbers* headNumeros;
    node *next;
};

agenda *listCreate(){
    agenda *new= malloc(sizeof(agenda));
    if(new) new->inicio= NULL;
    return new;
}

numbers *numbersCreate(){
    numbers *new= malloc(sizeof(numbers));
    if(new){
        new->inicio= NULL;
    }
    return new;
}

node *nodeCreate(char *nome, char *cpf){
    node *new= malloc(sizeof(node));
    if(new){
        strcpy(new->nome, nome);
        strcpy(new->cpf, cpf);
        new->next= NULL;
    }
    return new;
}

node2* node2Create(char *telef){
    node2* new= malloc(sizeof(node2));
    if(new){
        strcpy(new->numeros, telef);
        new->nextNumber= NULL;
    }
    return new;
}

bool addNumbers(numbers *list, char *telef){
    node2 *new= node2Create(telef);
    if(!new) return false;
    if(list->inicio==NULL) list->inicio= new;
    else{
        node2 *aux= list->inicio;
        while(aux->nextNumber) aux= aux->nextNumber;
        aux->nextNumber= new;
    }
    return true;
}

bool add(agenda *list, char *nome, char* cpf, numbers *lista){
    node *new= nodeCreate(nome, cpf);
    if(!new) return false;
    new->headNumeros= lista;
    if(list->inicio==NULL) list->inicio= new;
    else{
        node* aux= list->inicio;
        while(aux->next) aux= aux->next;
        aux->next= new;
    }
    return true;
}

void listPrint(agenda *list){
    node *aux= list->inicio;
    while(aux){
        printf("Nome: %s\nCPF: %s\n", aux->nome, aux->cpf);
        puts("Numeros: ");
        node2* aux2= aux->headNumeros->inicio;
        while(aux2){
            printf("%s\n", aux2->numeros);
            aux2= aux2->nextNumber;
        }
        aux= aux->next;
    }
    putchar('\n');
}