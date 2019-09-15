#include <stdio.h>
#include <stdlib.h>
int main()
{ 
	char ch;
	FILE *fp;
	fp=fopen("2.txt","r");
	if (fp!=NULL)
	{
		while((ch=fgetc(fp))!=EOF){
			printf("%c",ch );
		}
	}
	else{
		printf("lolllllllllllllllllllllllllllll");
	}
	fclose(fp);
	return 0;
}