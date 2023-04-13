#include "stdio.h"
#include "colecao.h"

typedef struct _aluno_{
    char nome[30];
    int matricula;
    float nota;
}Aluno;

int main(void){
    Colecao *colecao;
    Aluno *aluno_1, *aluno_2;

    aluno_1 = (Aluno *)malloc(sizeof(Aluno));
    aluno_2 = (Aluno *)malloc(sizeof(Aluno));

    strcpy(aluno_1->nome, "pedro");
    strcpy(aluno_2->nome, "carlos");

    colecao = colCreate(2);
    colInsert(colecao, (void*)aluno_1);
    colInsert(colecao, (void*)aluno_2);

    
    Aluno *lista = colList(colecao);

    printf("%s", lista[1].nome);

    colList(colecao);
    
    return 0;
}