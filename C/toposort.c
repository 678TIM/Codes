#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
struct node{
	int succ;
	Node* next;
};

int main(){
    int n;
    scanf("%d", &n);
    int COUNT[n+1]; // Note array is 1-indexed. Hence we need one more slot.
    Node* LIST[n+1];
    Node* alpha = NULL;
    // initializations
    for (int k = 1; k <= n; k++){
        COUNT[k] = 0;
        LIST[k] = NULL;
    }
    int m;
    m = n;
    // GET INPUTS
    int x,y;
    scanf("%d %d", &x, &y);
    while (x != 0 && y != 0){
        COUNT[y]++; // increments the count of direct predecessors of k by 1
        // insert node at the HEAD of a linked list
        alpha = (Node*)malloc(sizeof(Node)); // aka GETNODE(alpha)
        alpha->succ = y; // succ := a direct successor
        alpha->next = LIST[x];
        LIST[x] = alpha;
        scanf("%d %d", &x, &y);
    }
    // initialize LINKED output queue
    int front = 0, rear = 0;
    for (int k = 1; k <= n; k++){
        if (COUNT[k] == 0){
            if (front == 0){
                front = k;
                rear = k;
            } else {
            COUNT[rear] = k;
            rear = k;
            }
        } 
    }
    // // test OUTPUT
    // for (int i = 1; i <= n; i++){
    //     printf("%d ", COUNT[i]);
    // }
    // printf("\n");
    // OUTPUT
    while (front != 0){
        printf("%d ", front);
        m--;
        alpha = LIST[front];
        while (alpha != NULL){
            y = alpha->succ;
            COUNT[y]--; // decrement count of direct successors by 1
            if (COUNT[y] == 0){ // enqueue to output queue
                COUNT[rear] = y;
                rear = y;
            }
            // FREE THE NODES!
            Node* to_free;
            to_free = alpha;
            alpha = alpha->next;
            free(to_free);
        }
        front = COUNT[front];
    }

    return 0;
}

