#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char fname[20];
    char lname[20];
} name;

typedef struct {
    int month;
    int year;
} date;

typedef struct {
    name personName;
    date expiryDate;
    int balance;
    int idNum;
} bankInfo;

struct node {
    bankInfo data;
    struct node *next;
} *Node;

void createNode(int);
void display();
void transfer();

int main() {
    while(1){
        printf("1. Populate");
        printf("2. Transfer");
        printf("3. Delete");
    }
    createNode(3);
    printf("\n\nInfo:\n");
    display();
    
    transfer();
    printf("\n\nNew Info:\n");
    display();

    return 0;
}

void createNode(int n){
  struct node *temp, *newNode;
  
  Node=malloc(sizeof(struct node));
  
//   printf("Enter fname: ");
//   scanf(" %s", Node->data.personName.fname);
  
//   printf("Enter lname: ");
//   scanf(" %s", Node->data.personName.lname);
  
//   printf("Enter month: ");
//   scanf("%d", &Node->data.expiryDate.month);
  
//   printf("Enter year: ");
//   scanf("%d", &Node->data.expiryDate.year);    
  
  printf("Enter balance: ");
  scanf("%d", &Node->data.balance);
  
  printf("Enter id number: ");
  scanf("%d", &Node->data.idNum);       
  
  Node->next=NULL;
  temp=Node;
  
  for(int i=1; i<n; i++){
      newNode=malloc(sizeof(struct node));
        printf("\n");
      
    //   printf("Enter fname: ");
    //   scanf(" %s", newNode->data.personName.fname);
      
    //   printf("Enter lname: ");
    //   scanf(" %s", newNode->data.personName.lname);
      
    //   printf("Enter month: ");
    //   scanf("%d", &newNode->data.expiryDate.month);
      
    //   printf("Enter year: ");
    //   scanf("%d", &newNode->data.expiryDate.year);   
      
      printf("Enter balance: ");
      scanf("%d", &newNode->data.balance);
      
      printf("Enter id number: ");
      scanf("%d", &newNode->data.idNum);      
      
      
      newNode->next=NULL;
      
      temp->next=newNode;
      temp=temp->next;
  }
}

void display(){
    struct node *temp;
    
    temp=Node;
    while(temp!=NULL){
        // printf("%s", temp->data.personName.fname);
        // printf(" %s\n", temp->data.personName.lname);
        
        // printf("%d - %d", temp->data.expiryDate.month, temp->data.expiryDate.year);
        
      printf("Balance = %d", temp->data.balance);
      printf("\nId Number = %d", temp->data.idNum);
        
        printf("\n\n");
        
        temp=temp->next;
    }
    
}

void transfer(){
    struct node *temp;
    
    temp=Node;
    int id, idTo, amt;
    
    printf("Enter id number: ");
    scanf("%d", &id);
    
    printf("Enter id number to transfer: ");
    scanf("%d", &idTo);
    
    printf("Enter amount to transfer: ");
    scanf("%d", &amt);
    
    while(temp!=NULL){
        if(temp->data.idNum == idTo){
            temp->data.balance=((temp->data.balance)+amt);
        }
        if(temp->data.idNum == id){
            temp->data.balance=((temp->data.balance)-amt);
        }
        temp=temp->next;
    }
}
    
    
