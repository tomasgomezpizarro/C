#include <stdbool.h>
#include <time.h>

static unsigned int contadorswaps = 0;
static unsigned int contadorcomparaciones = 0;
clock_t tiempoinicio;

bool goes_before(int x, int y){
    contadorcomparaciones ++;
    return x<y;
}

bool array_is_sorted(int a[], unsigned int length){
    for (unsigned int i=1; i<length;i++){
        if (goes_before(a[i], a[i-1])){
            return 0;
        }
    }
    return 1;
}

void swap(int a[], unsigned int i, unsigned int j){
    contadorswaps++;
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void reset_comparisons_counter(){
    contadorcomparaciones = 0;
}

unsigned int comparisons_number(){
    return contadorcomparaciones;
}

void reset_swaps_counter(){
    contadorswaps = 0;
}

unsigned int swaps_number(){
    return contadorswaps;
}

void set_current_time(){
    tiempoinicio = clock();
}

double calculate_elapsed_time(){
    return (double)(clock()-tiempoinicio);
}