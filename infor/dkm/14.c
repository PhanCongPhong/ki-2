#include <stdio.h>
#include <stdlib.h>
int main()
{   char *a=(char*)calloc(90,sizeof(int));
	int c=getchar(),n=0;
	while(c!=EOF){a[n++]=c;c=getchar();}
	for (int i = 0; a[i]!='\0'; ++i)
	{
		if(a[i]=='\\' && a[i+1]=='n')
		{
			a[i]='\n';
			for (int j = i+1; a[j]!='\0'; ++j)
			{
				a[j]=a[j+1];
			}
		}
	}
	for (int i = 0; a[i]!='\0'; ++i)
	{
		printf("%c",a[i] );
	}
	return 0;
}