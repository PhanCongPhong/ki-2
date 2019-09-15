#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{   
	int n1,n2, j=0,i=0;
	char *s=(char*)calloc(1000,sizeof(char));
	FILE *fp1,*fp2; 
	fp1=fopen(argv[1],"r");
    fp2=fopen(argv[2],"r");
	 if (argc < 3)
    {
        printf("ERROR #1: Command has not enough parameters\n");
        return -1;
    }
    if ((!fp1)||(!fp2))
    {
        printf("ERROR #2: FIle error\n");
        return -2;
    }
	while((!feof(fp1))||(!feof(fp2))){
		if (!feof(fp1))
		{
			fscanf(fp1,"%s\n",s);
			printf("%s\n",s);
		}
		if (!feof(fp2))
		{
			fscanf(fp2,"%s\n",s);
			printf("%s\n",s);
		}
		
	}
	
	free(fp1);free(fp2);
	free(s);
	return 0;
}