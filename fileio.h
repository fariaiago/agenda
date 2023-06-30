#ifndef AGENDA_FILEIO_H
#define AGENDA_FILEIO_H

#include <stdbool.h>

struct agenda;

/**
 * @brief Carrega os dados do banco em disco para a memória
 * @return Uma instância de agenda
*/
struct agenda *carregar_dados();

/**
 * @brief Salva os dados do banco na memória em disco
 * @param agenda* Banco de dados na memória
*/
void salvar_dados(struct agenda *agenda);

/**
 * @brief Lê dados de um arquivo e insere-os no banco de dados
 * @param caminho Caminho ao arquivo que será lido
*/
void atualizar_de_arquivo(char *caminho);

/**
 * @brief Verifica se um telefone é valido
 * @param numero String que representa o número de telefone
 * @return Se o número de telefone é valido
*/
bool validar_telefone(char *numero);

/**
 * @brief Verifica se um CPF é valido
 * @param cpf String que representa o CPF
 * @return Se o CPF é valido
*/
bool validar_cpf(char *cpf);

/**
 * @brief Verifica se um e-mail é valido
 * @param email String que representa o endereço de e-mail
 * @return Se o e-mail é valido
*/
bool validar_email(char *email);

#endif