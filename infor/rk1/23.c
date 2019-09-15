#include <stdio.h>
int main()
{
	int n=0,c,k=0;
    char a[90];c=getchar();
    while(c!=EOF && c!='\n'){
    	a[n]=c;
    	c=getchar();n++;
    }
    for (int i = 0; i < n; ++i)
    {
    	if (a[i]=='a' &&(a[i+1]==' '||a[i+1]=='    '))
    	{
    		k++;
    	}
    }
    printf("%d",k );
	return 0;
}