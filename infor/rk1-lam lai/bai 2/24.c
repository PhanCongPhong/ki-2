#include <stdio.h>
int main() 
{int a,n=0,s=0;
    char c[90]; a=getchar();
    while(a!=EOF){c[n]=a;a=getchar();n++;}
    for(int i=0; i<n;i++){ 
       if ((int)c[i]>=48 && (int)c[i]<=57)
       {
         s=s+(int)c[i]-48;
       }
       if (c[i]=='\n')
       {
         printf("%d\n",s );
         s=0;
       }
    }
return 0;
}