#include <stdio.h>
int main()
{
	 int c, n=0,count = 0;
    char a[90],b[90];
    c= getchar(); 
    while (c !='\n'){
        a[n]=c;  
        c= getchar();
        n++;    }
    for (int i = 0; i < n; ++i){
    	if (a[i+1]=='-'){   
				if (a[i]<a[i+2]){
    		  for (c=a[i];c<=a[i+2];c++){
    			b[count]=c;
    			count++;
					}
    	  }
    	  else{
    	    	for (c=a[i];c>=a[i+2];c--){
    			   b[count]=c;
    			   count++;
					  }

    	  }
    	}
    }
    for (int i = 0; i < count; ++i){
    	if (b[i]!=b[i-1])
    	{
    		printf("%c",b[i] );
    	}
    }

	return 0;
}