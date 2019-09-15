//you have to make a file with name file.txt
#include <stdio.h>
#include <stdlib.h> 							// atoi lib
#define __MAX_SIZE 256

int main(int argc, char **argv)
{
	if (argc < 5)
	{
		printf("ERROR: Command has not enough parameters\n");
		return -1;
	}
	
	FILE *fs = fopen("1.txt", "r");
	int i=1, j=1,a,b,k=0,count=0;
	if (argc >= 5)
		{
			a = atoi(argv[2]);				  //function convert char to int
			b = atoi(argv[4]);
		}
	rewind(fs); 						     //put the pointer on the first position of the file
	int total = 0;
	char tmp[__MAX_SIZE];
	while( !feof(fs))
	{
		printf("- Page %d -\n",j++);
		for( i=1; i<= a; i++)
			{
				
				fgets(tmp, b+1, fs);
				if(feof(fs))                // exit the loop if end of file
				break;
				if(tmp[0] == '\n')		    //remove a loop if tmp={\n}	(1 character \n)			
				{
					i--;
					continue;
				}
				printf("%d:",i);
				for(k=0; tmp[k] != '\0' && tmp[k] != '\n'; k++)   //output the characters
				{
					printf("%c",tmp[k]);
				}
				printf("\n");
			}
	}
	fclose(fs);
	return 0;
}