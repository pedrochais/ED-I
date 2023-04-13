#include "stdio.h"
#include "colecao.h"

/*
Implemente o TAD Colection Genérico e o utilize para fazer um programa com os seguintes requisitos (obrigatório utilizar a mesma API):

Defina uma estrutura do TIPO ESCOLHIDO ( tipo aluno, ou tipo disco, ou tipo Time, etc...) que tenha pelo menos os seguintes campos:
1. um campo char [30].
2. um campo inteiro.
3. um campo float.

Implemente as seguintes operações:

1. Criar uma coleção.
2. Inserir um TIPO ESCOLHIDO na coleção.
3. Remover um TIPO ESCOLHIDO na coleção identificado pelo campo char, int e float.
4. Consultar um TIPO ESCOLHIDO na coleção identificado pelo campo char, int e float.
5. Listar os elementos na coleção.
6. Destruir a coleção se estiver vazia.
7. Esvaziar a coleção.
*/

typedef struct _aluno_{
    char nome[30];
    int idade;
    float media;
}Aluno;

int main(void){
    int a = 5;
    int b = 3;

    Colecao *colection;

    colection = colCreate(5);

    colInsert(colection, 25);
    colInsert(colection, 50);
    colInsert(colection, 75);
    colInsert(colection, 40);

    colRemove(colection, 75);


    return 0;
}