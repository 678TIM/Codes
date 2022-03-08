#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*      1 - I N D E X E D VERSION        */

int quick_select(int A[], int p, int r, int k);

void insertion_sort(int A[], int from, int to) {
    for(int i = from; i < to; i++) {
        for(int j = i + 1; j > from && A[j] < A[j - 1]; j--) {
            int temp = A[j - 1];
            A[j - 1] = A[j];
            A[j] = temp;
        }
    }
}

int median_of_medians(int A[], int p, int r){
	// Write your code here
    // MAKE A COPY OF THE ORIGINAL ARRAY (this is where u do insertion sort)
    int length = r-p+1; // length of ORIGINAL array
    int copy[length+1]; // plus 1 cuz 1-indexed lol
    for (int i=1; i<=length; i++){
        copy[i] = A[i];
    }
    
    int new = ceil(length/5); // length of NEW subarray which will contain the median(s)
    int B[new+1]; // array which contains the median(s)
    for (int i=p; i < new+1; i++){
        if (i < new){ // FIRST NEW-1 GROUPS (guaranteed length 5 each)
            insertion_sort(copy, i*5-4, i*5); // minus cuz 1-indexed
            B[i] = copy[i*5-2]; // say i=2. then the median of the 2nd group is at index 8.
        } else if (i == new){ // LAST GROUP
            int rem = length % 5;
            if (rem == 0){
                insertion_sort(copy, i*5-4, i*5);
                B[i] = copy[i*5-2];
            } else {
                insertion_sort(copy, i*5-4, i*5-(5-rem));
                int med = (rem+1)/2;
                B[i] = copy[i*5+med];
            }
        }
    }
    if (new > 5){
        return quick_select(B, 1, new, (new+1)/2);
    } else {
        int med = (new+1)/2;
        return B[med];
    }

}

int partition(int A[], int p, int r){
	// Write your code here
    int median = median_of_medians(A, p, r);
    // printf("Median found : %d\n", median);
    // find index of median AND swap A[ind] with A[r]
    for (int i = p; i<r; i++){
        if (A[i] == median){
            int temp = A[i];
            A[i] = A[r];
            A[r] = temp;
        }
    }
    int x = A[r];
    int i = p-1;
    for (int j = p; j<r; j++){
        if (A[j] <= x){
            i++;
            // swap A[i] with A[r]
            int temp2 = A[i];
            A[i] = A[j];
            A[j] = temp2;
        }  
    }
    // swap A[i+1] and A[r]
    int temp3 = A[i+1];
    A[i+1] = A[r];
    A[r] = temp3;
    // printf("Current index of pivot: %d\n", i+1);
    
    return i+1;
}

int quick_select(int A[], int p, int r, int rank){
	// Write your code here
    if (p == r){
        return A[p];
    }
    int q = partition(A, p, r);
    int k = q - p + 1;
    if (rank == k){
        return A[q];
    } else if (rank < k){
        return quick_select(A, p, q-1, rank);
    } else {
        return quick_select(A, q+1, r, rank - k);
    }
}

int main(){
	int T, M;
	scanf("%d", &T);
	while(T-- > 0){
		scanf("%d", &M);
		int arr[M+1];

		//read the elements of the input array
		for(int i=1; i<=M; i++){
			scanf("%d",&arr[i]);
		}

		int median_index = ((M+1)/2);
        // printf("Target Median Index (1-indexed): %d\n", median_index);
		printf("Median: %d\n", quick_select(arr, 1, M, median_index));
	}
}
