typedef struct _fila_ Fila;

Fila *criarFilaCircular(int n);
int filaDestruir(Fila *fila);
int filaEnfileirar(Fila *fila, void *data); //INSERE ELEMENTO NO FIM DA FILA
void *filaDesenfileirar(Fila *fila); // REMOVE ELEMENTO DO INICIO DA FILA
int filaPrimeiro(Fila *fila); //ACESSA O ELEMENTO DO INICIO DA FILA
void *filaUltimo(Fila *fila); //ACESSA O ULTIMO ELEMENTO DA FILA
int filaCheia(Fila *fila); //VERIFICA SE A FILA TÁ CHEIA
int filaVazia(Fila *fila); //VERIFICA SE A FILA TA VAZIA
int filaPromoverUltimo(Fila *fila, int n);
int filaPunePrimeiro(Fila *fila, int n);