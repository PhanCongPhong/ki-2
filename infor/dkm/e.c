#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num=5;

	int *array  =(int*) calloc(num,sizeof(int));
	for (int i = 0; i < num; ++i)
	{
		scanf("%d",array+i);
	}
	return 0;
}
