#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <conio.h>
#include <time.h>

typedef struct
{
  char login[10];
  char matkhau[100];
  int sach;
  int sinhvien;
}users;

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
//sinh vien
typedef struct
{
  char sorachot[10];
  char ho[100];
  char ten[100];
  char tendem[100];
  char khoa[100];
  char chuyennganh[100];
}sinhvien;

typedef struct
{
  char sorachotmoi[10];
  char homoi[100];
  char tenmoi[100];
  char tendemmoi[100];
  char khoamoi[100];
  char chuyennganhmoi[100];
}sinhvienmoi;

//void ve sinh vien
void WriteFilesinhvien(char *FileName)
{
FILE *f;
    sinhvien arrsinhvien;
    int i,n;
    printf("Nhap thong tin sinh vien!\n");
    printf("Nhap so luong sinh vien n = ");
    scanf("%d",&n);

    f= fopen(FileName,"a");
    //fprintf(f,"ISBN;tensach;tacgia;soluong;soluongchomuon\n");

    for(i=0;i<n;i++)
    {
        printf("Nhap thong tin sinh vien thu %d\n",i+1);

        printf("Nhap ma so ra chot :");
        fflush(stdin);
        gets(arrsinhvien.sorachot);

        printf("Nhap ho : ");
        fflush(stdin);
        gets(arrsinhvien.ho);

        printf("Nhap ten :");
        fflush(stdin);
        gets(arrsinhvien.ten);

        printf("Nhap ten dem :");
        fflush(stdin);
        gets(arrsinhvien.tendem);

        printf("Nhap khoa theo hoc :");
        fflush(stdin);
        gets(arrsinhvien.khoa);

        printf("Nhap nganh theo hoc :");
        fflush(stdin);
        gets(arrsinhvien.chuyennganh);

       fprintf(f,"%s",arrsinhvien.sorachot);
       fprintf(f,",%s",arrsinhvien.ho);
       fprintf(f,",%s",arrsinhvien.ten);
       fprintf(f,",%s",arrsinhvien.tendem);
       fprintf(f,",%s",arrsinhvien.khoa);
       fprintf(f,",%s",arrsinhvien.chuyennganh);

    }

 fclose(f);
 printf("\nBam phim bat ky de tiep tuc!!!\n");
getch();
}

void Searchsinhvien(char *FileName)

{

char ISBNSEACH[10];

FILE *f;

int Found=0;

sinhvien arrsinhvien;

fflush(stdin);

printf("Nhap ma so ra chot de tim thong tin sinh vien: ");gets(ISBNSEACH);

f=fopen(FileName,"rb");

while (!feof(f) && Found==0)

{

if(f!=NULL){
fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],<<%[^>]>>\n",&arrsinhvien.sorachot,&arrsinhvien.ho,&arrsinhvien.ten,&arrsinhvien.tendem,&arrsinhvien.khoa,&arrsinhvien.chuyennganh);
}
if (strcmp(arrsinhvien.sorachot,ISBNSEACH)==0)
{
    Found=1;

}
}

fclose(f);

if (Found == 1)

{printf("Tim thay sinh vien co sorachot %s\n Ho: %s\n Ten : %s. \n Ten dem: %s\n Khoa theo hoc: %s \n Chuyen nganh theo hoc: %s",arrsinhvien.sorachot,arrsinhvien.ho,arrsinhvien.ten,arrsinhvien.tendem,arrsinhvien.khoa,arrsinhvien.chuyennganh);
}
else

printf("Khong tim thay sinh vien co so ra chot %s nhu vay !!!",ISBNSEACH);

printf("\nBam phim bat ky de tiep tuc!!!\n");

getch();

}

void inrahetsinhvien(char *FileName)
{
    int i;
    FILE *f;
    sinhvien arrsinhvien;
    f=fopen(FileName,"rb");
   printf("SORACHOT     HO      TEN      TEN_DEM    KHOA       CHUYEN NGANH\n");
    while (!feof(f))

{
if(f!=NULL){
fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],<<%[^>]>>\n",&arrsinhvien.sorachot,&arrsinhvien.ho,&arrsinhvien.ten,&arrsinhvien.tendem,&arrsinhvien.khoa,&arrsinhvien.chuyennganh);
}

printf("%-12s%-10s%-10s%-10s%-10s%-15s\n",arrsinhvien.sorachot,arrsinhvien.ho,arrsinhvien.ten,arrsinhvien.tendem,arrsinhvien.khoa,arrsinhvien.chuyennganh);


}
    fclose(f);
