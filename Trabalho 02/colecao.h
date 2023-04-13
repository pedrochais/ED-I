#ifndef COLECAO_H_
#define COLECAO_H_

typedef struct Colecao;

Colecao *colCreate(int n);
int colDestroy(Colecao *colecao);
int colInsert(Colecao *colecao, void *item);
int colRemove(Colecao *colecao, void *chave, int *comparar(void *, void *));
void *colQuery(Colecao *colecao, void *chave, int *comparacao(void *, void *));
int colClean(Colecao *colecao);
int colDestroy(Colecao *colecao);
void *getFirst(Colecao *colecao);
void *getNext(Colecao *colecao);

#endif