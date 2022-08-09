#include <stdio.h>
#include <stdlib.h>
int main(){
	int *arr; //initialize a integer pointer for array
	int size,item,pos; 
	//Input the size of an array from user
	printf("Enter the size of array :  \n");
	scanf("%d",&size);

	//Dynamic memmory allocation using malloc
	arr = (int *)malloc(sizeof(int)*size);
	//Taking element as input in array
	printf("\nEnter the elements of array : \n");
	for(int i=0 ; i < size ; i++)
		scanf("%d",&arr[i]);
	printf("\nElements of Array are : \n");
	for(int i=0 ; i < size ; i++)
		printf("%d ",arr[i]);

	printf("\nEnter the position where you want to insert new element\n");
	scanf("%d",&pos);
	if(pos > size+1)
	{
			printf("\033[91mError! Index is out of bound!\033[00m\n");
			return -1;
	}
	printf("\nEnter the element : \n");
	scanf("%d",&item);
	//Resizing array by one for insertion
	arr = (int *)realloc(arr,size+1);
	//Adjusting all the elements of the array
	for(int i=size-1;i>=pos-1;i--)
			arr[i+1] = arr[i];
	arr[pos-1] = item;
	size++;

	printf("Resultant array is : \n");
	for(int i=0 ; i < size; i++)
		printf("%d ",arr[i]);
	printf("\n");
	free(arr);
	return 0 ;
}
