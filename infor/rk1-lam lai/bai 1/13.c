#include <stdio.h>
int main()
{
	int n=0,c,k=0;
	char a[90];
	c = getchar();
	while(c != '\n')
	{
		a[n] = c;
		c = getchar();
		n++;
	}
	printf("%s\n",a);
	for (int i = 0; a[i]!='\0'; ++i)
	{
		if (a[i]=='a'&& (a[i+1]==' '||a[i+1]=='\0' || a[i+1]=='	'))
		{ k++;  
		}
	}
	printf("%d", k);
	return 0;
}
