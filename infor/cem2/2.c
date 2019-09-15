
#include <stdio.h>
int main()
{
    int c, n=0;
    char a[90];
    c= getchar(); 
    while (c !='\n'){
        a[n]=c;  
        if (c =='\t' || c==' '){a[n]='\n';};
        c= getchar();
        n++;    
    }
   for (int i = 0; i < n; ++i)
   {
   	  if (a[i]=='\n' && a[i+1]=='\n')
   	  {
        for (int j = i; j < n; ++j)
        {
        	a[j]=a[j+1];
        } i--;n--;
   	  } 
   }
    if(a[n-1]=='\n'){
    	a[n-1]='\0';
    }
    if(a[0]=='\n'){
		for (int j = 0; j < n; ++j){
        	a[j]=a[j+1];
        }
        n--;
   	}
     for (int i = 0; i < n; ++i){
  	printf("%c",a[i] );}
    return 0;
}