#include <stdio.h>
#include <stdlib.h>

int main(){

	const int ARR1_LEN = 16;
	const int ARR2_LEN = 4;
	const int ELEM_SIZE = 1;

	int LEN = 0;
	char arr1[16] = "bababacabaatest!";
	char arr2[4] = "abcd";
	for (int i = 0; i < ARR1_LEN; i++){
		int FOUND = 0;
		for (int k = 0; k < ARR2_LEN; k++){
			if (arr1[i] == arr2[k]){
				FOUND = 1;
				break;
			}
		}
		if (FOUND == 1){
			LEN++;
		} else {
			break;
		}
		
	}
	printf("%d\n", LEN);

	return 0;
}