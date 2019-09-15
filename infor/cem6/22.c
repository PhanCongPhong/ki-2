#include <stdio.h>
int binsearch( int x, int v[], int l,int r){
int mid=(l+r)/2;
while(l <= r){
	if (v[mid]==x)
	{
		return mid;
	}
	else if (v[mid] > x)
	{
		return binsearch(x,v,l,mid-1);
	}
	else{
		return binsearch(x,v,mid+1,r);
	}
}
return -1;
}
 int main()
{   int x,y;
	scanf("%d",&x);
	int a[10]={0,1,2,3,4,5,6,7,8,9};
    y=binsearch(x,a,0,9);
    if (y!=-1)
    {
    	printf("a[%d] = %d",y,x );
    }
    else{
    	printf("fail");
    }
	return 0;
}