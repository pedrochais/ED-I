#include "fila.c"

int main(void){
    Fila *fila;

    fila = criarFila(5);
    printf("[Fila criada]");

    //filaEnfileirar(fila, (int) 1);
    filaEnfileirar(fila, (int) 2);
    //filaEnfileirar(fila, (int) 3);
    //filaEnfileirar(fila, (int) 4);

    //filaDesenfileirar(fila);
    //filaDesenfileirar(fila);

    int item = (int)filaPrimeiro(fila);

    printf("%i", item);

    return 0;
}