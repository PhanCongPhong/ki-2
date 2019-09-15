#include <stdio.h>
void test(char s1[],char s2[]){
	int k=-1;
	for (int i = 0; s1[i]!='\0'; ++i)
    {
    	for (int j = 0; s2[j]!='\0'; ++j)
    	{
    		if (s1[i]==s2[j])
    		{
    			k=i; break;
    		}
    	}
    }
    printf("%d",k );
}
int main()
{
	char s1[90],s2[90];
	gets(s1);gets(s2);
	test(s1,s2);
	return 0;
}