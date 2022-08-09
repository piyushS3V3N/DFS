#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *fptr;
	char* c=(char *)malloc(sizeof(128));
	scanf("%[^\n]%*c",c);
	printf("Input : %s",c);
	fptr= fopen("test.txt","w");
	fprintf(fptr, "%s ", c);
	fclose(fptr);
	free(c);
	return 0;
}