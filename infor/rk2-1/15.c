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
int *funs(int *arr1, int *arr2, int arrSize1, int arrSize2){
   int *s=(int*)calloc(100,sizeof(int));
   int count=0;
	for (int i = 0; i<arrSize1; ++i)
	{
		for (int j = 0; j<arrSize2 ; ++j)
		{
			if(arr1[i]==arr2[j]) {s[count]=arr1[i];count++; }
		}
	}
	quick_sort1(s,0,count-1);
	for (int i = 0; i < count; ++i)
	{    
		
		for (int j = 0; j<i; ++j)
		{
			if (s[i]==s[j])
			{
				for (int k = i;k<count; ++k)
				{
					s[k]=s[k+1];
				}
			}
			count--;i--;
		}
		
	}
	
	return s;
	
}

int main (){ 
	int arrSize1,arrSize2;
	int *arr1, *arr2 ,*s;
	s=(int*)calloc(100,sizeof(int));
	scanf("%d",&arrSize1);
	arr1=(int*)calloc(arrSize1,sizeof(int));
	for (int i = 0; i < arrSize1; ++i)
	{
		scanf("%d",(arr1+i) );
	}
	scanf("%d",&arrSize2);
    arr2=(int*)calloc(arrSize2,sizeof(int));
	for (int i = 0; i < arrSize2; ++i)
	{
		scanf("%d",(arr2+i) );
	}
	s=funs(arr1,arr2,arrSize1,arrSize2);
	for (int i = 0; s[i]!='\0'; ++i)
	{
		printf("%d ",s[i] );
	}
   return 0;
}