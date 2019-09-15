#include <stdio.h>
#include <math.h>
void hexan(char a[], int n){
  int m=0,b[90];
  for (int i = 0; i < n; ++i)
    {
      if (a[i]<='9' && a[i] >= '0')
      {
        b[i]=a[i]-'0';
      }
      else if (a[i]<='F' && a[i]>= 'A')
      {
        b[i]=10+a[i]-'A';
      }
      else if (a[i]<='f' && a[i]>= 'a')
      {
        b[i]=10+a[i]-'a';
      }
        m+=b[i]*pow(16,n-i-1);
    }
    printf("%d",m );
}
int main()
{
    int c, n=0;
    char a[90];
    c= getchar(); 
    while (c !='\n' && c !=EOF){
        a[n]=c;  
        c= getchar();
        n++;    
    }
    hexan(a,n);
  
    return 0;
}