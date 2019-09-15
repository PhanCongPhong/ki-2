#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){

    FILE *fp;
    char str[100][100],a[100],temp[100];
    int hh[100];
    int l,num;
    int cnt=0;
    fp=fopen("file.txt","r");
    int i,j,k;
    for(i=0;i<20;i++)hh[i]=1;
    while(fgets(a,100,fp)!=NULL){
        for(i=0;i<strlen(a);i++){
            str[cnt][i]=a[i];
        }
        cnt++;
    }
    for(i=0; i<cnt; i++){
        for(j=i+1; j<cnt; j++)
        {
            if(strcmp(str[i],str[j])>0)
            {
                strcpy(temp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);
            }
        }
    }
    for(i=0;i<cnt-1;i++){
        int isequal=1;
        if(strlen(str[i])!=strlen(str[i+1]))continue;
        int l=strlen(str[i]);
        if(l<strlen(str[i+1]))l=strlen(str[i+1]);
        for(j=0;j<l;j++){
            if(str[i][j]!=str[i+1][j]){
                isequal=0;
                break;
            }
        }
        if(isequal){
            hh[i]++;
            for(j=i+1;j<cnt-1;j++){
                strcpy(str[j],str[j+1]);
            }
            cnt--;
            i--;
        }
    }
    for(i=0;i<cnt;i++){
        int ll=hh[i];
        char ch='0'+hh[i];
        j=strlen(str[i]);
        str[i][j-1]=' ';
        str[i][j]=ch;
        str[i][j+1]='\0';

    }
    for(i=0;i<cnt;i++){
        printf("%s\n",str[i]);

    }
    printf("\n");
    for(i=cnt-1;i>=0;i--){
        printf("%s\n",str[i],hh[i]);

    }
}

