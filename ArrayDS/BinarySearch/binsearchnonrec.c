#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr;
	int size,item;
	int low = 0,high ;
	printf("Enter the size of array : \n");
	scanf("%d",&size);
	high = size-1;
	arr = (int *)malloc(sizeof(int)*size);
	printf("Enter the elements in array : \n");
	for(int i=0 ; i < size ; i++)
		scanf("%d",&arr[i]);
	printf("\nElements in Array Are : \n");
	for(int i=0 ;i < size ; i++)
		printf("%d ",arr[i]);
	
	printf("\nEnter the element you want to search for : \n");
	scanf("%d",&item);

	while(low <=high)
	{
			int mid = (low +high)/2;

			if (item == arr[mid])
			{
					printf("Item found at %d \n",mid);
					return 0;
			}
			else if(item < arr[mid])
					high = mid -1;
			else
					low = mid+1;
	}
	printf("Element not found in array  !\n");
	return -1; 
}
