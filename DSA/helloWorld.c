// printf("hello world");

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

    // insertNode(&head, &tail, 5);
    // insertNode(&head, &tail, 15);
    // insertNode(&head, &tail, 115);
    // insPos(&head, &tail, 100, 2);
    // display(head, tail);
    char choice;
    int data;
        
    while(1){
        printf("Options:\na. Insert node\nb. Insert position\nd. Display data\nEnter choice: ");
        scanf(" %c", &choice);
        
        if(choice == 'a' || choice == 'A') {
            printf("Enter data: ");
            scanf("%d", &data);
            
            insertNode(&head, &tail, data);
        } else if (choice == 'b' || choice == 'B') {
            int idx;
            printf("Enter index: ");
            scanf("%d", &idx);
            
            printf("Enter data: ");
            scanf("%d", &data);
            insPos(&head, &tail, data, idx);
        } else if (choice == 'd' || choice == 'D') {
            display(head, tail);
        }
        printf("\n");
    }

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

    // If the list is empty or idx is 0, insert at the beginning
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

    // Traverse to find the position
    while (temp != NULL && count < idx - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {  // If index is beyond the last node, insert at the end
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    } else {  // Insert in between nodes
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        } else {
            *tail = newNode;  // Update tail if at the end
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

