#include <stdio.h>
#include <stdlib.h>
void funs(int *arr1, int *arr2, int arrSize){
	
	int a[arrSize];
    for (int i = 0; i < arrSize; ++i)
    {
    	a[i]=arr1[i]-arr2[i];
    }
	printf("kq:");
    for (int i = 0; i < arrSize; ++i)
    {
    	printf("%d ",a[i] );
    }
}
int main (){ 
	int arrSize=0;
	int *arr1, *arr2 ;
	scanf("%d",&arrSize);
	arr1=(int*)calloc(arrSize,sizeof(int));
	arr2=(int*)calloc(arrSize,sizeof(int));
	printf("\ns1:\n");
	for (int i = 0; i < arrSize; ++i)
	{
		scanf("%d",(arr1+i) );
	}
	printf("\ns2:\n");
	for (int i = 0; i < arrSize; ++i)
	{
		scanf("%d",(arr2+i) );
	}
	funs(arr1,arr2,arrSize);
   
}