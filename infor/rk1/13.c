
#include <stdio.h>
int main()
{
	int i = 0; 
char s; 
 while ((s = getchar ())!= EOF) { 
if ((i%2==0) && (97 <= s) && (s <= 122) ){ 
putchar (s-32); 
} else if ((i% 2!=0 ) && (65 <= s) && (s <= 90)) { 
putchar (s + 32); 
} else { 
putchar (s); 
} 
i ++; 
}
	return 0;
}