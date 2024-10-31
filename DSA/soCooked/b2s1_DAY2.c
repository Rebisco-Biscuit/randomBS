#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void insertNode(struct node **head, struct node **tail, int data);
void insPos(struct node **head, struct node **tail, int data, int idx);
void display(struct node *head, struct node *tail);

int main() {
    struct node *head = NULL;
    struct node *tail = NULL;

    insertNode(&head, &tail, 5);
    insertNode(&head, &tail, 15);
    insertNode(&head, &tail, 115);
    insPos(&head, &tail, 100, 2);
    display(head, tail);

    return 0;
}

void display(struct node *head, struct node *tail) {
    printf("\nData: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
    printf("Reverse: ");
    while (tail != NULL) {
        printf("%d -> ", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

void insPos(struct node **head, struct node **tail, int data, int idx) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL || idx == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        if (*tail == NULL) {
            *tail = newNode;
        }
        return;
    }

    struct node *temp = *head;
    int count = 0;

    while (temp != NULL && count < idx - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        } else {
            *tail = newNode;
        }
        temp->next = newNode;
    }
}

void insertNode(struct node **head, struct node **tail, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL || *tail == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}
