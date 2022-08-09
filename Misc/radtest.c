#include <stdio.h>
#include <math.h>
void radixSort(int arr[],int len)
{
    int farr[10]={0,0,0,0,0,0,0,0,0,0};
    int sarr[10]={0,0,0,0,0,0,0,0,0,0};
    int oarr[len],cod=0,k;
   int i,j,max=arr[0],sum=0,curr;
    for(i=1;i<len;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    while(max!=0)
    {
        cod++;
        max/=10;
    }
    for(k =0 ;k<cod;k++){
            sum=0;
    for(i=0;i<10;i++)
    {
        sarr[i] = 0;
        farr[i]=0;
    }
    for(i=0;i<len;i++)
    {
        curr = (int) (arr[i]/pow(10,k)) % 10;
        farr[curr]++;

    }

    for(i=0;i<10;i++)
    {
        sum += farr[i];
        sarr[i]=sum;
    }

    for(i=len-1;i>=0;i--)
    {
        curr = (int) (arr[i]/pow(10,k)) % 10;
        sarr[curr]--;
				oarr[sarr[curr]] = arr[i];
				
        
    }
    //printArr(oarr);
    for(i=0;i<len;i++)
    {
        arr[i] = oarr[i];
    }
		for(i=0 ; i < len ; i++)
			oarr[i]  = 0;
    }
		for(int i= 0 ; i < len ; i++)
			printf("%d ",arr[i]);
}

int main(){
	int arr[] = {200, 451 , 121 , 120};
	radixSort(arr , 4);
}
