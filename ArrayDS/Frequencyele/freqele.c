#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int *arr,*freq;
	int size,count = 0;
	printf("Enter the size of array : ");
	scanf("%d",&size);
	arr = (int  *)malloc(sizeof(int)*size);
	printf("Enter the elements of array : ");
	for(int i=0 ; i < size; i++)
		scanf("%d",&arr[i]);
	freq = (int *)malloc(sizeof(int)*size);
	for(int i=0 ; i < size; i++)
	{
		count = 1;
		for(int j =i+1 ; j < size; j++)	
			if(arr[i] == arr[j]){	
					count++;
					freq[j]=-1;
			}
			if(freq[i] != -1)
				freq[i] = count;
	}
	printf("\nFrequency of all the elements in array is : \n");
	for(int i =0 ; i<size;i++)
		if(freq[i] != -1)
			printf("%d : %d\n",arr[i],freq[i]);
	printf("\n");
}
