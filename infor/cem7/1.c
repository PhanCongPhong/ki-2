#include <stdio.h>
#include <stdlib.h>
void swap(int v[], int i, int j) {
 int temp = v[i];
 v[i] = v[j];
 v[j] = temp;
}
void sell_sort(int *v,int n){
	int gap, i, j;
    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j-=gap) {
               swap(v, j, j+gap);
            }
        }
    } 
}
int main()
{ int *a ;
  int sizearr;
  scanf("%d",&sizearr);
  a=(int*)calloc(sizearr,sizeof(int));
  for (int i = 0; i < sizearr; ++i)
  {
  	scanf("%d",a+i);
  }
  sell_sort(a,sizearr);

  for (int i = 0; i < sizearr; ++i)
  {
  	printf("%d ", a[i]);
  }
}