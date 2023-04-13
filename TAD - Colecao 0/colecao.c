#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct _colecao_{
    int numItens;
    int maxItens;
    int *item;
}Colecao;

Colecao *colCreate(int n){ //para criar uma coleção com base na quantidade de itens que serão alocados
    
    Colecao *colecao;

    if(n > 0){                                              // 1. testa se numero informado é maior que 0 (tamanho da coleção = n) 
        colecao = (Colecao *)malloc(sizeof(Colecao)*n);     // 2. aloca memória para a variável colecao do tipo Colecao
        if(colecao != NULL){                                // 3. faz o teste para verificar se alocou
            colecao->item = (int *)malloc(sizeof(int)*n);   // 4. aloca memória para a variável item em colecao
            if(colecao->item != NULL){                      // 5. faz o teste para verificar se alocou
                printf("[colecao criada e espaços alocados]\n");
                colecao->numItens = 0;                      // 6. inicializa numItens
                colecao->maxItens = n;                      // 7. inicializa maxItens atribuindo valor de n
                return colecao;                             // 8. retorna variável do tipo Colecao alocada
            }
            free(colecao);                                  // 9. libera memoria alocada em coleção caso não for possível alocar para item
        }
    }
    return NULL;                                            // 10. retorna NULL caso n não for válido
}

int colInsert(Colecao *colecao, int item){ // para inserir um item na coleção
    if(colecao != NULL){                                    // 1. verifica se colecao existe
        
        if(colecao->numItens < colecao->maxItens){          // 2. verifica se ainda há espaço para colocar itens na coleção
            printf("[item adicionado]\n");

            colecao->item[colecao->numItens] = item;        // 3. atribui item ao vetor *item
            colecao->numItens++;                            // 4. itera sobre o contador de itens
            return TRUE;
        }
    }
    return FALSE;
}

int colRemove(Colecao *colecao, int key){
    if(colecao != NULL){
        if(colecao->numItens > 0){
            int i = 0, data;
            
            while(i < colecao->numItens && colecao->item[i] != key){
                printf("w: %i\n", colecao->item[i]);
                i++;
            }

            if(colecao->item[i] == key){
                data = colecao->item[i];    // pra quê?
                printf("d: %i\n", data);

                for(int j = i; j < colecao->numItens; j++){
                    colecao->item[j] = colecao->item[j+1];
                    printf("%i\n", colecao->item[j]);
                }
                colecao->numItens--;
                return data;                // pra quê?
            }
        }
        return -32767;
    }
}

int colQuery(Colecao *colecao, int key){
    int i = 0, data;

    if(colecao != NULL){
        if(colecao->numItens > 0){
            while(i < colecao->numItens && colecao->item[i] != key){
                i++;
            }

            if(colecao->item[i] == key){
                printf("[chave encontrada]");
                return colecao->item[i];
            }
        }
        return -32767;
    }
}

int colDestroy(Colecao *colecao){
    if(colecao != NULL){
        if(colecao->numItens == 0){
            free(colecao->item);
            free(colecao);
            return TRUE;
        }
    }
    return FALSE;
}