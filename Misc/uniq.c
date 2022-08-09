//W.A.P to print all the unique elements in the array

#include <stdio.h>
#include <stdlib.h>
int main(){
	int *freq  , *a;
	int size;
	printf("Enter the size of an array : ");
	scanf("%d",&size);
	a = (int *) malloc(sizeof(int)*size);
	freq = (int *) malloc(sizeof(int)*size);
	printf("\nEnter the value for array : \n");

	for(int i=0 ; i < size ; i++)
		scanf("%d",&a[i]);
	
	for(int i=0 ; i<size; i++)
		for(int j=0 ; j < size ; j++)
				if(a[i] == a[j])
					freq[i] += 1;
	for(int i=0 ; i < size ; i++)
			if(freq[i] == 1)
					printf("%d",a[i]);
	printf("\n");
	return 0;

}
