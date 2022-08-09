#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int * init_array(int size){
	int *arr = (int *)malloc(sizeof(int)*size);
	for(int i=0 ; i <size ; i++){
		arr[i] = (rand()%(12-0 + 1));
	}
	return arr;
}
void print_array(int *arr, int size)
{
	for(int i=0 ; i < size ;i++)
		printf("%d ",arr[i]);
}
int  binary_search(int *arr , int idx , int item, int size){
	int low = idx;
	int high = size-1;
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
void exponential_search(int *arr , int x,int size){
	int i = 1 ;
	while(i<size && arr[i] <= x)
		i=i*2;
	int ret = binary_search(arr , i/2, x ,size);
}

int main(){
	int *arr;
	int size = 14;
	arr = init_array(14);
	print_array(arr,size);
	exponential_search(arr , 7 , size);
	return 0;
}
