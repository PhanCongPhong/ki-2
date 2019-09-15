#include <stdio.h>
int main()
{
    int a[40],s=0;
    for (int i = 0; a[i] !=EOF; i++)
    {
        scanf("%d",&a[i]);
        s=s+a[i];
    }
    printf("%d",s );
    return 0;
}