//Número de nós de uma árvore
int abNNos(TNode *t){ 
    int nos_esquerdo, nos_direito, no_raiz = 0;
    if(t != NULL){
        nos_esquerdo = abNNos(t->left);
        nos_direito = abNNos(t->right);
        no_raiz = 1;
        return no_raiz + nos_direito + nos_esquerdo;
    }
    return 0; //Caso a árvore for vazia
}

//Número de nós folha de uma árvore
int abNNosFolhas(TNode *t){
    int nos_esquerdo, nos_direito, no_raiz = 0;
    if(t != NULL){
        nos_esquerdo = abNNosFolhas(t->left);
        nos_direito = abNNosFolhas(t->right);
        if(t->left == NULL && t->right == NULL){
            no_raiz = 1;
            return no_raiz + nos_esquerdo + nos_direito;
        }
    }
    return 0;
}

//Número de nós de grau 1 uma árvore
int abNNosGrau1(TNode *t){
    int nos_esquerdo, nos_direito, no_raiz = 0;
    if(t != NULL){
        nos_esquerdo = abNNosGrau1(t->left);
        nos_direito = abNNosGrau1(t->right);
        if((t->left != NULL && t->right == NULL) || (t->left == NULL && t->right != NULL)){
            no_raiz = 1;
            return no_raiz + nos_esquerdo + nos_direito;
        }
    }
    return 0;
}

//Número de nós de grau 2 uma árvore
int abNNosGrau2(TNode *t){
    int nos_esquerdo, nos_direito, no_raiz = 0;
    if(t != NULL){
        nos_esquerdo = abNNosGrau2(t->left);
        nos_direito = abNNosGrau2(t->right);
        if(t->left != NULL && t->right != NULL){
            no_raiz = 1;
            return no_raiz + nos_esquerdo + nos_direito;
        }
    }
    return 0;
}

//Número de nós com filho esquerdo
int abNNosFilhoEsq(TNode *t){
    int nos_esquerdo, nos_direito, no_raiz = 0;
    if(t != NULL){
        nos_esquerdo = abNNosFilhoEsq(t->left);
        nos_direito = abNNosFilhoEsq(t->right);
        if(t->left != NULL){
            no_raiz = 1;
            return no_raiz + nos_esquerdo + nos_direito;
        }
    }
    return 0;
}

//Número de nós com filho direito
int abNNosFilhoDir(TNode *t){
    int nos_esquerdo, nos_direito, no_raiz = 0;
    if(t != NULL){
        nos_esquerdo = abNNosFilhoDir(t->left);
        nos_direito = abNNosFilhoDir(t->right);
        if(t->right != NULL){
            no_raiz = 1;
            return no_raiz + nos_esquerdo + nos_direito;
        }
    }
    return 0;
}

//Número de nós com somente filho esquerdo
int abNNosFilhoEsq(TNode *t){
    int nos_esquerdo, nos_direito, no_raiz = 0;
    if(t != NULL){
        nos_esquerdo = abNNosFilhoEsq(t->left);
        nos_direito = abNNosFilhoEsq(t->right);
        if(t->left != NULL && t->right == NULL){
            no_raiz = 1;
            return no_raiz + nos_esquerdo + nos_direito;
        }
    }
    return 0;
}

//Número de nós com somente filho direito
int abNNosFilhoDir(TNode *t){
    int nos_esquerdo, nos_direito, no_raiz = 0;
    if(t != NULL){
        nos_esquerdo = abNNosFilhoDir(t->left);
        nos_direito = abNNosFilhoDir(t->right);
        if(t->right != NULL && t->left == NULL){
            no_raiz = 1;
            return no_raiz + nos_esquerdo + nos_direito;
        }
    }
    return 0;
}

//Altura de uma árvore binária
int abAltura(TNode *t){
    int hl, hr, h = 0;
    if(t != NULL){
        hl = abAltura(t->left);
        hr = abAltura(t->right);
        if(hl > h){
            h = hl;
        }else if(hr > h){
            h = hr;
        }
        return h;
    }
    return 0;
}

int abAltura(TNode *t){ //Solução do professor
    int hl, hr, h = 0;
    if(t != NULL){
        hl = abAltura(t->left);
        hr = abAltura(t->right);
        if(hl > hr){
            h = hl;
        }else{
            h = hr;
        }
        return 1 + h;
    }
    return 0;
}

//Nós com exatamente altura h
int abNNosAlturaH(TNode *t, int h, int level){
    int nos_esquerdo, nos_direito, no_raiz = 0;
    if(t != NULL){
        nos_esquerdo = abNNosAlturaH(t->left, h, level+1);
        nos_direito = abNNosAlturaH(t->rigth, h, level+1);
        if(level == h){ //level < h //level > h
            no_raiz = 1;
            return no_raiz + nos_esquerdo + nos_direito;
        }
    }
    return 0;
}

