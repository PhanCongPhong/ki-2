#include <stdio.h>
int main(){
	int n=0,c,k=0;
	char a[90];
while((c=getchar())!=EOF && c!='\n'){
		a[n]=c;
		n++;
	}
	printf("%s\n",a);
	for (int i = 0; a[i]!='\0'; ++i)
	{
		if (a[i]=='a'&& a[i+1]=='b')
		{ k++;  
		}
	}
printf("%d", k);
	return 0;
}