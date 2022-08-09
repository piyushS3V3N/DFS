#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr;
	int size, item;
	printf("Enter the size of array : \n");
	scanf("%d",&size);
	arr = (int *)malloc(sizeof(int)*size);
	printf("Enter the elements in array : \n");
	for(int i=0 ; i< size; i++)
		scanf("%d",&arr[i]);
	printf("\nEntered Elements are : \n");
	for(int i=0 ; i < size;i++)
		printf("%d ",arr[i]);
	printf("\nEnter the element to search : \n");
	scanf("%d",&item);

	for(int i=0 ; i < size;i++)
		if(item == arr[i]){
			printf("\nItem Found !! At position : %d\n", i);
			return 0;
			}
	printf("Item not found !! \n");
	return 0;
	}
