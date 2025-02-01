#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarArreglo(int** valores, int m, int n, int print){
    if (print){
        printf("Arreglo (%dx%d):\n", m, n);
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            valores[i][j] = rand()%11 - 5;
            if (print){
                printf(" %d",valores[i][j]);
            }
        }
        if (print){
            printf("\n");
        }
    }
}

void imprimir(int** valores, int m, int n){
    printf("Arreglo (%dx%d):\n", m, n);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf(" %d",valores[i][j]);
        }
        printf("\n");
    }
}

void reservarMemoria(int*** valores, int m, int n){
    *valores = (int**)malloc(m * sizeof(int*));
    if (*valores == NULL){
        printf("ERROR DE MALLOC");
        abort();
    }

    for (int i = 0; i < m; i++){
        (*valores)[i] = (int *)malloc(n * sizeof(int));
        if ((*valores)[i] == NULL){
            printf("ERROR DE MALLOC");
            abort();
        }
    }
}

void liberarMemoria(int** valores, int m){
    for (int i = 0; i < m; i++){
        free(valores[i]);
    }
    free(valores);
}

void prod(int** A, int** B, int** C, int m, int n, int p){
    int suma;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            suma = 0;
            for (int k = 0; k < n; k++){
                suma += A[i][k] * B[k][j];
            }
            C[i][j] = suma;
        }
    }    
}

int main()
{
    srand(time(0));
    int m = 3, n = 2, p=4;
    int** A = NULL;
    int** B = NULL;
    int** C = NULL;

    reservarMemoria(&A, m, n);
    inicializarArreglo(A, m, n, 1);

    reservarMemoria(&B, n, p);
    inicializarArreglo(B, n, p, 1);

    reservarMemoria(&C, m, p);

    prod(A, B, C, m, n, p);
    imprimir(C, m, p);

    liberarMemoria(A, m);
    liberarMemoria(B, n);
    return 0;
}