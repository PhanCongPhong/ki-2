#include <malloc.h> 
#include <stdio.h> 

int search(int a, int mass[], int n); 
void Sort(int n, int mass[]); 

int main() 
{ 
int N, a,x; 

scanf("%d ", &N); 
printf("\n"); 
scanf("%d ",&x); 
int* mass; 
mass = (int *)malloc(N * sizeof(int)); 

int i; 
for (i = 0; i < N; i++) 
scanf("%d", &mass[i]); 
Sort(N, mass); 
for (i = 0; i < N; i++){ 
if(mass[i]>x) { 

printf("%d ", mass[i]); 

} 
} 
return 0; 
} 


void Sort(int n, int mass[]) 
{ 
int newElement, location; 
int i; 
for (i = 1; i < n; i++) 
{ 
newElement = mass[i]; 
location = i - 1; 
while (location >= 0 && mass[location] > newElement) 
{ 
mass[location + 1] = mass[location]; 
location = location - 1; 
} 
mass[location + 1] = newElement; 
} 
}