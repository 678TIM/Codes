#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
  int data;
  Node* next;
};

void freeList(Node *list)
{
  Node *next_node;
  while (list != NULL)
  {
    next_node = list->next;
    free(list);
    list = next_node;
    
  }
}
void printList(Node *list)
{
  while (list != NULL)
  {
    printf("%d \n", list->data);
    list = list->next;
  }
}

int main()
{
 int A[10] = {10, 24,34,23,76,89,72,83,92, 100};
 Node* list = malloc(sizeof(Node));
 Node *last;
 list->next = NULL;
 for (int i = 0; i < 10; i++)
 {
   if (i == 0)
   {
     list->data = A[i];
     last = list;
   }
   else
   {
     Node *node = malloc (sizeof(Node));
     node->data = A[i];
     last->next = node;
     last = node;
   }
 }
 printList(list);
 freeList(list);

  return 0;

}
