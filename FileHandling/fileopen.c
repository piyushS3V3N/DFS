#include <stdio.h>
#include <stdlib.h>
int main(){
	char* s;
	FILE *fptr;
	fptr = fopen("test.txt","r");
	if (fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}	
	while(fscanf(fptr,"%s",s) == 1){
	printf("%s ",s);}
	fclose(fptr);
	return 0;
}