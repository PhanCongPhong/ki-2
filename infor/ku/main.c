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
struct student student[max];
struct book book[max];
int readstd (char *Namefile){
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
           fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",student[i].idstd,student[i].surname,student[i].name,student[i].middlename,student[i].department,student[i].major);
           i++;
        }
        
    }
    fclose(f);
    return i;
}
int teststd (char test[size])
{
    int i=readstd("student.csv");
    int k=-1;
    int j;
    for(j=0;j<i;j++)
    {
        if(strcmp(test,student[j].idstd)==0)
            k =j ;
    }
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
        k=teststd( newstd.idstd);
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

       fprintf(f,"\n%s",newstd.idstd);
       fprintf(f,",%s",newstd.surname);
       fprintf(f,",%s",newstd.name);
       fprintf(f,",%s",newstd.middlename);
       fprintf(f,",%s",newstd.department);
       fprintf(f,",%s",newstd.major);
    }
    fclose(f);
    printf("Success!!!\n");
}
void deletestudent (char *Namefile)//удалить студенть
{
    char deleteid[size];
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
        int i=readstd("student.csv");
        int k=teststd(deleteid);
        fclose(f);
    if(k==-1)
    {
        printf("No student found in file!!!\n");
    }
    else{ 
        int j=0; 
        f=fopen(Namefile,"w");
        rewind(f);
        for(j=0;j<i ;j++){
        if( j!=k){
        fprintf(f,"\n%s",student[j].idstd);
        fprintf(f,",%s",student[j].surname);
        fprintf(f,",%s",student[j].name);
        fprintf(f,",%s",student[j].middlename);
        fprintf(f,",%s",student[j].department);
        fprintf(f,",%s",student[j].major);
        }
    }
    fclose(f);
    }

    }
    
    printf("Success!!!\n");
}
void editingStudent( char *filename)
{
	FILE *f;
	struct student edititem;
    struct student x[max];
    int count=0;
	printf("ID:"); fflush(stdin);
	gets(edititem.idstd);
	
	f = fopen(filename, "r");
	rewind(f);
	int k = teststd(edititem.idstd); 
	int n = readstd(filename);
	fclose(f);
	if (k != -1)
	{
		printf("Enter Surname : ");
        fflush(stdin);
        gets(edititem.surname);

        printf("Enter name :");
        fflush(stdin);
        gets(edititem.name);

        printf("Enter middle name :");
        fflush(stdin);
        gets(edititem.middlename);

        printf("Enter department :");
        fflush(stdin);
        gets(edititem.department);

        printf("Enter major :");
        fflush(stdin);
        gets(edititem.major);
		f = fopen(filename, "w");
		int j;
		for(j=0;j<n ;j++){
        if( j!=k){
        fprintf(f,"\n%s",student[j].idstd);
        fprintf(f,",%s",student[j].surname);
        fprintf(f,",%s",student[j].name);
        fprintf(f,",%s",student[j].middlename);
        fprintf(f,",%s",student[j].department);
        fprintf(f,",%s",student[j].major);
        }
    }
		fprintf(f, "\n%s,%s,%s,%s,%s,%s", edititem.idstd, edititem.surname, edititem.name, edititem.middlename, edititem.department, edititem.major);
		fclose(f);
	}
	
}

void strswap(char a[], char b[])
{
	char tmp[max];
	strcpy(tmp, b);
	strcpy(b, a);
	strcpy(a, tmp);
}

