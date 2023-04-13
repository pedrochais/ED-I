void *sllRemovek(SLList *l, int k){
    SLNode *atual;
    SLNode *anterior;
    
    if(l != NULL && k > 0){
        atual = l->primeiro;
        for(int i = 0; i < k; i++){
            anterior = atual; //anterior é igual ao atual
            atual = atual->proximo; //e o atual é igual ao próximo
            if(atual == NULL){
                return NULL;
            }
        }
        anterior->proximo = atual->proximo;
        return atual->dado; //retorna o que foi retirado
    }

    
}