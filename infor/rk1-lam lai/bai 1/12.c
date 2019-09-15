#include <stdio.h>
int main(){
	int n=0,c,i,j;
	char a[90];
	for (int i = 0; i < 90; ++i)
	{
		a[i]='\0';
	}
	while((c=getchar())!=EOF ){
		a[n]=c;
		n++;
	}
	for (i = 0; a[i]!='\0'; ++i)
	{
		if (a[i]=='\\'&& a[i+1]=='n')
		{    a[i]='\n';
			for (j= i; a[j]!='\0'; ++j)
			{
				a[j+1]=a[j+2];
			}
		}
	}
	printf("%s", a);
	return 0;
}
