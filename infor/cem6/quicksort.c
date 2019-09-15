#include<stdio.h>
void swap(int v[], int i, int j) {
 int temp = v[i];
 v[i] = v[j];
 v[j] = temp;
}
void quick(int v[],int l,int h){
if (l >= h) return;
int p=v[h];
int i=l-1;
for (int j = l; j < h; ++j)
{
	if (v[j] < p)
	{
		i++; swap(v,i,j);
	}
}
swap(v,i+1,h);
quick(v,i+2,h);
quick(v,l,i);
}
void quick_sort1(int v[], int l, int r) {
 int i, mid;
 if (l >= r)
 return;
 swap(v, l, (l + r)/2);
 mid = l;
 for (i = l+1; i <= r; i++)
 if (v[i] < v[l])
 swap(v, ++mid, i);
 swap(v, l, mid);
 quick_sort1(v, l, mid-1);
 quick_sort1(v, mid+1, r);
}
void quick_sort(int v[], int n) {
 int Sl[10] ,Sr[10] ,l ,r,i,mid; 
 int Sp = 1;//So phan tu cua Stack
 Sl[Sp-1] = 0; Sr[Sp-1] = n-1;
 while (Sp > 0){
	 l = Sl[Sp-1] ; r = Sr[Sp-1]; 
     Sp--;
	 while (l<r)
	 {
		swap(v, l, (l + r)/2);
        mid = l;
        for (i = l+1; i <= r; i++)
            if (v[i] < v[l])
                swap(v, ++mid, i);
        swap(v, l, mid);
		Sp++;
		Sl[Sp-1]=l;Sr[Sp-1] = mid-1;
        l=mid+1;
		
	 }
	 
 }
}

void Quick_Sort (int *a,int n)
{
int Sl[10] ,Sr[10] ,l ,r; 
//Sl ,Sr :Mang dung nhu Stack luu tru vi tri ben trai, ben phai
int Sp = 1;//So phan tu cua Stack
Sl[Sp-1] = 0; Sr[Sp-1] = n-1;
while (Sp > 0)//2 Stack khac rong
{
l = Sl[Sp-1] ; r = Sr[Sp-1]; 
Sp--;
while ( l<r)
{
int i=l ,j=r ,x =  (a[(i+j)/2]);
while (i<=j)
{
while (  (a[i]) < x)
i++;
while ( (a[j]) > x)
j--;
if (i<=j)
swap (a,i++,j--);
}
if (i<r)
{
Sp++;
Sl[Sp-1] = i; Sr[Sp-1] = r;
}
r = j;
}
}
}