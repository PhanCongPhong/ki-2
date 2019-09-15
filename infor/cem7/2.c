#include <stdio.h>
#include <stdlib.h>
char *readstr(){
	char *str=(char*)calloc(100,sizeof(char));
	scanf("%s",str);
	return str;
}
int main(){
	char *str;
	str=readstr();
	printf("%s",str );
	free(str);
	return 0;
}
