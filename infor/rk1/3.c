#include "stdio.h"
void read_string(char s[], int len){
	int c,i=0;
	while((c=getchar()) !=EOF && i <len && c != '\n'){s[i++]=c;}s[i]='\0';

}
void print_string(char s[]){
	int i=0;
	while(s[i] !='\0'){putchar(s[i]);i++;}
}
int main()
{ 
	char s[5];
	read_string(s,5);
	print_string(s);
	return 0;
}