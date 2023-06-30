#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef struct agenda agenda;
typedef struct telefones numbers;
typedef struct email email;
typedef struct no node;

agenda *listCreate();
node *nodeCreate(char*, char *);


#endif
