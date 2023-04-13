typedef struct _fila_ Fila;

Fila *criarFila(int n){
int filaDestruir(Fila *fila);
int filaEnfileirar(Fila *fila, void *data); //insere data no fim da fila
void *filaDesenfileirar(Fila *fila); // remove o elemento do inicio da fila
int filaPrimeiro(Fila *fila); // acessa o elemento do início da fila
int filaVazia(Fila *fila);