#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr;
	int size;

	printf("Enter the size of array : ");
	scanf("%d",&size);
	arr = (int *) malloc(sizeof(int)*size);
	printf("Enter the elements for the array : \n");
	for(int i=0 ; i < size ; i++)
			scanf("%d",&arr[i]);
	
	printf("\nElements in the array : ");
	for(int i=0 ; i < size ; i++)
			printf("%d ",arr[i]);
	printf("\nAfter Insertion Sort : ");
	for(int i=1 ; i < size ; i++)
	{
			int value = arr[i];
			int j=i;

			while (j > 0 && arr[j-1] > value)
			{
				arr[j] = arr[j-1];
				j--;
			}
			arr[j] = value;
	}
	for(int i=0 ; i < size ; i++)
			printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
