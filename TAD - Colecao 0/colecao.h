#include "colecao.c"

typedef struct _colecao_ Colecao;

Colecao *colCreate(int maxItens);
int colInsert(Colecao *colecao, int item);
int colRemove(Colecao *colecao, int item);
int colQuery(Colecao *colecao, int key);
int colDestroy(Colecao *colecao);