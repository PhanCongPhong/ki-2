#include <stdio.h>
int main(){
	char a[90];
	gets(a);
	for (int i = 0; a[i]!='\0'; ++i)
	{
		if (a[i]=='D')
		{
			for (int j= i+1; a[j]!='\0'; ++j)
			{
				a[j]=a[j+1];
			}
		}
	}
	for (int i = 0; a[i]!='\0'; ++i){
		printf("%c",a[i] );
	}
	return 0;
}