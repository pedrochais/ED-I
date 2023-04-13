//inserir após nó especificado pela chave em lista circular duplamente encadeada
int dsllInsertAfterSpec(DLList *l, void *key, int (*cmp)(void *, void *), void *data){
    DLLNode *node, *newnode;
    if(l != NULL){
        newnode = (DLLNode *)malloc(sizeof(DLLNode));
        if(l->first != NULL && newnode != NULL){
            node = l->first;
            while(cmp(key, node->data) != TRUE && node->next != l->first){
                node = node->next;
            }
            if(cmp(key, node->data) == TRUE){
                newnode->data = data;
                newnode->next = node->next;
                node->next = newnode;
                newnode->prev = node;

                return TRUE;
            }
            
        }
    }
    return FALSE;

}

//inserir após nó especificado pela chave em lista circular simplesmente encadeada
int dsllInsertAfterSpec(SLList *l, void *key, int (*cmp)(void *, void *), void *data){
    DLLNode *node, *newnode;
    if(l != NULL){
        newnode = (DLLNode *)malloc(sizeof(DLLNode));
        if(l->first != NULL && newnode != NULL){
            node = l->first;
            while(cmp(key, node->data) != TRUE && node->next != l->first){
                node = node->next;
            }
            if(cmp(key, node->data) == TRUE){
                newnode->data = data;
                newnode->next = node->next;
                node->next = newnode;

                return TRUE;
            }
            
        }
    }
    return FALSE;

}

//inserir antes do nó especificado pela chave em lista circular duplamente encadeada
int dsllInsertBeforeSpec(DLList *l, void *key, int (*cmp)(void *, void *), void *data){
    DLLNode *node, *newnode;
    if(l != NULL){
        newnode = (DLLNode *)malloc(sizeof(DLLNode));
        if(l->first != NULL && newnode != NULL){
            node = l->first;
            while(cmp(key, node->data) != TRUE && node->next != l->first){
                node = node->next;
            }
            if(cmp(key, node->data) == TRUE){
                newnode->data = data;

                if(node == l->first){
                    newnode->next = node;
                    newnode->prev = l->first;
                    node->prev = newnode;

                    return TRUE;
                }
                
                newnode->next = node;
                newnode->prev = node->prev;
                node->prev = newnode;

                return TRUE;
            }
            
        }
    }
    return FALSE;
}