#include <stdlib.h>
#include <stdio.h>

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
    insertNode(&head, &tail, 20);
    insertNode(&head, &tail, 25);
    display(head, tail);
    
    insPos(&head, &tail, 100, 2);
    display(head, tail);    
    insPos(&head, &tail, 100, 4);
    display(head, tail);    

    return 0;
}

void display(struct node *head, struct node *tail) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insPos(struct node **head, struct node **tail, int data, int idx) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(*head == NULL || idx == 0) {
        newNode->next = *head;
        if(*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        if(*tail == NULL) {
            *tail = newNode;
        }        
        return;
    }
    
    struct node *temp = *head;
    int i = 0;
    while(temp != NULL && i < idx - 1) {
        temp = temp->next;
        i++;
    }
    
    if(temp == NULL) {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        
        if(temp->next != NULL) {
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
    
    struct node *temp = *head;
    
    if(*head == NULL || *tail == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        newNode->prev = temp; 
        temp->next = newNode; 
        (*tail) = newNode;
    }   
}
