#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char stack[10] = {0};
	char input[10] = {0};
	int top = -1;
	int i;
	scanf("%s",input);
	printf("%s\n",input);
	
	int len = strlen(input);
	
	for(i = 0;i < len;i++){
		
		if(input[i] == '(' || input[i] == '[' || input[i] == '{'){
			
			stack[i] = input[i];
			top++;
			
		}else if(input[i] == ')'){

			if(stack[top] == '('){
			
				top--;
				
			}else{
				
				break;
				
			}
			
		}else if(input[i] == ']'){
			
			if(stack[top] == '['){
				
				top--;
				
			}else{
				
				break;
				
			}
			
		}else if(input[i] == '}'){
			
			if(stack[top] == '{'){
				
				top--;
				
			}else{
				
				break;
				
			}
			
		}
		
	}
	
	if (top == -1){
		
		printf("Y\n");
		
	}else{
		
		printf("N \n");
		
	}
	
	return 0;
	
}
