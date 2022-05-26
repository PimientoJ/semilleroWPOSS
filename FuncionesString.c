#include<stdio.h>

	int myStrlen(char *cadena); //Función myStrlen declarada
	char* myStrcat (char *cadena, char *segunda); //Función myStrcat declarada
	char* myStrcpy (char *tercer, char *cadena); //Funcion myStrcpy declarada
	char* myStrncat (char *cadena, char *segunda, int valor); //Función myStrncat declarada 
	char* myStrncpy (char *cadena, char *tercer1, int valor); //Función myStrncpy declarada
	int myStrcmp (char *cadena, char *segunda); //Función myStrcmp declarada
	int myStrncmp (char *cadena, char *segunda, int valor); //Función myStrncmp declarada
	
	//Variables Globales
	char cadena[100], segunda[100];
	int valor=4;
	int resultado;


	//Función myStrlen
	int myStrlen(char *cadena) {
	  if (*cadena == '\0') 
	    return 0;
	
	  return (1 + myStrlen(++cadena));
	}

	//Función myStrcat
	char* myStrcat (char *cadena, char *segunda){

	while(*cadena)
	    cadena++;
	while(*segunda) {
	        *cadena = *segunda;
	        segunda++;
	        cadena++;
	     }
	*cadena = '\0';
	
	 return cadena;
	}

	//Funcion Strcpy
	char* myStrcpy (char *tercer, char *cadena){
	while (*cadena)
	{
    	*tercer = *cadena;
   		cadena++;
      	tercer++;
    }
    *tercer= '\0';   
    return tercer;		
		}

	//Funcion Strncat
	char* myStrncat (char *cadena, char *segunda, int valor){
  	int i = 0;
 		while (*cadena)
		 {
   			cadena++;   
  		 }
  			while(i<valor) 
			  {
    			*cadena = *segunda;
    			segunda++;
    			cadena++;
    			i++;
 			  }
  	*cadena = '\0';
 
 	return segunda;
	}

	//Quinta Función
	char* myStrncpy (char *cadena, char *tercer1, int valor){
		int i=0;
			while(i<valor)
			{
				*tercer1=*cadena;
				cadena++;
				tercer1++;
				i++;
			}
		tercer1='\0';		
		return tercer1;
	}

	//Sexta función
	int myStrcmp (char *cadena, char *segunda){
		    while (*cadena == *segunda){
        if(*cadena == '\0' || *segunda == '\0'){
        	printf("Las palabras son iguales ");
        	return 0;
            break;
        }
        cadena++;
        segunda++;    
    }
	    if (*cadena < *segunda ){
	    	printf("La palabra son diferentes");
	        return -1;
	    }
				else
				{
			    	printf("La palabra son diferentes!");
			        return 1;  
			    }

	}

	//Fución myStrncmp
	int myStrncmp (char *cadena, char *segunda, int valor){
	int i;
	  for(i=0; i < valor; i++){
	        if(segunda[i] > cadena[i]){
	          return -1;     
	        }else if(segunda[i] < cadena[i]){
	          return 1;
	        }
	    return 0;
	  }
}

	int main(){
		
		//primera función	
		printf("primera funcion \n");
		printf("ingresar una cadena: ");
		gets(cadena);
		printf("la cantidad de caracteres de la cadena es de: %i", myStrlen(cadena));
		
		//segunda función
		printf("\n prueba de la segunda funcion \n ");
		printf("ingresa una palabra: ");
		gets(cadena);
		printf("ingresa una segunda palabra: ");
		gets(segunda);
		strcat(cadena, segunda);
		printf("La union de sus dos palabras palabras son las siguietes: %s\n", cadena);

		//tercera funcion
		printf("prueba de la tercera funcion \n");
	   	char tercer[100];
	  	printf("Digite una palabra cualquiera: ");
	   	gets(cadena);
	   	myStrcpy(tercer, cadena);
	   	printf("su palabra copiada es: %s\n", tercer);

		//Cuarta función
		printf("Prueba de la cuarta funcion");
		printf("\nIngresar ua cadena: ");
		gets(cadena);
		printf("\nIngrese otra cadena: ");
		gets(segunda);
		myStrncat(cadena,segunda,valor);
		printf("%s\n%s\n",cadena,segunda);
	
		//Quinta función
		char tercer1[100];
		printf("Prueba de la quinta funcion");
		printf("\n Digite una palabra: ");
		gets(cadena);
		myStrncpy(cadena, tercer1, valor);
		printf(" %s\n%s\n", cadena, tercer1);

	    //sexta función
		printf("Prueba de la sexta funcion");
		printf("\nPrimera palabra: ");
		gets(cadena);
		printf("Segunda palabra: ");
		gets(segunda);
		
		myStrcmp(cadena, segunda);
		resultado = myStrcmp(cadena, segunda);
		printf("%i\n", resultado);
	
		//Septima función
		printf("Prueba de la septima función");
	    printf("\nPrimera palabra:");
	    gets(cadena);
	    printf("Segunda palabra:");
	    gets(segunda);
	    myStrncmp(cadena, segunda, valor);
	
	    resultado = myStrncmp(cadena, segunda, valor);
	     printf("%i\n", resultado);
	
	    if(resultado == 0){
	       printf("Las palabras son exactamente iguales");
	    }else if(resultado == 1){
	      printf("Las primera palabra es mayor que la segunda palabra");
	    }else{
	     printf("Las primera palabra es menor que la segunda palabra");
	    }
	    

		return 0;		
	}




