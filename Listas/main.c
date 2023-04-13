#include "lista.c"

int main(void){

    LList *lista;

    lista = listaCriar();

    listaInserirPrimeiro(lista, 5);
    listaInserirUltimo(lista, 6);
    listaInserirUltimo(lista, 8);

    int ultimo = listaObterUltimo(lista);

    //printf("primeiro: %i\n", primeiro);
    printf("ultimo: %i", ultimo);


    return 0;
}