#include <stdio.h>
#include <conio.h>
void ctp(int a[], int n)
{
	int j=n-1;
	int i,t;
	for(i=0;i<n-1;i++)
	{
		for(j;j>i;j--)
		{
			if(a[j]>a[j-1])
			{
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
	for(i=0;i<10;i++)
		printf("%d\n",a[i]);
}
int main()
{
	int a[10];
	a[0]=12;
	a[1]=8;
	a[2]=78;
	a[3]=67;
	a[4]=2;
	a[5]=6;
	a[6]=5;
	a[7]=4;
	a[8]=1;
	a[9]=22;
	ctp(a,10);
	
	getch();
	return 0;
}