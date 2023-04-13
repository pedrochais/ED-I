#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _lnode_ {
    void *data;
    struct _lnode_ *proximo;
} LNode;

typedef struct _llist_ {
    LNode *primeiro;
}LList;

LList *listaCriar(){
    LList *lista;
    lista = (LList *)malloc(sizeof(LList));
    if(lista != NULL){
        lista->primeiro = NULL;
    }
    return lista;
}

int listaDestruir(LList *lista){
    if(lista != NULL){
        if(lista->primeiro == NULL){
            free(lista);
            return TRUE;
        }
    }
    return FALSE;
}

int listaInserirPrimeiro(LList *lista, void *data){
    LNode *newnode;
    if(lista != NULL){
        newnode = (LNode *)malloc(sizeof(LNode));
        if(newnode != NULL){
            newnode->data = data; // insere o dado na variável 'data' do novo nó
            //newnode->proximo = lista->primeiro;
            newnode->proximo = NULL; // insere valor NULL na variável 'proximo' do novo nó
            lista->primeiro = newnode;

            return TRUE;
        }
    }
    return FALSE;
}

void *listaRemoverPrimeiro(LList *lista){
    LNode *primeiro;
    void *data;

    if(lista != NULL){
        if(lista->primeiro != NULL){
            primeiro = lista->primeiro;
            data = primeiro->data;
            lista->primeiro = primeiro->proximo;
            free(primeiro);
            return data;
        }
    }
    return NULL;
}

LNode *listaObterUltimo(LList *lista){
    LNode *ultimo;

    if(lista != NULL){
        if(lista->primeiro != NULL){
            ultimo = lista->primeiro;
            printf("-------\n");
            while(ultimo->proximo != NULL){
                printf("-> %i\n", ultimo->data);
                ultimo = ultimo->proximo;
            }
            return ultimo;
        }
    }
    return NULL;
}

int listaInserirUltimo(LList *lista, void *data){
    LNode *newnode;
    LNode *ultimo;

    if(lista != NULL){
        if(lista->primeiro != NULL){
            newnode = (LNode *)malloc(sizeof(LNode));
            /*
            newnode->data = data;
            newnode->proximo = NULL;
            ultimo = listaObterUltimo(lista);
            ultimo->proximo = newnode;

            return TRUE;
            */
            if(newnode != NULL){
                //newnode->data = data;
                data = newnode->data;
                if(lista->primeiro != NULL){ //CASO A LISTA ESTEJA VAZIA INSERE UM ELEMENTO
                    newnode->proximo = NULL;
                    lista->primeiro = newnode;
                }else{ //HÁ ELEMENTOS NA LISTA
                    ultimo = listaObterUltimo(lista); 
                    ultimo->proximo = newnode;
                    newnode->proximo = NULL;
                }
                return TRUE;
            }
        }
    }
}

void *listaObterPrimeiro(LList *lista){
    LNode *primeiro;
    if(lista != NULL){
        if(lista->primeiro != NULL){
            primeiro = lista->primeiro;
            return primeiro->data;
        }
    }
}

