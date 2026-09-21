#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }

    struct Node *last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;
}

void insertBeginning(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }

    struct Node *last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;

    head = newNode;
}

void deleteBeginning() {
    if (head == NULL)
        return;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *last = head->prev;
    struct Node *temp = head;

    head = head->next;

    head->prev = last;
    last->next = head;

    free(temp);
}

void deleteEnd() {
    if (head == NULL)
        return;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *last = head->prev;
    struct Node *newLast = last->prev;

    newLast->next = head;
    head->prev = newLast;

    free(last);
}

void displayForward() {
    if (head == NULL)
        return;

    struct Node *temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

void displayBackward() {
    if (head == NULL)
        return;

    struct Node *temp = head->prev;

    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);

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