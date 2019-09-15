#include <stdio.h>
#include <stdlib.h>
int *funs(int *a, int n){
  int *b=(int*)calloc(50,sizeof(int));
  int j=0;
  for (int i = n-1; i >= 0; --i)
	{
		
			b[j]=a[i];j++;
		
	}
    return b;

}
int main()
{
	int n;
	scanf("%d",&n);
	int *a=(int*)calloc(n,sizeof(int));
	int *b=(int*)calloc(50,sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",a+i);
	}
	
	b=funs(a,n);
	
		
	for (int i = 0; b[i]!='\0'; ++i)
	{
		printf("%d ",b[i] );
	}
	free(a);
	free(b);
	return 0;
}