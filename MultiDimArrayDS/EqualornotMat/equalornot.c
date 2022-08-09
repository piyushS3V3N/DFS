#include <stdio.h>
#include <stdlib.h>

int main(){
	int **arr, **arrb ,flag = 1;
	int sizei,sizej;
	printf("Enter the row and column for matrix : ");
	scanf("%d %d",&sizei,&sizej);
	
	arr = (int **)malloc(sizeof(int)*sizei);
	for(int i=0 ; i < sizei ; i++)
		arr[i] = (int *)malloc(sizeof(int)*sizej);
	
	arrb = (int **)malloc(sizeof(int)*sizei);
	for(int i=0 ; i < sizei ; i++)
		arrb[i] = (int *)malloc(sizeof(int)*sizej);
	
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
			if(arr[i][j] != arrb[i][j])
				{
						flag = 0 ;
						break;
				}
	
	if(flag == 1)
		printf("Two matrices are equal \n");
	else
		printf("Two matrices are not equal \n");
	return 0;
}
