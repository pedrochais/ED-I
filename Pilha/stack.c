#include "stack.h"
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _stack_{
    int maxItens;
    int top;
    void* *item;
} Stack;

Stack *stkCreate(int n){
    Stack *stack;
    if(n > 0){
        stack = (Stack *)malloc(sizeof(Stack));

        if(stack != NULL){
            stack->item = (void**)malloc(sizeof(void*) * n);

            if(stack->item != NULL){
                stack->maxItens = n;
                stack->top = -1;
                return stack;
            }
            free(stack);
        }
    }
    return NULL;
}

int stkDestroy(Stack *stack){
    if(stack != NULL){
        if(stack->top < 0){ //CASO VERDADEIRO SIGNIFICA QUE A PILHA ESTÁ VAZIA
            free(stack->item);
            free(stack);

            return TRUE;
        }
    }
    return FALSE;
}

int stkPush(Stack *stack, void *elm){
    if(stack != NULL){
        if(stack->item != NULL){
            if(stack->top < stack->maxItens-1){
                stack->top++;
                stack->item[stack->top] = elm;

                return TRUE;
            }
        }
    }
    return FALSE;
}

void *stkPop(Stack *stack){ // TIRAR O ÚLTIMO ELEMENTO DA PILHA
    void *data;
    if(stack != NULL){
        if(stack->item != NULL){
            if(stack->top >= 0){
                data = stack->item[stack->top];
                stack->top--;
                return data;
            }
        }
    }
    return NULL;
}

void *stkTop(Stack *stack){
    
    if(stack != NULL){
        if(stack->item != NULL){
            if(stack->top >= 0){
                return stack->item[stack->top];
            }
        }
    }
    return NULL;
}

int stkEmpty(Stack *stack){
    if(stack != NULL){
        if(stack->item != NULL){
            if(stack->top < 0){
                return TRUE;
            }
        }
    }
    return FALSE;
}

void stkClean(Stack *stack){
    void *elm;
    if(stack != NULL){
        elm = stkPop(stack);
        while(elm != NULL){
            elm = stkPop(stack);
        }
    }
}