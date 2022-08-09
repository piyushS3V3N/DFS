#include <stdio.h>
#include <string.h>

#define RANGE 255


void countSort(char arr[])
{
		char output[strlen(arr)];

		int count[RANGE + 1],i ;
		memset(count, 0 , sizeof(count));

		for(i = 0 ; arr[i] ; i++)
			++count[arr[i]];

		for(i=1 ; i<=RANGE ; ++i)
			count[i] += count[i-1];

		for(i=0 ; arr[i] ; ++i){
			output[count[arr[i]] -1] = arr[i];
			--count[arr[i]];
			}

		for(i=0 ; arr[i] ; ++i)
			arr[i] = output[i];
}

int main()
{
	char arr[] = {1,3,96,2,18,21,32,86,91};

	countSort(arr);
	printf("Sorted Character Array is \n");
	for(int i = 0 ; i < sizeof(arr) ; i++)
		printf("arr[%d] : %d ",i, arr[i]);
	printf("\n");
	return 0;
}
