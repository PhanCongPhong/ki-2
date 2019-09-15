#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *funs(char *str,char ch1, char ch2){
	char*a;
	int k=strlen(str);
	a=(char*)calloc(100,sizeof(char));
	for (int i = 0; i < k; ++i)
	{
		if (str[i]==ch1)
		{
			a[i]=ch2;
		}
		else{a[i]=str[i];}
	}
	return a;
}
int main()
{
	char ch1,ch2,str[100];
	char *a;
	for (int i = 0; i < 100; ++i)str[i]='\0';
	scanf("%c",&ch1);
    fflush(stdin);
	scanf("%c",&ch2);
	 fflush(stdin);
	gets(str);
	a=funs(str,ch1,ch2);
	printf("%s",a );
	return 0;
}