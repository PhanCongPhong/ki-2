#include <stdio.h>
#include <math.h>
void hexan(char a[], int n){
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
    printf("%d",m );
  
}
int main()
{
    int c, n=0;
    char a[90] ;
    while ( (c= getchar()) !='\n' && c !=EOF){
       a[n]=c;  
       n++;    
    }
    hexan(a,n);
    return 0;
}