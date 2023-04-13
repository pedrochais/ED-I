#include "pilha.c"

#define TRUE 1
#define FALSE 0

int main(void){
    Pilha *pilha;
    char *string = {"abcbacb0aabcbcab"};

    pilha = pilhaCriar(3); //criar

    
    pilhaPush(pilha, (int) 5);
    //pilhaPush(pilha, (int) 4);
    //pilhaPush(pilha, (int) 1);

    //pilhaPop(pilha);
    

    int teste = pilhaIsEmpty(pilha);
    //int teste = pilhaPop(pilha);
    printf("%i", teste);

    

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