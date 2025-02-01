#include <stdio.h>
#include <stdlib.h>

int min(int** p, int n, int m){
    int min_ = p[0][0];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (p[i][j] < min_){
                min_ = p[i][j];
            }
        }
    }
    return min_;
}

int* min_por_fila(int**p, int n, int m){
    int* mins = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        mins[i] = p[i][0];
        for (int j = 0; j < m; j++){
            if (p[i][j] < mins[i]){
                mins[i] = p[i][j];
            }
        }
    }
    return mins;
}

int main(){
    int n, m;
    printf("Ingrese la cantidad de filas del array: ");
    scanf("%d", &n);
    printf("Ingrese la cantidad de columnas del array: ");
    scanf("%d", &m);

    int** a = (int**)malloc(n * sizeof(int*));
    if (a == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(m * sizeof(int));
        if (a[i] == NULL) {
            printf("Error al asignar memoria.\n");
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Ingrese el elemento (%d, %d): ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Minimo: %d\n", min(a, n, m));
    int* mins = min_por_fila(a, n, m);
    for (int i = 0; i < n; i++) {
        printf("Min fila %d: %d\n", i, mins[i]);
    }

    free(mins);

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}