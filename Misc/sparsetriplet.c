#include <stdio.h>
#include <stdlib.h>

int countZero(int **arr,int sizei ,int sizej)
{
	int total=0; 
	for(int i=0 ; i < sizei; i++)
		for(int j=0; j< sizej ;j++)
			if(arr[i][j] ==0)
				total++;
	return total;
}

void printArray(int **arr , int sizei ,int sizej)
{
	for(int i=0 ; i < sizei ; i++)
	{
		for(int j=0 ; j < sizej;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
		}
		printf("\n");
}


int main(){
	int **arr, **triparr , sizei, sizej;
	int total=0;
	printf("Enter the rows and columns for matrix : \n");
	scanf("%d %d",&sizei,&sizej);
	arr = (int**)malloc(sizeof(int)*sizej);
	for(int i=0 ; i< sizei;i++)
		arr[i] = (int *)malloc(sizeof(int)*sizej);
	
	triparr = (int **)malloc(sizeof(int)*3);
	for(int i=0 ; i < 3 ;i++)
		triparr[i] = (int *)malloc(sizeof(int)*(sizej +1));

	printf("Enter the elements for array \n");
	for(int i=0 ; i < sizei;i++)
		for(int j=0 ; j< sizej ; j++)
			scanf("%d",&arr[i][j]);	
	total = countZero(arr, sizei , sizej);
	triparr[0][0] = sizei;
	triparr[1][0] = sizej;
	triparr[2][0] = total;
	for(int i=0 ; i < sizei ; i++)
		for(int j=0 ; j < sizej ; j++)
		{	
			if(arr[i][j] != 0)
			 {
			 	triparr[0][j+1] = i;
				triparr[1][j+1] = j;
				triparr[2][j+1] = arr[i][j];
			 }
		}
	printArray(triparr , 3 , sizej);
	return 0;
}
