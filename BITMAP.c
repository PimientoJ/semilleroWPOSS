#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void Vista(int x, int y , int numb[]);
void EstructuraGotoxy(int a, int b);
int Calcular(int valor, int recorrer, int fin, int numb[]);

int numb[64];


int main(){ 
   char numh[17];
   int valor;
   int size, e=0, fin=0, recorrer=3, a=4, b=2, c=0;
   int d=0; 

   do{
      system("cls");
      printf("\t BIENVENIDOS \n");
      printf("\t\t =========== \n");
      printf("Ingresar un numero hexadecimal:");
      gets(numh);
      system("cls");
      size = strlen(numh);
      //Convertir la cadena en mayusculas
      int inicio;
      for (inicio = 0; numh[inicio] != '\0'; ++inicio){
		numh[inicio] = toupper(numh[inicio]);
	   }
      
     while(e<size){

        switch(numh[e]){
           case 'A':
            valor=10;
            Calcular(valor, recorrer, fin, numb);
            fin=fin+4;
            recorrer=recorrer+4;
            d=0;
            break;
            
            case 'B':
            valor=11;
            Calcular(valor, recorrer, fin, numb);
            fin=fin+4;
            recorrer=recorrer+4;
            d=0;
            break;

            case 'C':
            valor=12;
            Calcular(valor, recorrer, fin, numb);
            fin=fin+4;
            recorrer=recorrer+4;
            d=0;
            break;

            case 'D':
            valor=13;
            Calcular(valor, recorrer, fin, numb);
            fin=fin+4;
            recorrer=recorrer+4;
            d=0;
            break;

            case 'E':
            valor=14;
            Calcular(valor, recorrer, fin, numb);
            fin=fin+4;
            recorrer=recorrer+4;
            d=0;
            break;

            case 'F':
            valor=15;
            Calcular(valor, recorrer, fin, numb);
            fin=fin+4;
            recorrer=recorrer+4;
            d=0;
            break;

            default:

             if(numh[e]>='0' && numh[e]<='9'){
                  	valor=numh[e]-'0';
		            Calcular(valor, recorrer, fin, numb);
		            fin=fin+4;
		            recorrer=recorrer+4;
		            d=0;
               }
               else {
                  e=size;
                  d= 1;
                  b=b+4;            
               }
                break;
        }
        e++;     
       } 
              
   }while (d==1); 
   Vista(a,b,numb);
   printf("\n\n\tnumero hexadecimal: %s", numh);
    return 0;
} 

int Calcular(int valor, int recorrer, int fin, int numb[]){
	
	int e=recorrer;
	while(e>=fin){	
		numb[e]=valor%	2;
		valor = valor/2;  
		e--;
	}
	return *numb;
}

void EstructuraGotoxy (int x, int y) {
	HANDLE hcon;
	COORD dwPos;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos);
}
void Vista(int x, int y , int numb[]){
	
	int x1=0, y1=y;
	int li=y+16;
	
	while(x1<64){
		if(numb[x1]==0){
			EstructuraGotoxy(x,y);
			printf("\t  bit 0%d ",x1+1);
			y++;
		}else{
			EstructuraGotoxy(x,y);
			printf("\t%c bit 0%d ", 16,x1+1); 
			y++;
		}
		if(y==li){
			x=x+25;
			y=y1;			
		}
		x1++;
	}

   
}
