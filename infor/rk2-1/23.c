#include <stdio.h>
#include <stdlib.h>
int strlen(char *s) {
int i;
 i = 0;
while (s[i] != '\0') {
 ++i;
 }
return i;
}
int main()
{
	char *str=(char*)calloc(100,sizeof(char));
  scanf("%s",str);
  printf("%d",strlen(str) );
	return 0;
}