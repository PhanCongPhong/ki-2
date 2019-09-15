#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
int main ()
{
    time_t     now;
    struct tm  ts;
    char       buf[80];
    time(&now);
    ts = *localtime(&now);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S", &ts);
    printf("%s\n", buf);
    getch();
    return 0;
}
