#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 1000
#define MAXLINES 5000
char *lineptr[MAXLINES];
int l[MAXLEN];
void readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[], int nlines);
void qs(int l[], int left, int right);
int main()
{
	
	int nlines;
	scanf("%d",&nlines);
	fflush(stdin);
	readlines(lineptr,nlines);
	qs(l,0,nlines-1);
	printf("--------------------------------------------OK\n" );
	for (int i = 0; i < nlines; i++)
     printf("%s\n", lineptr[i]);
	return 0;
  
}
int get_line(char s[], int lim) {
int c, i;
for (i = 0;
i < lim-1 && (c = getchar()) != EOF && c != '\n';
++i) {
 s[i] = c;
}
if (c == '\n'){
 s[i] = c;
 ++i;
 }
 s[i] = '\0';
return i;
}
void readlines(char *lineptr[],int nlines) {
 int len,i=0;
 char *p, line[MAXLEN]; 
 while (i< nlines && (len = get_line(line, MAXLEN)) > 0  ){
 	   
 	   	p = (char*) calloc(len,sizeof(int));
           line[len-1] = '\0';
           strcpy(p, line);
           lineptr[i] = p;
           l[i]=len-1;
           i++;
       }
   }
   void swap(char *v[], int i, int j) {
      char *temp;
      temp = v[i];
      v[i] = v[j];
       v[j] = temp;
    }
    void swap_int(int v[], int i, int j) {
      int temp = v[i];
      v[i] = v[j];
      v[j] = temp;
    }
    void qs(int v[], int left, int right) {
       int i, last;
       if (left >= right)return;
       swap_int(v, left, (left+right)/2);
       swap(lineptr, left, (left+right)/2);
         last = left;
      for (i = left+1; i <= right; i++)
             if (v[i]< v[left]) {
             	swap(lineptr, ++last, i);
                swap_int(v, last, i);}
                  
       swap(lineptr, left, last);
       swap_int(v,left, last);
       qs(v, left, last-1);
       qs(v, last+1, right);
}