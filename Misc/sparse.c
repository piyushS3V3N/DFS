#include <stdio.h>
#include <stdlib.h>

int countZeros(int **arr , int sizei ,int sizej)
{	int total=0;
	for(int i=0 ; i < sizei; i++)
		for(int j =0 ; j < sizej ; j++)
			if(arr[i][j] == 0)
				total++;
	return total;
}
void printArray(int **arr ,int sizei ,int sizej)
{
	for(int i= 0; i < sizei ; i++){
		for(int j = 0 ; j < sizej ; j++)
			printf("%d ",arr[i][j]);
		printf("\n");}
	printf("\n");
}
int main(){
	int **arr , sizei , sizej,total=0;
	printf("Enter the rows and columns for matrix : ");
	scanf("%d %d" ,&sizei, &sizej);
	arr = (int **) malloc(sizeof(int)*sizei);
	for(int i=0 ; i < sizei ; i++)
		arr[i] = (int *)malloc(sizeof(int)*sizej);
	printf("Enter the element for array : \n");
	for(int i=0 ; i < sizei;i++)
		for(int j=0 ; j < sizej ; j++)
			scanf("%d",&arr[i][j]);
	printArray(arr , sizei, sizej);
	total = countZeros(arr, sizei, sizej);
	
	if(total > (sizei*sizej)/2)
		printf("Matrix is a sparse matrix \n");
	else
		printf("Matrix is not a sparse matrix \n");
	return 0;	
}
