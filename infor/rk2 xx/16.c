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

void funs(int *a, int n, int m){
	quick_sort1(a,0,n-1);
  
  for (int i = 0; i < n; ++i)
	{
		if (a[i]>m)
		{
			printf("%d ",a[i] );
		}
	}
}
int main()
{
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int *a=(int*)calloc(n,sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	
	funs(a,n,m);
	
		
	free(a);
	return 0;
}