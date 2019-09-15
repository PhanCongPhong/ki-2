#include <stdio.h>
#include <stdlib.h>
char *funs(char *str,char ch1, char ch2){
	char*a;
	a=(char*)calloc(100,sizeof(char));
	for (int i = 0; str[i]!='\0'; ++i)
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
	char ch1,ch2;
	char *str=(char*)calloc(100,sizeof(char));
	char *a;
	scanf("%c",&ch1);
	getchar();
	scanf("%c",&ch2);
	getchar();
	char c; int count=0;
     while((c=getchar()) != '\n'){
        
        str[count]=c;
        
        
        count++;
    }
	a=funs(str,ch1,ch2);
	printf("%s",a );
	return 0;
}