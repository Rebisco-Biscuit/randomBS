/* 
2. Write a program in C to create a singly linked list of n nodes and display it in reverse order.
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
                                                                                                              
 The list in reverse are :                                                                                    
 Data = 7                                                                                                     
 Data = 6                                                                                                     
 Data = 5 
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *link;
} *node1;

void createNode(int);
void revNode();
void display();

int main(){
    int size;
    
    printf("Enter node size: ");
    scanf("%d", &size);
    
    if(size <=0){
        printf("Cannot create list with a size of %d.", size);
    } else {
      
    createNode(size);
    
    printf("\nOriginal List:\n");
    display();
    
    
    revNode();

    printf("\n\nReversed List:\n");
    display();
    
    }
}

void createNode(int n){
    struct node *newNode, *temp;
    int num;
    
    node1=malloc(sizeof(struct node));
    
    if(node1==NULL){
        printf("Memory allocation failed.");
    } else {
        printf("Enter data for node 1: ");
        scanf("%d", &num);
        node1->num=num;
        node1->link=NULL;
        
        temp=node1;
        
        
        for(int i=2; i<=n; i++){
            newNode=malloc(sizeof(struct node));
            
            printf("Enter data for node %d: ", i);
            scanf("%d", &num);
            
            newNode->num=num;
            newNode->link=NULL;
            
            temp->link=newNode;
            temp=temp->link;
        }
        
    }
}

void revNode() {
    struct node *prevNode, *curNode;

    if(node1 != NULL) {
        prevNode = node1;
        curNode = node1->link;
        node1 = node1->link;

        prevNode->link = NULL;

        while(node1 != NULL) {
            node1 = node1->link;
            curNode->link = prevNode;

            prevNode = curNode;
            curNode = node1;
        }
        node1 = prevNode;
    }
}
void display(){
    struct node *temp;
    
    if(node1==NULL){
        printf("List is empty.");
    } else {
        temp=node1;
        
        while(temp!=NULL){
            printf("Data = %d\n", temp->num);
            temp=temp->link;
        }
    }
}
