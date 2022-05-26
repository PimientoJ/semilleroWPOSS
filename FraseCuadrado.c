#include <stdio.h>
#include <string.h>

int main(void){
    char frase[30+1];
    int i,j,k;
    
    printf("Ingrese una frase cualquiera: ");
 		
    scanf("%[^\n]s",&frase);
    printf("%s\n", frase);

    int cantidad=strlen(frase); 

        for (j=0; j < cantidad; j++)
        {
        	
        	if(cantidad-j>2)
		  {
        	
        	printf("%c",frase[j+1]);
        	for(k=0;k<cantidad-2; k++)
			{
        		printf(" ");
			}
			
			printf("%c\n",frase[cantidad-j-2]);			
			
		
				
		}	

     }

     for(i=cantidad-1; i >= 0; i--){
         printf("%c", frase[i]);
     }
     
    return 0;

}
