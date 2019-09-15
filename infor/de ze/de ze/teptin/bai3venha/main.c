#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>

typedef struct
{
  char ISBNsach[10];
  char sorachotsinhvien[100];
  char ngaytrasach[100];
}sinhvienvasach;

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
  char sorachot[10];
  char ho[100];
  char ten[100];
  char tendem[100];
  char khoa[100];
  char chuyennganh[100];
}sinhvien;
//sinh vien


//

void Searchsinhvienvasach(char *FileName)

{

char ISBNseach[10];
char sorachotseach[100];
char seach[100];
FILE *f;
FILE *fb;
FILE *fc;
int Found=0;

sinhvien arrsinhvien;
thuvien arrtv;

sinhvienvasach arrsinhvienvasach;
fflush(stdin);
printf("Nhap thong tin ma sach hoac so ra chot: ");gets(seach);
// lay thoi gian
FILE *fx;
   // ham thoi gian
    time_t     now;
    struct tm  ts;
    char       buf[80];
    time(&now);
    ts = *localtime(&now);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S", &ts);
    printf("%s\n", buf);

  fflush(stdin);
  fx=fopen("library.log","a");

  fprintf(fx,"\n\"%s\"",buf);
  fprintf(fx,";\"admin\"");
  fprintf(fx,";\"Nhap thong tin: %s\"",seach);

fclose(fx);


//
f=fopen(FileName,"rb");

while (!feof(f))

{

if(f!=NULL){
fscanf(f,"%[^,],%[^,],<<%[^>]>>\n",&arrsinhvienvasach.ISBNsach,&arrsinhvienvasach.sorachotsinhvien,&arrsinhvienvasach.ngaytrasach);
}
if (strcmp(arrsinhvienvasach.ISBNsach,seach)==0)
  {

    printf("\n ISBN sach: %s\nSinh vien muon sach co so ra chot: %s\nNgay tra sach : %s \n\n ",arrsinhvienvasach.ISBNsach,arrsinhvienvasach.sorachotsinhvien,arrsinhvienvasach.ngaytrasach);
// dua ra thong tin cua sinh vien
    fb=fopen("students.csv","rb");

    while (!feof(fb))
     {

    if(fb!=NULL)
    {
fscanf(fb,"%[^,],%[^,],%[^,],%[^,],%[^,],<<%[^>]>>\n",&arrsinhvien.sorachot,&arrsinhvien.ho,&arrsinhvien.ten,&arrsinhvien.tendem,&arrsinhvien.khoa,&arrsinhvien.chuyennganh);
   }
if (strcmp(arrsinhvien.sorachot,arrsinhvienvasach.sorachotsinhvien)==0)
{
    printf("Tim thay sinh vien co sorachot: %s\nHo: %s\nTen : %s. \nTen dem: %s\nKhoa theo hoc: %s \nChuyen nganh theo hoc: %s",arrsinhvien.sorachot,arrsinhvien.ho,arrsinhvien.ten,arrsinhvien.tendem,arrsinhvien.khoa,arrsinhvien.chuyennganh);
}
}

fclose(fb);
//////
}
else if (strcmp(arrsinhvienvasach.sorachotsinhvien,seach)==0)
{
 printf("\nTim thay ISBN sach cho muon: %s\nMa so ra chot %s\nNgay tra sach : %s \n\n ",arrsinhvienvasach.ISBNsach,arrsinhvienvasach.sorachotsinhvien,arrsinhvienvasach.ngaytrasach);
  //// dua ra thong tin cac quyen sach ma sinh vien muon
  //rewind(fc);
  fc=fopen("books.csv","rb");

while (!feof(fc))

{

if(fc!=NULL){
fscanf(fc,"%[^,],%[^,],<<%[^>]>>,%d,%d\n",&arrtv.ISBN,&arrtv.tensach,&arrtv.tacgia,&arrtv.tongsoluong,&arrtv.sochomuon);
}
 if(strcmp(arrtv.ISBN,arrsinhvienvasach.ISBNsach)==0)
{

  printf("Tim thay sach co ma: %s\n Ten sach la: %s\n Tac gia la : %s. \n Tong so luong la:%d\n So luong cho muon la: %d\n",arrtv.ISBN,arrtv.tensach,arrtv.tacgia,arrtv.tongsoluong,arrtv.sochomuon);
}

}

fclose(fc);
}
}
fclose(f);

}
// ham chinh
int main()
{


Searchsinhvienvasach("student_books.csv");

    return 0;
}

