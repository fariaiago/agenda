#include "contato.h"
#include "fileio.h"

struct noTele{
    char numeros[160];
    node2* nextNumber;
};

struct telefones{
    node2 *inicio;
};

struct noEmail{
    char email[160];
    node3* nextEm;
};

struct email{
   node3* inicioEm;
};

struct agenda{
    node *inicio;
};

struct no{
    char nome[160];
    char cpf[160];
    numbers* headNumeros;
    mail* headEmail;
    node *next;
};

agenda *listCreate(){
    agenda *new= malloc(sizeof(agenda));
    if(new) new->inicio= NULL;
    return new;
}

numbers *numbersCreate(){
    numbers *new= malloc(sizeof(numbers));
    if(new) new->inicio= NULL;
    return new;
}

mail* emailsCreate(){
    mail* new= malloc(sizeof(mail));
    if(new) new->inicioEm= NULL;
    return new;
}

node *nodeCreate(char *nome, char *cpf){
    node *new= malloc(sizeof(node));
    if(new){
        strcpy(new->nome, nome);
        strcpy(new->cpf, cpf);
        new->next= NULL;
    }
    return new;
}

node2* node2Create(char *telef){
    node2* new= malloc(sizeof(node2));
    if(new){
        strcpy(new->numeros, telef);
        new->nextNumber= NULL;
    }
    return new;
}

node3 *node3Create(char *email){
    node3 *new= malloc(sizeof(node3));
    if(new){
        strcpy(new->email, email);
        new->nextEm= NULL;
    }
    return new;
}

bool addNumbers(numbers *list, char *telef){
    node2 *new= node2Create(telef);
    if(!new) return false;
    if(list->inicio==NULL) list->inicio= new;
    else{
        node2 *aux= list->inicio;
        while(aux->nextNumber) aux= aux->nextNumber;
        aux->nextNumber= new;
    }
    return true;
}

bool addEmails(mail *list, char *email){
    node3 *new= node3Create(email);
    if(!new) return false;
    if(list->inicioEm==NULL) list->inicioEm= new;
    else{
        node3 *aux= list->inicioEm;
        while(aux->nextEm) aux= aux->nextEm;
        aux->nextEm= new;
    }
    return true;
}

bool add(agenda *list, char *nome, char* cpf, numbers *listaNum, mail* listaEm){
    node *new= nodeCreate(nome, cpf);
    if(!new) return false;
    new->headNumeros= listaNum;
    new->headEmail= listaEm;
    if(list->inicio==NULL) list->inicio= new;
    else{
        if(strcmp(new->nome, list->inicio->nome)<0){
            new->next= list->inicio;
            list->inicio= new;
        }else{
            node *y= list->inicio;
            while(y->next){
                if(strcmp(y->next->nome, new->nome) >0) break;
                y= y->next;
            }
            new->next= y->next;
            y->next= new;
        }
    }
    return true;
}

bool listRemove(agenda *list, char *nome){
    node *ant= NULL;
    node *p= list->inicio;

    while(p && strcmp(p->nome, nome)!=0){
        ant= p;
        p= p->next;
    }
    if(!p) return false;
    if(!ant) list->inicio= p->next;
    else ant->next= p->next;

    free(p);
    return true;
}

bool search(agenda *list, char* nome){
    node *ant= NULL;
    node *p= list->inicio;

    while(p && strcmp(p->nome, nome)){
        ant= p;
        p= p->next;
    }
    if(!p){
        puts("Contato inexistente.");
        return false;
    }
    if(!ant){
        puts("------------------------------------------------------");
        printf("Nome: %s\nCPF: %s\n", nome, p->cpf);
        puts("\tNumeros: ");
        node2* aux= p->headNumeros->inicio;
        printf("Numero principal: %s\n", aux->numeros);
        puts("Outros: ");
        aux= aux->nextNumber;
        while(aux){
            printf("%s\n", aux->numeros);
            aux= aux->nextNumber;
        }

        node3 *aux2= p->headEmail->inicioEm;
        puts("\tEmails: ");
        printf("Email principal: %s\n", aux2->email);
        aux2= aux2->nextEm;
        puts("Outros: ");
        while(aux2){
            printf(" %s\n", aux2->email);
            aux2= aux2->nextEm;
        }
    }else{
        ant= p;
        puts("------------------------------------------------------");
        printf("Nome: %s\nCPF: %s\n", nome, ant->cpf);
        puts("\tNumeros: ");
        node2* aux= ant->headNumeros->inicio;
        printf("Numero principal: %s\n", aux->numeros);
        puts("Outros: ");
        aux= aux->nextNumber;
        while(aux){
            printf("%s\n", aux->numeros);
            aux= aux->nextNumber;
        }

        node3 *aux2= ant->headEmail->inicioEm;
        puts("\tEmails: ");
        printf("Email principal: %s\n", aux2->email);
        aux2= aux2->nextEm;
        puts("Outros: ");
        while(aux2){
            printf(" %s\n", aux2->email);
            aux2= aux2->nextEm;
        }
    }
    return true;
}

void listPrint(agenda *list){
    node *aux= list->inicio;
    while(aux){
        puts("------------------------------------------------------");
        printf("Nome: %s\nCPF: %s\n", aux->nome, aux->cpf);
        puts("\tNumeros: ");

        node2* aux2= aux->headNumeros->inicio;
        printf("Numero principal: %s\n", aux2->numeros);
        puts("Outros: ");
        aux2= aux2->nextNumber;
        int lps=0;
        while(aux2){
            printf("%s\n", aux2->numeros);
            aux2= aux2->nextNumber;
            lps++;
            if(lps==2) break;
        }

        puts("\tEmails: ");
        node3 *aux3= aux->headEmail->inicioEm;
        printf("Email principal: %s\n", aux3->email);
        puts("Outros: ");
        aux3= aux3->nextEm;
        lps=0;
        while(aux3){
            printf(" %s\n", aux3->email);
            aux3= aux3->nextEm;
            lps++;
            if(lps==2) break;
        }
        aux= aux->next;
        putchar('\n');
    }
    putchar('\n');
}

bool updateContact(agenda* lista, numbers *listanum, mail* listaem, char* nome,char *num, char *telef){
    node*aux= lista->inicio;
    while(aux && strcmp(aux->nome, nome)!=0){
        aux=aux->next;
    }
    if(validar_telefone(telef)){
        addNumbers(aux->headNumeros, telef);
    }else{
        while(!validar_telefone(telef)){
            printf("Telefone: ");
            scanf("%[^\n]", telef);
            scanf("%*c");
        }
        addNumbers(aux->headNumeros, telef);
    }
   ;

}