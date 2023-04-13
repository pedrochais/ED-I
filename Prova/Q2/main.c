int Pune(Stack *s, int n){
    void *elemento;

    if(s != NULL && s->top > -1 && n > 0){
        if(n > s->top){
            return FALSE;
        }
        elemento = s->item[s->top];

        for(int i = 0; i < n; i++){
            s->item[s->top-i] = s->item[s->top-i-1];
        }
        s->item[s->top-n] = elemento;
        return TRUE;
    }
    return FALSE;
}