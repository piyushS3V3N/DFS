#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void countsort(int arr[], int n, int k)
{
    // create an integer array of size `n` to store the sorted array
    int output[n];
 
    // create an integer array of size `k + 1`, initialized by all zero
    int freq[k + 1];
    memset(freq, 0, sizeof(freq));
 
    // 1. Using the value of each item in the input array as an index,
    // store each integer's count in `freq[]`
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
 
    // 2. Calculate the starting index for each integer
    int total = 0;
    for (int i = 0; i < k + 1; i++)
    {
        int oldCount = freq[i];
        freq[i] = total;
        total += oldCount;
    }
 
    // 3. Copy to the output array, preserving the order of inputs with equal keys
    for (int i = 0; i < n; i++)
    {
        output[freq[arr[i]]] = arr[i];
        freq[arr[i]]++;
    }
 
    // copy the output array back to the input array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
int main(){
	int *arr;
	int size;
	printf("Enter the size of array : ");
	scanf("%d",&size);
	arr = (int *)malloc(sizeof(int)*size);
	printf("\nEnter the element in array : ");
	for(int i=0 ; i < size ; i++)
	{
		scanf("%d",&arr[i]);
	}
	countsort(arr,size,10);
	for(int i=0 ; i < size ; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
		
}
