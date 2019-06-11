#include <stdlib.h>
#include <stdio.h>

void maxheap(int heap[],int);

int main(){
	
	int heap[7] = { 0, 8, 14, 16, 10, 9};
	int i;
	int n = 6;
	
	printf("°}¦C:");
	
	for(i = 1;i < 6;i++){
		
		printf("%d ",heap[i]);
		
	}
	
	maxheap(heap,n);
	
	printf("\n°ïÅ|¾ğ:");
	for(int j = 1;j < 6;j++){
		
		printf("%d ",heap[j]);
		
	}
	
	printf("\n");
	printf("°ïÅ|±Æ§Ç:");
	
	
	int temp;
	n = 4;
	for(i = 5;i > 0;i--){
		
		printf("%d ",heap[1]);
		
		temp = heap[i];
		heap[i] = heap[1];
		heap[1] = temp;
		
		maxheap(heap,n);
		n--;
	}
	
	return 0;
	
}

void maxheap(int heap[],int n){
	
	int i;
	int temp;
	
	for(i = n;i > 1;i--){
		
		if(heap[i] > heap[i / 2]){
			
			temp = heap[i];
			heap[i] = heap[i / 2];
			heap[i / 2] = temp;
			
		}
		
	}
	
}




