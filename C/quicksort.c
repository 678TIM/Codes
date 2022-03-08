#include <stdio.h>
#include <stdlib.h>

void shuffle(int* A, int* B, int P, int M){
    for (int i=0; i<M; i++){
        int ind = ((i+1)*P) % M;
        B[i] = ind;
    }
    for (int j=0; j<M; j++){
        B[j] = A[B[j]];
    }
}

void print_list(int* A, int start, int end){
    for (int i=start; i<end; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

// TO-DO: PRINT PARTITIONED ARRAYS/SUB-ARRAY
void quicksort(int* A, int p, int r){
    if (p < r){
        int q;
        q = partition(A, p, r); // note that partition returns index of pivot
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int partition(int* A, int p, int r){
    int x = A[r];
    int i = p - 1;
    for (int j=p; j<= r-1; j++){
        if (A[j] <= x){
            i++;
            // exchange A[i] with A[j]
            int temp1;
            temp1 = A[i];
            A[i] = A[j];
            A[j] = temp1;
        }
    }
    // exchange A[i + 1] with A[r]
    int temp2;
    temp2 = A[i+1];
    A[i+1] = A[r];
    A[r] = temp2;

    print_list(A, p, r+1);
    return i + 1; // INDEX of pivot
}

int main(){
    int T; // number of test cases
    scanf("%d\n", &T);
    int M = 1000; // CHANGE 8 to 1000 when finalizing and submitting
    int P = 524287; // CHANGE 13 to 524287 ^^^
    for (int i=0; i<T; i++){ 
        // initialize array
        int A[M]; 
        for (int j=0; j<M; j++){ // store array elements
            int temp;
            scanf("%d", &temp);
            A[j] = temp;
        }
        // print_list(A, 0, M); // TOGGLE WHEN DONE TESTING
        // SHUFFLE THE ARRAY (P=13 for sample; P = 524287 for actual)
        int B[M];
        shuffle(A, B, P, M);
        print_list(B, 0, M);
        quicksort(B, 0, M-1);
        print_list(B, 0, M);
    }
    return 0;
}
