#include "contato.h"

int menuUI(){
    int op;

    puts("O que voce quer fazer? ");
    printf("Digite: \n [0]Para adicionar\n [1]Para remover\n [2]Para ver a lista\n [3]Buscar\n [4]Fechar\n");
    printf("Choice: ");
    putchar('\n');
    scanf("%d", &op); 
    return op;
}

int main(void){
    agenda* li= listCreate();

    char nome[160], telefone[160], cpf[160], email[160];
    int opt;

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
                

                printf("Telefone: ");
                scanf("%[^\n]", telefone);
                scanf("%*c");
                addNumbers(numeros, telefone);

                printf("Email: ");
                scanf(" %[^\n]", email);
                scanf("%*c");
                addEmails(emails, email);

                printf("Quer adicionar mais um numero? Digite [0] para nao ou [1] para sim: ");
                int choice;
                scanf("%d", &choice);
                while(choice!=0){
                    printf("Telefone: ");
                    scanf(" %[^\n]", telefone);
                    scanf("%*c");
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
}