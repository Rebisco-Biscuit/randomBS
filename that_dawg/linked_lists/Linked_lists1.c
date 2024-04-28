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

typedef struct node {
 	int num;
	struct node *link;
} *node1;

void createNode(int);
void display();

int main (){
	int size;

	printf("Input the number of nodes: );
	scanf("%d", &size);

	createNode(size);
	diplay();
}

void createNode(int size){
	struct node *head, *current, *newNode;
	int num;

	if(head==NULL){
		printf("Cannot create an empty list.");
	} else {
		head=malloc(sizeof(struct node));
	}

	printf("Input data for node 1: ");
	scanf("%d", &num);

	head->num = num;
	head->link=NULL;
	current=head;

	for(int i=2; i<size; i++){
		newNode=malloc(sizeof(struct node));
		
		printf("Input data for node %d", i);
		scanf("%d", &num);

		newNode->num = num;
		newNode->link = NULL;

