#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _fila_{
    int maxItens; // tamanho do cofo
    int traseira; // índice do último elemento da fila
    int frente;   // índice do primeiro item da fila
    int nItens;
    void **item;
}Fila;

Fila *criarFilaCircular(int n){
    if(n > 0){
        Fila *fila;
        fila = (Fila *)malloc(sizeof(Fila));
        if(fila != NULL){
            fila->item = (void **)malloc(sizeof(void*)*n);

            if(fila->item != NULL){
                fila->maxItens = n;
                fila->frente = 0;
                fila->traseira = -1;
                fila->nItens = 0;
                return fila;
            }
            free(fila);
        }
    }
    return NULL; 
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
        if(fila->nItens < fila->maxItens){
            fila->traseira = filaIncCircular(fila->traseira, fila->maxItens);
            fila->item[fila->traseira] = data;
            fila->nItens++;
            return TRUE;
        }
    }
    return FALSE;
}

void *filaDesenfileirar(Fila *fila){ //modificado 
    void *data;
    if(fila != NULL){
        if(fila->nItens > 0){
            data = fila->item[fila->frente];
            fila->frente = filaIncCircular(fila->frente, fila->maxItens);
            printf("frente: %i\n", fila->frente);
            fila->nItens--;
            return data;
        }
    }
    return NULL;
}

void *filaPrimeiro(Fila *fila){
    if(fila != NULL){
        if(fila->traseira >= 0){
            return fila->item[fila->frente];
        }
    }
    return NULL;
}

void *filaUltimo(Fila *fila){
    if(fila != NULL){
        if(fila->traseira >= 0){
            return fila->item[fila->traseira];
        }
    }
    return NULL;
}

int filaCheia(Fila *fila){
    if(fila->nItens < fila->maxItens){
        return FALSE;
    }
    return TRUE;
}

int filaVazia(Fila *fila){
    if(fila != NULL){
        if(fila->nItens == 0){
            return TRUE;
        }
    }
    return FALSE;
}

int filaPromoverUltimo(Fila *fila, int n){
    void *aux;
    int indice;
    if(fila != NULL){
        if(n > 0){
            aux = fila->item[fila->traseira];
            for(int i = 0; i < n; i++){
                if(fila->traseira-i < 0){
                    indice = filaDecCircular(fila->traseira-i, fila->maxItens-i+1);
                }else{
                    indice = fila->traseira-i;
                }
                fila->item[indice] = fila->item[indice-1];
            }
            fila->item[indice-1] = aux;
            return TRUE;
        }
    }
    return FALSE;
}

int filaPunePrimeiro(Fila *fila, int n){
    void *aux;
    int indice;
    if(fila != NULL){
        if(n > 0){
            aux = fila->item[fila->frente];
            for(int i = 0; i < n; i++){
                if(fila->frente+i > fila->maxItens-1){
                    indice = i-1;
                }else{
                    indice = fila->frente+i;
                }
                fila->item[indice] = fila->item[indice+1];
            }
            fila->item[indice+1] = aux;
        }
    }
}

//EM DESENVOLVIMENTO
void reorganizarFila(Fila *fila){
    void *ultimo;
    while(fila->frente != 0){
        ultimo = fila->item[fila->traseira];

        for(int i = 0; i < fila->nItens; i++){

            int indice = fila->frente+i;

            if(indice > fila->maxItens){
                indice = 0;
            }

            fila->item[indice] = fila->item[indice+1];

        }

        fila->frente--;
        fila->traseira = filaDecCircular(fila->traseira, fila->maxItens);
        
    }
}

int filaIncCircular(int traseira, int maxItens){
    if(traseira < maxItens-1){
        return traseira+1;
    }else{
        return 0;
    }
}

int filaDecCircular(int traseira, int maxItens){
    if(traseira > 0){
        return traseira-1;
    }else{
        return maxItens-1;
    }
}