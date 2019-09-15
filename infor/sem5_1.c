#include <stdio.h>
void phan(char s1[],char s2[]){
	int i, k=-1,flag=0;
	for(i=0; s1[i]!='\0'; ++i){
    	for (int j = 0; s2[j]!='\0'; ++j){
    		if (s1[i]==s2[j]){
    			k=i;
    			flag=1;
    			break;
    		}
    	}
    	if(flag==1)break;
    }
    printf("%d",k );
}

int main(){
    
	char s1[90],s2[90];
	gets(s1);gets(s2);
	phan(s1,s2);
	return 0;
}
