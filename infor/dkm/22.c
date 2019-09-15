#include <stdio.h>
#include <stdlib.h>
int main()
{   char *a=(char*)calloc(90,sizeof(int));
	int c=getchar(),n=0,b[1000]={0},max=0;
	while(c!=EOF){a[n++]=c;c=getchar();}
	for (int i = 0; a[i]!='\0'; ++i) b[(int)a[i]]++;
	for (int i = 0; i < 1000; ++i)
	{
		if (b[i]>max)
		{
			max=b[i];c=i;
		}
	}
	printf("%c",c );

	return 0;
}
