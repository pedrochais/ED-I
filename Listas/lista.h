typedef struct _lnode_ LNode;
typedef struct _llist_ LList;

LList *listaCriar(void);
int listaDestruir(LList *lista);
int listaInserirPrimeiro(LList *lista, void *data);
void *listaRemoverPrimeiro(LList *lista);
int listaInserirUltimo(LList *lista, void *data);

LNode *listaObterUltimo(LList *lista);