printf("\nBam phim bat ky de tiep tuc!!!\n");
getch();
}

void xoasinhvien(char *FileName)

{
char ISBNSEACH[10];
int i,n,m;
n=0;
m=1;
FILE *f;

int Found=0;

sinhvien arrsinhvien[100];
sinhvienmoi arrsinhvienmoi[100];

fflush(stdin);

printf("Nhap so ra chot can xoa: ");gets(ISBNSEACH);

f=fopen(FileName,"rb");

while (!feof(f) && Found==0)

{

if(f!=NULL){
 n=n+1;
fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],<<%[^>]>>\n",&arrsinhvien[n].sorachot,&arrsinhvien[n].ho,&arrsinhvien[n].ten,&arrsinhvien[n].tendem,&arrsinhvien[n].khoa,&arrsinhvien[n].chuyennganh);

}
if (strcmp(arrsinhvien[n].sorachot,ISBNSEACH)==0) Found =1;
}
fclose(f);

if (Found == 1)

{
printf("Tim thay sinh vien co sorachot %s\n Ho: %s\n Ten : %s. \n Ten dem: %s\n Khoa theo hoc: %s \n Chuyen nganh theo hoc: %s",arrsinhvien[n].sorachot,arrsinhvien[n].ho,arrsinhvien[n].ten,arrsinhvien[n].tendem,arrsinhvien[n].khoa,arrsinhvien[n].chuyennganh);

rewind(f);
f=fopen(FileName,"rb");
while (!feof(f))

{

if(f!=NULL){

fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^,],<<%[^>]>>\n",&arrsinhvienmoi[m].sorachotmoi,&arrsinhvienmoi[m].homoi,&arrsinhvienmoi[m].tenmoi,&arrsinhvienmoi[m].tendemmoi,&arrsinhvienmoi[m].khoamoi,&arrsinhvienmoi[m].chuyennganhmoi);

}
//if(feof(f)) break;
m=m+1;
}
fclose(f);

f= fopen("students.csv","wt");
      for (i=1;i<m;i++){
            if(i!=n){
       fprintf(f,"%s",arrsinhvienmoi[i].sorachotmoi);
       fprintf(f,",%s",arrsinhvienmoi[i].homoi);
       fprintf(f,",%s",arrsinhvienmoi[i].tenmoi);
       fprintf(f,",%s",arrsinhvienmoi[i].tendemmoi);
       fprintf(f,",%s",arrsinhvienmoi[i].khoamoi);
       fprintf(f,",<<%s>>\n",arrsinhvienmoi[i].chuyennganhmoi);
      }}
   fclose(f);
}
else
printf("Tim khong thay sinh vien co ma %s !!!",ISBNSEACH);

printf("\nBam phim bat ky de tiep tuc!!!\n");
getch();
}

void mainsinhvien(char *FileName)
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
        printf("1. Nhap thong tin sinh vien moi \n");

        printf("2. Dua ra thong tin toan bo sinh vien \n");

        printf("3. Tim kiem sinh vien \n");

		printf("4. Xoa \n");

        printf("0. Tro lai menu ban dau \n");

       printf("Ban chon 1, 2, 3, 4, 0 : "); scanf("%d",&c);

if(c==1)
    WriteFilesinhvien("students.csv");
else if(c==2)
    inrahetsinhvien("students.csv");
else if(c==3)
    Searchsinhvien("students.csv");
else if(c==4)
	xoasinhvien("students.csv");
else if (c==0)
{
 ReadFile("users.csv");
}
else break;

 // danh sach hoat dong
fflush(stdin);
fx=fopen("library.log","a");

  fprintf(fx,"\n\"%s\"",buf);
  fprintf(fx,";\"admin\"");
  if(c==1)
    fprintf(fx,";\"Nhap thong tin sinh vien moi\"");
  else if(c==2)
    fprintf(fx,";\"Dua ra toan bo sinh vien\"");
  else if(c==3)
    fprintf(fx,";\"Tim kiem sinh vien\"");
  else if(c==4)
    fprintf(fx,";\"Xoa\"");
  else break;

    }
fclose(fx);

}
//////void thu vien sach

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
    fprintf(f,"\n%s",arrtv.ISBN);
       fprintf(f,",%s",arrtv.tensach);
       fprintf(f,",%s",arrtv.tacgia);
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

