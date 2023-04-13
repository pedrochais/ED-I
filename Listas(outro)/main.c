#include "sllist.c"
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#define TRUE 1
#define FALSE 0
/*
typedef struct _aluno_{
    char nome[30];
    int matricula;
    float nota;
}Aluno;
*/
int main()
{
    int qtd_insercoes = 0, opcao;
    SLList *lista = NULL;

    do
    {
        opcao = 0;
        printf("Selecione uma opcao:\n1 - Criar a lista\n2 - Inserir um item na lista\n3 - Buscar um item da lista\n4 - Remover um item da lista\n5 - Exibir os itens da lista\n6 - Esvaziar a lista\n7 - Destruir a lista\n8 - Sair do programa\n");
        scanf("%d", &opcao);
        fflush(stdin);
        printf("\n");
        switch(opcao)
        {
            case 1:
                if(lista == NULL)
                {
                    lista = sllCriar();
                    if(lista != NULL)
                    {
                        printf("Lista criada com sucesso!\n");
                    }
                    else
                    {
                        printf("Erro ao criar lista!\n");
                    }
                }
                else
                {
                    printf("A lista ja foi criada!\n");
                }
                break;
            case 2:
                if(lista != NULL)
                {
                    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
                    if(aluno != NULL)
                    {
                        printf("Insira um nome para o aluno:\n");
                        fgets(aluno->nome, 30, stdin);
                        printf("Insira uma matricula para o aluno:\n");
                        scanf("%d", &aluno->matricula);
                        fflush(stdin);
                        printf("Insira uma nota para o aluno:\n");
                        scanf("%f", &aluno->nota);
                        fflush(stdin);
                        if(sllInserirComoUltimo(lista, (void *)aluno) == FALSE)
                        {
                            printf("Erro ao inserir aluno!\n");
                        }
                        else
                        {
                            printf("Aluno adicionado com sucesso!\n");
                            qtd_insercoes++;
                        }
                    }
                }
                else
                {
                    printf("A lista nao foi criada!\n");
                }
                break;
            case 3:
                if(lista != NULL)
                {
                    Aluno *a;
                    int opcao_interna = 0;
                    printf("Deseja buscar o aluno pela matricula ou pela nota?\n1 - Matricula\n2 - Nota\n");

                    scanf("%d", &opcao_interna);
                    fflush(stdin);
                    printf("\n");

                    switch(opcao_interna)
                    {
                        case 1: ;
                            int mat;

                            printf("Digite a matricula:\n");
                            scanf("%d", &mat);
                            fflush(stdin);

                            a = (Aluno *)sllBuscar(lista, (void *)&mat, cmpMat);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do aluno:\n\nNome: %sMatricula: %d\nNota: %.1f\n", a->nome, a->matricula, a->nota);
                            }
                            else
                            {
                                printf("\nAluno nao encontrado ou lista vazia!\n");
                            }
                            break;
                        case 2: ;
                            float nota;

                            printf("Digite a nota:\n");
                            scanf("%f", &nota);
                            fflush(stdin);

                            a = (Aluno *)sllBuscar(lista, (void *)&nota, cmpNota);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do aluno:\n\nNome: %sMatricula: %d\nNota: %.1f\n", a->nome, a->matricula, a->nota);
                            }
                            else
                            {
                                printf("\nAluno nao encontrado ou lista vazia!\n");
                            }
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                }
                else
                {
                    printf("A lista nao foi criada!\n");
                }
                break;
            case 4:
                if(lista != NULL)
                {
                    Aluno *a;
                    int opcao_interna = 0;
                    printf("Deseja remover o aluno pela matricula ou pela nota?\n1 - Matricula\n2 - Nota\n");

                    scanf("%d", &opcao_interna);
                    fflush(stdin);
                    printf("\n");

                    switch(opcao_interna)
                    {
                        case 1: ;
                            int mat;

                            printf("Digite a matricula:\n");
                            scanf("%d", &mat);
                            fflush(stdin);

                            a = (Aluno *)sllRetirar(lista, (void *)&mat, cmpMat);
                            if(a != NULL)
                            {
                                qtd_insercoes--;
                                printf("\nInformacoes do aluno removido:\n\nNome: %sMatricula: %d\nNota: %.1f\n", a->nome, a->matricula, a->nota);
                            }
                            else
                            {
                                printf("\nAluno nao encontrado ou lista vazia!\n");
                            }
                            break;
                        case 2: ;
                            float nota;

                            printf("Digite a nota:\n");
                            scanf("%f", &nota);
                            fflush(stdin);

                            a = (Aluno *)sllRetirar(lista, (void *)&nota, cmpNota);
                            if(a != NULL)
                            {
                                qtd_insercoes--;
                                printf("\nInformacoes do aluno removido:\n\nNome: %sMatricula: %d\nNota: %.1f\n", a->nome, a->matricula, a->nota);
                            }
                            else
                            {
                                printf("\nAluno nao encontrado ou lista vazia!\n");
                            }
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                }
                else
                {
                    printf("A lista nao foi criada!\n");
                }
                break;
            case 5:
                if(lista != NULL)
                {
                    Aluno *a;

                    a = (Aluno *)sllPegarPrimeiro(lista);
                    if(a != NULL)
                    {
                        printf("Informacoes do aluno 1:\nNome: %sMatricula: %d\nNota: %.1f\n", a->nome, a->matricula, a->nota);
                        for(int i = 1; i < qtd_insercoes; i++)
                        {
                            a = (Aluno *)sllPegarProximo(lista);
                            if(a != NULL)
                            {
                                printf("\nInformacoes do aluno %d:\nNome: %sMatricula: %d\nNota: %.1f\n", i+1, a->nome, a->matricula, a->nota);
                            }
                        }
                    }
                    else
                    {
                        printf("A lista esta vazia!\n");
                    }
                }
                else
                {
                    printf("A lista nao foi criada!\n");
                }
                break;
            case 6:
                if(lista != NULL)
                {
                    if(sllEsvaziar(lista) == FALSE)
                    {
                        printf("A lista ja esta vazia!\n");
                    }
                    else
                    {
                        qtd_insercoes = 0;
                        printf("Lista esvaziada com sucesso!\n");
                    }
                }
                else
                {
                    printf("A lista nao foi criada!\n");
                }
                break;
            case 7:
                if(lista != NULL)
                {
                    if(sllDestruir(lista) == FALSE)
                    {
                        printf("A lista nao esta vazia! Esvazie-a antes de destruir\n");
                    }
                    else
                    {
                        lista = NULL;
                        printf("Lista destruida com sucesso!\n");
                    }
                }
                else
                {
                    printf("A lista nao foi criada!\n");
                }
                break;
            case 8:
                sllEsvaziar(lista);
                sllDestruir(lista);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        printf("\n");
    }while(opcao != 8);

    return 0;
}
