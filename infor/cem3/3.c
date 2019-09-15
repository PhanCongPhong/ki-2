#include <stdio.h>
int main()
{   int c,p[10],max;
   char a[100][10];
    for (int i = 0; i < 10; ++i)
    {
       p[i]=0;
    }
    while((c=getchar())!=EOF){p[c-'0']++;}
    max=p[0];
    /*горизонтальной гистограммы*/
    for (int i = 0; i < 10; ++i)
    {  if (p[i]>max)
       {
           max=p[i];
       }
        printf("%d : ",i);
        for (int j = 0; j < p[i]; ++j)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("\n---------------------------------\n");
    // вертикальной гистограммы:
   for (int j = 0; j < max; ++j)
   {
       for (int i = 0; i < 10; ++i)
       {   if (j<= (max-p[i]-1))
           {
               a[j][i]=' ';
           }
           else{a[j][i]='#';}
           printf("%c  ", a[j][i]);
       }
       printf("\n");
   }
   for (int i = 0; i < 10; ++i)
   {
       printf("%d  ",i );
   }
 
    return 0;
}