#include "fila.c"

int main(void){
    Fila *fila;

    fila = criarFilaCircular(3);

    filaEnfileirar(fila, (int) 1);
    filaEnfileirar(fila, (int) 2);
    filaEnfileirar(fila, (int) 4);

    mostrarFila(fila);


    int primeiro = (int)filaPrimeiro(fila);
    int ultimo = (int)filaUltimo(fila);

    printf("primeiro: %i\n", primeiro);
    printf("ultimo: %i\n", ultimo);

    printf("cheio: %i\n", filaCheia(fila));
    printf("vazio: %i", filaVazia(fila));

    return 0;
}