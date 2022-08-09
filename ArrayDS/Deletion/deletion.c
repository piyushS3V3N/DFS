#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr;
	int size,pos;

	printf("Enter the size of the array : \n");
	scanf("%d",&size);
	arr = (int *)malloc(sizeof(int)*size);

	printf("Enter the elements inside the array : \n");
	for(int i=0 ; i < size;i++)
		scanf("%d",&arr[i]);
	printf("\nEntered Array is : ");
	for(int i=0; i < size ; i++)
		printf("%d ",arr[i]);
	
	printf("\nEnter the positon of element you want to delete : ");
	scanf("%d",&pos);
	if(pos > size-1){
		printf("Error Deletion is not possible !");
		return -1;
		}
	for(int i=pos-1 ; i < size; i++)
			arr[i] = arr[i+1];
	size--;
	arr = (int *)realloc(arr, size);
	printf("Array after deletion is : \n");
	for(int i=0 ; i< size;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
	}
