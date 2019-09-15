#include <stdio.h>
#include <stdlib.h>
int stricmpr(char *a, char *b){
	int n=0;
	do
	{
		if (a[n] > b[n])
			return 1;
		else if (a[n] < b[n])
			return -1;
		n++;
	} while (a[n] != '\0' || b[n] != '\0');
	return 0;
  
}
int main()
{
	char *s1=(char*)calloc(100,sizeof(char));
	char *s2=(char*)calloc(100,sizeof(char));
    scanf("%s",s1);
    scanf("%s",s2);
   int n=stricmpr(s1,s2);
    printf("%d",n );
	free(s1);
	free(s2);
	return 0;
}