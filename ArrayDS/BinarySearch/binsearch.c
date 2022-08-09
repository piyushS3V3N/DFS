#include <stdio.h>
#include <stdlib.h>  

int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2; 
        if (arr[mid] == x)  return mid;

        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);

        return binarySearch(arr, mid+1, r, x);
   }

   return -1;
}

int main()
{
	int *arr;
	int size,item,result;
	printf("Enter the size of array : \n");
	scanf("%d",&size);
	arr = (int *)malloc(sizeof(int)*size);

	printf("Enter the elements in array : \n");
	for(int i=0 ; i< size;i++)
		scanf("%d",&arr[i]);

	printf("\nEnter the item to search : ");
	scanf("%d",&item);
	result = binarySearch(arr, 0, size-1 , item);
	if(result == -1)
	{
	printf("Element is not present in array.\n");
	}
	else{
		printf("Element is present at index %d \n",result);
	}
	return 0 ; 
}
