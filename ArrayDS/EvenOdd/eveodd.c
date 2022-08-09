#include <stdio.h>
#include <stdlib.h>

int main(){
	int *arr,*even,*odd;
	int size,evc=0 ,odc=0;
	printf("Enter the size of array : ");
	scanf("%d",&size);
	arr = (int *) malloc(sizeof(int)*size);
	printf("\nEnter the elements for array : ");
	even = (int *)malloc(sizeof(int)*1);
	odd = (int *) malloc(sizeof(int)*1);
	for(int i=0 ; i < size ; i++)
		scanf("%d",&arr[i]);
	for(int i=0 ; i < size ; i++)
		if(arr[i]%2 ==0)
		{
			even[evc] = arr[i];
			evc++;
			even = (int *)realloc(even,sizeof(int)*(evc+1));
		}
		else{
			odd[odc] = arr[i];
			odc++;
			odd = (int *)realloc(odd,sizeof(int)*(odc+1));
		}
	printf("\nEven items : ");
	for(int i =0 ;i < evc ; i++)
		printf("%d ",even[i]);
	printf("\nOdd items : ");
	for(int i=0 ; i<odc;i++)
		printf("%d ",odd[i]);
	printf("\n");
	return 0;
}
