typedef struct _pilha_ Pilha;

Pilha *pilhaCriar(int maximo);
int pilhaPush(Pilha *pilha, void *elemento); //ADICIONA ELEMENTO DA PILHA
void *pilhaPop(Pilha *pilha); //RETIRA ELEMENTO DA PILHA
void *pilhaTop(Pilha *pilha); //RETORNA O ELEMENTO DO TOPO (ÚLTIMO ADICIONADO)
int pilhaIsEmpty(Pilha *pilha); //RETORNA UM BOOLEAN INDICANDO SE ESTÁ VAZIA OU NÃO
int pilhaDestruir(Pilha *pilha); //DESTRÓI A PILHA