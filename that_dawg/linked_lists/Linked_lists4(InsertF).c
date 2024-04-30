#include <stdlib.h>
#include <stdio.h>

struct node {
    int num;
    struct node *link;
} *node1;

void createNode(int);
void insertF(int);
void display();

int main() {
    int size, n;
    
    printf("Enter list size: ");
    scanf("%d", &size);
    
    createNode(size);
    
    printf("\n\nList: ");
    display();
    
    printf("\nEnter data to insert at front: ");
    insertF(n);

    return 0;
}

void createNode(int size){
    struct node *temp, *newNode;
    
    node1=malloc(sizeof(struct node));
    
    printf("Enter data for node 1: ");
    scanf("%d", &node1->num);
    
    node1->link=NULL;
    
    temp=node1;
    
    for(int i=2; i<=size; i++){
        newNode=malloc(sizeof(struct node));
        
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->num);
        newNode->link=NULL;
        
        temp->link=newNode;
        temp=temp->link;
    }
}

void display(){
    struct node *temp;
    
    temp=node1;
    
    while(temp!=NULL){
        printf("\nData = %d", temp->num);
        temp=temp->link;
    }
}

void insertFront(int n){
    struct node *temp, *frontNode;
    
    frontNode=malloc(sizeof(struct node));
    frontNode->num=n;
    frontNode->link=node1;
    
    node1->link=temp;
    
}
