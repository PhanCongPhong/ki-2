#include <stdio.h>
int main()
{
    int c;
    c= getchar(); 
    while (c !=EOF){
        if (c !=' '&& c !='\t')
        {
            putchar (c);}
        c= getchar();    
    }
    return 0;
}