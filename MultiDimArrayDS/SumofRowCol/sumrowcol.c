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
	{
		for(int j=0 ; j < sizej ; j++)
				sum+=arr[i][j];
		printf("The sum of the %d row of  matrix is %d \n",i,sum);
		sum=0;
	}
	sum =0;
	for(int i=0 ; i < sizej ; i++)
	{
		for(int j=0 ; j < sizei ; j++)
			sum+=arr[i][j];
		printf("The sum of the %d column is %d \n",i , sum);
	}
	return 0;
}
