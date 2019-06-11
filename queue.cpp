#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node{
	int num;
	struct node *next;
	struct node *prev;
}NODE;

NODE* GenerateNode(int num){
	NODE *new_node;
	new_node = (NODE*)malloc(sizeof(NODE));
	new_node -> num = num;
	new_node -> next = NULL;
	return new_node;
}

int main(){
	
	int i = 0,num = 0,randnum = 0;
	char input[5] = {};
	NODE *head = NULL,*top,*temp,*current;
	srand(time(NULL));
	
	while(1){
		
		printf(">>");
		scanf("%s",input);
		
		if(strcmp(input,"push") == 0){
			
			randnum = rand() % 100;
			
			if(head == NULL){
				
				head = GenerateNode(randnum);
				top = head;
				
			}else{
				
				top -> next = GenerateNode(randnum);
				temp = top;
				top = top -> next;
				top -> prev = temp;
				
			}
			
		}else if(strcmp(input,"pop") == 0){
			
			if(head == NULL){
				
				printf("The stack is empty");
				
			}else{
				
				if(top == head){
					
					head = NULL;
					printf("The stack is empty");
					
				}else{
					
					head = head -> next;
					head -> prev = NULL;
					
				}
				
			} 
			
			
		}else if(strcmp(input,"end") == 0){
			
			break;
			
		}else{
			
			printf("invalid command");
			
		}
		
		if(head != NULL){
			
			current = head;
			while(current != NULL){
				
				printf("%d ",current -> num);
				current = current -> next;
				
			}
			
		}
		
		printf("\n");
		
	}
	
	return 0;
}

