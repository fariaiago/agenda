#include "contato.h"

int main(void){
    agenda* li= listCreate();

    char nome[160], telefone[160], cpf[160];
    int opt;

    puts("O que voce quer fazer? ");
    printf("Digite: \n [0]Para adicionar\n [1]Para remover\n [2]Para ver a lista\n [3]Fechar\n");
    printf("Choice: ");
    putchar('\n');
    scanf("%d", &opt);
    while(opt!=3){
        numbers* numeros= numbersCreate();
        switch(opt){
            case 0:
                scanf(" %[^\n]", nome);
                scanf("%*c");

                scanf(" %[^\n]", cpf);
                scanf("%*c");
                

                scanf(" %[^\n]", telefone);
                scanf("%*c");
                addNumbers(numeros, telefone);

                printf("Quer adicionar mais um numero?");
                int choice;
                scanf("%d", &choice);
                while(choice!=0){
                    scanf(" %[^\n]", telefone);
                    scanf("%*c");
                    addNumbers(numeros, telefone);

                    printf("Quer adicionar mais um numero?");
                    scanf("%d", &choice);
                }

                add(li, nome, cpf, numeros);
                break;

            case 1:
                break;
            
            case 2:
                listPrint(li);
                break;

        }
                    
                    free(numeros);
                    puts("O que voce quer fazer? ");
                    printf("Digite: \n [0]Para adicionar\n [1]Para remover\n [2]Para ver a lista\n [3]Fechar\n");
                    printf("Choice: ");
                    scanf("%d", &opt);
                    putchar('\n');
    }
    

}