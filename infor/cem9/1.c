#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{   
	int n, j,x=5,count=0,i=0;
	char *s=(char*)calloc(1000,sizeof(char));
	FILE *fp; 
	fp=fopen(argv[1],"r");
	 if (argc < 2)
    {
        printf("ERROR #1: Command has not enough parameters\n");
        return -1;
    }
    if (!fp)
    {
        printf("ERROR #2: FIle error\n");
        return -2;
    }
	while (  !feof(fp))
	{
		fscanf(fp,"%c",&s[i++]);n=i;
	}
	fclose(fp);
	if (argc > 2)
	{
		x=atoi(argv[2]);
	}
	
	for ( j = n-1; j >= 0; j--)
	{
		if (s[j]=='\n')
		{
			count++;
		}
		if (count==x)
		{  
			break;
		}
	}
	for ( i = j+1; i < n; ++i)
	{
		printf("%c",s[i] );
	}
	free(fp);
	free(s);
	return 0;
}