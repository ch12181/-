#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	
    int data;
    struct node *next;
    
}Node;

Node *create(){
   	Node *tmpNode;
   	tmpNode = (Node *)malloc(sizeof(Node));
   	if(tmpNode == NULL){	
       	printf("°O¾ÐÅé¤£¨¬");
       	exit(1);
   	}
   	tmpNode->next = NULL;
   	return tmpNode;
}

void insertNode(Node *head, int data){
    Node *tmp = create();
    tmp->next = NULL;
    tmp->data = data;
    
    Node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next= tmp;
    
}

void deleteNode(Node *head){
    Node *ptr = head;
    Node *tmp = NULL;
    while(ptr->next != NULL){
        tmp = ptr;
        ptr = ptr->next;
    }
    tmp->next = NULL;
    free(ptr);
    
}

void findNode(Node *head, int data){
    Node *ptr = head;
    int length=0;
    while(ptr->next != NULL ){
        if(ptr->data == data){
            printf("data at index : %d\n",length);
            break;
        }
        ptr = ptr->next;
        length++;
    }
}

void travelNode(Node *head){
    Node *ptr = head;
    while(ptr->next != NULL){
        ptr=ptr->next;
        printf("%d\t",ptr->data);
    }
    printf("\n");
}

void insertNodeAtIndex(Node *head,int index,int data){
	Node *tmp = create();
    
    tmp->data = data;
    Node *ptr = head;
    int i;
    for(i = 0;i <= index;i++){
        ptr = ptr->next;
    }
    tmp->next = ptr->next;
    ptr->next = tmp;
    
	while(ptr->next != NULL){
        ptr = ptr->next;
    }
    
}

void deleteNode(Node *head,int index){
	Node *ptr = head;
	Node *tmp = NULL;
	for(i = 0;i <= index;i++){
        ptr = ptr->next;
    }
	
}


int main(){
	
	Node *head = create();
	insertNode(head,5);
	insertNode(head,6);
	insertNode(head,7);
	insertNode(head,8);
	insertNodeAtIndex(head,1,0);
	travelNode(head);
	deleteNode(head,2);
	printf("\n");
	travelNode(head);
	return 0;
} 
