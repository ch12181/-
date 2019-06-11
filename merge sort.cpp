#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size_1 10000
#define size_2 20000
#define size_3 40000

void MergeSort(int [],int);
void Merge(int [],int [],int [],int,int);

int main(){
	
	int arr1[size_1];
	int arr2[size_2];
	int arr3[size_3];
	
	srand(time(NULL));
	
	int i;
	
	for(i = 0;i < size_1;i++){
		
		arr1[i] = rand() % 25001 + rand() % 25000 + 1;
		
	}
	
	for(i = 0;i < size_2;i++){
		
		arr2[i] = rand() % 25001 + rand() % 25000 + 1;
		
	}
	
	for(i = 0;i < size_3;i++){
		
		arr3[i] = rand() % 25001 + rand() % 25000 + 1;
		
	}
	
	clock_t start,end;
	double time1;
	start = clock();
	
	MergeSort(arr1,size_1);
	
	end = clock();
	time1 = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("\nMergeSort Time(10000) = %lf\n",time1);
	
	double time2;
	start = clock();
	
	MergeSort(arr2,size_2);
	
	end = clock();
	time2 = ((double)(end - start)) / CLOCKS_PER_SEC;
//	for(i = 0;i < size_2;i++){
//		
//		printf("%d ",arr2[i]);
//		
//	}
	printf("\nMergeSort Time(20000) = %lf\n",time2);
	
	double time3;
	start = clock();
	
	MergeSort(arr3,size_3);
	
	end = clock();
	time3 = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("\nMergeSort Time(40000) = %lf\n",time3);
	
	printf("\naverage time = %lf\n",(time1 + time2 + time3) / 3);
	
	return 0;
	
}

void MergeSort(int arr[],int len){
	
	if(len < 2){
		
		return;
		
	}
	
	int mid;
	mid = len / 2;
	
	int right[mid];
	int left[len - mid];
	int i;
	
	for(i = 0;i < mid;i++){
		
		right[i] = arr[i];
		
	}
	
	for(i = mid;i < len;i++){
		
		left[i - mid] = arr[i];
		
	}
	
	MergeSort(right,mid);
	MergeSort(left,len - mid);
	
	Merge(arr,right,left,mid,len - mid);
	
}

void Merge(int arr[],int right[],int left[],int rightcount,int leftcount){
	
	int i,j,k;
	i = 0;
	j = 0;
	k = 0;
	while(i < leftcount && j < rightcount){
		
		if(left[i] < right[j]){
			
			arr[k] = left[i];
			k++;
			i++;
			
		}else{
			
			arr[k] = right[j];
			k++;
			j++;
			
		}
		
	}
	
	while(i < leftcount){
		
		arr[k] = left[i];
		k++;
		i++;
		
	}
	
	while(j < rightcount){
		
		arr[k] = right[j];
		k++;
		j++;
		
	}
	
}












