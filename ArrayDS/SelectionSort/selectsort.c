#include <stdio.h>
#include <stdlib.h>

int main(){
		int *arr;
		int size,min , temp;
		printf("Enter the size of array : ");
		scanf("%d",&size);
		arr = (int *) malloc(sizeof(int)*size);
		
		printf("\nEnter the elements for array : ");
		for(int i=0 ; i < size ; i++)
			scanf("%d",&arr[i]);
		
		printf("\nEntered  elements in array are : ");
		for(int i=0 ; i < size ; i++)
			printf("%d ", arr[i]);
		
		for(int i =0 ; i < size-1 ; i++)
		{
			min = i ; 
			for(int j= i+1 ; j < size ; j++)
			{
				if(arr[j] < arr[min])
					min = j;
			}
				temp = arr[min];
				arr[min] = arr[i] ; 
				arr[i] = temp;
			}
		printf("\nArray after selection sort : ");
		for(int i=0 ; i < size ; i++)
			printf("%d ", arr[i]);
		printf("\n");

		return 0;
	}
