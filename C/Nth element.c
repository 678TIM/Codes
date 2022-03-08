#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
	int data;
	Node* next;
};

void build_linked_list(Node **head_ptr){
	int num; 
	while (1){
		scanf("%d ", &num);
		if (num == -1) {
			break;
		} else { // insert a node at the start of the list
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = num; // assigns the data part to hold the value num
			newNode->next = *head_ptr; // assigns the next part to point to NULL
			*head_ptr = newNode; // assigns the head to point to newNode
		}
	}
}

int count(Node *head, int x){
	// Write your code here
	int count = 0;
	Node* current = head;
	while (current != NULL){
		if (current->data == x){
			count++; // increment count if data part of current node == x
		}
		current = current->next; // point to the next node
	}
	return count;
}

int get_nth(Node *head, int n){
	Node* current = head; // sets first node to be head
	for(int i = 1; i <= n; i++){
		if(i==n){
			return current->data; // returns element at nth index
			break;
		}
		current = current->next; // point to the next node
	}
}
