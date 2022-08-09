#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr ;
	int size,temp,max , max2;
	printf("Enter the size for the array : \n");
	scanf("%d",&size);
	arr = (int *) malloc(sizeof(int)*size);
	printf("\nEnter the elements for the array : ");
	for(int i=0 ; i < size ; i++)
		scanf("%d",&arr[i]);
	printf("\nElements of the array are : ");
	for(int i=0 ; i < size ; i++)
		printf("%d ",arr[i]);
	max=arr[0];
	max2=arr[1];
	for(int i=0 ; i < size ; i++)
	{
		if(arr[i] > max)
		{
			temp = max;
			max = arr[i];
			max2 = max;
		}
		else if(arr[i] < max &&  arr[i] > max2)
			max2 = arr[i];

	}
	printf("\nLargest element is %d and second largest is %d\n",max , max2);
	return 0;
}
