#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /* 1 = true; 0 = false */

int main() {
    int start,end;
    scanf("%d%d", &start, &end);
    int nums[end];
    int i;
    /* initialize array up to end */
    for (i=0; i<=end; i++) {
        nums[i] = 1;
    }
    for (int p=2; p*p <= end; p++) {
        if (nums[p]) {
            for (int j = p*p; j <= end; j+=p) {
                nums[j] = 0;
            }
        }
    }
    nums[0] = 0;
    nums[1] = 0;
    int none = 1; // boolean
    for (int j=start; j <= end; j++) {
        if (nums[j]) {
            none = 0;
            break;
        }
    }
    if (none) {
        printf("None");
    } else {
        for (int k = start; k <= end; k++) {
           if (nums[k] && k >= start && k <= end) {
                 printf("%d ", k);
             }
         }
    }
   
    return 0;
}