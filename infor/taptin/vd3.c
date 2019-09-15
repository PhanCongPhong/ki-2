#include <stdlib.h> 
#include <stdio.h>
int strilen(char str[]){ 
int size=0; 
while(str[size++]!='\0'){ 
} 
return size-1; 
} 

char *stricat(char str1[],char str2[]){ 
int strSize1=0, strSize2=0, i=0; 
char*res; 
strSize1=strilen(str1); 
strSize2=strilen(str2); 
res=(char*)calloc(strSize1 + strSize2 + 1,sizeof(char)); 
for(i=0;i<strSize1;i++){ 
res[i]=str1[i]; 
} 
for(i=0;i<strSize2;i++){ 
res[strSize1+i]=str2[i]; 
} 
res[strSize1+strSize2]='\0'; 
return res; 
} 

int main() 
{ 
char str1[100], str2[100]; 
char*resStr; 
scanf("%s",str1); 
scanf("%s",str2); 

resStr=stricat(str1, str2); 
printf("%s",resStr); 

free(resStr); 
return 0; 
}