#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int ISBN;
  char tensach[100];
  char tacgia[100];
  int tongsoluong;
  int sochomuon;
}thuvien;

int main()
{
    FILE *f;
    thuvien arrtv;
    int i,n;
    printf("Nhap thong tin cho sach!\n");
    printf("Nhap so loai sach se them vao thu vien n =");
    scanf("%d",&n);

    // trong tep tinf
    f= fopen("bandanhsach.csv","a");
    //fprintf(f,"ISBN;tensach;tacgia;soluong;soluongchomuon\nx");
    //fwrite(&arrtv[i];sizeof(int),1,f);
    //nhap
    for(i=0;i<n;i++)
    {
        printf("Nhap thong tin loai sach thu %d\n",i+1);

        printf("Nhap ma sach ISBN :");
        fflush(stdin);
        scanf("%d",&arrtv.ISBN);


        printf("Nhap ten sach : ");
        fflush(stdin);
        gets(arrtv.tensach);
        //fgets(arrtv[i].tensach,100,f);

        printf("Nhap ten tac gia :");
        fflush(stdin);
        gets(arrtv.tacgia);
        //fgets(arrtv[i].tacgia,100,f);

        printf("Nhap so luong sach nay co trong thu vien :");
        scanf("%d",&arrtv.tongsoluong);
        fflush(stdin);
        //fgets(arrtv[i].tongsoluong,256,f);

        printf("Nhap so luong sach hoc sinh da muon :");
        scanf("%d",&arrtv.sochomuon);
        fflush(stdin);
       // fgets(arrtv[i].sochomuon,256,f);
       fprintf(f,"\n%d",arrtv.ISBN);
       fprintf(f,";%s",arrtv.tensach);
       fprintf(f,";%s",arrtv.tacgia);
       fprintf(f,";%d",arrtv.tongsoluong);
       fprintf(f,";%d",arrtv.sochomuon);
    }

 fclose(f);
  
 // tim sach theo ma
 int ISBNnhap,j;
 f=fopen("bangdanhsach.csv","r");
 //fread(&n,sizeof(int),1,f);
 printf("\n nhap vao ma sach ISBNnhap=");
 scanf("%d",&ISBNnhap);
 for (j=0;j<=n;i++ )
 {
     //fread(&arrtv.ISBN,sizeof(int),1,f);
     fscanf(f,"%d",&arrtv.ISBN);
     if(ISBNnhap==arrtv.ISBN)
     {
         printf("TIM THAY LOAI SACH :%s\n",arrtv.tensach);
         printf("TAC GIA :%s",arrtv.tacgia);
     }
 }
 fclose(f);

 return 0;
}

