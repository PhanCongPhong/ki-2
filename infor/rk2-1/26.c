#include <stdio.h>
#include <stdlib.h>
char *touppercase(char *str){
	char*a;
	a=(char*)calloc(100,sizeof(char));
	for (int i = 0; str[i]!='\0'; ++i)
	{
		if ((str[i]>='a')&&(str[i]<='z')) 
        {     
             str[i]-=32;
             a[i]=str[i];
        } 
		else{a[i]=str[i];}
	}
	return a;
}
int main()
{
	
	char *str=(char*)calloc(100,sizeof(char));
	char *a=(char*)calloc(100,sizeof(char));
	scanf("%s",str);
	a=touppercase(str);
	printf("%s",a );
	return 0;
}