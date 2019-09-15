#include <stdio.h>
int main() 
{int a,n=0,k=1;
    char c[90]; a=getchar();
    while(a!=EOF){c[n]=a;a=getchar();n++;}
    for(int i=0; i<n;i++){
      if(c[i]=='\n'){k++;};
      if((k%2==1)&&(c[i]>='A')&&((int)c[i]<=90)){
        printf("%c",(int)c[i]+32);
      }
       else if((k%2==0)&&((int)c[i]>=97)&&((int)c[i]<=122)){
        printf("%c",(int)c[i]-32);
        }
    else{printf("%c",c[i]);}
    

}
return 0;
}

