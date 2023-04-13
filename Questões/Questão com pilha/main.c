#include "pilha.c"

#define TRUE 1
#define FALSE 0

int main(void){
    Pilha *pilha;
    char *string = {"abc0cba"};

    printf("%i", verificar(string, 7));

    

    return 0;
}
/*
Pilha *pilhaCriar(int maximo);
int pilhaPush(Pilha *pilha, void *elemento); //ADICIONA ELEMENTO DA PILHA
void *pilhaPop(Pilha *pilha); //RETIRA ELEMENTO DA PILHA
void *pilhaTop(Pilha *pilha); //RETORNA O ELEMENTO DO TOPO (ÚLTIMO ADICIONADO)
int pilhaIsEmpty(Pilha *pilha); //RETORNA UM BOOLEAN INDICANDO SE ESTÁ VAZIA OU NÃO
int pilhaDestruir(Pilha *pilha); //DESTRÓI A PILHA
*/