#include <stdio.h>
#include <stdlib.h>

int main(){
	int **arr, **arrb , **sum;
	int sizei,sizej;
	printf("Enter the row and column for matrix : ");
	scanf("%d %d",&sizei,&sizej);
	
	arr = (int **)malloc(sizeof(int)*sizei);
	for(int i=0 ; i < sizei ; i++)
		arr[i] = (int *)malloc(sizeof(int)*sizej);
	
	arrb = (int **)malloc(sizeof(int)*sizei);
	for(int i=0 ; i < sizei ; i++)
		arrb[i] = (int *)malloc(sizeof(int)*sizej);
	
	sum = (int **)malloc(sizeof(int)*sizei);
	for(int i=0 ; i < sizei ; i++)
		sum[i] = (int *)malloc(sizeof(int)*sizej);
	
	printf("Enter the value for matrix1 : ");
	for(int i=0 ; i < sizei ; i++)
		for(int j=0 ; j < sizej ; j++)
			scanf("%d",&arr[i][j]);
	printf("Enter the value for matrix2 : ");
	for(int i=0 ; i < sizei ; i++)
		for(int j=0 ; j < sizej ; j++)
			scanf("%d",&arrb[i][j]);
	
	for(int i =0 ; i < sizei; i++)
		for(int j=0 ; j < sizej ; j++)
			sum[i][j] = arr[i][j] + arrb[i][j];
	
	for(int i=0 ; i < sizei ; i++)
	{	
		for(int j=0 ; j<sizej ; j++)
				printf("%d ",sum[i][j]);
		printf("\n");
	}
	return 0;
}
