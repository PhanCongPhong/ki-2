#include <stdio.h>
int main()
{   int i=0,n = 0,k,c, count = 0;
	char a[200], b[200];
    c= getchar();
      while (c !='\n'){
        a[n]=c;   c= getchar();
        n++;    
    }
    while(i<n)
    {   if (a[i]==a[i+1] && a[i]!=' ' && a[i]!='\t')
        {
             k=i;
             while(a[k+1]==a[i]){k++;}
             if (k>=(i+2))
             {
                for (int j = i; j <=k; j++)
                {
                    b[count] = a[j];
                    count++;
                }
                i=k;
             }
        }
     i++;
    }
    for(i = 0; i< count; i++)
    {   printf("%c",b[i]);
        if(b[i] != b[i + 1] &&  b[i+1]!='\0')
        {printf("\n");

        }
    }
     return(0);
}