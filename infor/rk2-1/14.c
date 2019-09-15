#include <stdio.h>
#include <stdlib.h>
void swap(int v[], int i, int j) {
 int temp = v[i];
 v[i] = v[j];
 v[j] = temp;
}
void quick_sort1(int v[], int l, int r) {
 int i, mid;
 if (l >= r)
 return;
 swap(v, l, (l + r)/2);
 mid = l;
 for (i = l+1; i <= r; i++)
 if (v[i] < v[l])
 swap(v, ++mid, i);
 swap(v, l, mid);
 quick_sort1(v, l, mid-1);
 quick_sort1(v, mid+1, r);
}
int *funs(int *a, int n){
  int *b=(int*)calloc(50,sizeof(int));
  int j=0;
  for (int i = 0; i < n; ++i)
	{
		if (abs(a[i])%2==1)
		{
			b[j]=a[i];j++;
		}
	}
	quick_sort1(b,0,j-1);
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
