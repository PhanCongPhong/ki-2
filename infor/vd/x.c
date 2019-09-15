#include<stdio.h>
#include <stdlib.h>
int *xArr(int a ){
	int *newArr=(int*)calloc(a,sizeof(int));
	for (int i = 1; i <= a; ++i)
	{
		newArr[i-1]=i;
	}
	return newArr;
}
int main()
{ 
    int m;
	do{scanf("%d",&m);}while(m<=1 || m>=1000);
	int *newArr=xArr(m);
    for (int i = 0; i < m; i++)
    {
    	printf("%d ",newArr[i] );
    }
	return 0;
}