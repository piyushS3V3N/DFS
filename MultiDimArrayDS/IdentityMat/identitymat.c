#include <stdio.h>
#include <stdlib.h>

int main(){
	int **arr,  flag=1;
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
			if(i==j && arr[i][j] !=1)
				flag=0;
			else if(i!=j&& arr[i][j] !=0)
					flag=0;
	
		if(flag==1)
			printf("\nEntered Matrix is an Identity Matrix !\n");
		else
			printf("\nEntered Matrix is not an Identity Matrix !\n");
	return 0;
}
