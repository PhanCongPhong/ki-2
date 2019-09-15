#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    FILE *fp;
    fp=fopen("phong.txt","r");
    char str[100][100];
    int a[100],pos=0;
    printf("Menu:\n1 - add\n2 - remove\n3 - list\n");
    while(fscanf(fp,"%s",str[pos])==1){
        fscanf(fp,"%d",&a[pos]);
        pos++;
    }
    fclose(fp);
    int test,up;
    char temp[100];
    while(scanf("%d",&test) && test){
        if(test==1){
            scanf("%s %d",&temp,&up);
            int i=0;
            int flag=0;
            for(i=0; i<pos; i++){
                if(strcmp(temp,str[i])==0){
                    flag=1;
                    a[i]=up;
                    break;
                }
            }
            if(flag==0){
                strcpy(str[pos],temp);
                a[pos]=up;
                pos++;
            }
        }
        else if(test ==2){
            scanf("%s",&temp);
            int i=0,j=0;
            int flag=0;
            for(i=0; i<pos; i++){
                if(strcmp(temp,str[i])==0){
                    flag=1;
                    for(j=i+1; j<pos; j++){
                        strcpy(str[j-1],str[j]);
                    }
                    pos--;
                    break;
                }
                if(flag)
                    break;
            }
        }
        else{
            int i=0;
            for(i=0; i<pos; i++)
                printf("%s %d\n",str[i],a[i]);
        }
        int i;
        FILE *dp;
        dp=fopen("in.txt","w");
        for(i=0; i<pos; i++){
            fprintf(dp,"%s %d\n",str[i],a[i]);
        }
        fclose(dp);
    }
}