#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _colecao_{
    int quantItens;
    int quantMax;
    int current;
    void **item;
} Colecao;

Colecao *colCreate(int n){
    Colecao *colecao;

    if(n > 0){
        colecao = (Colecao *)malloc(sizeof(Colecao)*n);
        if(colecao != NULL){
            colecao->item = (void **)malloc(sizeof(void*)*n);
            if(colecao->item != NULL){
                printf("[colecao criada]\n");
                colecao->quantItens = 0;
                colecao->quantMax = n;
                colecao->current = 0;

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
            printf("[item inserido]\n");

            return TRUE;
        }
    }
    return FALSE;
}

void *colQuery(Colecao *colecao, void *key, int *comparacao(void *, void *)){
    if(colecao != NULL){
        int i = 0, data;
        if(colecao->quantItens > 0){
            while(i < colecao->quantItens && comparacao(colecao->item[i], key) == TRUE){
                i++;
            }

            if(comparacao(colecao->item[i], key) == TRUE){
                return colecao->item[i];
            }
        }
        return NULL;
    }
}

