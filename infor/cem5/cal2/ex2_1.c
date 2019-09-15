#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include <math.h>

#define MAXOP 100  /* макс. размер операнда или оператора */
#define NUMBER '0' /* признак числа */
#define MAXLINE 500  /* макс. размер строки ввода */
#define PI 3.14159265

int getop (char []);
int getl(char [], int);
void push (double);
double pop (void);

char line[MAXLINE];
int line_i;

/* калькулятор с обратной польской записью */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    
    while (getl(line, MAXLINE) != 0) 
    {
        line_i = 0;
        while ((type = getop(s)) != '\0') 
        {
            switch (type) 
            {
                case NUMBER:
                    push (atof(s));
                    break;
                case '+':
                    push (pop() + pop());
                    break;
                case '*':
                    push (pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push (pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push (pop() / op2);
                    else
                        printf("ошибка: деление на нуль\n");
                    break;
                case '^':
                    op2 = pop();
                    push(pow(pop(),op2));
                    break;
                case '%':
                    op2 = pop();
                    if (op2 != 0.0)
                        push ((int)pop() % (int)op2);
                    else
                        printf("ошибка: деление на нуль\n");
                    break;
                case 's':
                    push(sin(pop()*PI /180));
                    break;
                case 'c':
                    push(cos(pop()*PI /180));
                    break;
                case '\n':
                    printf("\t%.8g\n", pop());
                    break;
                default:
                    printf("ошибка: неизвестная операция %s\n", s);
                    break;
            }
        }
    }
    return 0;
}


#define MAXVAL 100  /* максимальная глубина стека */

int sp = 0;         /* следующая свободная позиция в стеке */
double val[MAXVAL]; /* стек */

/* push: положить значение f в стек */ 
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ошибка: стек полон, %g не помещается\n", f);
}

/* pop: взять с вершины стека и выдать в качестве результата */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf ("ошибка: стек пуст\n");
    return 0.0;
    }
}


#include <ctype.h>

/* getop: получает следующий оператор или операнд */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = line[line_i++]) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;  /* не число */
    i = 0;
    if (isdigit(c)) /* накапливаем целую часть */
        while (isdigit(s[++i] = c = line[line_i++]));
    if (c =='.') /* накапливаем дробную часть */
        while (isdigit(s[++i] = line[line_i++]));
    s[i] = '\0';
    line_i--;
    
    return NUMBER;
}

/* getline: читает строку в s, возвращает длину */
int getl(char s[], int lim)
{
    int c, i;
    i = 0;
    
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}