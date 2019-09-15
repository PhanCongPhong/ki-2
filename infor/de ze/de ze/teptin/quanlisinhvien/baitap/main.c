#include <stdio.h>
#include <stdlib.h>

   typedef struct
    {
        char hoten[100];
        char quequan[100];
        int namsinh;
    }sinhvien;

  int main()
  {
      printf("kieu struct trong c !!!");
       int i;
      sinhvien arrsv[100];
      int n;
      printf("\nso luong sinh vien n= ");
      scanf("%d",&n);
      printf("thong tin cho tung sinh vien : \n");
      for(i=0;i<n;i++)
      {
          printf("\n Nhap thong tin cho sinh vien thu %d :",i+1);

          printf("\n Nhap ho ten : ");
          fflush(stdin);
          gets(arrsv[i].hoten);

          printf("\n Nhap que quan : ");
          fflush(stdin);
          gets(arrsv[i].quequan);

          printf("nhap nam sinh :");
          int tg=0;
          scanf("%d",&tg);
          arrsv[i].namsinh=tg;
      }
      printf("\n Danh sach sinh vien vua nhap la :");
      for(i=0;i<n;i++)
      {
        printf("SV%d- Hoten:%s, Que quan :%s,Nam sinh:%d",i+1,
               arrsv[i].hoten,arrsv[i].quequan,arrsv[i].namsinh);
      }

    return 0;
}
