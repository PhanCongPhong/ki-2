#include <stdio.h>
#include <stdlib.h>
 
void Hex(int n) 
{
    if (n < 16)  
    {
        printf("%c","0123456789ABCDEF"[n]); // hien thi ky tu thu n trong chuoi
        return;
    } 
    else {Hex(n / 16);
    }
    printf("%c","0123456789ABCDEF"[n % 16]);
}
 
int main() {
    int n;
    printf("Enter your number: ");
    scanf("%d", &n);
    printf("Number in hex:");
    Hex(n);
    return 0;
}