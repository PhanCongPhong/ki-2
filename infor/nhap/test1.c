#include <stdio.h>
int main()
{   int c,p[10];
    for (int i = 0; i < 10; ++i)
    {
       p[i]=0;
    }
    while((c=getchar())!=EOF){p[c-'0']++;}
    for (int i = 0; i < 10; ++i)
    {
        printf("%d : %d",i,p[i] );
    }
    return 0;
}