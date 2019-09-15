#include <stdio.h>
#include <stdlib.h>
int *fun(int *a, int *b, int sizearr){
	int *c=(int*)calloc(sizearr,sizeof(int));
	for (int i = 0; i < sizearr; ++i)
	{
		c[i]=a[i]-b[i];
	}
	return c;
}
int main(int argc, char const *argv[])
{
	int sizearr;
	scanf("%d",&sizearr);
	int *a=(int*) calloc(sizearr,sizeof(int));
	int *b=(int*) calloc(sizearr,sizeof(int));
	for (int i = 0; i < sizearr; ++i)
	{
		scanf("%d",a+i);
	}
	for (int i = 0; i < sizearr; ++i)
	{
		scanf("%d",b+i);
	}
    int *c=fun(a,b,sizearr);
    for (int i = 0; i < sizearr; ++i)
    {
    	printf("%d ",c[i] );
    }
	return 0;
}