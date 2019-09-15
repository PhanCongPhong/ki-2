#include <stdio.h>
void xoa( char s1[], char s2[]){
	int count;
	for (int i = 0; s1[i]!='\0'; ++i)
	{
		count=0;
		for (int j = 0; s2[j]!='\0'; ++j)
		{
			if (s1[i]==s2[j])
			{
				count++;
			}
		}
		if (count==0)
		{
			printf("%c", s1[i]);
		}
	}
}
int main(){
	char s1[90],s2[90];
	gets(s1);gets(s2);
    xoa(s1,s2);
	return 0;
}