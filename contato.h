#ifndef CONTATO_H
#define CONTATO_H
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define gmail "@gmail.com"
#define hotmail "@hotmail.com"
#define proton "@proton.me"
#define yahoo "@yahoo.com.br"
#define uft "@mail.uft.edu.br"

typedef struct agenda agenda;
typedef struct telefones numbers;
typedef struct email mail;
typedef struct no node;
typedef struct noTele node2;
typedef struct noEmail node3;

/*
 * Função que cria a lista principal
*/
agenda *listCreate();

/*
 * Função que cria a lista de numeros
*/
numbers *numbersCreate();

/**
 * Função que cria a lista de emails
*/
mail *emailsCreate();

/**
 * Função que cria o nó em relação a lista principal;
 * @param char* os dois se referem respectivamente ao nome e cpf
*/
node *nodeCreate(char*, char*);

/**
 * Função que cria o nó em relação a lista de numeros
 * @param char* se refere ao telefone
*/
node2 *node2Create(char*);

/**
 * Função que cria o nó em relação a lista de emails
 * @param char* se refere ao email
*/
node3 *node3Create(char*);

/**
 * Função que adiciona os numeros numa lista de telefones
 * @param numbers* a lista que a operação será realizada
 * @param char* se refere aos numeros de telefone
*/
bool addNumbers(numbers*, char*);

/**
 * Função que adiciona os emails numa lista de emails
 * @param mail* lista em que a operação será realizada
 * @param char* se refere aos emails
*/
bool addEmails(mail*, char*);

/**
 * Função que adiciona o nome, cpf, lista de numeros e lista de emails na lista principal(agenda)
 * @param agenda* se refere a lista principal
 * @param char* se refere, respectivamente, ao nome e cpf
 * @param numbers* lista de numeros
 * @param mail* lista de emails
*/
bool add(agenda *, char *, char *, numbers*, mail*);

/**
 * Função que remove um contato específico da lista
 * @param agenda* lista em que a operação será realizada
 * @param char* se refere ao nome
*/
bool listRemove(agenda*, char*);

/**
 * Função que procura um contato específico na agenda e exibe os detalhes do mesmo
 * @param agenda* lista que a operação será realizada
 * @param char* se refere ao nome
*/
bool search(agenda*, char*);

/**
 * Função que imprime a lista completa de contatos
 * @param agenda* lista que a operação será realizada
*/
void listPrint(agenda *);

#endif
