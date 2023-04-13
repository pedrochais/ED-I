#ifndef ALUNO_C_
#define ALUNO_C_

#include "aluno.h"

#define TRUE 1
#define FALSE 0

typedef struct{
    char nome[30];
    int matricula;
    float nota;
}Aluno;

int compararMatricula(void *matChave, void *item){
    Aluno *aluno;
    int *chave;

    aluno = (Aluno *)item;
    chave = (int *)matChave;

    if(aluno->matricula == *chave){
        return TRUE;
    }else{
        return FALSE;
    }
}

#endif