#include <stdio.h>
#include<string.h>
int main()
{
	int n=0,c,k=0;
	char a[90];
	for(int i=0; i<90;i++){a[i]='\0';}
	c = getchar();

	while(c != EOF)
	{
		a[n] = c;
		c = getchar();
		n++;
	}
	k=strlen(a);
	printf("%s : %d : %d\n",a, n ,k);

	return 0;
}
