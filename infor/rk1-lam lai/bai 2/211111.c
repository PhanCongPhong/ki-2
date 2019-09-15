#include <stdio.h>
int main() 
{int a,n=0, j;
    char c[90]; a=getchar();
    while(a!=EOF){c[n]=a;a=getchar();n++;}
    for(int i=0; i<n;i++){
      if (c[i]=='/' && c[i+1]=='/')
      {
        j=i;
        while(c[j]!='\n'){j++;i=j-1;}
       
      }
      else{
        printf("%c",c[i] );
      }

}
return 0;
}