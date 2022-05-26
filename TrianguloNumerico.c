#include<stdio.h>

int main(void){
    int h, i, j;

    printf("Ingrese un numero cualquiera: ");
    scanf("%i", &h);

    for(i=h; i>=1; i--){
       for(j=h; j>= i; j--){
           printf("%i", j);
        }
        printf("\n");
    }   

    return 0;
}
