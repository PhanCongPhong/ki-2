#include <stdio.h>
int main (){
     int c,last,i;
     last=getchar();
       i=1;
    while((c=getchar()) !=EOF && c!='\n')  {
    i++;
     if(c==last){ 
        if(i==3){
              for( int j=0; j<3; j++){
                  putchar(c);
                     }
                 }else if(i>3){
                         putchar(c);
                        } else{
                   if(i>2){ putchar('\n');
                           }
                           i=1;}
                              last=c;
                   } 
         putchar('\n');
                       return 0;
}
}
