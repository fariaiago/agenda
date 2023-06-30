#include "cli.h"
#include <stdio.h>

void boas_vindas()
{
	printf("Bem-vindo(a) à Agenda de contatos.\n"
			"\tOs comandos disponíveis são:\n"
			"COMANDO\t\t\tDESCRIÇÂO\t\t\tARGUMENTOS\n"
			COMANDO_ADICIONAR_CONTATO"\t\t\tAdiciona um contato\n"
			COMANDO_REMOVER_CONTATO"\t\t\tRemove um contato\n"
			COMANDO_EDITAR_CONTATO"\t\t\tEdita um contato\n"
			COMANDO_PROCURAR_CONTATO"\t\t\tProcura por contatos no banco de dados\n"
			COMANDO_ADICIONAR_ARQUIVO"\t\t\tAdiciona contatos via arquivo\n"
			COMANDO_REMOVER_ARQUIVO"\t\t\tRemove contatos via arquivo\n"
			COMANDO_PROCURAR_ARQUIVO"\t\t\tProcura contatos via arquivo\n"
			COMANDO_LISTAR_CONTATOS"\t\t\tLista todos os contatos\n"
			COMANDO_SAIR"\t\t\tSai do programa\n");
}

enum STATUS_COMANDO quando_adicionar_contato(agenda *agenda, char *args)
{}

enum STATUS_COMANDO quando_remover_contato(agenda *agenda, char *args)
{}

enum STATUS_COMANDO quando_editar_contato(agenda *agenda, char *args)
{}

enum STATUS_COMANDO quando_procurar_contato(agenda *agenda, char *args)
{}

enum STATUS_COMANDO quando_adicionar_via_arquivo(agenda *agenda, char *args)
{}

enum STATUS_COMANDO quando_remover_via_arquivo(agenda *agenda, char *args)
{}

enum STATUS_COMANDO quando_procurar_via_arquivo(agenda *agenda, char *args)
{}

enum STATUS_COMANDO quando_listar_contatos(agenda *agenda, char *args)
{}