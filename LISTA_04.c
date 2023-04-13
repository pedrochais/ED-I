#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/* ENUNCIADO
Considere as matrizes ma e mb armazenadas em vetor e seus tamanhos nxm e pxq e faca as seguintes funções:


A)  retorna o resultado da multiplicação de ma por mb se for possível em um vetor
int *MultMat ( int * vma, int *vmb, int n, int m, int p, int q)

B) retorna a matriz transposta de ma
int *TranspostadeMat ( int * vma, int n, int m)

C) retorna a soma dos elementos da linha l da matriz ma
int *SomaDosElementosDalinhaL (int * vma, int n, int m)


D) retorna  TRUE se ma é simétrica e FALSE caso contrario
Int ESimetrica ( int * vma, int n, int m)

E) retorna os elementos do triangulo superior da matriz ma
int *TRainguloSuperiodemat ( int * vma, int n, int m)


F) retorna a soma dos elementos da diagonal principal ( i=j)
int *ElementosDiagonal ( int * vma, int n, int m)
*/

// n/p: linhas
// m/q: colunas
int *MultMat(int *matriz_1, int *matriz_2, int n, int m, int p, int q);
int *TranspostadeMat(int *vma, int n, int m);
int *SomaDosElementosDaLinhaL(int *vma, int n, int m);
int ESimetrica(int *vma, int n, int m);
int *TrianguloSuperiorDeMat(int *vma, int n, int m);
int *ElementosDiagonal(int *vma, int n, int m);

int main(void){
    int n, m, *ma;
    int p, q, *mb;

    n = 2;
    m = 2;
    p = 2;
    q = 2;

    ma = (int *)malloc(sizeof(int)*n*m);
    mb = (int *)malloc(sizeof(int)*p*q);

    if(ma == NULL || mb == NULL){
        printf("[Erro ao alocar memória]\n");
        exit(0);
    }
    /*
    ma[0] = mb[0] = 11;
    ma[1] = mb[1] = 22;
    ma[2] = mb[2] = 33;
    ma[3] = mb[3] = 44;
    
    ma[4] = 55;
    ma[5] = 66;
    ma[6] = 77;
    ma[7] = 88;
    ma[8] = 99;
    */
    ma[0] = 1;
    ma[1] = 2;
    ma[2] = 3;
    ma[3] = 4;

    mb[0] = 5;
    mb[1] = 6;
    mb[2] = 7;
    mb[3] = 8;


    int *resultado = MultMat(ma, mb, n, m, p, q);
    //int *resultado = TranspostadeMat(ma, n, m);
    //int *resultado = SomaDosElementosDaLinhaL(ma, n, m);
    //ESimetrica(ma, n, m);
    //int *resultado = TrianguloSuperiorDeMat(ma, n, m);
    //int *resultado = ElementosDiagonal(ma, n, m);


    //printf("%i", *resultado); //para a função SomaDosElementosDaLinhaL


    /*
    int index = 0;  //para a função TrianguloSuperiorDeMat e ElementosDiag
    while(resultado[index] != '\0'){
        printf("%i ", resultado[index]);
        index++;
    } 
    */

    
    /*
    int indice = 0; // para as funções MultMat e TranspostadeMat
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%i     ", resultado[indice]);
            indice++;
        }
        printf("\n");
    }
    */
    
    
    return 0;
}

int *MultMat(int *vma, int *vmb, int n, int m, int p, int q){
    int *resultado, soma_elemento = 0, indice = 0;
    resultado = (int *)malloc(sizeof(int)*m*p);

    if(resultado == NULL){
        printf("[Erro ao alocar memória]\n");
        exit(0);
    }

    if(m == p || n == q){
        for(int i = 0; i < n; i++){ //para percorrer cada linha na primeira matriz
            for(int k = 0; k < q; k++){ //para percorrer cada coluna na segunda matriz
                soma_elemento = 0;
                for(int e = 0; e < m; e++){ // percorre cada elemento da linha(matriz_1) e coluna(matriz_2)
                    soma_elemento += vma[i*m+e]*vmb[e*p+k];
                }
                resultado[indice] = soma_elemento;
                printf("[%i][%i] = %i / ", i, k, soma_elemento);
                indice++;
            }
            printf("\n");
        }
    } else {
        printf("[Não é possível realizar a operação]");
        return NULL;
    }
    return resultado;
}

int *TranspostadeMat(int *vma, int n, int m){
    int *transposta;
    transposta = (int *)malloc(sizeof(int)*n*m);

    if(transposta == NULL){
        printf("[Erro ao alocar memória]\n");
        exit(0);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //printf("%i <-- %i\n", j*m+i, i*m+j);
            transposta[j*m+i] = vma[i*m+j]; 
        }
    }
    return transposta;
}

int *SomaDosElementosDaLinhaL(int *vma, int n, int m){
    int soma = 0, *somaP = &soma;

    for(int j = 0; j < m; j++){
        soma += vma[1*m+j];
    }

    return somaP;
}

int ESimetrica(int *vma, int n, int m){
    int *transposta = TranspostadeMat(vma, n, m);

    for(int i = 0; i < 4; i++){
        if(vma[i] != transposta[i]){
            printf("FALSE");
            return 0;
        }
    }

    printf("TRUE");
    return 0;
}


int *TrianguloSuperiorDeMat(int *vma, int n, int m){
    int *elementos, indice = 0;
    elementos = (int *)malloc(sizeof(int));

    if(elementos == NULL){
        printf("[Erro ao alocar memória]\n");
        exit(0);
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < m; j++){
            elementos[indice] = vma[i*m + j];
            indice++;

            elementos = realloc(elementos, indice*sizeof(int));
            if(elementos == NULL){
                printf("[Erro ao alocar memória]\n");
                exit(0);
            }
        }
    }
    return elementos;
}

int *ElementosDiagonal(int *vma, int n, int m){
    int *elementos, indice = 0;
    elementos = (int *)malloc(sizeof(int));

    if(elementos == NULL){
        printf("[Erro ao alocar memória]\n");
        exit(0);
    }

    for(int i = 0; i < n; i++){
        for(int j = i; j < m; j++){
            if(j == i){
                elementos[indice] = vma[i*m + j];
                indice++;

                elementos = realloc(elementos, indice*sizeof(int));
                if(elementos == NULL){
                    printf("[Erro ao alocar memória]\n");
                    exit(0);
                }
            } 
        }
    }
    return elementos;
}