//Números de nós com valor key
int abNumNosValorMaiorQueKey(TNode *t, void *key, int *cmp(void *, void *)){
    int nl, nr, n = 0
    int stat;
    if(t != NULL){
        
        nl = abNumNosValorMaiorQueKey(t->left, key, cmp);
        nr = abNumNosValorMaiorQueKey(t->right, key, cmp);
        //stat = cmp(t->data, key); //se stat > 0 então t->data é maior que key
        stat  = cmp(t->data, key);
        if(stat > 0 ){
            n = 1;
            return n + nl + nr;
        }
    }
    return 0;
}

//Verificar se uma árvore é topologicamente igual a outra
int abETopoIgual(TNode *t1, TNode *t2){
    if(t1 != NULL && t2 != NULL){
        stat1 = abETopoIgual(t1->left, t2->left);
        stat2 = abETopoIgual(t1->right, t2->right);

        return stat1 && stat2;

    }else if((t1 != NULL && t2 == NULL) || ((t1 == NULL && t2 != NULL))){
        return FALSE;
    }else{
        return TRUE;
    }
}

//Resolução do professor
int abETopoIgual(TNode *t1, TNode *t2){ 
    if(t1 != NULL){
        if(t2 != NULL){
            stat1 = abETopoIgual(t1->left, t2->left);
            stat2 = abETopoIgual(t1->right, t2->right);

            return stat1 && stat2;
        }else{
            return FALSE;
        }
    }else{
        if(t2 == NULL){
            return TRUE;
        }else{
            return FALSE;
        }
    }
}

//Verificar se duas árvores binárias são topologicamente iguais
int abETopoIgual(TNode *t1, TNode *t2, int *cmp(void *, void *)){ 
    if(t1 != NULL){
        if(t2 != NULL){
            if(cmp(t1->data, t2->data) == TRUE){
                stat1 = abETopoIgual(t1->left, t2->left);
                stat2 = abETopoIgual(t1->right, t2->right);
            }
            
            return stat1 && stat2;
        }else{
            return FALSE;
        }
    }else{
        if(t2 == NULL){
            return TRUE;
        }else{
            return FALSE;
        }
    }
}

//  ÁRVORE BINÁRIA DE PESQUISA
void *abpQuery(TNode *t, void *key, void *cmp(void *, void *)){
    int stat;
    if(t != NULL){
        stat = cmp(key, t->data)
        if(stat == 0){ //encontrou
            return t->data;
        }else if(stat < 0){ //se for menor que 0 (-1) a busca será direcionada para a árvore esquerda
            return abpQuery(t->left, key, cmp)
        }else{ //se for maior que 0 (1) a busca será direcionada para a árvore direita
            return abpQuery(t->right, key, cmp);
        }
    }
    return NULL;
}

TNode *abpInsert(TNode *t, void *data, int *cmp(void *, void *)){
    TNode *newnode;
    int stat;
    if(t != NULL){
        stat = cmp(t->data, data);
        if(stat < 0){
            t->left = abpInsert(t->left, data, cmp);
        }else{
            t->right = abpInsert(t->right, data, cmp);
        }
        return t;
    }
    newnode = (TNode *)malloc(sizeof(TNode));
    if(newnode != NULL){
        newnode->left = newnode->right = NULL;
        newnode->data = data;
        return newnode;
    }
    return NULL;
}

TNode *abpMenor(TNode *t){
    if(t != NULL){
        if(t->left != NULL){
            return abpMenor(t->left);
        }else{
            return t;
        }
    }
    return NULL;
}

TNode *abpMaior(TNode *t){
    if(t != NULL){
        if(t->right != NULL){
            return abpMaior(t->right);
        }else{
            return t;
        }
    }
    return NULL;
}

TNode *abpRemove(TNode *t, void *key, int cmp(void *, void *), void **data){
    if(t != NULL){
        stat = cmp(data, t->data);
        //Inicia a busca pelo nó que será removido
        if(stat < 0){
            t->left = abpRemove(t->left, key, cmp, data);
            return t;
        }else if(stat > 0){
            t->right = abpRemove(t->right, key, cmp, data);
            return t;
        }else{ //Encontrou o nó e agora irá analisar que tipo de nó é
            if(t->left == NULL && t->left == NULL){ //Nó folha
                *data = t->data;
                free(t);
                return NULL;
            }else if(t->left == NULL){ //Nó de grau 1 com filho direito apenas
                aux = t->right;
                *data = t->data;
                free(t);
                return aux;
            }else if(t->right == NULL){ //Nó de grau 1 com filho esquerdo apenas
                aux = t->left;
                *data = t->data;
                free(t);
                return aux;
            }else{ //Nó de grau 2
                *data = t->data;
                t->left = abpRemoveMenor(t->left, key, cmp, &data2); //Busca o menor nó
                t->data = data2;
                return t;
            }
        }
    }
}

TNode *abpRemoveMenor(TNode *t, void *key, int *cmp(void *, void *), void **data){
    void *data;
    if(t != NULL){
        if(t->left != NULL){
            t->left = abpRemoveMenor(t->left, key, cmp, &data2);
        }else{
            if(t->right != NULL){
                aux = t->right;
                *data = t->data;
                free(t);
                return aux;
            }else{
                *data = t->data;
                free(t);
                return NULL;
            }
        }
    }
    *data = NULL;
    return NULL;
}