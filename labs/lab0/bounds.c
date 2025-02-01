#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    int where;
};

struct bound_data check_bound(int value, int arr[], int length) {
    struct bound_data res;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    res.where = -1;
    for (int i=0; i < length; i++){
        if (value < arr[i]){
            res.is_upperbound = false;
        } else if (value > arr[i]){
            res.is_lowerbound = false;
        } else {
            res.exists = true;
            res.where = i;
        }
        
    }
    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    printf("Ingrese uno por uno los elementos del array: \n");
    for (int i = 0; i < ARRAY_SIZE; i++){
        printf("Ingrese el numero %d: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("Ingrese el numero a evaluar: ");
    scanf("%d", &value);

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    printf("%d\n", result.is_upperbound); // Imprime 1
    printf("%d\n", result.is_lowerbound); // Imprime 0
    printf("%d\n", result.exists);        // Imprime 1
    printf("%d\n", result.where);         // Imprime 2

    return EXIT_SUCCESS;
}

