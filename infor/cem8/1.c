#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int strend(char *s, char *t){
   int n=strlen(s),m=strlen(t),count=0;
   if (n<m) return 0;
  int k=n-m;
  for (int i = 0; i < m; ++i)
  {
  	if (*(t+i)==*(s+k)) count++;
  	k++;
  }
  if (count==m) return 1;
   else return 0;
}
int main(){
  char s[100],t[100];
  gets(s);gets(t);
  int res=strend(s,t);
  printf("%d", res);
}