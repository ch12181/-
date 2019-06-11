#include <stdlib.h>
#include <stdio.h>

struct node                     
{
    int data;                     
    struct node *left;            
    struct node *right;           
};
typedef struct node treenode;     


treenode* add_node(treenode* root,int value)
{
    treenode* newnode;                
    treenode* current;                                    
    
    newnode = (treenode*) malloc (sizeof(treenode));
    newnode -> data = value;
    newnode -> right = NULL;
    newnode -> left = NULL;
    
    current = root;
    
    if(root == NULL){
    	
    	root = newnode;
    	
	}else{
		
		while(1){
		
			if(newnode -> data > current -> data){
				
				if(current -> right == NULL){
					
					current -> right = newnode;
					break; 
					
				}else{
					
					current = current -> right;
					
				}
				
			}else{
				
				if(current -> left == NULL){
					
					current -> left = newnode;
					break; 
					
				}else{
					
					current = current -> left;
					
				}
				
			}
			
		}
		
	}
	
	return root;
}

void preorder_travel(treenode* ptr)
{
    
    if ( ptr != NULL ){
    	
    	printf("%d ",ptr -> data);
    	preorder_travel(ptr -> left);
    	preorder_travel(ptr -> right);
    	
	}
    
}

char searchNode(treenode* root,int input){
	
	treenode* current = root;
	char x;
	
	while(1){
		
		if(input == current -> data){
			
			x = 'Y';
			return x;
			
		}else{
			
			if(input > current -> data){
				
				if(current -> right == NULL){
					
					x = 'N';
					return x;
					
				}
				current = current -> right;
				
			}else{
				
				if(current -> left == NULL){
					
					x = 'N';
					return x;
					
				}
				
				current = current -> left;
				
			}
			
		}
		
	}
	
}

void main()
{
    
    int input = 1;
    int i; 
    char search;
    treenode* root = NULL;            
    
    while(input != 0){
    	
    	scanf("%d",&input);
    	if(input == 0){
    		
    		break;
    		
		}
    	root = add_node(root,input); 
    	
	}   
	
	input = 1;
	while(input != 0){
		
		scanf("%d",&input);
		if(input == 0){
    		
    		break;
    		
		}
		
		search = searchNode(root,input);
		printf("%c ",search);
		
	}
	
    printf("\n");
    preorder_travel(root); 
	                           
}



