typedef struct _stack_ Stack;

Stack *stkCreate(int max);
int stkPush(Stack *s, void*elm);
void *stkPop(Stack *s);
void *stkTop(Stack *s);
int stkIsEmpty(Stack *s);
int stkEmpty(Stack *s);