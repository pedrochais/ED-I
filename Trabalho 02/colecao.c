#ifndef COLECAO_C_
#define COLECAO_C_

#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"

#define TRUE 1
#define FALSE 0

typedef struct{
    int quantItens;
    int quantMax;
    int atual;
    void **item;
} Colecao;

Colecao *colCreate(int n){
    Colecao *colecao;

    if(n > 0){
        colecao = (Colecao *)malloc(sizeof(Colecao)*n);
        if(colecao != NULL){
            colecao->item = (void **)malloc(sizeof(void*)*n);
            if(colecao->item != NULL){
                colecao->quantItens = 0;
                colecao->quantMax = n;
                colecao->atual = 0;

                return colecao;
            }
            free(colecao);
        }
    }
    return NULL;
}

int colDestroy(Colecao *colecao){
    if(colecao != NULL){
        if(colecao->quantItens == 0){
            free(colecao->item);
            free(colecao);

            return TRUE;
        }
    }
    return FALSE;
}

int colInsert(Colecao *colecao, void *item){
    if(colecao != NULL){
        if(colecao->quantItens < colecao->quantMax){
            colecao->item[colecao->quantItens] = item;
            colecao->quantItens++;

            return TRUE;
        }
    }
    return FALSE;
}

int colRemove(Colecao *colecao, void *chave, int *comparar(void *, void *)){
    if(colecao != NULL){
        if(colecao->quantItens > 0){
            int i = 0, comparacao;
            void *item;
            
            while(i < colecao->quantItens){
                comparacao = comparar(chave, colecao->item[i]);
                if(comparacao == TRUE){
                    break;
                }else{
                    i++;
                }
            }

            if(comparacao == TRUE){
                for(int j = i; j < colecao->quantItens; j++){
                    colecao->item[j] = colecao->item[j+1];
                }
                colecao->quantItens--;
                return TRUE;
            }
        }
    }
    return FALSE;
}

void *colQuery(Colecao *colecao, void *chave, int *comparacao(void *, void *)){
    if(colecao != NULL){
        int i = 0;
        if(colecao->quantItens > 0){
            while(i < colecao->quantItens && comparacao(chave, colecao->item[i]) != TRUE){
                i++;
            }

            if(comparacao(chave, colecao->item[i]) == TRUE){
                return colecao->item[i];
            }
        }
    }
    return NULL;
}

int colClean(Colecao *colecao){
    if(colecao != NULL){
        if(colecao->quantItens > 0){
            for(int i = 0; i < colecao->quantItens; i++){
                colecao->item[i] = NULL;
            }
            colecao->quantItens = 0;
            return TRUE;
        }
    }
    return FALSE;
}

void *getFirst(Colecao *colecao){
    if(colecao != NULL){
        colecao->atual = 0;
        return colecao->item[colecao->atual];
    }
}

void *getNext(Colecao *colecao){
    if(colecao != NULL){
        colecao->atual++;
        if(colecao->atual < colecao->quantItens){
            return colecao->item[colecao->atual];
        }
    }
}

#endif
