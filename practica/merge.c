#include <stdio.h>

void merge(int *n, int l, int s, int e){
    if (s == e){ 
        return ;
    }
    int midterm = (s+e)/2;
    merge(n, l, s, midterm);
    merge(n, l, midterm + 1, e);
    for (int i = 0; i<17; i++){
        printf("%d ", n[i]);
    }
    printf("\n");
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
    int n[] = {8,1,6,7,4,5,2,3,1,4,53,1,94,0,-8,7,-4};

    merge(n, 17, 0, 16);

    for (int i = 0; i<17; i++){
        printf("%d ", n[i]);
    }
    return 0;
}