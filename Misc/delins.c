#include <stdio.h>

int main(){

	int i,size , a[10],d , pos;

	printf("Enter the number of elements  of the array : ");

	scanf("%d",&size);

	printf("Enter the elements of the array : ");
	for(i = 0 ; i < size ; i++){
			scanf("%d", &a[i]);
	}

	printf("Array : ");

	for(i = 0 ; i < size ; i++)
	{
			printf("%d ",a[i]);
	}

	printf("\n Enter the position of the element you want to delete : \n");
	scanf("%d",&pos );
	//Check if position given is not out of bound of array
	//i.e. not more than size of array
	if(pos >=size+1)
	{
		printf("Deletion is not possible \n");
	}
	else{
	//Iterate from position-1 e.g. 3 means 2 [0 1 2] array indexing
	//i<=size-1 or i<size 
		for(i=pos-1;i<size;i++)
			a[i] = a[i+1];
			size--;
	printf("Resultant Array : \n");
	for(i=0 ; i < size ; i++)
		printf("%d",a[i]);
	printf("\nElement Deleted !!\n");
	}
	printf("Current Size : %d \n",size);
	printf("Enter the element you want to insert : \n");
	scanf("%d",&d);
	printf("\nEnter the position of the element you want to insert : ");
	scanf("%d",&pos);
	// From last index i.e. size to position given -1 so to ensure loop runs
	// we take exactly size in our case 3 then position -1 i.e. 3-1 = 2 
	// now since i > size it will run definitely so first shift the elements
	// to other side then enter the value at desired location
	for(i = size-1 ;i>=pos-1 ; i--)
	{
		a[i+1] = a[i];
	}
		a[pos-1] = d;
	size++;

printf("Resultant Array : \n");

for(i =0 ; i < size ; i++)
{
		printf("%d ",a[i]);
}
printf("\n");
return 0;
}
