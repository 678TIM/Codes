#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node Node;
struct node{
    int key; // contains key from 0-31
    char* word; // contains word
    Node* next; // contains link to next word or NULL
};

int compute_HV(int k, int func){
    if (func == 1){
        return k % 32;
    } else if (func == 2){
        int exp = pow(2, 11);
        return ((31 * k) % exp) >> 6;
    } else {
        return ((1731 * k + 520123) % 524287) % 32;
    }
}

void hash(Node* *hash_table, int n, int func){
    for (int i=0; i<n; i++){ // process input words and their HVs
        char* input = (char*)malloc(10); // allocates NEW memory para di ma-overwrite ng last word lmao XD
        scanf("%s", input);
        int length = strlen(input);
        int k=0;
        for (int j=0; j<length; j++){
            k += input[j];
        }
        // printf("Word: %s, ASCII: %d | ", input, k);
        k = compute_HV(k, func); // process hashval
        // printf("Word: %s, Hash Val: %d\n", input, k);
        // Insert the WORD
        Node* alpha = (Node*)malloc(sizeof(Node));
        alpha->key = k;
        alpha->word = input;
        alpha->next = hash_table[k]; // note hash_table[k] is initially NULL. alpha then points to NULL
        hash_table[k] = alpha; // and hash_table[k] now points to alpha!
    }        
    // PRINT THE HASH TABLE
    Node* curr;
    for (int i=0; i<32; i++){
        printf("%d: ", i);
        for (curr = hash_table[i]; curr != NULL; curr = curr->next){
            printf("%s ", curr->word);
        }
        printf("\n");
    }
}

int main(){
    int n, func;
    scanf("%d\n%d\n", &func, &n);
    Node* hash_table[32]; // declare array of pointers which wille eventually contain the words
    for (int i=0; i < 32; i++){ // init to be equal to NULL
        hash_table[i] = NULL;
    }
    hash(hash_table, n, func); // let the HASH(ING) begin!
    return 0;
}
