//#include "stack.h"
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _pilha_{
    int maxItens;
    int topo;
    void* *item;
} Pilha;

Pilha *pilhaCriar(int maximo){
    Pilha *pilha;
    if(maximo > 0){
        pilha = (Pilha *)malloc(sizeof(Pilha));

        if(pilha != NULL){
            pilha->item = (void**)malloc(sizeof(void*) * maximo);

            if(pilha->item != NULL){
                pilha->maxItens = maximo;
                pilha->topo = -1;
                return pilha;
            }
            free(pilha);
        }
    }
    return NULL;
}

int pilhaDestruir(Pilha *pilha){ 
    if(pilha != NULL){
        if(pilha->topo < 0){ //CASO VERDADEIRO SIGNIFICA QUE A PILHA ESTÁ VAZIA
            free(pilha->item);
            free(pilha);

            return TRUE;
        }
    }
    return FALSE;
}

int pilhaPush(Pilha *pilha, void *elemento){
    if(pilha != NULL){
        if(pilha->item != NULL){
            if(pilha->topo < pilha->maxItens-1){
                pilha->topo++;
                pilha->item[pilha->topo] = elemento;

                return TRUE;
            }
        }
    }
    return FALSE;
}

void *pilhaPop(Pilha *pilha){ 
    void *data;
    if(pilha != NULL){
        if(pilha->item != NULL){
            if(pilha->topo >= 0){
                data = pilha->item[pilha->topo];
                pilha->topo--;
                return data;
            }
        }
    }
    return NULL;
}

void *pilhaTop(Pilha *pilha){
    
    if(pilha != NULL){
        if(pilha->item != NULL){
            if(pilha->topo >= 0){
                return pilha->item[pilha->topo];
            }
        }
    }
    return NULL;
}

int pilhaIsEmpty(Pilha *pilha){
    if(pilha != NULL){
        if(pilha->item != NULL){
            if(pilha->topo < 0){
                return TRUE;
            }
        }
    }
    return FALSE;
}

void pilhaClean(Pilha *pilha){
    void *elemento;
    if(pilha != NULL){
        elemento = pilhaPop(pilha);
        while(elemento != NULL){
            elemento = pilhaPop(pilha);
        }
    }
}

int verificar()