void sortingstudent( char *filename)
{
	FILE *fs = fopen(filename, "r");
	int i, j;
	int n = readstd("student.csv");
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j< n; j++)
		{
			if (strcmp(student[i].idstd, student[j].idstd) > 0)
			{
				strswap(student[i].idstd, student[j].idstd);
				strswap(student[i].surname, student[j].surname);
				strswap(student[i].name, student[j].name);
				strswap(student[i].middlename, student[j].middlename);
				strswap(student[i].department, student[j].department);
               strswap(student[i].major, student[j].major);
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%10s | %10s | %10s | %10s | %10s | %10s\n", student[i].idstd, student[i].surname, student[i].name, student[i].middlename, student[i].department,student[i].major);
}
void mainstudent(char *login)
{
    char Namefile[]="student.csv";
    int i=0;
    int m;
    FILE *fx;
    char *c[max];
    int temp;
    time_t     now;
    struct tm  ts;
    char   buf[size];
    time(&now);
    ts = *localtime(&now);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S", &ts);
    printf("%s\n", buf);
    int a;
    for(;;)
    {
        printf("Menu:\n");
        printf("1.Add new students\n");
        printf("2.Delete studens\n");
        printf("3.Edit student\n");
        printf("4.Show list student\n");
        printf("5.Exit\n");
        scanf("Choose what you want 1,2,3,4 or 5!!!\n");
        scanf("%d",&a);
        switch(a){
        case 1:
            addstudent(Namefile);
            break;
        case 2:
            deletestudent(Namefile);
            break;
        case 3:
            editingStudent(Namefile);
            break;
        case 4:
            sortingstudent(Namefile);
            break;
        }
        if(a==5)
            break;
        fflush(stdin);
        fx=fopen("library.log","a");
        fprintf(fx,"\n\"%s\"",buf);
        fprintf(fx,",\"%s\"",login);
        if(a==1)
            fprintf(fx,",\"Add new students\"");
        else if(a==2)
            fprintf(fx,",\"Delete studens\"");
        else if(a==3)
            fprintf(fx,",\"Edit studens\"");
        else if(a==4)
            fprintf(fx,",\"Look list students\"");
        else break;
        fclose(fx);
    }

}
//end part 1 student
int readbook (char *Namefile)
{
   
    int i=0;
    char temp[size];
    FILE *f;
    f= fopen(Namefile,"r+");
    if(!f)
    {
        return 0;
    }
    else
    {
        rewind(f);
        while(fgets(temp,size,f))
        {
           fscanf(f, "%[^,],%[^,],%[^,],%d,%d",book[i].ISBN,book[i].author,book[i].namebook,&book[i].totalbook,&book[i].access);
           i++;
        }
    }
    fclose(f);
    return i;
}
int testbook (char test[size])
{
     int i=readbook("book.csv");
    int k=-1;
    int j;
    for(j=0;j<i;j++)
    {
        if(strcmp(test,book[j].ISBN)==0)
            k =j ;
    }
    return k;
}
void addbook(char *Namefile)
{
  struct book newb;
    int n;
    int i=0;
    FILE *f;
    printf("How many book do you want to add? \n");
    scanf ("%d",&n);
    f=fopen(Namefile,"a");
    for(i=0;i<n;i++)
    {
        int k;
        printf("Enter book %d\n",i+1);
        printf("Enter ISBN :\n");
        do{
        fflush(stdin);
        gets(newb.ISBN);
        k=testbook(newb.ISBN);
        if(k!=-1)
        {
            printf("This book is already in the file!!!\n");
            printf("Enter ISBN :\n");
        }
        }
        while(k!=-1);
        printf("Enter author : \n");
        fflush(stdin);
        gets(newb.author);

        printf("Enter namebook :\n");
        fflush(stdin);
        gets(newb.namebook);

        printf("Enter totalbook :\n");
        fflush(stdin);
        scanf("%d",&newb.totalbook);

        printf("Enter access:");
        fflush(stdin);
        scanf("%d",&newb.access);


       fprintf(f,"\n%s",newb.ISBN);
       fprintf(f,",%s",newb.author);
       fprintf(f,",%s",newb.namebook);
       fprintf(f,",%d",newb.totalbook);
       fprintf(f,",%d",newb.access);
    }
    fclose(f);
    printf("Success!!!\n\n");
}
void deletebook (char *Namefile)
{
    char deleteid[size];
    FILE *f;
    printf("Enter ISBN book to delete\n");
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
        int i=readbook("book.csv");
        int k=testbook(deleteid);
        fclose(f);
    if(k==-1)
    {
        printf("No book found in file!!!\n");
    }
    else{ 
        int j=0; 
        f=fopen(Namefile,"w");
        rewind(f);
        for(j=0;j<i ;j++){
        if( j!=k){
        fprintf(f,"\n%s",book[j].ISBN);
        fprintf(f,",%s",book[j].author);
        fprintf(f,",%s",book[j].namebook);
        fprintf(f,",%d",book[j].totalbook);
        fprintf(f,",%d",book[j].access);

        }
    }
    fclose(f);
    }

    }
    
    printf("Success!!!\n");
}
void borrowbook (char *Namefile)
{
    char borrowid[size];
    FILE *f;
    printf("Enter ISBN book to borrow\n");
    fflush(stdin);
    gets(borrowid);
    f= fopen(Namefile,"r+");
    if(!f)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(f);
        int i=readbook("book.csv");
        int k=testbook(borrowid);
        fclose(f);
    if(k==-1)
    {
        printf("No book found in file!!!\n");
    }
    else if(book[k].access==0){
        printf("There is no longer this book in the library\n");
    }
    else{ 
        int j=0; 
        f=fopen(Namefile,"w");
        rewind(f);
        for(j=0;j<i ;j++){
        if( j!=k){
            fprintf(f,"\n%s",book[j].ISBN);
            fprintf(f,",%s",book[j].author);
            fprintf(f,",%s",book[j].namebook);
            fprintf(f,",%d",book[j].totalbook);
            fprintf(f,",%d",book[j].access);

        }
        else
        {
            fprintf(f,"\n%s",book[j].ISBN);
            fprintf(f,",%s",book[j].author);
            fprintf(f,",%s",book[j].namebook);
            fprintf(f,",%d",book[j].totalbook);
            fprintf(f,",%d",book[j].access-1);
        }
        
        
        }

    fclose(f);
    }

    }
    
    printf("Success!!!\n");
}
void returnbook (char *Namefile)
{
    char returnid[size];
    FILE *f;
    printf("Enter ISBN book to add\n");
    fflush(stdin);
    gets(returnid);
    f= fopen(Namefile,"r+");
    if(!f)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(f);
        int i=readbook("book.csv");
        int k=testbook(returnid);
        fclose(f);
    if(k==-1)
    {
        printf("No book found in file!!!\n");
    }
    else if(book[k].access==book[k].totalbook){
        printf("Library enough this books\n");
    }
    else{ 
        int j=0; 
        f=fopen(Namefile,"w");
        rewind(f);
        for(j=0;j<i ;j++){
        if( j!=k){
            fprintf(f,"\n%s",book[j].ISBN);
            fprintf(f,",%s",book[j].author);
            fprintf(f,",%s",book[j].namebook);
            fprintf(f,",%d",book[j].totalbook);
            fprintf(f,",%d",book[j].access);

        }
        else
        {
            fprintf(f,"\n%s",book[j].ISBN);
            fprintf(f,",%s",book[j].author);
            fprintf(f,",%s",book[j].namebook);
            fprintf(f,",%d",book[j].totalbook);
            fprintf(f,",%d",book[j].access+1);
        }
        
        
        }

    fclose(f);
    }

    }
    
    printf("Success!!!\n");
}
void mainbook(char *login)
{
    char Namefile[]="book.csv";
    FILE *fx;
    time_t     now;
    struct tm  ts;
    char       buf[80];
    time(&now);
    ts = *localtime(&now);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S", &ts);
    printf("%s\n", buf);
    int a;
    for(;;)
    {
        printf("Menu:\n");
        printf("1.Add new book.\n");
        printf("2.Delete book.\n");
        printf("3.Borrow book\n");
        printf("4.Return Book.\n");
        printf("5.Exit.\n");
        scanf("Choose what you want 1,2,3,4 or 5!!!\n");
        scanf("%d",&a);
        switch(a){
        case 1:
            addbook(Namefile);
            break;
        case 2:
            deletebook(Namefile);
            break;
        case 3:
            borrowbook(Namefile);
            break;
        case 4:
            returnbook(Namefile);
            break;
        }
        if(a==5)
            break;
        fflush(stdin);
        fx=fopen("library.log","a");
        fprintf(fx,"\n\"%s\"",buf);
        fprintf(fx,",\"%s\"",login);
        if(a==1)
            fprintf(fx,",\"Add new book\"");
        else if(a==2)
            fprintf(fx,",\"Delete book\"");
        else if(a==3)
            fprintf(fx,",\"Borrow book\"");
        else if(a==4)
            fprintf(fx,",\"Return book\"");
        else break;
        fclose(fx);
    }
}
//end book
//user-part 2
void ReadFile(char *Namefile)
{

	char login[100];
	char pass[100];
	char temp[size];
	int i=0;
    FILE *f;
    struct users data[max];
    f=fopen(Namefile,"rb");
    if(!f)
    {
       printf("No file!!!\n");
    }
    else
    {
        rewind(f);
        while(fgets(temp,size,f))
        {
           fscanf(f, "%[^,],%[^,],%d,%d\n",data[i].login,data[i].pass,&data[i].student,&data[i].book);
           i++;
        }
    }
    fclose(f);
    int k=-1;
    int c;
    do{
        fflush(stdin);
        printf("Enter login : ");gets(login);
        printf("Enter password : ");gets(pass);
        int j=0;
        for(j;j<=i;j++)
        {
            if(strcmp(login,data[j].login)==0 && strcmp(pass,data[j].pass)==0)
                k =j ;
        }
        if(k==-1)
        {
            printf("Your login or password is not correct!!!\n");
            printf("You want to login again?\n");
            printf("1.Yes\n");
            printf("2.No\n");
            int test;
            scanf("%d",&test);
            if(test==2)
            {
                FILE *fx;
                time_t     now;
                struct tm  ts;
                char       buf[80];
                time(&now);
                ts = *localtime(&now);
                strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S", &ts);
                fflush(stdin);
                fx=fopen("library.log","a");
                fprintf(fx,"\n\"%s\"",buf);
                fprintf(fx,",\"login unsuccessful\"");
                fclose(fx);
                break;
            }
        }
    }
    while(k==-1);
    if (k!=-1)
    {
        printf("Congratulations !!! You are successfully logged in!!!\n");
        printf("Book : %d \n",data[k].book);
        printf("Student : %d \n",data[k].student);

    if(data[k].book==1 && data[k].student==0 )
    {
        printf("\nWELCOME TO LIBRARY!!!\n");
        mainbook(login);
        c=1;

    }
    else if (data[k].book==0 && data[k].student==1 )
    {
        printf("\nWELCOME TO LIST STUDENTS!!!\n");
        mainstudent(login);
        c=2;

    }
    else if(data[k].book==1 && data[k].student==1 )
    {
        for(;;)
        {
            printf("1. MENU BOOK. \n");
            printf("2. MENU STUDENTS. \n");
            printf("3. EXIT. \n");
            printf("Choose what you want 1,2 or 3!!!\n"); scanf("%d",&c);
       if(c==1)
       {
            printf("\nWELCOME TO LIBRARY!!!\n");
            mainbook(login);
       }
       else if(c==2)
       {
            printf("\nWELCOME TO LIST STUDENTS!!!\n");
            mainstudent(login);
       }
       else break;
    }
    }
    }
}
 
int main()
{
    ReadFile("users.csv");
    return 0;
}