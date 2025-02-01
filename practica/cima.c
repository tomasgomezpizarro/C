#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cima(int a[], int start, int end){
    if (start == end){
        return start;
    }
    int mid = (start + end)/2;
    if (a[mid] < a[mid+1]){
        return cima(a, mid+1, end);
    } else {
        return cima(a, start, mid);
    }
}

void merge(int *n, int s, int e){
    if (s == e){ 
        return ;
    }
    int midterm = (s+e)/2;
    merge(n, s, midterm);
    merge(n, midterm + 1, e);
    int aux[e-s+1];
    int j = 0;
    int i = 0;
    while (i+j<=e-s){
        if (midterm + 1 + j > e){
            aux[i+j] = n[s+i];
            i++;
        }
        if (n[s+i] > n[midterm + 1 + j] || s+i > midterm){
            aux[i+j] = n[midterm + 1 + j];
            j++;
        } else {
            aux[i+j] = n[s+i];
            i++;
        }
    }

    for (int i = 0; i<=e-s; i++){
        n[s+i] = aux[i];
    }


}

int main()
{
    srand(time(0));
    int min = 10, max = 50;
    int n = 10;
    int a[n];

    for (int i = 0; i < n; i++) {
        a[i] = min + rand() % (max - min + 1); // Random number in [min, max]
    }

    int cim = rand()%n, temp;
    printf("Cima: %d\n", cim);

    merge(a, 0, cim);
    merge(a, cim+1, n-1);

    for (int i = 0; i<n; i++){
        printf("%d ", a[i]);
    }

    printf("\n");
    
    for (int i = 0; i<(n-cim-1)/2; i++){
        temp = a[i+cim+1];
        a[i+cim+1] = a[n-1-i];
        a[n-1-i] = temp;
    }

    for (int i = 0; i<n; i++){
        printf("%d ", a[i]);
    }

    printf("\n");

    printf("Cima: %d", cima(a, 0, 8));

    return 0;
}