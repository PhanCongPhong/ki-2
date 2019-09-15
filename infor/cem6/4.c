#include <stdio.h>
void countingsort(int [],int);
void mergeSort(int [], int , int );
 int main()
{ 
	int a[11]={7,0,1,8,3,2,5,4,9,6,11};
    int b[11]={1,4,2,3,3,2,5,7,6,90,4};
   countingsort(a,11);
   mergeSort(b,0,10);
    printf("\n a:\n");
    for (int i = 0; i < 11; ++i)
    {
    	printf("%d  ", a[i]);
    }
    printf("\n b:\n");
    for (int i = 0; i < 11; ++i)
    {
    	printf("%d  ", b[i]);
    }
	return 0;
}