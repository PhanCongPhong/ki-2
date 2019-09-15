#include <stdio.h>
#include <stdlib.h>
int main()
{   char *a=(char*)calloc(90,sizeof(int));
	int c=getchar(),n=0;
	while(c!=EOF){a[n++]=c;c=getchar();}
	for (int i = 0; a[i]!='\0'; ++i)
	{
		if (a[i-1]!='D')
		{
			printf("%c", a[i]);
		}
	}
	return 0;
}