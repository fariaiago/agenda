#ifndef AGENDA_CLI_H
#define AGENDA_CLI_H

#include "contato.h"

#define COMANDO_ADICIONAR_CONTATO "ad"
#define COMANDO_REMOVER_CONTATO "rm"
#define COMANDO_EDITAR_CONTATO "ed"
#define COMANDO_PROCURAR_CONTATO "pr"
#define COMANDO_ADICIONAR_ARQUIVO "adaqv"
#define COMANDO_REMOVER_ARQUIVO "rmaqv"
#define COMANDO_PROCURAR_ARQUIVO "praqv"
#define COMANDO_LISTAR_CONTATOS "ls"
#define COMANDO_SAIR "s"

#define DELIMITADOR " \n"

enum STATUS_COMANDO
{
	SUCESSO, NUM_ARGS_INCORRETO, ARG_INVALIDO
};

/**
 * Imprime na tela as boas-vindas quando o programa inicia
*/
void boas_vindas();

/**
 * Callback para o comando de adicionar um contato
 * @param agenda A agenda em que a operação será realizada
 * @param args Argumentos do comando
 * @return O status do comando
*/
enum STATUS_COMANDO quando_adicionar_contato(agenda *agenda, char *args);

/**
 * Callback para o comando de remover um contato
 * @param agenda A agenda em que a operação será realizada
 * @param args Argumentos do comando
 * @return O status do comando
*/
enum STATUS_COMANDO quando_remover_contato(agenda *agenda, char *args);

/**
 * Callback para o comando de editar um contato
 * @param agenda A agenda em que a operação será realizada
 * @param args Argumentos do comando
 * @return O status do comando
*/
enum STATUS_COMANDO quando_editar_contato(agenda *agenda, char *args);

/**
 * Callback para o comando de procurar contato(s)
 * @param agenda A agenda em que a operação será realizada
 * @param args Argumentos do comando
 * @return O status do comando
*/
enum STATUS_COMANDO quando_procurar_contato(agenda *agenda, char *args);

/**
 * Callback para o comando de adicionar via arquivo
 * @param agenda A agenda em que a operação será realizada
 * @param args Argumentos do comando
 * @return O status do comando
*/
enum STATUS_COMANDO quando_adicionar_via_arquivo(agenda *agenda, char *args);

/**
 * Callback para o comando de remover via arquivo
 * @param agenda A agenda em que a operação será realizada
 * @param args Argumentos do comando
 * @return O status do comando
*/
enum STATUS_COMANDO quando_remover_via_arquivo(agenda *agenda, char *args);

/**
 * Callback para o comando de procurar via arquivo
 * @param agenda A agenda em que a operação será realizada
 * @param args Argumentos do comando
 * @return O status do comando
*/
enum STATUS_COMANDO quando_procurar_via_arquivo(agenda *agenda, char *args);

/**
 * Callback parao comando de listar todos os contatos
 * @param agenda A agenda em que a operação será realizada
 * @param args Argumentos do comando
 * @return O status do comando
*/
enum STATUS_COMANDO quando_listar_contatos(agenda *agenda, char *args);

#endif