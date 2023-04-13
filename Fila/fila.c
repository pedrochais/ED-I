#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct _fila_{
    int maxItens; // tamanho do cofo
    int traseira; // índice do último elemento da fila
    int frente;   // índice do primeiro item da fila
    void **item;
}Fila;

Fila *criarFila(int n){
    if(n > 0){
        Fila *fila;
        fila = (Fila *)malloc(sizeof(Fila));
        if(fila != NULL){
            fila->item = (void **)malloc(sizeof(void*)*n);

            if(fila->item != NULL){
                fila->maxItens = n;
                fila->frente = 0;
                fila->traseira = -1;
                return fila;
            }
            free(fila);
        }
        return NULL;
    }
}

int filaDestruir(Fila *fila){
    if(fila != NULL){
        if(fila->traseira < 0){
            free(fila->item);
            free(fila);
            return TRUE;
        }
        return FALSE;
    }
}

int filaEnfileirar(Fila *fila, void *data){
    if(fila != NULL){
        if(fila->traseira < fila->maxItens-1){
            fila->traseira++;
            fila->item[fila->traseira] = data;

            return TRUE;
        }
    }
    return FALSE;
}

void *filaDesenfileirar(Fila *fila){
    void *data;
    if(fila != NULL){
        if(fila->traseira >= 0){
            data = fila->item[fila->frente];
            for(int i = fila->frente; i < fila->traseira; i++){
                fila->item[i] = fila->item[i+1];
            }
            fila->traseira--;
            return data;
        }
    }
    return NULL;
}

int filaPrimeiro(Fila *fila){
    if(fila != NULL){
        if(fila->traseira >= 0){
            return fila->item[fila->frente];
        }
    }
    return NULL;
}

int filaVazia(Fila *fila){
    if(fila != NULL){
        if(fila->traseira < 0){
            return TRUE;
        }
    }
    return FALSE;
}