#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr;
	int size;
	printf("Enter the size of array : ");
	scanf("%d",&size);
	arr = (int *)malloc(sizeof(int)*size);
	printf("\nEnter the elements in array : ");
	for(int i=0 ; i < size ; i++)
		scanf("%d",&arr[i]);
	printf("\nElements of array are : ");
	for(int i=0 ; i < size ; i++)
		printf("%d ",arr[i]);
	for(int i=0 ; i < size ; i++)
		for(int j=i+1 ; j < size; j++)
			{
				if(arr[i] == arr[j])
				{
					for(int k = j ; k <= size-1;k++)
						{
							arr[k] = arr[k+1];
						}
						size--;	
						j--;
				}
			}
		
	printf("\nElements of array after removing duplicate are : ");
	for(int i=0 ; i < size ; i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
