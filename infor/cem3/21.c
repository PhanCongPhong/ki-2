#include <stdio.h>
int strlen(char s[]){
	int i=0;
	while(s[i]!='\0'){i++;}
    return i;
}
int main()
{
	char s1[90],s2[90];
	gets(s1);
	gets(s2);
	int n1=strlen(s1),n2=strlen(s2);
	for (int i = 0; i < n2; ++i)
	{
		for (int j = 0; j < n1; ++j)
		{
			if (s2[i]==s1[j])
			{
				for (int k = j; k < n1; ++k)
				{
					s1[k]=s1[k+1];
				}
				n1--;j--;
			}
		}
	}
	for (int i = 0; i < n1; ++i)
	{
		printf("%c",s1[i] );
	}
	return 0;
}