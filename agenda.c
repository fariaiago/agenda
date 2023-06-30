#include "contato.h"
#include "fileio.h"

int menuUI(){
    int op;

    puts("O que voce quer fazer? ");
    printf("Digite: \n [0]Para adicionar uma pessoa\n [1]Para remover um contato\n [2]Para ver a lista completa\n [3]Para buscar um contato específico\n [4]Para atualizar um contato\n [5]Fechar\n");
    printf("Choice: ");
    scanf("%d", &op); 
    putchar('\n');
    return op;
}

int main(void){
    agenda* li= listCreate();

    char nome[160], telefone[160], cpf[160], email[160];
    int opt;
    puts("Bem-vindo(a) à Agenda de Contatos!");
    printf("\tLEMBRE-SE:\n\tA forma padrao das entradas sao com os espacos e caracteres especiais do jeito a seguir:\n\t\tCPF:xxx-xxx-xxx-xx\n\t\tNUMERO:+55 DDD 9xxxx-xxxx\n\n");
    opt= menuUI();
    while(opt!=4){
        numbers* numeros= numbersCreate();
        mail *emails= emailsCreate();
        switch(opt){
            case 0:
                printf("Nome: ");
                scanf(" %[^\n]", nome);
                scanf("%*c");


                printf("CPF: ");
                scanf(" %[^\n]", cpf);
                scanf("%*c");
                while(!validar_cpf(cpf)){
                    printf("CPF: ");
                    scanf(" %[^\n]", cpf);
                    scanf("%*c");
                }
                

                printf("Telefone: ");
                scanf("%[^\n]", telefone);
                scanf("%*c");
                while(!validar_telefone(telefone)){
                    printf("Telefone: ");
                    scanf("%[^\n]", telefone);
                    scanf("%*c");
                }
                addNumbers(numeros, telefone);

                printf("Email: ");
                scanf(" %[^\n]", email);
                scanf("%*c");
                while(!validar_email(email)){
                    printf("Email: ");
                    scanf(" %[^\n]", email);
                    scanf("%*c");
                }
                addEmails(emails, email);

                printf("Quer adicionar mais um numero? Digite [0] para nao ou [1] para sim: ");
                int choice;
                scanf("%d", &choice);
                while(choice!=0){
                    printf("Telefone: ");
                    scanf(" %[^\n]", telefone);
                    scanf("%*c");
                    while(!validar_telefone(telefone)){
                        printf("Telefone: ");
                        scanf("%[^\n]", telefone);
                        scanf("%*c");
                    }
                    addNumbers(numeros, telefone);

                    printf("Quer adicionar mais um numero? Digite [0] para nao ou [1] para sim: ");
                    scanf("%d", &choice);
                }
                printf("Quer adicionar mais um email? Digite [0] para nao ou [1] para sim: ");
                scanf("%d", &choice);
                while(choice!=0){
                    printf("Email: ");
                    scanf(" %[^\n]", email);
                    scanf("%*c");
                    while(!validar_email(email)){
                        printf("Email: ");
                        scanf(" %[^\n]", email);
                        scanf("%*c");
                    }
                    addEmails(emails, email);

                    printf("Quer adicionar mais um email? Digite [0] para nao ou [1] para sim: ");
                    scanf("%d", &choice);
                }

                add(li, nome, cpf, numeros, emails);
                break;

            case 1:
                printf("Voce quer excluir somente um contato ou varios? Digite[0] para um ou [1] para varios: ");
                scanf("%d", &choice);
                if(choice==0){
                    printf("Digite o nome do contato que quer excluir da agenda: ");
                    scanf(" %[^\n]", nome);
                    scanf("%*c");
                    listRemove(li, nome);
                }else{
                    printf("Digite o nome do contato que quer excluir da agenda: ");
                    scanf(" %[^\n]", nome);
                    scanf("%*c");
                    listRemove(li, nome);

                    choice=1;
                    while(choice!=0){
                        printf("Digite o nome do contato que quer excluir da agenda: ");
                        scanf(" %[^\n]", nome);
                        scanf("%*c");
                        listRemove(li, nome);

                        printf("Quer excluir mais um? 0 sim 1 nao");
                        scanf("%d", &choice);
                    }
                }
                break;
            
            case 2:
                listPrint(li);
                break;

            case 3:
                printf("Digite o nome que quer buscar na agenda: ");
                scanf(" %[^\n]", nome);
                scanf("%*c");
                search(li, nome);
                break;

        }
        putchar('\n');
        opt= menuUI();
        putchar('\n');
    }
	salvar_dados(li);
}