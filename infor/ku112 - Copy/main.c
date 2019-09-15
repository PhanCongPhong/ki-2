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
struct library
{
    char ISBN[size];
    char idstd[size];
    char day[size];
};
struct student student[max];
struct book book[max];
struct users user[max];
struct library lbr[max];
int readstd(char *Namefile)
{
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
            fscanf(f, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", student[i].idstd, student[i].surname, student[i].name, student[i].middlename, student[i].department, student[i].major);
            i++;
        }
    }
    fclose(f);
    return i;
}
int teststd(char test[size])
{
    int i = readstd("student.csv");
    int k = -1;
    int j;
    for (j = 0; j < i; j++)
    {
        if (strcmp(test, student[j].idstd) == 0)
            k = j;
    }
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
            k = teststd(newstd.idstd);
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

        fprintf(f, "\n%s", newstd.idstd);
        fprintf(f, ",%s", newstd.surname);
        fprintf(f, ",%s", newstd.name);
        fprintf(f, ",%s", newstd.middlename);
        fprintf(f, ",%s", newstd.department);
        fprintf(f, ",%s", newstd.major);
    }
    fclose(f);
    printf("Success!!!\n");
}
void deletestudent(char *Namefile) //удалить студенть
{
    int j = 0;
    char temp[size];
    FILE *flbr;
    flbr = fopen("student_books.csv", "r+");
    int b = 0;
    if (!flbr)
    {
        printf("No file!!\n");
    }
    else
    {
        rewind(flbr);
        while (fgets(temp, size, flbr))
        {
            fscanf(flbr, "%[^,],%[^,],%[^\n]", lbr[b].ISBN, lbr[b].idstd, lbr[b].day);
            b++;
        }
    }
    fclose(flbr);
    char deleteid[size];
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
        int i = readstd("student.csv");
        int k = teststd(deleteid);
        fclose(f);
        if (k == -1)
        {
            printf("No student found in file!!!\n");
        }
        else
        {
            int h = -1;
            for (j = 0; j < b; j++)
            {
                if (strcmp(deleteid, lbr[j].idstd) == 0)
                    h = j;
            }
            if (h == -1)
            {
                int j = 0;
                f = fopen(Namefile, "w");
                rewind(f);
                for (j = 0; j < i; j++)
                {
                    if (j != k)
                    {
                        fprintf(f, "\n%s", student[j].idstd);
                        fprintf(f, ",%s", student[j].surname);
                        fprintf(f, ",%s", student[j].name);
                        fprintf(f, ",%s", student[j].middlename);
                        fprintf(f, ",%s", student[j].department);
                        fprintf(f, ",%s", student[j].major);
                    }
                }
                fclose(f);
            }
            else
            {
                printf("This student has not returned the book. You cannot delete him!\n");
            }
        }
    }

    printf("Success!!!\n");
}

