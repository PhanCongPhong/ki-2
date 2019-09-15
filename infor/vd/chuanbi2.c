#include <stdio.h>
#include <stdlib.h>
int *xArr(int sizeArr){
    int *arrInt =(int*)calloc(sizeArr,sizeof(int)); 
    for (int i = 0; i < sizeArr; ++i)
    {
        *(arrInt + i)= i * i;
    }
    return arrInt;
}
int main(){
	int sizeArr =0;
	int *arrInt;
	scanf("%d", &sizeArr);
	arrInt=xArr(sizeArr);
    
    for (int i = 0; i < sizeArr; ++i)
    {
    	printf("arrInt[%d]=%d\n",i, *(arrInt +i) );
    }
    free(arrInt);
	return 0;

}