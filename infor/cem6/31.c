#include <stdio.h>
void swap(int v[], int i, int j) {
 int temp = v[i];
 v[i] = v[j];
 v[j] = temp;}
void quick_sort(int v[], int n) {
 int Sl[10] ,Sr[10] ,l ,r,i,mid; 
 int Sp = 1;
 Sl[Sp-1] = 0; Sr[Sp-1] = n-1;
 while (Sp > 0){
	 l = Sl[Sp-1] ; r = Sr[Sp-1]; 
     Sp--;
	 while (l<r){
		swap(v, l, (l + r)/2);
        mid = l;
        for (i = l+1; i <= r; i++)
            if (v[i] < v[l])
                swap(v, ++mid, i);
        swap(v, l, mid);
		Sp++;
		Sl[Sp-1]=l;Sr[Sp-1] = mid-1;
        l=mid+1; }
	}
}
 int main()
{ 
	int a[11]={7,0,1,8,3,2,5,4,9,6,11};
   quick_sort(a,10);
    for (int i = 0; i < 11; ++i)
    {
    	printf("%d\n", a[i]);
    }
	return 0;
}