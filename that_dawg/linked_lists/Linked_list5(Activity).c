#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
int countNode();
void insertEnd();
void display();
void transfer();

int main() {
    int opt, totalNodes=0, n;
    
    while(1){
        printf("1. Populate\n");
        printf("2. Transfer\n");
        printf("3. View List\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        
        printf("\nEnter choice: ");
        scanf("%d", &opt);
        
        switch(opt){
            case 1:
                totalNodes=countNode();
                if(totalNodes == false){
                    printf("\nEnter nodes to create: ");
                    scanf("%d", &n);
                    if(n<=0){
                        printf("Cannot create %d nodes.\n\n", n);
                    } else {
                        createNode(n);
                        printf("\nNodes created successfully.\n\n");
                    }
                } else {
                    insertEnd();
                    printf("\nAdded successfully.\n\n");
                }
                break;
            case 2:
                transfer();
                printf("\nTransferred successfully.\n\n");
                break;
            case 3:
                display();
                printf("\n");
                break;
            case 4:
                //delete
                break;
            case 5:
                return 0;
        }
    }

    return 0;
}

void insertEnd(){
    struct node *temp, *newNode;
    
    newNode=malloc(sizeof(struct node));
    
    printf("Enter balance: ");
    scanf("%d", &newNode->data.balance);
      
    printf("Enter id number: ");
    scanf("%d", &newNode->data.idNum);
    
    temp=Node;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

int countNode(){
    struct node *temp;
    int ctr;
    
    temp=Node;
    
    while(temp!=NULL){
        temp=temp->next;
        ctr++;
    }
    return ctr;
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
  
  printf("\nEnter balance: ");
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
  printf("\n");
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
    
    
