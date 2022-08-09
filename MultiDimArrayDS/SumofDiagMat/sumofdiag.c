#include <stdio.h>
#include <stdlib.h>

int main(){
	int **arr,  sum=0;
	int sizei,sizej;
	printf("Enter the row and column for matrix : ");
	scanf("%d %d",&sizei,&sizej);
	
	arr = (int **)malloc(sizeof(int)*sizei);
	for(int i=0 ; i < sizei ; i++)
		arr[i] = (int *)malloc(sizeof(int)*sizej);
	

	printf("Enter the value for matrix : ");
	for(int i=0 ; i < sizei ; i++)
		for(int j=0 ; j < sizej ; j++)
			scanf("%d",&arr[i][j]);
	
	for(int i =0 ; i < sizei ; i++)
		for(int j=0 ; j < sizej ; j++)
			if(i=j)
				sum+=arr[i][j];
	printf("The sum of the diagonal of a square matrix is %d \n",sum);
	return 0;
}
