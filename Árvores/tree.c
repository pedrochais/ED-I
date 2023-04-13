typedef struct _tnode_{
    void *data;
    struct t_node *left;
    struct t_node *right;
}TNode;

typedef struct _tree_ Tree;

//total de nós de uma árvore binária completa de altura h
//n = 2^(h+1)-1

void preOrdem(TNode *t, void (*visit) (void *)){
    if(t != NULL){
        visit(t->data);
        preOrdem(t->left, visit);
        preOrdem(t->right, visit);
    }
}

void posOrdem(TNode *t, void (*visit) (void *)){
    if(t != NULL){
        posOrdem(t->left, visit);
        posOrdem(t->right, visit);
        visit(t->data);
    }
}

void simetrico(TNode *t, void (*visit) (void *)){
    if(t != NULL){
        simetrico(t->left, visit);
        visit(t->data);
        simetrico(t->right, visit);
    }
}

//Calcular o número de nós total de uma árvore
int abNNos(TNode *t){
    int nl, nr, n; //nleft nright
    if(t != NULL){
        nl = abNNos(t->left);
        nr = abNNos(t->right);
        n = 1; //visit //é o nó da raiz

        return n+nl+nr;
    }
    return 0;
}

//Calcular o número de nós folha
int abNNosFolha(TNode *t){
    int nl, nr, n = 0;
    if(t != NULL){
        nl = abNNosFolha(t->left);
        nr = abNNosFolha(t->right);
        if(t->left == NULL && t->right == NULL){
            n = 1;
        }

        return n+nl+nr;
    }
    return 0;
}

//Calcular nós com grau 1
int abNNosGrau1(TNode *t){
    int nl, nr, n = 0;
    if(t != NULL){
        nl = abNNosGrau1(t->left);
        nr = abNNosGrau1(t->right);
        if((t->left == NULL && t->right != NULL) || (t->left != NULL && t->right == NULL)){
            n = 1; //visit
        }

        return n+nl+nr;
    }
    return 0;
}

//Calcular altura da árvore
int abAltura(TNode *t){
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
    int nl, nr, n = 0;
    if(t != NULL){
        nl = abNNosAlturaH(t->left, h, level+1);
        nr = abNNosAlturaH(t->rigth, h, level+1);
        if(level == h){ //level < h //level > h
            n = 1;
            return n + nl + nr;
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
    int stat1, stat2;
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

//Calcular nós com exatamente a altura h
int abNNosAlturaH(TNode *t, int h, int level){
    int nl, nr, n = 0;
    if(t != NULL){
        nl = abNNosAlturaH(t->left, level+1);
        nr = abNNosAlturaH(t->right, level+1);
        if(level == h){
            n = 1;
        }
        return n+nl+nr;
    }
    return 0;
}

//Verificar se duas árvores binárias são topologicamente iguais
int abETopoIgual(TNode *t1, TNode *t2, int *cmp(void *, void *)){ 
    int stat1, stat2;
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

//Verificar se uma árvore é maior que a outra
int abT1EMaiorQueT2(TNode *t1, TNode *t2, int *cmp(void *, void *)){
    if(t1 != NULL){
        if(t2 != NULL){
            stat0 = cmp(t1->data, t2->data);
            stat1 = abT1EMaiorQueT2(t1->left, t2->left);
            stat2 = abT1EMaiorQueT2(t1->right, t2->right);
            return stat1 && stat2 && stat0;
        }else{
            return FALSE;
        }
    }else{
        if(t2 != NULL){
            return TRUE;
        }else{
            return FALSE;
        }
    }
}

//Verifica se duas árvores binárias são iguais
int abEIgual(TNode *t1, TNode *t2, int *cmp(void *, void *)){
    if(t1 != NULL){
        if(t2 != NULL){
            if(cmp(t1->data, t2->data) == 0){
                stat3 = TRUE;
            }else{
                stat3 = FALSE;
            }

            stat1 = abEIgual(t1->left, t2->left);
            stat2 = abEIgual(t1->right, t2->right);
            return stat1 && stat2 && stat3;
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

//Soma dos nós da árvore
float abSomaNos(TNode *t, float *getdata(void *)){
    float val;
    if(t != NULL){
        val = getdata(t->data);
        val_l = abSomaNos(t->left, getdata);
        val_r = abSomaNos(t->right, getdata);
        return val + val_l + val_r;
    }
    return 0;
}

//Verificar se duas árvores são espelhadas
int abEEspelhada(TNode *t1, TNode *t2, int *cmp(void *, void *)){
    if(t1 != NULL){
        if(t2 != NULL){
            stat3 = cmp(t1->data, t2->data);
            stat1 = abEEspelhada(t1->left, t2->right);
            stat2 = abEEspelhada(t1->right, t2->left);
            return stat1 && stat2 && stat3;
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

/* ÁRVORE BINÁRIA DE PESQUISA */
//Buscar item
void *abpQuery(TNode *t, void *key, int *cmp(void *, void *)){
    int stat;
    if(t != NULL){
        stat = cmp(key, t->data);
        if(stat == 0){
            return t->data;
        }else if(stat < 0){
            return abpQuery(t->left, key, cmp);
        }else{
            return abpQuery(t->right, key, cmp)
        }
    }
    return NULL;
}

//Inserir item
TNode *abpInsert(TNode *t, void *data, int *cmp(void *, void *)){
    TNode *newnode;
    if(t != NULL){
        if(cmp(data, t->data) < 0){ //insere na subarvore esquerda
            t->left = abpInsert(t->left, data, cmp);
            return t;
        }else{
            t->right = abpInsert(t->right, data, cmp);
            return t;
        }
    }
    newnode = (TNode *)malloc(sizeof(TNode));
    if(newnode != NULL){
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    return NULL;
}

//Busca pelo nó com o menor valor
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

float abpPegaMenor(TNode *t, float *getdata(void *)){
    if(t != NULL){
        if(t->left != NULL){
            return abpPegaMenor(t->left, getdata);
        }else{
            return getdata(t->data);
        }
    }
    return 0;
}

float abpPegaMaior(TNode *t, float *getdata(void *)){
    if(t != NULL){
        if(t->right != NULL){
            return abpPegaMaior(t->maior, getdata);
        }else{
            return getdata(t->data);
        }
    }
    return 0;
}

//Busca pelo nó com o maior valor
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

//Remover determinado item da lista
TNode *abpRemove(TNode *t, void *key, int cmp(void *, void *), void **data){
    TNode *aux;
    int stat;
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

TNode *abpRemoveMaior(TNode *t, void *key, int *cmp(void *, void *), void **data){
    void *data;
    if(t != NULL){
        if(t->right != NULL){
            t->right = abpRemoveMaior(t->right, key, cmp, &data2);
        }else{
            if(t->left != NULL){
                aux = t->left;
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