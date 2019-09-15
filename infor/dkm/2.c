#include <stdio.h>
#include <stdlib.h>
int funs(int *a, int sizearr,int find){
	int count=0;
	for (int i = 0; i < sizearr; ++i)
	{
		if (a[i]==find)
		{
			count++;
		}
	}
	return count;
}
int main(int argc, char const *argv[])
{
	int sizearr,find;
	scanf("%d",&sizearr);
    scanf("%d",&find);
    int *a=(int*)calloc(sizearr,sizeof(int));
    for (int i = 0; i < sizearr; ++i)
    {
    	scanf("%d",a+i);
    }
    int b=funs(a,sizearr,find);
    printf("%d",b );
	return 0;
}