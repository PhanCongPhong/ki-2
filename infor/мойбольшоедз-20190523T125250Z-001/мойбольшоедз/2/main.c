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
struct student
{
    char idstd[size];
    char surname[size];
    char name[size];
    char middlename[size];
    char department[size]; //khoa
    char major[size];
};
struct book
{
    char ISBN[size];
    char author[size];
    char namebook[size];
    int totalbook;
    int access;
};
int teststd(char *Namefile, char test[size])
{
    struct student data[max];
    int i = 0;
    char temp[size];
    FILE *f;
    f = fopen(Namefile, "r+");
    if (!f)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(f);
        while (fgets(temp, size, f))
        {
            fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data[i].idstd, data[i].surname, data[i].name, data[i].middlename, data[i].department, data[i].major);
            i++;
        }
    }
    int k = -1;
    int j = 0;
    for (j; j <= i; j++)
    {
        if (strcmp(test, data[j].idstd) == 0)
            k = j;
    }
    fclose(f);
    return k;
}
void addstudent(char *Namefile) //добавить студенть
{
    struct student newstd;
    int n;
    int i = 0;
    FILE *f;
    printf("How many students do you want to add?\n");
    scanf("%d", &n);
    f = fopen(Namefile, "a");
    for (i = 0; i < n; i++)
    {
        int k;
        printf("Enter information student %d\n", i + 1);
        printf("Enter ID :");
        do
        {
            fflush(stdin);
            gets(newstd.idstd);
            k = teststd(Namefile, newstd.idstd);
            if (k != -1)
            {
                printf("Error:This student is already in the file!!!\n");
                printf("Enter ID :");
            }
        } while (k != -1);
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

        fprintf(f, "%s", newstd.idstd);
        fprintf(f, ",%s", newstd.surname);
        fprintf(f, ",%s", newstd.name);
        fprintf(f, ",%s", newstd.middlename);
        fprintf(f, ",%s", newstd.department);
        fprintf(f, ",%s\n", newstd.major);
    }
    fclose(f);
    printf("Success!!!\n");
}
void deletestudent(char *Namefile) //удалить студенть
{
    struct student data[max];
    char deleteid[size];
    int i = 0;
    char temp[size];
    FILE *f;
    printf("Enter ID student to delete\n");
    fflush(stdin);
    gets(deleteid);
    f = fopen(Namefile, "r+");
    if (!f)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(f);
        while (fgets(temp, size, f))
        {
            fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data[i].idstd, data[i].surname, data[i].name, data[i].middlename, data[i].department, data[i].major);
            i++;
        }
    }
    int k = -1;
    int j = 0;
    for (j; j <= i; j++)
    {
        if (strcmp(deleteid, data[j].idstd) == 0)
            k = j;
    }
    fclose(f);
    if (k == -1)
    {
        printf("No student found in file!!!\n");
    }
    else
    {
        f = fopen(Namefile, "w");
        rewind(f);
        fprintf(f, "ID,Surname,Name,Middlename,Department,Major\n");
        for (j = 0; j <= i; j++)
        {
            if (j != k)
            {
                fprintf(f, "%s", data[j].idstd);
                fprintf(f, ",%s", data[j].surname);
                fprintf(f, ",%s", data[j].name);
                fprintf(f, ",%s", data[j].middlename);
                fprintf(f, ",%s", data[j].department);
                fprintf(f, ",%s\n", data[j].major);
            }
        }
        fclose(f);
    }
    printf("Success!!!\n");
}
void searchstudent(char *Namefile) //найти студент
{
    struct student data[max];
    char searchsur[size];
    int i = 0;
    char temp[size];
    FILE *f;
    printf("Enter surname\n");
    fflush(stdin);
    gets(searchsur);
    f = fopen(Namefile, "r+");
    if (!f)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(f);
        while (fgets(temp, size, f))
        {
            fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data[i].idstd, data[i].surname, data[i].name, data[i].middlename, data[i].department, data[i].major);
            i++;
        }
    }
    int test = 0;
    int k[i + 1];
    int j = 0;
    for (j; j <= i; j++)
    {
        if (strcmp(searchsur, data[j].surname) == 0)
            k[j] = j;
        else
            k[j] = -1;
    }
    fclose(f);
    printf("loading.....\n");
    printf("ID\t\tSurname\t\tName\t\tMiddlename\t\tDepartment\tMajor\n");
    for (j = 0; j <= i; j++)
    {
        if (k[j] != -1)
        {
            printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", data[j].idstd, data[j].surname, data[j].name, data[j].middlename, data[j].department, data[j].major);
            test = 1;
        }
    }
    if (test == 0)
    {
        printf("No student found in file!!!\n");
    }
    else
        printf("Success!!!\n");
}
void copyfile(char *Namefile)
{
    struct student data[max];
    int i = 0, j;
    char temp[size];
    FILE *f;
    f = fopen(Namefile, "r+");
    if (!f)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(f);
        while (fgets(temp, size, f))
        {
            fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data[i].idstd, data[i].surname, data[i].name, data[i].middlename, data[i].department, data[i].major);
            i++;
        }
    }
    fclose(f);
    time_t now;
    struct tm ts;
    char buf[size];
    int n1;
    int n2;
    int n;
    char c[size] = "students_";
    time(&now);
    ts = *localtime(&now);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S", &ts);
    n1 = strlen(c);
    n2 = strlen(buf);
    for (n = 0; n < n2; n++)
    {
        if (buf[n] == ' ')
        {
            buf[n] = '.';
        }
        if (buf[n] == ':')
        {
            buf[n] = '-';
        }
        c[n + n1] = buf[n];
    }
    c[n1 + n2] = '.';
    c[n1 + n2 + 1] = 'c';
    c[n1 + n2 + 2] = 's';
    c[n1 + n2 + 3] = 'v';
    c[n1 + n2 + 4] = NULL;
    printf("%s\n", c);
    FILE *fcopy;
    fcopy = fopen(c, "w");
    rewind(fcopy);
    fprintf(fcopy, "ID,Surname,Name,Middlename,Department,Major\n");
    for (j = 0; j <= i; j++)
    {
        fprintf(fcopy, "%s", data[j].idstd);
        fprintf(fcopy, ",%s", data[j].surname);
        fprintf(fcopy, ",%s", data[j].name);
        fprintf(fcopy, ",%s", data[j].middlename);
        fprintf(fcopy, ",%s", data[j].department);
        fprintf(fcopy, ",%s\n", data[j].major);
    }
    fclose(fcopy);
    printf("Success!!!\n");
}
void restorefile(char *Namefile)
{
    struct student data[max];
    int i = 0, j, n;
    char c[size];
    char temp[size];
    FILE *f, *f1;
    f = fopen(Namefile, "r+");
    if (!f)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(f);
        while (fgets(temp, size, f))
        {
            fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", data[i].idstd, data[i].surname, data[i].name, data[i].middlename, data[i].department, data[i].major);
            i++;
        }
    }
    fclose(f);
    f1 = fopen("students.csv", "w");
    rewind(f1);
    fprintf(f1, "ID,Surname,Name,Middlename,Department,Major\n");
    for (j = 0; j <= i; j++)
    {
        fprintf(f1, "%s", data[j].idstd);
        fprintf(f1, ",%s", data[j].surname);
        fprintf(f1, ",%s", data[j].name);
        fprintf(f1, ",%s", data[j].middlename);
        fprintf(f1, ",%s", data[j].department);
        fprintf(f1, ",%s\n", data[j].major);
    }
    fclose(f1);
    printf("You've successfully restore the folder\n");
}
void mainstudent(char *login)
{
    char Namefile[] = "students.csv";
    int i = 0;
    int m;
    FILE *fx;
    char *c[max];
    int temp;
    time_t now;
    struct tm ts;
    char buf[size];
    time(&now);
    ts = *localtime(&now);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S", &ts);
    printf("%s\n", buf);
    int a;
    for (;;)
    {
        printf("Menu:\n");
        printf("1.Add new students\n");
        printf("2.Search students\n");
        printf("3.Delete studens\n");
        printf("4.Copy file\n");
        printf("5.Restore file\n");
        printf("6.Exit\n");
        scanf("Choose what you want 1,2,3,4,5 or 6!!!\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            addstudent(Namefile);
            break;
        case 2:
            searchstudent(Namefile);
            break;
        case 3:
            deletestudent(Namefile);
            break;
        case 4:
            copyfile(Namefile);
            break;
        case 5:
            printf("Enter the folder you backed up:\n");
            char namefile[size];
            fflush(stdin);
            gets(namefile);
            restorefile(namefile);
            break;
        }
        if (a == 6)
            break;
        fflush(stdin);
        fx = fopen("library.log", "a");
        fprintf(fx, "\n\"%s\"", buf);
        fprintf(fx, ",\"%s\"", login);
        if (a == 1)
            fprintf(fx, ",\"Add new students\"");
        else if (a == 2)
            fprintf(fx, ",\"Search students\"");
        else if (a == 3)
            fprintf(fx, ",\"Delete studens\"");
        else if (a == 4)
            fprintf(fx, ",\"Copy file\"");
        else if (a == 5)
            fprintf(fx, ",\"Restore file\"");
        else
            break;
        fclose(fx);
    }
}
int testbook(char *Namefile, char test[size])
{
    struct book data[max];
    int i = 0;
    char temp[size];
    FILE *f;
    f = fopen(Namefile, "r+");
    if (!f)
    {
        return 0;
    }
    else
    {
        rewind(f);
        while (fgets(temp, size, f))
        {
            fscanf(f, "%[^,],%[^,],%[^,],%d,%d", data[i].ISBN, data[i].author, data[i].namebook, &data[i].totalbook, &data[i].access);
            i++;
        }
    }
    int k = -1;
    int j = 0;
    for (j; j <= i; j++)
    {
        if (strcmp(test, data[j].ISBN) == 0)
            k = j;
    }
    fclose(f);
    return k;
}
void addbook(char *Namefile) //добавить студенть
{
    struct book newb;
    int n;
    int i = 0;
    FILE *f;
    printf("How many book do you want to add? \n");
    scanf("%d", &n);
    f = fopen(Namefile, "a");
    for (i = 0; i < n; i++)
    {
        int k;
        printf("Enter book %d\n", i + 1);
        printf("Enter ISBN :\n");
        do
        {
            fflush(stdin);
            gets(newb.ISBN);
            k = testbook(Namefile, newb.ISBN);
            if (k != -1)
            {
                printf("This book is already in the file!!!\n");
                printf("Enter ISBN :\n");
            }
        } while (k != -1);
        printf("Enter author : \n");
        fflush(stdin);
        gets(newb.author);

        printf("Enter namebook :\n");
        fflush(stdin);
        gets(newb.namebook);

        printf("Enter totalbook :\n");
        fflush(stdin);
        scanf("%d", &newb.totalbook);

        printf("Enter access:");
        fflush(stdin);
        scanf("%d", &newb.access);

        fprintf(f, "%s", newb.ISBN);
        fprintf(f, ",%s", newb.author);
        fprintf(f, ",%s", newb.namebook);
        fprintf(f, ",%d", newb.totalbook);
        fprintf(f, ",%d\n", newb.access);
    }
    fclose(f);
    printf("Success!!!\n\n");
}
int deletebook(char *Namefile)
{
    struct book data[max];
    char deletebook[size];
    int i = 0;
    char temp[size];
    FILE *f;
    printf("Enter ISBN :\n");
    fflush(stdin);
    gets(deletebook);
    f = fopen(Namefile, "r+");
    if (!f)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(f);
        while (fgets(temp, size, f))
        {
            fscanf(f, "%[^,],%[^,],%[^,],%d,%d", data[i].ISBN, data[i].author, data[i].namebook, &data[i].totalbook, &data[i].access);
            i++;
        }
    }
    int k = -1;
    int j = 0;
    for (j; j < i; j++)
    {
        if (strcmp(deletebook, data[j].ISBN) == 0)
            k = j;
    }
    if (k == -1)
    {
        printf("No book found in file!!!\n");
    }
    else
    {
        f = fopen(Namefile, "w");
        rewind(f);
        fprintf(f, "ISBN,Author,Namebook,Totalbook,Access\n");
        for (j = 0; j < i - 1; j++)
        {
            if (j != k)
            {
                fprintf(f, "%s", data[j].ISBN);
                fprintf(f, ",%s", data[j].author);
                fprintf(f, ",%s", data[j].namebook);
                fprintf(f, ",%d", data[j].totalbook);
                fprintf(f, ",%d\n", data[j].access);
            }
        }
        fclose(f);
    }
    printf("Success!!!\n\n");
}
void searchbook(char *Namefile)
{
    struct book data[max];
    char searchISBN[size];
    int i = 0;
    char temp[size];
    FILE *f;
    printf("Enter ISBN :\n");
    fflush(stdin);
    gets(searchISBN);
    f = fopen(Namefile, "r+");
    if (!f)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(f);
        while (fgets(temp, size, f))
        {
            fscanf(f, "%[^,],%[^,],%[^,],%d,%d", data[i].ISBN, data[i].author, data[i].namebook, &data[i].totalbook, &data[i].access);
            i++;
        }
    }
    int k = -1;
    int j = 0;
    for (j; j <= i; j++)
    {
        if (strcmp(searchISBN, data[j].ISBN) == 0)
            k = j;
    }
    fclose(f);
    printf("Loading.....\n");
    printf("ISBN\t\tAuthor\t\tNamebook\t\tTotalbook\t\tAccess\n");
    if (k != -1)
    {
        printf("%s\t\t%s\t\t%s\t\t%d\t\t%d\n", data[k].ISBN, data[k].author, data[k].namebook, data[k].totalbook, data[k].access);
        printf("Success!!!\n\n");
    }
    else
    {
        printf("\nNo book!!!\n");
    }
}
void infobook(char *Namefile)
{
    struct book data[max];
    int *arrdata[max];
    int i = 0;
    char temp[size];
    FILE *f;
    f = fopen(Namefile, "r+");
    if (!f)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(f);
        while (fgets(temp, size, f))
        {
            fscanf(f, "%[^,],%[^,],%[^,],%d,%d", data[i].ISBN, data[i].author, data[i].namebook, &data[i].totalbook, &data[i].access);
            arrdata[i] = atoi(data[i].ISBN);
            i++;
        }
    }
    fclose(f);
    int x, y;
    int t;
    x = 0;
    y = i - 2;
    for (x; x < i - 2; x++)
    {
        for (y = i - 2; y > x; y--)
        {
            if (arrdata[y] < arrdata[y - 1])
            {
                t = arrdata[y];
                arrdata[y] = arrdata[y - 1];
                arrdata[y - 1] = t;
            }
        }
    }
    for (x = 0; x < i - 1; x++)
    {
        for (y = 0; y < i; y++)
        {
            if (arrdata[x] == atoi(data[y].ISBN))
                printf("%s\t%s\t\t%s\t\t%d\t\t%d\n", data[y].ISBN, data[y].author, data[y].namebook, data[y].totalbook, data[y].access);
        }
    }
    printf("Success!!!\n\n");
}
void mainbook(char *login)
{
    char Namefile[] = "book.csv";
    FILE *fx;
    time_t now;
    struct tm ts;
    char buf[80];
    time(&now);
    ts = *localtime(&now);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S", &ts);
    printf("%s\n", buf);
    int a;
    for (;;)
    {
        printf("Menu:\n");
        printf("1.Add new book.\n");
        printf("2.Search book.\n");
        printf("3.Delete book.\n");
        printf("4.Information book.\n");
        printf("5.Exit.\n");
        scanf("Choose what you want 1,2,3,4 or 5!!!\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            addbook(Namefile);
            break;
        case 2:
            searchbook(Namefile);
            break;
        case 3:
            deletebook(Namefile);
            break;
        case 4:
            infobook(Namefile);
            break;
        }
        if (a == 5)
            break;
        fflush(stdin);
        fx = fopen("library.log", "a");
        fprintf(fx, "\n\"%s\"", buf);
        fprintf(fx, ",\"%s\"", login);
        if (a == 1)
            fprintf(fx, ",\"Add new book\"");
        else if (a == 2)
            fprintf(fx, ",\"Search book\"");
        else if (a == 3)
            fprintf(fx, ",\"Delete book\"");
        else if (a == 4)
            fprintf(fx, ",\"Information book\"");
        else
            break;
        fclose(fx);
    }
}
void ReadFile(char *Namefile)
{

    char login[100];
    char pass[100];
    char temp[size];
    int i = 0;
    FILE *f;
    struct users data[max];
    f = fopen(Namefile, "rb");
    if (!f)
    {
        return 0;
    }
    else
    {
        rewind(f);
        while (fgets(temp, size, f))
        {
            fscanf(f, "%[^,],%[^,],%d,%d\n", data[i].login, data[i].pass, &data[i].student, &data[i].book);
            i++;
        }
    }
    fclose(f);
    int k = -1;
    int c;
    do
    {
        fflush(stdin);
        printf("Enter login : ");
        gets(login);
        printf("Enter password : ");
        gets(pass);
        int j = 0;
        for (j; j <= i; j++)
        {
            if (strcmp(login, data[j].login) == 0 && strcmp(pass, data[j].pass) == 0)
                k = j;
        }
        if (k == -1)
        {
            printf("Your login or password is not correct!!!\n");
            printf("You want to login again?\n");
            printf("1.Yes\n");
            printf("2.No\n");
            int test;
            scanf("%d", &test);
            if (test == 2)
            {
                FILE *fx;
                time_t now;
                struct tm ts;
                char buf[80];
                time(&now);
                ts = *localtime(&now);
                strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S", &ts);
                fflush(stdin);
                fx = fopen("library.log", "a");
                fprintf(fx, "\n\"%s\"", buf);
                fprintf(fx, ",\"login unsuccessful\"");
                fclose(fx);
                break;
            }
        }
    } while (k == -1);
    if (k != -1)
    {
        printf("Congratulations !!! You are successfully logged in!!!\n");
        printf("Book : %d \n", data[k].book);
        printf("Student : %d \n", data[k].student);

        if (data[k].book == 1 && data[k].student == 0)
        {
            printf("\nWELCOME TO LIBRARY!!!\n");
            mainbook(login);
            c = 1;
        }
        else if (data[k].book == 0 && data[k].student == 1)
        {
            printf("\nWELCOME TO LIST STUDENTS!!!\n");
            mainstudent(login);
            c = 2;
        }
        else if (data[k].book == 1 && data[k].student == 1)
        {
            for (;;)
            {
                printf("1. MENU BOOK. \n");
                printf("2. MENU STUDENTS. \n");
                printf("3. EXIT. \n");
                printf("Choose what you want 1,2 or 3!!!\n");
                scanf("%d", &c);
                if (c == 1)
                {
                    printf("\nWELCOME TO LIBRARY!!!\n");
                    mainbook(login);
                }
                else if (c == 2)
                {
                    printf("\nWELCOME TO LIST STUDENTS!!!\n");
                    mainstudent(login);
                }
                else
                    break;
            }
        }
    }
}
int main()
{
    ReadFile("users.csv");
    return 0;
}
