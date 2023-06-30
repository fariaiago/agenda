#include "fileio.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ZERO_ASCII 48

#define TEL_TAMANHO_PAIS 15
#define TEL_TAMANHO_DDD 12

#define CPF_TAMANHO_DIGITOS 9
#define CPF_TAMANHO_CRU 11
#define CPF_TAMANHO_FORMATADO 14

#define EMAIL_GMAIL "@gmail.com"
#define EMAIL_YAHOO "@yahoo.com.br"
#define EMAIL_UFTMAIL "@mail.uft.edu.br"
#define EMAIL_HOTMAIL "@hotmail.com"
#define EMAIL_PROTONMAIL "@proton.me"

struct agenda *carregar_dados()
{}

void salvar_dados(struct agenda *agenda)
{}

void adicionar_de_arquivo(char *caminho)
{}

bool validar_telefone(char *numero)
{
	size_t len = strlen(numero);
	if(len != TEL_TAMANHO_PAIS && len != TEL_TAMANHO_DDD)
	{
		return false;
	}
	char tel_limpo[TEL_TAMANHO_DDD];
	if(len == TEL_TAMANHO_PAIS)
	{
		memcpy(tel_limpo, &numero[3], TEL_TAMANHO_DDD);
	}
	for (int i = 0; i < TEL_TAMANHO_DDD; i++)
	{
		if(!isdigit(tel_limpo[i]))
		{
			return false;
		}
	}
	return true;
}

bool validar_cpf(char *cpf)
{
	size_t len = strlen(cpf);
	if(len != CPF_TAMANHO_CRU && len != CPF_TAMANHO_FORMATADO)
	{
		return false;
	}
	char cpf_limpo[11];

	if(len == CPF_TAMANHO_FORMATADO)
	{
		// Copia os nove digitos pulando os pontos
		cpf_limpo[0] = cpf[0]; cpf_limpo[1] = cpf[1]; cpf_limpo[2] = cpf[2];
		cpf_limpo[3] = cpf[4]; cpf_limpo[4] = cpf[5]; cpf_limpo[5] = cpf[6];
		cpf_limpo[6] = cpf[8]; cpf_limpo[7] = cpf[9]; cpf_limpo[8] = cpf[10];
		// Copia os dois digitos de verificação
		cpf_limpo[9] = cpf[12]; cpf_limpo[10] = cpf[13];
	}
	else
	{
		strncpy(cpf_limpo, cpf, CPF_TAMANHO_CRU);
	}

	int vlr1 = 0, vlr2 = 0;
	for (int i = 0; i < CPF_TAMANHO_DIGITOS; i++)
	{
		if(isalpha(cpf_limpo[CPF_TAMANHO_DIGITOS - 1 - i]))
		{
			return false;
		}
		int c_vlr = (int) cpf_limpo[CPF_TAMANHO_DIGITOS - 1 - i] - ZERO_ASCII;
		vlr1 += c_vlr * (9 - (i % 10));
		vlr2 += c_vlr * (9 - ((i + 1)) % 10);
	}
	vlr1 = (vlr1 % 11) % 10;
	vlr2 += vlr1 * 9;
	vlr2 = (vlr2 % 11) % 10;
	return vlr1 == cpf_limpo[9] - ZERO_ASCII && vlr2 == cpf_limpo[10] - ZERO_ASCII;
}

bool validar_email(char *email)
{
	if(strstr(email, EMAIL_GMAIL) > email || strstr(email, EMAIL_YAHOO) > email || strstr(email, EMAIL_UFTMAIL) > email
			|| strstr(email, EMAIL_HOTMAIL) > email || strstr(email, EMAIL_PROTONMAIL) > email)
		return true;
	return false;
}