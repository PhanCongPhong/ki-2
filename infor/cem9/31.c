#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    FILE *f1, *f2,*f3;
    if((f1 = fopen("File1.txt","r")) == NULL){
        printf ("ERROR");
        return 1;
    }
    if((f2 = fopen("File2.txt","r")) == NULL){
        printf ("ERROR");
        return 1;
    }
    if((f3 = fopen("File3.txt","w")) == NULL){
        printf ("ERROR");
        return 1;
    }
    char s[100];
    while (!feof(f1) || !feof(f2)){
        if (!feof(f1)){
            fscanf(f1,"%s\n",s);
            fprintf(f3,"%s\n",s);
        }
        if (!feof(f2)){
            fscanf(f2,"%s\n",s);
            fprintf(f3,"%s\n",s);
        }
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}