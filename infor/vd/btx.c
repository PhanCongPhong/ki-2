#include <stdio.h>
#include <stdlib.h>
int *test(int m){
	int *a;
	a=(int*)calloc(m-1,sizeof(int));
	for (int i = 0; i < m; ++i)
	{
		a[i]=i+1;
	}
	return a;
}
 int main()

{   int *a;
	int m;
	do{scanf("%d",&m);}
	while(m<=1 || m>=1000);
    a=test(m);
    for (int i = 0; i < m; ++i)
    {
    	printf("%d ",a[i] );
    }
	return 0;
}
