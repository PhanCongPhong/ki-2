#include <stdio.h>
int strlen(char s[])
{
	int i=0;
	while(s[i]!='\0'){i++;}
    return i;
}
void xoa(char s1[], char s2[]){
	for (int i = 0; i < strlen(s2); ++i)
	{
		for (int j = 0; j < strlen(s1); ++j)
		{
			if (s2[i]==s1[j])
			{   int n1=strlen(s1);
				for (int k = j; k < n1; ++k)
				{
					s1[k]=s1[k+1];
				}
				j--;
			}
		}
	}
	
}
int main()
{
	char s1[90],s2[90];
	gets(s1);
	gets(s2);
	xoa(s1,s2);
	int n=strlen(s1);
	for (int i = 0; i < n; ++i)
	{printf("%c",s1[i] );
	}
	return 0;
}