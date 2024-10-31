#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *addNode(struct node *head, struct node **tail, int data);
void display(struct node *head, struct node *tail);

int main() {
    int choice, data;
    struct node *head = NULL;
    struct node *tail = NULL;
    
    while (1) {
        printf("Add node or end? 1 : > 1 :: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            
            head = addNode(head, &tail, data);
        } else {
            display(head, tail);
            break;
        }
    }

    return 0;
}

void display(struct node *head, struct node *tail) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\nNodes in reverse: \n");
    while(tail != NULL){
        printf("%d -> ", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

struct node *addNode(struct node *head, struct node **tail, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    struct node *temp;

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        newNode->prev = temp;
        *tail = newNode;
        temp->next = newNode;
    }
    
    return head;
}
