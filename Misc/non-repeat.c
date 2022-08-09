#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr; 
	int size;
	printf("\nEnter the size of array : \n");
	scanf("%d",&size);
	arr = (int *) malloc(size * sizeof(int));
	printf("Enter the elements of array : \n");
	for(int i=0 ; i < size; i++)
			scanf("%d ",&arr[i]);
	printf("Entered Array is : \n {");
	for(int i =0 ; i < size ; i++)
		printf("%d ",arr[i]);
	printf("}\n");
	return 0;
}
