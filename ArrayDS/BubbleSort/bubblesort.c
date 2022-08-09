#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr;
	int size,temp;
	printf("Enter the size of array : ");
	scanf("%d",&size);
	arr = (int *)malloc(sizeof(int)*size);
	printf("\nEnter the elements for the array : ");
	for(int i=0 ; i < size ; i++)
		scanf("%d",&arr[i]);
	printf("\nElements in array : ");
	for(int i=0 ; i<size ; i++)
		printf("%d ",arr[i]);
	
	for(int i=0 ; i < size-1; i++)
		for(int j=0 ; j < size-i-1; j++)
			if(arr[j] > arr[j+1]){
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;}
	printf("\nElements after Bubble Sort : ");
	for(int i=0 ; i<size ; i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
