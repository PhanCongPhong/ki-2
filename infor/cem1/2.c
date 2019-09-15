#include <stdio.h>
int strlen(char s[]) {
int i;
 i = 0;
while (s[i] != '\0') {
 ++i;
 }
return i;
}
int main()
{   int n;
	char name[32];
    printf("Enter your name...\n");
    gets(name);
     n = strlen(name);
     for (int i=0; i<n+6;i++){
        printf("*");
    }
    printf("\n*  %s  *\n", name);
      for (int i=0; i<n+6;i++){
        printf("*");
    }
     return(0);
}