void editingStudent(char *filename)
{
    FILE *f;
    struct student edititem;
    struct student x[max];
    int count = 0;
    printf("ID:");
    fflush(stdin);
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
        for (j = 0; j < n; j++)
        {
            if (j != k)
            {
                fprintf(f, "\n%s", student[j].idstd);
                fprintf(f, ",%s", student[j].surname);
                fprintf(f, ",%s", student[j].name);
                fprintf(f, ",%s", student[j].middlename);
                fprintf(f, ",%s", student[j].department);
                fprintf(f, ",%s", student[j].major);
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

void sortingstudent(char *filename)
{
    FILE *fs = fopen(filename, "r");
    int i, j;
    int n = readstd("student.csv");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
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
        printf("%10s | %10s | %10s | %10s | %10s | %10s\n", student[i].idstd, student[i].surname, student[i].name, student[i].middlename, student[i].department, student[i].major);
}

int readbook(char *Namefile)
{

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
            fscanf(f, "%[^,],%[^,],%[^,],%d,%d", book[i].ISBN, book[i].author, book[i].namebook, &book[i].totalbook, &book[i].access);
            i++;
        }
    }
    fclose(f);
    return i;
}
void searchstudent(char *filestd, char *filebook, char *filelibrary)
{
    char searchidstd[size];
    char temp[size];
    int j = 0;
    int x, y, z;
    int k[size];
    int test;
    FILE *fstd;
    printf("Enter Id student\n");
    fflush(stdin);
    gets(searchidstd);
    // fstd= fopen(filestd,"r+");
    int a = readstd(filestd);
    FILE *flbr;
    flbr = fopen(filelibrary, "r+");
    int b = 0;
    if (!flbr)
    {
        printf("No file!!\n");
    }
    else
    {
        rewind(flbr);
        while (fgets(temp, size, flbr))
        {
            fscanf(flbr, "%[^,],%[^,],%[^\n]", lbr[b].ISBN, lbr[b].idstd, lbr[b].day);
            b++;
        }
    }
    fclose(flbr);
    FILE *fbook;
    int c = readbook(filebook);
    x = teststd(searchidstd);
    if (x == -1)
    {
        printf("No student in file!!!\n");
    }
    else
    {
        for (j = 0; j < b; j++)
        {
            if (strcmp(lbr[j].idstd, student[x].idstd) == 0)
                k[j] = j;
            else
                k[j] = -1;
        }
        printf("      Idstd\t\tDay\t\tISBN\t\tAuthor \t\tNamebook\t\tTotalbook\t\tAccess\n");
        test = -1;
        for (j = 0; j < b; j++)
        {
            y = k[j];
            if (y != -1)
            {
                int m = 0;
                for (m; m <= c; m++)
                {
                    if (strcmp(lbr[y].ISBN, book[m].ISBN) == 0)
                    {
                        printf("%12s %14s %14s %15s %20s %20d %20d\n", student[x].idstd, lbr[y].day, book[m].ISBN, book[m].author, book[m].namebook, book[m].totalbook, book[m].access);
                        test = 1;
                    }
                }
            }
        }
        if (test == -1)
            printf("This student dont borrow book\n");
    }
}
void mainstudent(char *login)
{
    char Namefile[] = "student.csv";
    char filestd[max] = "student.csv";
    char filebook[max] = "book.csv";
    char filelibrary[max] = "student_books.csv";
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
        printf("2.Delete studens\n");
        printf("3.Edit student\n");
        printf("4.Show list student\n");
        printf("5.Search student-book borrow\n");
        printf("6.Exit\n");
        scanf("Choose what you want 1,2,3,4, 5 or 6!!!\n");
        scanf("%d", &a);
        switch (a)
        {
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
        case 5:
            searchstudent(filestd, filebook, filelibrary);
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
            fprintf(fx, ",\"Delete studens\"");
        else if (a == 3)
            fprintf(fx, ",\"Edit studens\"");
        else if (a == 4)
            fprintf(fx, ",\"Look list students\"");
        else if (a == 5)
            fprintf(fx, ",\"Search student-book borrow\"");
        else
            break;
        fclose(fx);
    }
}
int testbook(char test[size])
{
    int i = readbook("book.csv");
    int k = -1;
    int j;
    for (j = 0; j < i; j++)
    {
        if (strcmp(test, book[j].ISBN) == 0)
            k = j;
    }
    return k;
}
void addbook(char *Namefile)
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
            k = testbook(newb.ISBN);
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

        fprintf(f, "\n%s", newb.ISBN);
        fprintf(f, ",%s", newb.author);
        fprintf(f, ",%s", newb.namebook);
        fprintf(f, ",%d", newb.totalbook);
        fprintf(f, ",%d", newb.access);
    }
    fclose(f);
    printf("Success!!!\n\n");
}
void deletebook1(char *Namefile)
{
    int j = 0;
    char temp[size];
    FILE *flbr;
    flbr = fopen("student_books.csv", "r+");
    int b = 0;
    if (!flbr)
    {
        printf("No file!!\n");
    }
    else
    {
        rewind(flbr);
        while (fgets(temp, size, flbr))
        {
            fscanf(flbr, "%[^,],%[^,],%[^\n]", lbr[b].ISBN, lbr[b].idstd, lbr[b].day);
            b++;
        }
    }
    fclose(flbr);
    char deleteid[size];
    FILE *f;
    printf("Enter ISBN book to delete\n");
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
        int i = readbook("book.csv");
        int k = testbook(deleteid);
        fclose(f);
        if (k == -1)
        {
            printf("No book found in file!!!\n");
        }
        else
        {
            int h = -1;
            for (j = 0; j < b; j++)
            {
                if (strcmp(deleteid, lbr[j].ISBN) == 0)
                    h = j;
            }
            if (h == -1)
            {
                int j = 0;
                f = fopen(Namefile, "w");
                rewind(f);
                for (j = 0; j < i; j++)
                {
                    if (j != k)
                    {
                        fprintf(f, "\n%s", book[j].ISBN);
                        fprintf(f, ",%s", book[j].author);
                        fprintf(f, ",%s", book[j].namebook);
                        fprintf(f, ",%d", book[j].totalbook);
                        fprintf(f, ",%d", book[j].access);
                    }
                }
                fclose(f);
            }
            else
            {
                printf("have students borrow this book. You cannot delete!\n");
            }
        }
    }

    printf("Success!!!\n");
}

