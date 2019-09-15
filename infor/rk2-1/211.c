#include <stdio.h>
#include <stdlib.h>
int strlen(char s[]) {
int i;
 i = 0;
while (s[i] != '\0') {
 ++i;
 }
return i;
}
char *stricat(char *s1, char *s2){
	char *s=(char*)calloc(200,sizeof(char));
  int n1=strlen(s1);
  int n2=strlen(s2);
  for (int i = 0; i < n1; ++i)
  {
  	s[i]=s1[i];
  }
  for (int i = 0; i < n2; ++i)
  {
  	s[i+n1]=s2[i];
  }
  return s;
}
int main()
{
	char *s1=(char*)calloc(100,sizeof(char));
	char *s2=(char*)calloc(100,sizeof(char));
	char *s=(char*)calloc(200,sizeof(char));
    char c; int count=0;
     while((c=getchar()) != '\n'){
        
        s1[count]=c;
        
        
        count++;
    }

    count=0;
     while((c=getchar()) != '\n'){
        
        s2[count]=c;
        
        
        count++;
    }
    s=stricat(s1,s2);
    printf("%s",s );
	free(s1);
	free(s2);
	return 0;
}
