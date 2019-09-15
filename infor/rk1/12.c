#include <stdio.h>
int main()
{
	int n=0,c, max=0;
	char a[90],b[500]={0};
	c=getchar();
	while(c!=EOF){a[n]=c;c=getchar();n++;
	}
	for (int i = 0; i < n; ++i)
	{
		b[(int)a[i]]++;
	}
	for (int i = 0; i < n; ++i)
	{
		if (b[(int)a[i]]>max)
		{
		max=b[(int)a[i]];
		}
	}
	for (int i = 0; i < 500; ++i)
	{
		if (b[i]==max)
		{
			printf("%c",i);
		}
	}
}