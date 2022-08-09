#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr;
	int size,total;
	printf("Enter the size of the array : ");
	scanf("%d",&size);
	
	arr = (int *)malloc(sizeof(int)*size);
	
	printf("\nEnter the elements inside the array : ");
	for(int i=0 ; i < size ; i++)
		scanf("%d",&arr[i]);
	printf("\nElements in the array are : ");
	for(int i=0 ; i < size ; i++)
		printf("%d ",arr[i]);	
	total = (size+1)*(size+2)/2;
	for(int i=0 ; i < size ; i++)
		total -= arr[i];
	printf("\nMissing number is : %d\n",total);

	return 0;
}
