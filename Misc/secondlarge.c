//W.A.P To find the second largest element in an array

#include <stdio.h>

int main()
{
		int max1 ,max2;
		int a[4];
		printf("Enter the elements in array : \n");
		for(int i=0; i < 4  ; i++)
		scanf("%d",&a[i]);
		max1 = a[0];
		for(int i=0 ; i < 4;i++)
					if(a[i] > max1)
					{
							max2 = max1;
							max1 = a[i];
					}
					else if(a[i] > max2 && a[i] < max1)
					{
						max2 = a[i];
					}
		printf("Second largest element is : %d",max2);
							
}
