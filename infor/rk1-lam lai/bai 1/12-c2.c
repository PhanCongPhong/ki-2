#include <stdio.h>
int main(){
	char a[90];
	int i, j;
	gets(a);
	for (i = 0; a[i]!='\0'; ++i)
	{
		if (a[i]=='\\'&& a[i+1]=='n')
		{   a[i]='\n';
			for (j= i; a[j]!='\0'; ++j)
			{
				a[j+1]=a[j+2];
			}
		}
	}
printf("%s", a);
	return 0;
}
