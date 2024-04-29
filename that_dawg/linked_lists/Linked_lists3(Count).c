/* 
Write a program in C to create a singly linked list of n nodes and count the number of nodes.
Test Data :
Input the number of nodes : 3
Input data for node 1 : 5
Input data for node 2 : 6
Input data for node 3 : 7
Expected Output :

 Data entered in the list are :                                                                               
 Data = 5                                                                                                     
 Data = 6                                                                                                     
 Data = 7
      
 Total number of nodes = 3
  */

#include <stdlib.h>
#include <stdio.h>

struct node {
    int num;
    struct node *link;
} *node1;

void createNode(int);
void display();
int countNode();

int main() {
    int num, totalNodes;
    printf("Enter number of nodes: ");
    scanf("%d", &num);

    createNode(num);
    display();
    
    totalNodes=countNode();
    printf("\n\nTotal Number of nodes: %d", totalNodes);
    
    return 0;
}

void createNode(int num){
    struct node *temp, *newNode;
    int n;
    
    node1=malloc(sizeof(struct node));
    
    printf("Enter value for node 1: ");
    scanf("%d", &n);
    
    node1->num=n;
    node1->link=NULL;
    
    temp=node1;
    
    for(int i=2; i<=num; i++){
        newNode=malloc(sizeof(struct node));
        
        printf("Enter value for node %d: ", i);
        scanf("%d", &n);
        
        newNode->num=n;
        newNode->link=NULL;
        
        temp->link=newNode;
        temp=temp->link;
        
    }
}

void display(){
    struct node *temp;
    
    temp=node1;
    
    while(temp != NULL){
        printf("\nData = %d", temp->num);
        temp=temp->link;
    }
}

int countNode(){
    struct node *temp;
    int i=0;
    
    temp=node1;
    
    while(temp != NULL){
        i++;
        temp=temp->link;
    }
    return i;
}
