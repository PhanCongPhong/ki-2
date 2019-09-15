#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{   int p,n,count=1,j;
	FILE *fp; 
	fp=fopen("1.txt","r");
	 if (argc < 5)
    {
        printf("ERROR #1: Command has not enough parameters\n");
        return -1;
    }
    if (!fp)
    {
        printf("ERROR #3: FIle error\n");
        return -2;
    }
    p=atoi(argv[2]);
    n=atoi(argv[4]);
    char *s=(char*)calloc(100,sizeof(char));
	while ( !feof(fp))
	{  
		for (int i = 0; i < p ; i++)
        {    
            for (j = 0; j < n; j++)
            {    
                fscanf(fp,"%c",&s[j]);
                if (feof(fp))
                {
                    break;
                }
                
                if (s[0]=='\n')
                {
                   j--;continue;
                }
                
                if (s[j]=='\n')
                {   s[j]='\0';
                    break;
                }
            }
            s[j]='\0';if (s[0]!='\0')
            {
                printf("%d  : %s\n",i+1,s);
            }  
        }
        
        printf("-Page %d-\n\n",count++);
	}
	fclose(fp);
	
	free(fp);
	free(s);
	return 0;
}