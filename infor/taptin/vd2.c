#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int strilen (char str[]){
	int size=0;
	while(str[size++]!='\0');
		return size-1;
	
}
char *stricat(char str1[],char str2[]){
	char *res;
	int size1=0,size2=0,i=0;
	size1=strilen(str1);
	size2=strilen(str2);
	res=(char*)calloc(str1+str2+1,sizeof(char));
	for (int i = 0; i < size1; ++i)
	{
		res[i]=str1[i];
	}
	for (int i = 0; i < size2; ++i)
	{
		res[size1+i]=str2[i];
	}
	return res;
}
int main(){
	char str1[MAX_SIZE],str2[MAX_SIZE];
	char *resStr;
	scanf("%s",str1);
	scanf("%s",str2);
	 resStr= stricat(str1,str2);
	 printf("%s",resStr);
	free(resStr);
	return 0;
}