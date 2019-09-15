#include <stdio.h>
#include <stdlib.h>
int main()
{   char *a=(char*)calloc(90,sizeof(int));
	int c=getchar(),n=0,k=1;
	while(c!=EOF){a[n++]=c;c=getchar();}
	for (int i = 0; a[i]!='\0'; ++i)
	{
		if (a[i]=='\n')k++;
		if ((k%2==1) && (a[i]>='A') && (a[i]<='Z')) printf("%c",a[i]+'a'-'A' );
		else if ((k%2==0) && (a[i]>='a') && (a[i]<='z')) printf("%c",a[i]-'a' +'A');
		else printf("%c",a[i] );
	}

	return 0;
}
