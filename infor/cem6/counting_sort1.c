#include <stdio.h>
void countingsort(int a[],int n){
	int b[n];
	int max=a[0], min=a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i]>max){max=a[i];}
		else if(a[i]<min){min=a[i];}
	}
	int k=max-min+1;
	int count[k];
	for (int i = 0; i < k; ++i)
	{
		count[i]=0;
	}
	for (int i = 0; i < n; ++i)
	{
		count[a[i]-min]++;
	}
	for (int i = 1; i < k; ++i)
	{
		count[i]+=count[i-1];
	}
	for (int i = 0; i < n; ++i)
	{
		b[count[a[i]-min]-1]=a[i];
		count[a[i]-min]--;
	}
	for (int i = 0; i < n; ++i)
	{
		a[i]=b[i];
	}
}
