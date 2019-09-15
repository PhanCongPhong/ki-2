#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define size 100
#define max 1000
struct users
{
  char login[size];
  char pass[size];
  int student;
  int book;
};
struct student {
    char idstd[size];
    char surname[size];
    char name[size];
    char middlename[size];
    char department[size];//khoa
    char major[size];
};
struct book{
    char ISBN[size];
    char author[size];
    char namebook[size];
    int totalbook;
    int access;
};
int teststd (char *Namefile,char test[size])
{
    struct student data[max];
    int i=0;
    char temp[size];
    FILE *f;
    f= fopen(Namefile,"r+");
    if(!f)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(f);
        while(fgets(temp,size,f))
        {
           fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",data[i].idstd,data[i].surname,data[i].name,data[i].middlename,data[i].department,data[i].major);
           i++;
        }
    }
    int k=-1;
    int j=0;
    for(j;j<=i;j++)
    {
        if(strcmp(test,data[j].idstd)==0)
            k =j ;
    }
    fclose(f);
    return k;
}
void addstudent(char *Namefile)//добавить студенть
{
    struct student newstd;
    int n;
    int i=0;
    FILE *f;
    printf("How many students do you want to add?\n");
    scanf ("%d",&n);
    f=fopen(Namefile,"a");
    for(i=0;i<n;i++)
    {
        int k;
        printf("Enter information student %d\n",i+1);
        printf("Enter ID :");
        do{
        fflush(stdin);
        gets(newstd.idstd);
        k=teststd(Namefile, newstd.idstd);
        if(k!=-1)
        {
            printf("Error:This student is already in the file!!!\n");
            printf("Enter ID :");
        }
        }
        while(k!=-1);
        printf("Enter Surname : ");
        fflush(stdin);
        gets(newstd.surname);

        printf("Enter name :");
        fflush(stdin);
        gets(newstd.name);

        printf("Enter middle name :");
        fflush(stdin);
        gets(newstd.middlename);

        printf("Enter department :");
        fflush(stdin);
        gets(newstd.department);

        printf("Enter major :");
        fflush(stdin);
        gets(newstd.major);

       fprintf(f,"%s",newstd.idstd);
       fprintf(f,",%s",newstd.surname);
       fprintf(f,",%s",newstd.name);
       fprintf(f,",%s",newstd.middlename);
       fprintf(f,",%s",newstd.department);
       fprintf(f,",%s\n",newstd.major);
    }
    fclose(f);
    printf("Success!!!\n");
}
void deletestudent (char *Namefile)//удалить студенть
{
    struct student data[max];
    char deleteid[size];
    int i=0;
    char temp[size];
    FILE *f;
    printf("Enter ID student to delete\n");
    fflush(stdin);
    gets(deleteid);
    f= fopen(Namefile,"r+");
    if(!f)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(f);
        while(fgets(temp,size,f))
        {
           fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",data[i].idstd,data[i].surname,data[i].name,data[i].middlename,data[i].department,data[i].major);
           i++;
        }

    }
    int k=-1;
    int j;
    for(j=0;j<i;j++)
    {
        if(strcmp(deleteid,data[j].idstd)==0)
            k =j;
    }
    fclose(f);
    if(k==-1)
    {
        printf("No student found in file!!!\n");
    }
    else{
        f=fopen(Namefile,"w");
        rewind(f);
        for(j=0;j<i ;j++){
        if( j!=k){
        fprintf(f,"%s",data[j].idstd);
        fprintf(f,",%s",data[j].surname);
        fprintf(f,",%s",data[j].name);
        fprintf(f,",%s",data[j].middlename);
        fprintf(f,",%s",data[j].department);
        fprintf(f,",%s\n",data[j].major);
        }
    }
    fclose(f);
    }
    printf("Success!!!\n");
}
void swap(int *a, int *b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

void strswap(char a[], char b[])
{
	char tmp[max];
	strcpy(tmp, b);
	strcpy(b, a);
	strcpy(a, tmp);
}
int main(){
    int a;
     printf("Menu:\n");
        printf("1.Add new students\n");
        printf("2.Edit students\n");
        printf("3.Delete studens\n");
        printf("4.Copy file\n");
        printf("5.Restore file\n");
        printf("6.Exit\n");
        printf("Choose what you want 1,2,3,4,5 or 6!!!\n");
        scanf("%d",&a);
        switch(a){
        case 1:
            addstudent("student.csv");
            break;
        // case 2:
        //     editingstudent("student.csv");
        //     break;
        case 3:
            deletestudent("student.csv");
            break;}
    return 0;
}