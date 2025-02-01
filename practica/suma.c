#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int suma(int** valores, int m, int n){
    int suma = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            suma += valores[i][j];
        }
    }
   return suma; 
}

int main()
{
    srand(time(0));
    int m = 1000, n = 1000;
    int** valores = (int**)malloc(m * sizeof(int*));
    if (valores == NULL){
        printf("ERROR DE MALLOC");
        return 1;
    }

    for (int i = 0; i < m; i++){
        valores[i] = (int *)malloc(n * sizeof(int));
        if (valores[i] == NULL){
            printf("ERROR DE MALLOC");
            return 1;
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            valores[i][j] = rand()%11;
            // printf(" %d",valores[i][j]);
        }
        // printf("\n");
    }
    printf("Suma: %d", suma(valores, m, n));

    for (int i = 0; i < m; i++){
        free(valores[i]);
    }
    free(valores);
    return 0;
}