void returnbook_student(char *filestd, char *filebook, char *filelibrary)
{
    int j = 0;
    char temp[size];
    char searchISBN[size];
    char searchidstd[size];
    printf("Enter Id student\n");
    fflush(stdin);
    gets(searchidstd);
    FILE *flbr;
    flbr = fopen(filelibrary, "r+");
    int b = 0;
    if (!flbr)
    {
        printf("No file!!\n");
    }
    else
    {
        rewind(flbr);
        while (fgets(temp, size, flbr))
        {
            fscanf(flbr, "%[^,],%[^,],%[^\n]", lbr[b].ISBN, lbr[b].idstd, lbr[b].day);
            b++;
        }
    }
    fclose(flbr);
    FILE *fbook;

    int x = teststd(searchidstd);
    if (x == -1)
    {
        printf("No student in file!!!\n");
    }
    else
    {
        int n, t = 0;
        printf("How many book do you want to return?\n");
        scanf("%d", &n);
        for (t; t < n; t++)
        {

            printf("Enter ISBN book to return\n");
            fflush(stdin);
            gets(searchISBN);
            fbook = fopen(filebook, "r+");
            rewind(fbook);
            int i = readbook("book.csv");
            int k = -1;
            for (j = 0; j < b; j++)
            {
                if (strcmp(searchISBN, lbr[j].ISBN) == 0 && strcmp(searchidstd, lbr[j].idstd) == 0)
                    k = j;
            }
            fclose(fbook);
            if (k == -1)
            {
                printf("you cant return this book!!!\n");
            }
            else if (book[k].access == book[k].totalbook)
            {
                printf("all book in the library\n");
            }
            else
            {
                int j = 0;
                fbook = fopen(filebook, "w");
                rewind(fbook);
                for (j = 0; j < i; j++)
                {
                    if (j != k)
                    {
                        fprintf(fbook, "\n%s", book[j].ISBN);
                        fprintf(fbook, ",%s", book[j].author);
                        fprintf(fbook, ",%s", book[j].namebook);
                        fprintf(fbook, ",%d", book[j].totalbook);
                        fprintf(fbook, ",%d", book[j].access);
                    }
                    else
                    {
                        fprintf(fbook, "\n%s", book[j].ISBN);
                        fprintf(fbook, ",%s", book[j].author);
                        fprintf(fbook, ",%s", book[j].namebook);
                        fprintf(fbook, ",%d", book[j].totalbook);
                        fprintf(fbook, ",%d", book[j].access + 1);
                    }
                }
                fclose(fbook);
                fclose(fbook);
                flbr = fopen(filelibrary, "w");
                rewind((flbr));
                for (j = 0; j < b; j++)
                {
                    if (j != k)
                    {
                        fprintf(flbr, "\n%s", lbr[j].ISBN);
                        fprintf(flbr, ",%s", lbr[j].idstd);
                        fprintf(flbr, ",%s", lbr[j].day);
                    }
                }
                fclose(flbr);
            }
        }
    }
}
void borrowbook_student(char *filestd, char *filebook, char *filelibrary)
{
    char searchISBN[size];
    char searchidstd[size];
    printf("Enter Id student\n");
    fflush(stdin);
    gets(searchidstd);
    FILE *flbr;
    FILE *fbook;
    int x = teststd(searchidstd);
    if (x == -1)
    {
        printf("No student in file!!!\n");
    }
    else
    {
        int n, t = 0;
        printf("How many book do you want to borrow?\n");
        scanf("%d", &n);
        for (t; t < n; t++)
        {

            printf("Enter ISBN book to borrow\n");
            fflush(stdin);
            gets(searchISBN);
            char daybook[size];
            printf("Day?\n");
            fflush(stdin);
            gets(daybook);
            fbook = fopen(filebook, "r+");
            rewind(fbook);
            int i = readbook("book.csv");
            int k = testbook(searchISBN);
            fclose(fbook);
            if (k == -1)
            {
                printf("No book found in file!!!\n");
            }
            else if (book[k].access == 0)
            {
                printf("There is no longer this book in the library\n");
            }
            else
            {
                int j = 0;
                fbook = fopen(filebook, "w");
                rewind(fbook);
                for (j = 0; j < i; j++)
                {
                    if (j != k)
                    {
                        fprintf(fbook, "\n%s", book[j].ISBN);
                        fprintf(fbook, ",%s", book[j].author);
                        fprintf(fbook, ",%s", book[j].namebook);
                        fprintf(fbook, ",%d", book[j].totalbook);
                        fprintf(fbook, ",%d", book[j].access);
                    }
                    else
                    {
                        fprintf(fbook, "\n%s", book[j].ISBN);
                        fprintf(fbook, ",%s", book[j].author);
                        fprintf(fbook, ",%s", book[j].namebook);
                        fprintf(fbook, ",%d", book[j].totalbook);
                        fprintf(fbook, ",%d", book[j].access - 1);
                    }
                }
                fclose(fbook);
                fclose(fbook);
                flbr = fopen(filelibrary, "a");
                fprintf(flbr, "\n%s,%s,%s", searchISBN, searchidstd, daybook);
                fclose(flbr);
            }
        }
    }
}
void searchbook(char *filestd, char *filebook, char *filelibrary)
{
    char searchISBN[size];
    char temp[size];
    int j = 0;
    int x, y, z;
    int k[size];
    int test;
    FILE *fstd;
    printf("Enter ISBN book\n");
    fflush(stdin);
    gets(searchISBN);
    int a = readstd(filestd);
    FILE *flbr;
    flbr = fopen(filelibrary, "r+");
    int b = 0;
    if (!flbr)
    {
        printf("No file!!\n");
    }
    else
    {
        rewind(flbr);
        while (fgets(temp, size, flbr))
        {
            fscanf(flbr, "%[^,],%[^,],%[^\n]", lbr[b].ISBN, lbr[b].idstd, lbr[b].day);
            b++;
        }
    }
    fclose(flbr);
    FILE *fbook;
    int c = readbook(filebook);
    x = testbook(searchISBN);
    if (x == -1)
    {
        printf("No book in file!!!\n");
    }
    else
    {
        for (j = 0; j < b; j++)
        {
            if (strcmp(lbr[j].ISBN, book[x].ISBN) == 0)
                k[j] = j;
            else
                k[j] = -1;
        }
        printf("      Idstd\t\tDay\t\tSurname\t\tName \t\tMiddlename\t\tDepartment\t\tMajor\n");
        test = -1;
        for (j = 0; j < b; j++)
        {
            y = k[j];
            if (y != -1)
            {
                int m = 0;
                for (m; m <= c; m++)
                {
                    if (strcmp(lbr[y].idstd, student[m].idstd) == 0)
                    {
                        printf("%12s %14s %14s %15s %20s %20s %20s\n", student[m].idstd, lbr[y].day, student[m].surname, student[m].name, student[m].middlename, student[m].department, student[m].major);
                        test = 1;
                    }
                }
            }
        }
        if (test == -1)
            printf("This book dont borrow \n");
    }
}
void mainbook(char *login)
{
    char filestd[max] = "student.csv";
    char filebook[max] = "book.csv";
    char filelibrary[max] = "student_books.csv";
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
        printf("2.Delete book.\n");
        printf("3.Borrow book\n");
        printf("4.Return Book.\n");
        printf("5.Search Borrow Book.\n");
        printf("6.Exit.\n");
        scanf("Choose what you want 1,2,3,4,5 or 6!!!\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            addbook(Namefile);
            break;
        case 2:
            deletebook1(Namefile);
            break;
        case 3:
            borrowbook_student(filestd, filebook, filelibrary);
            break;
        case 4:
            returnbook_student(filestd, filebook, filelibrary);
            break;
        case 5:
            searchbook(filestd, filebook, filelibrary);
            break;
        }
        if (a == 6)
            break;
        fflush(stdin);
        fx = fopen("library.log", "a");
        fprintf(fx, "\n\"%s\"", buf);
        fprintf(fx, ",\"%s\"", login);
        if (a == 1)
            fprintf(fx, ",\"Add new book\"");
        else if (a == 2)
            fprintf(fx, ",\"Delete book\"");
        else if (a == 3)
            fprintf(fx, ",\"Borrow book\"");
        else if (a == 4)
            fprintf(fx, ",\"Return book\"");
        else if (a == 5)
            fprintf(fx, ",\"Search book\"");
        else
            break;
        fclose(fx);
    }
}
//end book
//user-part 2
int readuser(char *Namefile)
{

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
            fscanf(f, "%[^,],%[^,],%d,%d", user[i].login, user[i].pass, &user[i].student, &user[i].book);
            i++;
        }
    }
    fclose(f);
    return i;
}
int testuser(char test[size])
{
    int i = readuser("user.csv");
    int k = -1;
    int j;
    for (j = 0; j < i; j++)
    {
        if (strcmp(test, user[j].login) == 0)
            k = j;
    }
    return k;
}
void adduser(char *Namefile)
{
    struct users newb;
    int n;
    int i = 0;
    FILE *f;
    printf("How many user do you want to add? \n");
    scanf("%d", &n);
    f = fopen(Namefile, "a");
    for (i = 0; i < n; i++)
    {
        int k;
        printf("Enter user %d\n", i + 1);
        printf("Enter name account :\n");
        do
        {
            fflush(stdin);
            gets(newb.login);
            k = testuser(newb.login);
            if (k != -1)
            {
                printf("This user is already in the file!!!\n");
                printf("Enter name account:\n");
            }
        } while (k != -1);
        printf("Enter pass : \n");
        fflush(stdin);
        gets(newb.pass);

        printf("Enter student access :\n");
        fflush(stdin);
        scanf("%d", &newb.student);

        printf("Enter book access:");
        fflush(stdin);
        scanf("%d", &newb.book);

        fprintf(f, "%s,%s,%d,%d\n", newb.login, newb.pass, newb.student, newb.book);
    }
    fclose(f);
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
    fprintf(fx, ",\"Creat %d new accounts\"", n);
    fclose(fx);
    printf("Success!!!\n\n");
}
void ReadFile(char *Namefile)
{

    char login[100];
    char pass[100] = "1234";
    char temp[size];
    int i = 0;
    FILE *f;
    struct users data[max];
    f = fopen(Namefile, "rb");
    if (!f)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(f);
        while (fgets(temp, size, f))
        {
            fscanf(f, "%[^,],%[^,],%d,%d", data[i].login, data[i].pass, &data[i].student, &data[i].book);
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
//part 3

int main()
{
    int a;
    for (;;)
    {
        printf("**********MENU**********\n");
        printf("1.Add new account.\n");
        printf("2.Login.\n");
        printf("3.Exit.\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            adduser("user.csv");
            break;
        case 2:
            ReadFile("user.csv");
            break;
        }
        if (a == 3)
            break;
    }

    return 0;
}