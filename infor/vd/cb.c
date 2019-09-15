#include <stdio.h>
#include <stdlib.h>
int counts(int *arr, int arrSize, int find){
    int count=0;
    for (int i = 0; i < arrSize; ++i)
    {
    	if (arr[i]==find)
    	{
    		count++;
    	}
    }
    return count;
}
int main (){ 
	int arrSize=0;
	int find=0;
	int *arr;
	int res=0;
	scanf("%d",&arrSize);
	scanf("%d", &find);
	arr=(int*)calloc(arrSize,sizeof(int));
	for (int i = 0; i < arrSize; ++i)
	{
		scanf("%d",(arr+i) );
	}
	res=counts(arr, arrSize,find);
	printf("%d",res );
    free(arr);
}