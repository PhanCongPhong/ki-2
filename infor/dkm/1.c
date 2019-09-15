#include <stdio.h>
#include <stdlib.h>
int *funs(int m){
	int *a;
	a=(int*)calloc(m,sizeof(int));
	for (int i = 0; i < m; ++i)
	{
		a[i]=i+1;
	}
	return a;
}
int main(){
	int m;
	scanf("%d",&m);
	funs(m);
	int *a=funs(m);
	for (int i = 0; i < m; ++i)
	{
		printf("%d ",*(a+i) );
	}
}