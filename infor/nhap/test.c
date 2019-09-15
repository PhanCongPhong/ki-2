#include <stdio.h>
#define MAX_SIZE 100
int main()
{
	char arr[MAX_SIZE];
	int counter=0;
	scanf("%s",arr);
	 while(arr[counter]!='\0'){++counter;}
	printf("%d",counter );
	return 0;
}