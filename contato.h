#ifndef CONTATO_H
#define CONTATO_H
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


typedef struct agenda agenda;
typedef struct telefones numbers;
typedef struct email email;
typedef struct no node;
typedef struct noTele node2;

agenda *listCreate();
numbers *numbersCreate();
node *nodeCreate(char*, char*);
node2 *node2Create(char*);
bool addNumbers(numbers*, char*);
bool add(agenda *, char *, char *, numbers*);
node *idk(numbers*);
void listPrint(agenda *);

#endif
