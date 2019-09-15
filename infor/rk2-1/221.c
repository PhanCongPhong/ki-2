#include <stdio.h>
#include <stdlib.h>
char *stricpy(char *A, const char *B) // copy chuoi B[] vao chuoi A[]
{
  int n = 0;
  do
  {
    A[n] = B[n];
    n++;
  }
  while (B[n] != '\0');
  return A;
}
int main()
{
	char *strcptr=(char*)calloc(100,sizeof(char));
	char *destptr=(char*)calloc(100,sizeof(char));
    char c; int count=0;
     while((c=getchar()) != '\n'){
        
        strcptr[count]=c;
        
        
        count++;
    }

    destptr=stricpy(destptr,strcptr);
    printf("%s",destptr );
	free(strcptr);
	free(destptr);
	return 0;
}