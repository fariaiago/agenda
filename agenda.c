#include "cli.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TAMANHO_BUFFER 512
#define TAMANHO_SCANF "511"

int main(void)
{
	char bffr[TAMANHO_BUFFER], *comando;
	bool sair = false;
	boas_vindas();
	while (!sair)
	{
		enum STATUS_COMANDO status;
		fgets(bffr, TAMANHO_BUFFER-1, stdin);
		comando = strtok(bffr, DELIMITADOR);
		if(strcmp(comando, COMANDO_ADICIONAR_CONTATO) == 0)
		{
			status = quando_adicionar_contato(bffr);
		}
		else if(strcmp(comando, COMANDO_REMOVER_CONTATO) == 0)
		{
			status = quando_remover_contato(bffr);
		}
		else if(strcmp(comando, COMANDO_EDITAR_CONTATO) == 0)
		{
			status = quando_editar_contato(bffr);
		}
		else if(strcmp(comando, COMANDO_PROCURAR_CONTATO) == 0)
		{
			status = quando_procurar_contato(bffr);
		}
		else if(strcmp(comando, COMANDO_ADICIONAR_ARQUIVO) == 0)
		{
			status = quando_adicionar_via_arquivo(bffr);
		}
		else if(strcmp(comando, COMANDO_REMOVER_ARQUIVO) == 0)
		{
			status = quando_remover_via_arquivo(bffr);
		}
		else if(strcmp(comando, COMANDO_PROCURAR_ARQUIVO) == 0)
		{
			status = quando_procurar_via_arquivo(bffr);
		}
		else if(strcmp(comando, COMANDO_LISTAR_CONTATOS) == 0)
		{
			status = quando_listar_contatos(bffr);
		}
		else if(strcmp(comando, COMANDO_SAIR) == 0)
		{
			sair = true;
		}

		if(status == NUM_ARGS_INCORRETO)
		{
			puts("O comando desejado foi digitado com o número incorreto de argumentos");
		}
		else if (status == ARG_INVALIDO)
		{
			puts("O comando desejado possui um argumento com valor inválido");
		}
		
	}
	return 0;
}