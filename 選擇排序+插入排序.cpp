#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define max 40000

void selection_sort(int array1[]);
void insertion_sort(int array2[]);
void swap(int *a,int *b);

int main(){
	
	int array1[max];
	int array2[max];
	int i;
	
	srand(time(NULL));
	
	for(i = 0;i < max;i++){
		
		array1[i] = rand() % 10000;
		array2[i] = array1[i];
		
	}
	
	selection_sort(array1);
	insertion_sort(array2);
	
	return 0;
}

void selection_sort(int array1[]){
	
	int min;
	int i,j;

	clock_t start,end;
	double time;
	start = clock();
	
	for(i = 0;i < max;i++){
		
		min = i;
		
		for(j = i + 1;j < max;j++){
			
			if(array1[j] < array1[min]){
				
				min = j;
				
			}
			
		}
		
		swap(&array1[i],&array1[min]);
		
	}
	
	end = clock();
	time = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("\nselection_sort Time = %lf\n",time);
	
//	for(i = 0;i < max;i++){
//		
//		printf("%d ",array1[i]);
//		
//	}
	
}

void insertion_sort(int array2[]){
	
	int i,j,temp;

	clock_t start,end;
	double cpu_time_used;
	start = clock();
	
	for(i = 1;i < max;i++){
		
		temp = array2[i];
		
		for(j = i;j > 0 && array2[j - 1] > temp;j--){
			
			array2[j] = array2[j - 1];
			
		}
		
		array2[j] = temp;
		
	}
	
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("\ninsertion_sort Time = %lf\n",cpu_time_used);
	
//	for(i = 0;i < max;i++){
//		
//		printf("%d ",array2[i]);
//		
//	}
	
}

void swap(int *a,int *b){
	
    int temp;
	temp = *a;
    *a = *b;
    *b = temp;
    
}

