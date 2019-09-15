#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct city city;
#define __MAX_SIZE 256
struct city
{
	char name[14];
    int s;
};
city citys[__MAX_SIZE];
int read_city(const char *filename);
void addingcity(const char *filename);
void deletingcity(const char *filename);
void sortingcity(const char *filename);
int main(){
int n = read_city("phong.txt");
	if (n == -1)
	{
		printf("ERROR #1: empty file");
	}
	else
	{
		int x;
		printf("MENU :");
		printf("\n1) Add");
		printf("\n2) Delete");
		printf("\n3) Show");
		
		printf("\nYou want:");
		scanf("%d", &x);
		fflush(stdin);
		switch(x)
		{
			case 1:
			{
					addingcity("phong.txt");break;
				
			}
			case 2:
			{
					deletingcity("phong.txt");
					break;
					
			}
			case 3:
			{
				sortingBook("phong.txt");
				break;
			}
			
			default:;
		}
	}
}
int read_city(const char *filename)
{
	FILE *fs = fopen(filename, "r+");
	if (!fs) 
		return -1;
	
	//Read file
	rewind(fs);
	char tmp[__MAX_SIZE];
	int total = 0;
	while(fgets(tmp, __MAX_SIZE, fs))
	{
		fscanf(fs, "%s %d",citys[total].name,&citys[total].s);
		total++;
	}
	return total;
}