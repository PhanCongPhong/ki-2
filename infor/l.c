#include <stdio.h>
void test(char s[]){
	for (int i = 0; i < 5; ++i)
	{
		s[i]='2';
	}
}
void test1(int *a, int *b){
	int temp; temp=*a;*a=*b;*b=temp;
}
int main()
{   int a=3,b=4;
	char s[5];
	gets(s);
	test(s);
	for (int i = 0; i < 5; ++i)
	{
		printf("%c ",s[i] );
	}
	test1(&a,&b);
	printf("a= %d\n",a );
	return 0;
}