#include <stdio.h>
#define swap(i,j) int t=i;i= j ;j= t;
int main()
{
	char i='1',j='2';
	printf("i=%c,j=%c \n",i,j );
	swap(i,j)
    printf("i=%c,j=%c",i,j );
	return 0;
}