{printf("Tim thay sach co ma %s\n Ten sach la: %s\n Tac gia la : %s. \n Tong so luong la:%d\n So luong cho muon la: %d",arrtv[n].ISBN,arrtv[n].tensach,arrtv[n].tacgia,arrtv[n].tongsoluong,arrtv[n].sochomuon);

rewind(f);
f=fopen(FileName,"rb");
while (!feof(f))

{

if(f!=NULL){

fscanf(f,"%[^,],%[^,],<<%[^>]>>,%d,%d\n",&arrmoi[m].ISBNmoi,&arrmoi[m].tensachmoi,&arrmoi[m].tacgiamoi,&arrmoi[m].tongsoluongmoi,&arrmoi[m].sochomuonmoi);

}
//if(feof(f)) break;
m=m+1;
}
fclose(f);

/////
f= fopen("books.csv","wt");
      for (i=1;i<m;i++){
            if(i!=n){
       fprintf(f,"%s",arrmoi[i].ISBNmoi);
       fprintf(f,",%s",arrmoi[i].tensachmoi);
       fprintf(f,",%s",arrmoi[i].tacgiamoi);
       fprintf(f,",%d",arrmoi[i].tongsoluongmoi);
       fprintf(f,",%d\n",arrmoi[i].sochomuonmoi);
      }}
   fclose(f);
}
else
printf("Tim khong thay sinh vien co ma %s",ISBNSEACH);

printf("\nBam phim bat ky de tiep tuc!!!\n");
getch();
}

void mainthuvien(char *FileName)
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

        printf("0. Tro lai menu ban dau\n");

       printf("Ban chon 1, 2, 3, 4, 0 : "); scanf("%d",&c);

if(c==1)
    WriteFile("books.csv");
else if(c==2)
    inrahet("books.csv");
else if(c==3)
    Search("books.csv");
else if(c==4)
	xoa("books.csv");
else if (c==0)
{
 ReadFile("users.csv");
}
else break;

 // danh sach hoat dong
fflush(stdin);
fx=fopen("library.log","a");

  fprintf(fx,"\n\"%s\"",buf);
  fprintf(fx,";\"admin\"");
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

}

////
void ReadFile(char *FileName)
{

	char loginnhap[100];
	char matkhaunhap[100];
    FILE *f;
    int Found=0;

    users arrusers;

    fflush(stdin);

  printf("Vui long nhap tai khoan : ");gets(loginnhap);
  printf("Vui long nhap mat khau : ");gets(matkhaunhap);

f=fopen(FileName,"rb");

while (!feof(f) && Found==0)

{

if(f!=NULL){
fscanf(f,"%[^,],%[^,],%d,%d\n",&arrusers.login,&arrusers.matkhau,&arrusers.sach,&arrusers.sinhvien);
}
if (strcmp(arrusers.login,loginnhap)==0 && strcmp(arrusers.matkhau,matkhaunhap)==0 ) Found=1;

}

fclose(f);

if (Found == 1)
{
printf("Chuc mung!!!Ban da dang nhap thanh cong!!!\n");
printf("Duong dan toi sach : %d \n",arrusers.sach);
printf("Duong dan toi sinh vien : %d \n",arrusers.sinhvien);

if(arrusers.sach==1 && arrusers.sinhvien==0 )
{
printf("\nCHAO MUNG TOI THU VIEN SACH!!!\n");
 mainthuvien("books.csv");
}

else if (arrusers.sinhvien==1 && arrusers.sach==0 )
{
printf("\nCHAO MUNG BAN TOI DANH SACH SINH VIEN!!!\n");
mainsinhvien("students.csv");
}

else if(arrusers.sach==1 && arrusers.sinhvien==1 )
{
int c;
for(;;)
     {
       printf("1. SACH \n");
       printf("2. SINH VIEN \n");
       printf("3. THOAT \n");
       printf("Ban chon 1, 2, 3 : "); scanf("%d",&c);

       if(c==1)
       {
        printf("\nCHAO MUNG TOI THU VIEN SACH!!!\n");
        mainthuvien("books.csv");
       }
       else if(c==2)
       {
       printf("\nCHAO MUNG BAN TOI DANH SACH SINH VIEN!!!\n");
       mainsinhvien("students.csv");
       }
       else break;
     }
}

else
printf("Ban dang dang nhap khong thanh cong!!!");

}
}
// ham chinh
int main()
{
  ReadFile("users.csv");
    return 0;
}
