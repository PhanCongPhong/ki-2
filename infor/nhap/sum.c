#include <stdio.h>
double calc( int a, int b, char oper){  
	double res;
	switch(oper){
		case '+':
		   res=a+b; break;
		case '-':
		    res=a-b;break;
		default:
		printf("error" );   
	}
	return res;
}
int main()
{
  int a=1,b=5; 
  char c;
  scanf("%s",&c);
  int kq=0;
  kq=calc(a,b,c);
  printf("%d",kq );
  return 0;
}