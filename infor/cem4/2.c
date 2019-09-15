#include <stdio.h>
#include <math.h>
int hexan(char a[], int n){
  char b[]="0123456789ABCDEF",d[]="0123456789abcdef";
  int m=0,count=0;
  for (int i = 0; i < n; ++i)
    { for (int j = 0; j < 16; ++j)
      {
      if (a[i]==b[j]){ count=j;  }
      if (a[i]==d[j]){ count=j;  }
      }       
       m+=count*pow(16,n-i-1);
    }
  return m;
}
void checkbit(int n){
   int count=0;
  for (int i = 0; i < 32; ++i)
    {
      if ((n>>i)%2==1)
      {
       n=n>>i;break;
      }
    }
    while(n!=0){count++;n=n >>2;}
    printf("%d",count );
}
int main()
{   int c, n=0,m;
    char a[90] ;
    while ( (c= getchar()) !='\n' && c !=EOF){a[n]=c; n++; }
    m=hexan(a,n);
    checkbit(m);
    return 0;
}