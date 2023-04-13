#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#include "aluno.h"

#define TRUE 1
#define FALSE 0


int main(void){
    Colecao *colecao;
    Aluno *aluno;
    int option = -1, colExiste = FALSE;

    while(option != 0){
        printf("\n[1] Criar uma coleção\n[2] Inserir ALUNO na coleção\n[3] Remover ALUNO da coleção\n[4] Consultar ALUNO na coleção\n[5] Listar elementos da coleção\n[6] Destruir a coleção\n[7] Esvaziar a coleção\n\n~ ");
        scanf("%i", &option);
        getchar();

        switch(option){
            case 1: //criar coleção
            if(colExiste == FALSE){
                int quantidade;
                printf("Quantidade de elementos que serão adicionados na coleção: ");
                scanf("%i", &quantidade);
    
                colecao = colCreate(quantidade);

                if(colecao != NULL){
                    printf("[Colecao criada]\n");
                    colExiste = TRUE;
                }else{
                    printf("[Não foi possível criar a coleção]\n");
                }
            }else{
                printf("[Uma coleção já foi criada]\n");
            }
            break;

            case 2: // inserir aluno
            if(colExiste == TRUE && colecao != NULL){
                aluno = (Aluno *)malloc(sizeof(Aluno));
                aluno->matricula = colecao->quantItens+1;
                int inserido;

                printf("\n[Cadastro de aluno]\n");
                printf("Matrícula: %i\n", aluno->matricula);
                printf("Nome: ");
                fgets(aluno->nome, 30, stdin);
                printf("Nota: ");
                scanf("%f", &aluno->nota);

                inserido = colInsert(colecao, aluno);

                if(inserido == TRUE){
                    printf("[Aluno inserido na coleção]\n");
                }else{
                    printf("[Coleção cheia, não foi possível inserir um novo aluno]\n");
                }
                
            }else{
                printf("[É necessário criar uma coleção]\n");
            } 
            break;

            case 3: // remover aluno
            if(colExiste == TRUE && colecao != NULL){
                if(colecao->quantItens > 0){
                    int matricula, removido;

                    printf("\n[Remover aluno]\nInsira o número da matrícula: ");
                    scanf("%i", &matricula);

                    removido = colRemove(colecao, (void *)&matricula, compararMatricula);

                    if(removido == TRUE){
                        printf("[O aluno foi removido da coleção]\n");
                    }else{
                        printf("[Não foi possível remover o aluno da coleção]\n");
                    }
                }else{
                    printf("[Não há nenhum aluno cadastrado na coleção]\n");
                }
            }else{
                printf("[É necessário criar uma coleção]\n");
            }

            break;
            case 4:
            if(colExiste == TRUE && colecao != NULL){
                if(colecao->quantItens > 0){
                    int matricula;
                    Aluno *aluno;

                    while(TRUE){
                        printf("\n[Buscar aluno]\nInsira o número da matrícula: ");
                        scanf("%i", &matricula);

                        if(matricula < 1 || matricula > colecao->quantItens){
                            printf("[Matrícula inválida]\n");
                            continue;
                        }else{
                            break;
                        }
                    }

                    aluno = colQuery(colecao, (void *)&matricula, compararMatricula);
                    if(aluno != NULL){
                        printf("\n[Informações do aluno]\n + Matrícula: %i\n + Nome: %s + Nota: %.1f\n", aluno->matricula, aluno->nome, aluno->nota);

                    }else{
                        printf("[Aluno não encontrado]\n");
                    }

                }else{
                    printf("[Não há nenhum aluno cadastrado na coleção]\n");
                }
            }else{
                printf("[É necessário criar uma coleção]\n");
            }

            break;
            case 5:
            if(colExiste == TRUE && colecao != NULL){
                if(colecao->quantItens > 0){
                    Aluno *aluno;
                    aluno = getFirst(colecao);

                    printf("\n[Aluno 1]\nMatrícula: %i\nNome: %sNota: %.1f\n", aluno->matricula, aluno->nome, aluno->nota);
                    for(int i = 2; i <= colecao->quantItens; i++){
                        aluno = getNext(colecao);
                        printf("\n[Aluno %i]\nMatrícula: %i\nNome: %sNota: %.1f\n", i, aluno->matricula, aluno->nome, aluno->nota);
                    }
                }else{
                    printf("[Não há nenhum aluno cadastrado na coleção]\n");
                }
            }else{
                printf("[É necessário criar uma coleção]\n");
            }

            break;
            case 6:
            if(colExiste == TRUE && colecao != NULL){
                if(colecao->quantItens == 0){
                    int apagada = colDestroy(colecao);

                    if(apagada == TRUE){
                        printf("[A coleção foi destruída]\n");
                        colExiste = FALSE;
                    }else{
                        printf("[Não foi possível destruir a coleção]\n");
                    }
                }else{
                    printf("[É necessário esvaziar a coleção]\n");    
                }
            }else{
                printf("[É necessário criar uma coleção]\n");
            }

            break;
            case 7:
            if(colExiste == TRUE && colecao != NULL){
                if(colecao->quantItens > 0){
                    int vazia = colClean(colecao);

                    if(vazia == TRUE){
                        printf("[Todos os itens foram apagados]\n");
                    }else{
                        printf("[Não foi possível apagar os itens]\n");
                    }
                }else{  
                    printf("[A coleção já está vazia]\n");
                }
            }else{
                printf("[É necessário criar uma coleção]\n");
            }

            break;
        }
    }

    return 0;
}