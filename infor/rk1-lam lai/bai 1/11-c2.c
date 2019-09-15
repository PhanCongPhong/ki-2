#include <stdio.h>
int main()
{
	int n=0,c;
    char a[90];c=getchar();
    while(c!=EOF && c!='\n'){
    	a[n]=c;
    	c=getchar();
        n++;
    }
    for (int i = 0; a[i] != '\0'; ++i)
    {
    	if (a[i-1]!='D')
    	{
    		printf("%c",a[i] );
    	}
    }
	return 0;
}