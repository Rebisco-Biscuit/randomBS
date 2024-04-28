/* Fuck it, Lets skip to linked lists: 


Sabaw:

https://www.w3resource.com/c-programming-exercises/linked_list/index.php
https://www.cs.ucr.edu/~zhiyunq/teaching/cs153/lectures/C-tutorial/exercises-linked-list.html

*/

/* 
1. Write a program in C to create and display a Singly Linked List.
Test Data :
Input the number of nodes : 3
Input data for node 1 : 5
Input data for node 2 : 6
Input data for node 3 : 7
Expected Output :

 Data entered in the list :                                                                                   
 Data = 5                                                                                                     
 Data = 6                                                                                                     
 Data = 7 
 */


#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *link;
} *node1;

void createNode(int);
void display();

int main() {
    int size;
    
    printf("Enter node size: ");
    scanf("%d", &size);
    
    if(size <=0){
        printf("Cannot create a size of %d list.", size);
    } else {
        createNode(size);
        display();
    }

    return 0;
}

void createNode(int n){
    struct node *newNode, *tmp;
    int num;
    
    node1 = malloc(sizeof(struct node));
    
    if(node1==NULL){
        printf("Memory allocation failed.");
    } else {
        printf("Enter data for node 1: ");
        scanf("%d", &num);
        
        node1->num=num;
        node1->link=NULL;
        
        tmp=node1;
        
        for(int i=2; i<=n; i++){
            newNode=malloc(sizeof(struct node));
            
            printf("Enter data for node %d: ", i);
            scanf("%d", &num);
            
            newNode->num=num;
            newNode->link=NULL;
            
            tmp->link=newNode;
            tmp=tmp->link;
        }
    }
}

void display(){
    struct node *tmp;
    
    if(node1==NULL){
        printf("List is empty.");
    } else {
        tmp=node1;
        
        while(tmp!=NULL){
            printf("Data = %d\n", tmp->num);
            tmp=tmp->link;
        }
    }
}
