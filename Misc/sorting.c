#include <stdio.h>

int main(){
	int arr[] = {1,6,2,5,7,2,9,1,1};
	
	int temp = 0 ; 
	int size=sizeof(arr)/sizeof(int);
	printf(" \n{");
	for(int i =0 ; i < size-1 ; i++)
	{
			printf(" %d ",i , arr[i]);
	}
	printf("}\n");
	for(int i=0; i < size -1; i++)
		for(int j=0; j < size-i-1 ; j++)
				{
						if(arr[i] == arr[j])
							{
									for(int k=j ; k<size-1;k++)
											arr[k] = arr[k+1];

							}
				}
	printf(" \n{");
	for(int i =0 ; i < size-1 ; i++)
	{
			printf(" %d ",i , arr[i]);
	}
	printf("}\n");

}
