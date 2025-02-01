#include <stdio.h>


void quicksort(int a[], int start, int end){
    if (start < end){
        for (int i = 0; i<17; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
        int aux[end-start];
        int pivot = a[start], first=0, last=end-start-1;
        for (int i = start+1; i<end; i++){
            if (a[i] < pivot){
                aux[first] = a[i];
                first ++;
            } else{
                aux[last] = a[i];
                last --;
            }
        }
        aux[first] = pivot;
        for (int i=0; i<end-start; i++){
            a[start+i] = aux[i];
        }
        quicksort(a, start, start + first);
        quicksort(a, start + last + 1, end);
    }
}

void quicksortmod(int a[], int start, int end){
    if (start < end){
        for (int i = 0; i<17; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
        int aux[end-start];
        int pivot = a[start], first=0, last=end-start-1;
        for (int i = start+1; i<end; i++){
            if (a[i] < pivot){
                aux[first] = a[i];
                first ++;
            } else if (a[i] > pivot) {
                aux[last] = a[i];
                last --;
            }
        }
        for (int i = first; i <= last; i++){
            aux[i] = pivot;
        }
        for (int i=0; i<end-start; i++){
            a[start+i] = aux[i];
        }
        quicksort(a, start, start + first);
        quicksort(a, start + last + 1, end);
    }
}

int main()
{
    int n[] = {1,1,2,2,4,2,2,3,1,4,1,1,1,0,3,3,0};

    quicksort(n, 0, 17);

    for (int i = 0; i<17; i++){
        printf("%d ", n[i]);
    }
    return 0;
}