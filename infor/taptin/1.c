#include <stdio.h>
int main()
{
	int a,b;
	FILE *fp; 
	fp=fopen("1.txt","r");
	fscanf(fp,"%d",&a);
	fscanf(fp,"%d",&b);
	fclose(fp);
	printf("%d - %d\n",a, b );
	FILE *fo;
	fo=fopen("2.txt","w");
	fprintf(fo,"%d",a+b);
	fclose(fo);
	return 0;
}