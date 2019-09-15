#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXOP 100
#define number '0'
#define MAXLINE 500
#define PI 3.14159265
char b[MAXLINE];
int j;
int getl(char [],int);
void push(double);
double pop(void);
int getop (char s[]){
    int i,c;
    while((s[0]=c=b[j++])==' '|| c=='\t');
    s[1]='\0';
    if (!isdigit(c) && c!='.') {
        return c;
    }
    i=0;
    if (isdigit(c)) {
        while(isdigit(s[++i]=c=b[j++]));
    }
    if (c=='.') {
        while(isdigit(s[++i]=c=b[j++]));
    }
    s[i]='\0';
    j--;
    return number;
}
int main(){
    int type;
    double op2; char s[MAXOP];
    while(getl(b,MAXLINE)!=0){
        j=0;
        while((type=getop(s))!='\0'){
            switch (type)
            {
                case number:
                    push(atof(s));
                    break;
                case '+':
                    push(pop()+pop());
                    break;
                case '-':
                    op2 = pop();
                    push (pop() - op2);
                    break;
                case '*':
                    push(pop()*pop());
                    break;
               case '/' :
                    op2 = pop();
                    if (op2 != 0.0)
                        push (pop() / op2);
                    else
                        printf("error\n");
                    break;
               case '%' :
                    op2 = pop();
                    if (op2 != 0.0)
                        push ((int)(pop() / op2));
                    else
                        printf("error\n");
                    break;
                case '^':
                    op2 = pop();
                    push(pow(pop(),op2));
                    break;
                case 's':
                    push(sin(pop()*PI /180));
                    break;
                case 'c':
                    push(cos(pop()*PI /180));
                    break;    
                case '\n' :
                    printf("\t%.8g\n", pop());
                    break;
                default:
                  printf("error: unknown command %s\n", s);
                 return -1;}
        }
    }
    return 0;
    }