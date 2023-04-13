#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _dlnode_{
    struct _dlnode_ *next,
                    *prev;
    void *data;
} DLNode;

typedef struct _dllist_{
    DLNode *first;
    DLNode *current;
} DLList;

DLList *dllCreate(){
    DLList *list;
    list = (DLList *)malloc(sizeof(DLList));

    if(list != NULL){
        list->first = NULL;
        list->current = NULL;
        return list;
    }
    return NULL;
}

int dllDestroy(DLList *list){
    if(list != NULL && list->first == NULL){
        free(list);
        return TRUE;
    }
    return FALSE;
}

int dllInsertAsFirst(DLList *l, void *data){
    DLNode *newnode, *last;
    if(l != NULL){
        newnode = (DLNode *)malloc(sizeof(DLNode));
        if(newnode != NULL){
            newnode->data = data;
            newnode->next = NULL;

            if(l->first == NULL){
                l->first = newnode;
            }else{
                last = l->first;
                while(last->next != NULL){
                    last = last->next;
                }
                last->next = newnode;
            }
            return TRUE;
        }
    }
    return FALSE;
}

int dllInsertAfterSpec(DLList *l, void *key, void *data, int *cmp(void *, void *)){
    DLNode *spec, *newnode;
    
    if(l != NULL){
        if(l->first != NULL){
            spec = l->first;
            while(cmp(spec->data, key) != TRUE && spec->next != NULL){
                spec = spec->next;
            }
            if(cmp(spec->data, key) == TRUE){
                newnode = (DLNode *)malloc(sizeof(DLNode));
                
                if(newnode != NULL){
                    newnode->data = data;
                    newnode->next = spec->next;
                    spec->next = newnode;
                    newnode->prev = spec;
                    
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

int dllInsertBeforeSpec(DLList *l, void *key, void *data, int *cmp(void *, void*)){
    DLNode *spec, *newnode;
    
    if(l != NULL){
        if(l->first != NULL){
            spec = l->first;
            while(cmp(spec->data, key) != TRUE && spec->next != NULL){
                spec = spec->next;
            }
            if(cmp(spec->data, key) == TRUE){
                newnode = (DLNode *)malloc(sizeof(DLNode));
                newnode->data = data;
                newnode->next = spec;
                spec->prev = newnode;

                if(spec->prev != NULL){
                    newnode->prev = spec->prev;
                }else{
                    newnode->prev = NULL;
                    l->first = newnode;
                }

                return TRUE;
            }
        }
    }
    return FALSE;
}