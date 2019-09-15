#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

typedef struct
{
  char ISBN[10];
  char tensach[100];
  char tacgia[100];
  int tongsoluong;
  int sochomuon;
}thuvien;

typedef struct
{
  char ISBNmoi[10];
  char tensachmoi[100];
  char tacgiamoi[100];
  int tongsoluongmoi;
  int sochomuonmoi;
}thuvienmoi;



void WriteFile(char *FileName)
{
FILE *f;
    thuvien arrtv;
    int i,n;
    printf("Nhap thong tin cho sach!\n");
    printf("Nhap so loai sach se them vao thu vien n =");
    scanf("%d",&n);

    f= fopen(FileName,"a");
    //fprintf(f,"ISBN;tensach;tacgia;soluong;soluongchomuon\n");

    for(i=0;i<n;i++)
    {
        printf("Nhap thong tin loai sach thu %d\n",i+1);

        printf("Nhap ma sach ISBN :");
        fflush(stdin);
        gets(arrtv.ISBN);


        printf("Nhap ten sach : ");
        fflush(stdin);
        gets(arrtv.tensach);


        printf("Nhap ten tac gia :");
        fflush(stdin);
        gets(arrtv.tacgia);


        printf("Nhap so luong sach nay co trong thu vien :");
        scanf("%d",&arrtv.tongsoluong);
        fflush(stdin);


        printf("Nhap so luong sach hoc sinh da muon :");
        scanf("%d",&arrtv.sochomuon);
        fflush(stdin);
        fprintf(f,"\n");
       fprintf(f,"%s",arrtv.ISBN);
       fprintf(f,",%s",arrtv.tensach);
       fprintf(f,",<<%s>>",arrtv.tacgia);
       fprintf(f,",%d",arrtv.tongsoluong);
       fprintf(f,",%d",arrtv.sochomuon);


    }

 fclose(f);
 printf("\nBam phim bat ky de tiep tuc!!!\n");
getch();
}

void Search(char *FileName)

{

char ISBNSEACH[10];

FILE *f;

int Found=0;

thuvien arrtv;

fflush(stdin);

printf("ISBN can tim: ");gets(ISBNSEACH);

f=fopen(FileName,"rb");

while (!feof(f) && Found==0)

{

if(f!=NULL){
fscanf(f,"%[^,],%[^,],<<%[^>]>>,%d,%d\n",&arrtv.ISBN,&arrtv.tensach,&arrtv.tacgia,&arrtv.tongsoluong,&arrtv.sochomuon);
}
if (strcmp(arrtv.ISBN,ISBNSEACH)==0) Found=1;

}

fclose(f);

if (Found == 1)

printf("Tim thay sach co ma %s\n Ten sach la: %s\n Tac gia la : %s. \n Tong so luong la:%d\n So luong cho muon la: %d",arrtv.ISBN,arrtv.tensach,arrtv.tacgia,arrtv.tongsoluong,arrtv.sochomuon);

else

printf("Khong tim thay sach co ma %s nhu vay !!!",ISBNSEACH);

printf("\nBam phim bat ky de tiep tuc!!!\n");

getch();

}

void inrahet(char *FileName)
{
    int i;
    FILE *f;
    thuvien arrtv;
    f=fopen(FileName,"rb");
    printf("ISBN   TENSACH              TACGIA                TONGSOSACH  SOCHOMUON \n");
    while (!feof(f))

{
if(f!=NULL){
fscanf(f,"%[^,],%[^,],<<%[^>]>>,%d,%d\n",&arrtv.ISBN,&arrtv.tensach,&arrtv.tacgia,&arrtv.tongsoluong,&arrtv.sochomuon);
}

printf("%-7s%-20s%-25s%-15d%-10d\n",arrtv.ISBN,arrtv.tensach,arrtv.tacgia,arrtv.tongsoluong,arrtv.sochomuon);


}
    fclose(f);
printf("\nBam phim bat ky de tiep tuc!!!\n");
getch();
}

void xoa(char *FileName)

{
char ISBNSEACH[10];
int i,n,m;
n=0;
m=1;
FILE *f;
FILE *fb;

int Found=0;

thuvien arrtv[100];
thuvienmoi arrmoi[100];

fflush(stdin);

printf("ISBN can xoa: ");gets(ISBNSEACH);

f=fopen(FileName,"rb");

while (!feof(f) && Found==0)

{

if(f!=NULL){
 n=n+1;
fscanf(f,"%[^,],%[^,],<<%[^>]>>,%d,%d\n",&arrtv[n].ISBN,&arrtv[n].tensach,&arrtv[n].tacgia,&arrtv[n].tongsoluong,&arrtv[n].sochomuon);

}
if (strcmp(arrtv[n].ISBN,ISBNSEACH)==0) Found =1;
}
fclose(f);

if (Found == 1)

{printf("Tim thay sach co ma %s\n Ten sach la: %s\n Tac gia la : %s \n Tong so luong la:%d\n So luong cho muon la: %d",arrtv[n].ISBN,arrtv[n].tensach,arrtv[n].tacgia,arrtv[n].tongsoluong,arrtv[n].sochomuon);

rewind(f);
f=fopen("books.csv","rb");
while (!feof(f))

{

if(f!=NULL){

fscanf(f,"%[^,],%[^,],<<%[^>]>>,%d,%d\n",&arrmoi[m].ISBNmoi,&arrmoi[m].tensachmoi,&arrmoi[m].tacgiamoi,&arrmoi[m].tongsoluongmoi,&arrmoi[m].sochomuonmoi);

}
//if(feof(f)) break;
m=m+1;
}
fclose(f);
//
fb= fopen("books.csv","wt");
      for (i=1;i<m;i++){
            if(i!=n){
       fprintf(fb,"%s",arrmoi[i].ISBNmoi);
       fprintf(fb,",%s",arrmoi[i].tensachmoi);
       fprintf(fb,",<<%s>>",arrmoi[i].tacgiamoi);
       fprintf(fb,",%d",arrmoi[i].tongsoluongmoi);
       fprintf(fb,",%d\n",arrmoi[i].sochomuonmoi);
      }}
   fclose(fb);
}
else
printf("Tim khong thay sinh vien co ma %s",ISBNSEACH);

printf("\nBam phim bat ky de tiep tuc!!!\n");
getch();
}

int main()
{

   FILE *fx;
   // ham thoi gian
    time_t     now;
    struct tm  ts;
    char       buf[80];
    time(&now);
    ts = *localtime(&now);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S", &ts);
    printf("%s\n", buf);
    //
    int c;
    for (;;)
    {
        printf("1. Nhap sach moi \n");

        printf("2. Dua ra thong tin sach \n");

        printf("3. Tim kiem sach \n");

		printf("4. Xoa \n");

        printf("5. Thoat\n");

       printf("Ban chon 1, 2, 3, 4, 5 : "); scanf("%d",&c);

if(c==1)
    WriteFile("books.csv");
else if(c==2)
    inrahet("books.csv");
else if(c==3)
    Search("books.csv");
else if(c==4)
	xoa("books.csv");
else break;


// danh sach hoat dong
fflush(stdin);
fx=fopen("library.log","a");

  fprintf(fx,"\n\"%s\"",buf);
  if(c==1)
    fprintf(fx,";\"Nhap danh sach moi\"");
  else if(c==2)
    fprintf(fx,";\"Dua ra toan bo danh sach\"");
  else if(c==3)
    fprintf(fx,";\"Tim kiem\"");
  else if(c==4)
    fprintf(fx,";\"Xoa\"");
  else break;

    }
fclose(fx);
//
    return 0;
}
