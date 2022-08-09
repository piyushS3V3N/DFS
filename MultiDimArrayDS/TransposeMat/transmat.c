#include <stdio.h>
#include <stdlib.h>

int main(){
	int **arr,  **transpose;
	int sizei,sizej;
	printf("Enter the row and column for matrix : ");
	scanf("%d %d",&sizei,&sizej);
	
	arr = (int **)malloc(sizeof(int)*sizei);
	for(int i=0 ; i < sizei ; i++)
		arr[i] = (int *)malloc(sizeof(int)*sizej);
	
	transpose = (int **)malloc(sizeof(int)*sizej);
	for(int i=0 ; i < sizej ; i++)
		transpose[i] = (int *)malloc(sizeof(int)*sizei);
	
	printf("Enter the value for matrix : ");
	for(int i=0 ; i < sizei ; i++)
		for(int j=0 ; j < sizej ; j++)
			scanf("%d",&arr[i][j]);
	

	for(int i =0 ; i < sizei; i++)
		for(int j=0 ; j < sizej ; j++)
			{
				transpose[j][i] = arr[i][j];
			}
	printf("Multiplication of two matrices is : \n");
	for(int i=0 ; i < sizej ; i++)
	{	
		for(int j=0 ; j<sizei ; j++)
				printf("%d ",transpose[i][j]);
		printf("\n");
	}
	return 0;
}
