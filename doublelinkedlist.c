#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node* prev;
    struct node* next;
};

void insert(struct node **head, char x, int pos) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = x;

    if (pos == 1) {
        newnode->prev = NULL;
        newnode->next = *head;
        *head = newnode;
    }
    else {
        struct node *temp = *head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp != NULL) {
            newnode->next = temp->next;
            newnode->prev = temp;

            if (temp->next != NULL)
                temp->next->prev = newnode;

            temp->next = newnode;
        }
        else {
            free(newnode);
        }
    }
}

void display() {
}

int main() {
    struct node *head = NULL;
    printf("code completed");
    return 0;
}

