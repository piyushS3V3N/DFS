#include<stdio.h>
#include <stdlib.h>

int main(){
	FILE *fptr;
	char ch='o';
	
	fptr = fopen("f5.txt","w+");

	if(fptr==NULL)
	{
		printf("Error\n");
		return -1;
	}
	fputs("Java",fptr);
	rewind(fptr);
	while(!feof(fptr))
	{
		ch=fgetc(fptr);
		if(ch!='\0')
			printf("%c",ch);
	}
	fclose(fptr);
	return 0;
}