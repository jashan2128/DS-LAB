#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteBeginning() {
    if (head == NULL)
        return;

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

void deleteEnd() {
    if (head == NULL)
        return;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

void displayForward() {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void displayBackward() {
    if (head == NULL)
        return;

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    insertBeginning(5);

    displayForward();
    displayBackward();

    deleteBeginning();
    deleteEnd();

    displayForward();

    return 0;
}