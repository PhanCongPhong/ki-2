#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define size 100
#define max 1000
struct library
{
    char ISBN[size];
    char idstd[size];
    char day[size];
};
struct student
{
    char idstd[size];
    char surname[size];
    char name[size];
    char middlename[size];
    char department[size];
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
void searchstudent(char *filestd, char *filebook, char *filelibrary)
{
    struct student datastd[max];
    struct book databook[max];
    struct library datalbr[max];
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
    fstd = fopen(filestd, "r+");
    int a = 0;
    if (!fstd)
    {
        printf("No file!\n");
    }
    else
    {
        rewind(fstd);
        while (fgets(temp, size, fstd))
        {
            fscanf(fstd, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", datastd[a].idstd, datastd[a].surname, datastd[a].name, datastd[a].middlename, datastd[a].department, datastd[a].major);
            a++;
        }
    }
    fclose(fstd);
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
            fscanf(flbr, "%[^,],%[^,],%[^\n]", datalbr[b].ISBN, datalbr[b].idstd, datalbr[b].day);
            b++;
        }
    }
    fclose(flbr);
    FILE *fbook;
    fbook = fopen(filebook, "r+");
    int c = 0;
    if (!fbook)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(fbook);
        while (fgets(temp, size, fbook))
        {
            fscanf(fbook, "%[^,],%[^,],%[^,],%d,%d]", databook[c].ISBN, databook[c].author, databook[c].namebook, &databook[c].totalbook, &databook[c].access);
            c++;
        }
    }
    x = -1;
    for (j = 0; j < a; j++)
    {
        if (strcmp(searchidstd, datastd[j].idstd) == 0)
            x = j;
    }
    if (x == -1)
    {
        printf("No student in file!!!\n");
    }
    else
    {
        for (j = 0; j < b; j++)
        {
            if (strcmp(datalbr[j].idstd, datastd[x].idstd) == 0)
                k[j] = j;
            else
                k[j] = -1;
        }
        printf("Idstd\tDay\tISBN\t\tAuthor\t\tNamebook\t\tTotalbook\t\tAccess\n");
        test = -1;
        for (j = 0; j < b; j++)
        {
            y = k[j];
            if (y != -1)
            {
                int m = 0;
                for (m; m <= c; m++)
                {
                    if (strcmp(datalbr[y].ISBN, databook[m].ISBN) == 0)
                    {
                        printf("%s\t%s\t%s\t\t%s\t\t%s\t\t%d\t\t%d\n", datastd[x].idstd, datalbr[y].day, databook[m].ISBN, databook[m].author, databook[m].namebook, databook[m].totalbook, databook[m].access);
                        test = 1;
                    }
                }
            }
        }
        if (test == -1)
            printf("This student dont borrow book\n");
    }
}
void searchbook(char *filestd, char *filebook, char *filelibrary)
{
    struct student datastd[max];
    struct book databook[max];
    struct library datalbr[max];
    char searchISBN[size];
    char temp[size];
    int j = 0;
    int x, y, z;
    int k[size];
    int test;
    FILE *fstd;
    printf("Enter ISBN\n");
    fflush(stdin);
    gets(searchISBN);
    fstd = fopen(filestd, "r+");
    int a = 0;
    if (!fstd)
    {
        printf("No file!\n");
    }
    else
    {
        rewind(fstd);
        while (fgets(temp, size, fstd))
        {
            fscanf(fstd, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", datastd[a].idstd, datastd[a].surname, datastd[a].name, datastd[a].middlename, datastd[a].department, datastd[a].major);
            a++;
        }
    }
    fclose(fstd);
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
            fscanf(flbr, "%[^,],%[^,],%[^\n]", datalbr[b].ISBN, datalbr[b].idstd, datalbr[b].day);
            b++;
        }
    }
    fclose(flbr);
    FILE *fbook;
    fbook = fopen(filebook, "r+");
    int c = 0;
    if (!fbook)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(fbook);
        while (fgets(temp, size, fbook))
        {
            fscanf(fbook, "%[^,],%[^,],%[^,],%d,%d]", databook[c].ISBN, databook[c].author, databook[c].namebook, &databook[c].totalbook, &databook[c].access);
            c++;
        }
    }
    x = -1;
    for (j = 0; j < a; j++)
    {
        if (strcmp(searchISBN, databook[j].ISBN) == 0)
            x = j;
    }
    if (x == -1)
    {
        printf("No book in library!!!\n");
    }
    else //co sach
    {
        for (j = 0; j < b; j++)
        {
            if (strcmp(datalbr[j].ISBN, databook[x].ISBN) == 0)
                k[j] = j;
            else
                k[j] = -1;
        }
        test = -1;
        printf("Idstd\tDay\tSurnam\t\tName\t\tMiddlename\t\tDepartment\t\tMajor\n");
        for (j = 0; j < b; j++)
        {
            y = k[j];
            if (y != -1)
            {
                int m = 0;
                for (m; m < c; m++)
                {
                    if (strcmp(datalbr[y].idstd, datastd[m].idstd) == 0)
                    {
                        printf("%s\t%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", datastd[m].idstd, datalbr[y].day, datastd[m].surname, datastd[m].name, datastd[m].middlename, datastd[m].department, datastd[m].major);
                        test = 1;
                    }
                }
            }
        }
        if (test == -1)
            printf("This book is not borrowed");
    }
}
void borrowbook(char *filestd, char *filebook, char *filelibrary)
{
    struct student datastd[max];
    struct book databook[max];
    struct library datalbr[max];
    char searchISBN[size];
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
    fstd = fopen(filestd, "r+");
    int a = 0;
    if (!fstd)
    {
        printf("No file!\n");
    }
    else
    {
        rewind(fstd);
        while (fgets(temp, size, fstd))
        {
            fscanf(fstd, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", datastd[a].idstd, datastd[a].surname, datastd[a].name, datastd[a].middlename, datastd[a].department, datastd[a].major);
            a++;
        }
    }
    fclose(fstd);
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
            fscanf(flbr, "%[^,],%[^,],%[^\n]", datalbr[b].ISBN, datalbr[b].idstd, datalbr[b].day);
            b++;
        }
    }
    fclose(flbr);
    FILE *fbook;
    fbook = fopen(filebook, "r+");
    int c = 0;
    if (!fbook)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(fbook);
        while (fgets(temp, size, fbook))
        {
            fscanf(fbook, "%[^,],%[^,],%[^,],%d,%d]", databook[c].ISBN, databook[c].author, databook[c].namebook, &databook[c].totalbook, &databook[c].access);
            c++;
        }
    }
    fclose(fbook);
    x = -1;
    for (j = 0; j < a; j++)
    {
        if (strcmp(searchidstd, datastd[j].idstd) == 0)
            x = j;
    }
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
            printf("Enter ISBN\n");
            fflush(stdin);
            gets(searchISBN);
            char daybook[size];
            printf("Day?\n");
            fflush(stdin);
            gets(daybook);
            int y = -1;
            for (j = 0; j < c; j++)
            {
                if (strcmp(searchISBN, databook[j].ISBN) == 0)
                    y = j;
            }
            if (y == -1)
            {
                printf("No book \n");
            }
            else
            {
                if (databook[y].access >= 1)
                {
                    fopen(fbook, "w");
                    rewind((fbook));
                    fprintf(fbook, "ISBN,Author,Namebook,Totalbook,Access\n");
                    for (j = 0; j < c - 1; j++)
                    {
                        fprintf(fbook, "%s", databook[j].ISBN);
                        fprintf(fbook, ",%s", databook[j].author);
                        fprintf(fbook, ",%s", databook[j].namebook);
                        fprintf(fbook, ",%d", databook[j].totalbook);
                        if (j == y)
                            fprintf(fbook, ",%d\n", databook[j].access - 1);
                        else
                            fprintf(fbook, ",%d\n", databook[j].access);
                    }
                    fclose(fbook);
                    flbr = fopen(filelibrary, "a");
                    fprintf(flbr, "%s,%s,%s\n", searchISBN, searchidstd, daybook);
                    fclose(flbr);
                }
                if (databook[y].access == 0)
                    printf("All amount of this book have been borrowed!!! \n");
            }
        }
    }
}
void returnbook(char *filestd, char *filebook, char *filelibrary)
{
    struct student datastd[max];
    struct book databook[max];
    struct library datalbr[max];
    char searchISBN[size];
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
    fstd = fopen(filestd, "r+");
    int a = 0;
    if (!fstd)
    {
        printf("No file!\n");
    }
    else
    {
        rewind(fstd);
        while (fgets(temp, size, fstd))
        {
            fscanf(fstd, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", datastd[a].idstd, datastd[a].surname, datastd[a].name, datastd[a].middlename, datastd[a].department, datastd[a].major);
            a++;
        }
    }
    fclose(fstd);
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
            fscanf(flbr, "%[^,],%[^,],%[^\n]", datalbr[b].ISBN, datalbr[b].idstd, datalbr[b].day);
            b++;
        }
    }
    fclose(flbr);
    FILE *fbook;
    fbook = fopen(filebook, "r+");
    int c = 0;
    if (!fbook)
    {
        printf("No file!!!\n");
    }
    else
    {
        rewind(fbook);
        while (fgets(temp, size, fbook))
        {
            fscanf(fbook, "%[^,],%[^,],%[^,],%d,%d]", databook[c].ISBN, databook[c].author, databook[c].namebook, &databook[c].totalbook, &databook[c].access);
            c++;
        }
    }
    fclose(fbook);
    x = -1;
    for (j = 0; j < a; j++)
    {
        if (strcmp(searchidstd, datastd[j].idstd) == 0)
            x = j;
    }
    if (x == -1)
    {
        printf("No student!\n");
    }
    else //co sinh vien
    {
        int n, t = 0;
        printf("How many books do you want to borrow?\n");
        scanf("%d", &n);
        for (t; t < n; t++)
        {
            printf("Enter ISBN\n");
            fflush(stdin);
            gets(searchISBN);
            int y = -1;
            for (j = 0; j < b; j++)
            {
                if (strcmp(searchISBN, datalbr[j].ISBN) == 0 && strcmp(searchidstd, datalbr[j].idstd) == 0)
                    y = j;
            }
            if (y == -1)
            {
                printf("You cant return this book!!!\n");
            }
            else
            {
                fbook = fopen(filebook, "w");
                rewind((fbook));
                fprintf(fbook, "ISBN,Author,Namebook,Totalbook,Access\n");
                for (j = 0; j < c - 1; j++)
                {
                    fprintf(fbook, "%s", databook[j].ISBN);
                    fprintf(fbook, ",%s", databook[j].author);
                    fprintf(fbook, ",%s", databook[j].namebook);
                    fprintf(fbook, ",%d", databook[j].totalbook);
                    if (j == y)
                        fprintf(fbook, ",%d\n", databook[j].access + 1);
                    else
                        fprintf(fbook, ",%d\n", databook[j].access);
                }
                fclose(fbook);
                flbr = fopen(filelibrary, "w");
                rewind((flbr));
                fprintf(flbr, "ISBN,ID std,Day\n");
                for (j = 0; j < b - 1; j++)
                {
                    if (j != y)
                    {
                        fprintf(flbr, "%s", datalbr[j].ISBN);
                        fprintf(flbr, ",%s", datalbr[j].idstd);
                        fprintf(flbr, ",%s\n", datalbr[j].day);
                    }
                }
                fclose(flbr);
            }
        }
    }
}
int main()
{
    char filestd[max] = "students.csv";
    char filebook[max] = "book.csv";
    char filelibrary[max] = "students_book.csv";
    int i = 0;
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
        printf("1.Search student\n");
        printf("2.Search book\n");
        printf("3.Return book\n");
        printf("4.Borrow book\n");
        printf("5.Exit\n");
        scanf("Choose what you want 1,2,3,4 or 5!!!\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            searchstudent(filestd, filebook, filelibrary);
            break;
        case 2:
            searchbook(filestd, filebook, filelibrary);
            break;
        case 3:
            returnbook(filestd, filebook, filelibrary);
            break;
        case 4:
            borrowbook(filestd, filebook, filelibrary);
            break;
        }
        if (a == 5)
            break;
        fflush(stdin);
        fx = fopen("library.log", "a");
        fprintf(fx, "\n\"%s\"", buf);
        if (a == 1)
            fprintf(fx, ",\Search student\"");
        else if (a == 2)
            fprintf(fx, ",\"Search book\"");
        else if (a == 3)
            fprintf(fx, ",\"return book\"");
        else if (a == 4)
            fprintf(fx, ",\"borrow book\"");
        else
            break;
        fclose(fx);
    }
    return 0;
}
