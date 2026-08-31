#include <stdio.h>
#include <stdlib.h>

typedef struct node { 
    int data; 
    struct node* next;
} node; 

int main() { 
    node* first = (node*)malloc(sizeof(node)); 
    node* second = (node*)malloc(sizeof(node)); 
    node* third = (node*)malloc(sizeof(node));  

    first->data = 10; 
    second->data = 20; 
    third->data = 30;  

    first->next = second; 
    second->next = third; 
    third->next = NULL;  
    node* temp = first; 
    while(temp != NULL) { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
    free(first);
    free(second);
    free(third);

    return 0; 
}

