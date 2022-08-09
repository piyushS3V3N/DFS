#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr;
	int size,target;

	printf("Enter the size of array : ");
	scanf("%d",&size);
	
	arr = (int *)malloc(sizeof(int)*size);
	
	printf("\nEnter the elements for array :");
	for(int i=0 ; i<size ; i++)
		scanf("%d",&arr[i]);
	
	printf("\nEntered elements in array are : ");
	for(int i=0 ; i < size ; i++)
		printf("%d ",arr[i]);
	printf("\nEnter the amount of sum to find : ");
	scanf("%d",&target);
	for(int i=0 ; i < size ; i++)
		for(int j=i ; j < size ; j++)
				if((arr[j] + arr[i]) == target && arr[j] != arr[i])
					printf("{%d , %d}\n",arr[i],arr[j]);
	return 0;	
	}
