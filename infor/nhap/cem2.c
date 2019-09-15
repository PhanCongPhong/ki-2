#include <stdio.h>
int fac(int n){
	int i=1;
	int res=1;
	for (i; i <=n; ++i)
	{
		res*=i;
	}
	return res;
}
int facrec(int n){
	if (n==0)
	{
		return 1;
	}
	return facrec(n-1)*n;
}
int main(int argc, char const *argv[])
{
	printf("%d\n",fac(5) );
	printf("%d\n",facrec(5) );
	return 0;
}