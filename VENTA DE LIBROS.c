	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	


	typedef struct book_data{
	    char nombre[30];
	    int precio; 
	    int cantidad;
	}Libro;
	Libro libro[6]={{"Las luces de Septiembre", 24000, 0},                           
	            	{"El principe de la Niebla", 28000, 0},
	            	{"El Palacio de Medianoche", 45000, 0},
	            	{"Marina", 15000, 0},
	            	{"La Sombra del Viento", 27000, 0},
	            	{"El Juego del Angel", 30000, 0}};
	


	typedef struct booth_data{
	    char nombre[20];
	    int cantidad; 
	    int total; 
	}Caseta;
	Caseta caseta[3]={{"Caseta 1", 0, 0},                           
	            	  {"Caseta 2", 0, 0},
	            	  {"caseta 3", 0, 0}};
	
	Libro numL; 
	Caseta numC; 
	
	
	void menuPrincipal();
	void Opciones(char opcion, int repetir);
	void RealizarVenta();
	void SelecccionarLibro(int caseta);
	void ImprimirVenta();
	void GuardarValor(int casetas, int libros);
	void VentaCaseta();
	void FiltroLibro();
	void FiltroCaseta();
	
	int main(){
	    menuPrincipal();
		return 0;
	}


	void menuPrincipal(){
	    char opcion;
	    int repetir;	
		do{
			system("cls");
		    printf("\tBIENVENIDOS A LA VENTA DE LIBROS\n");
		     printf("\t================================\n");
		    printf("\n");
		    printf(" [1]. Realizar venta\n");
		    printf(" [2]. Imprimir ventas\n");
		    printf(" [0]. Salir");
		    printf("\n");
		    printf("Ingrese una opcion: ");
		    scanf ("%c", &opcion);
		    
		    if(opcion == '1' || opcion == '2' || opcion == '0'){
		    	 Opciones(opcion, repetir);
		    	 break;
			}else{
				repetir=1;
			}  	   
		}while(repetir==1);
	}

	void Opciones(char opcion, int repetir){
		 switch (opcion) {
	                case '1':
	                RealizarVenta();
	                break;
	
	                case '2': 
	                ImprimirVenta();
	                break;
	                
	                case '0':
	                repetir = 0;
	                break;
	                        
	            }
	}


	void RealizarVenta(int numValor, int numcantidad, int cantidadLibro){
	char opcion; 
	int repetir;
	int caseta;
	
	   do{
	       system("cls");
	       printf("\nSeleccione la caseta:");
	       printf("\b\n [1]. Caseta N%c1 \n [2]. Caseta N%c2 \n [3]. Caseta N%c3 \n [4]. Salir \n ", 248, 248, 248); 
	       printf("\n Digite una opcion: ");
	       scanf("%c", &opcion);
	
	       if(opcion == '1') { 
	           caseta = 1;
	           SelecccionarLibro(caseta);
	           break;
	       }if(opcion == '2'){
	           caseta = 2;
	           SelecccionarLibro(caseta);
	           break;
	       }if(opcion == '3'){
	           caseta = 3;
	           SelecccionarLibro(caseta);
	           break;
	       }if(opcion == '4'){
	           menuPrincipal(numValor, numcantidad, cantidadLibro);
	           break;
	       }else{
	           repetir = 1;
	       }
	   }while(repetir == 1);
	}


	void SelecccionarLibro(int caseta){
	    char opcion; 
	    int repetir;
	    int libro;    
	    do{
	        system("cls");
	        printf("\n Seleccione el libro a comprar:\n");
	        printf("\b [1]. Las luces de Septiembre -valor: 24.000 \n [2]. El principe de la Niebla, -valor: 28.000, \n [3]. El Palacio de Medianoche -valor: 45.000 \n [4]. Marina -valor: 15.000 \n [5]. La Sombra del Viento -valor: 27.000 \n [6]. El Juego del Angel -valor: 30.000 \n [7]. Salir \n "); 
	        printf("\n Digite una opcion: ");
	        scanf("%c", &opcion);
	        if(opcion == '1') { 
	           libro = 1;
	           printf("\nLibro vendido con exito!!!");
	           getchar();
	           GuardarValor(caseta, libro);
	           break;         
	       }if(opcion == '2') {
	           libro = 2;
	           printf("\nLibro vendido con exito!!!");
	           GuardarValor(caseta, libro); 
	           break;
	       }if(opcion == '3'){
	           libro = 3;
	           printf("\nLibro vendido con exito!!!");
	           GuardarValor(caseta, libro); 
	           break;
	       }if(opcion == '4'){
	            libro = 4;
	            printf("\nLibro vendido con exito!!!");
	            GuardarValor(caseta, libro); 
	            break;
	       }if(opcion == '5'){
	            libro = 5;
	            printf("\nLibro vendido con exito!!!");
	            GuardarValor(caseta, libro); 
	            break;
	       }if(opcion == '6'){
	            libro = 6;
	            printf("\nLibro vendido con exito!!!");
	            GuardarValor(caseta, libro); 
	            break;
	       }if(opcion == '7'){
	           menuPrincipal();
	           break;
	       }else{
	           repetir = 1;
	       }
	    }while(repetir == 1);
	   
	
	}


	void GuardarValor(int casetas, int libros){
	    int numValor;
	    int numCantidad;
	    int CantidadLibro;
	    
	    if(casetas == 1){
	       
	       
	        caseta[casetas-1].total = numValor + caseta[casetas-1].total; 
	        caseta[casetas-1].cantidad = 1 + caseta[casetas-1].cantidad; 
	        libro[libros-1].cantidad = 1 + libro[libros-1].cantidad;
	        menuPrincipal();
	               
	    }if(casetas == 2){
	      
	      
	        numValor = libro[libros-1].precio;
	        caseta[casetas-1].total = numValor + caseta[casetas-1].total;
	        caseta[casetas-1].cantidad = 1 + caseta[casetas-1].cantidad;  
	        libro[libros-1].cantidad = 1 + libro[libros-1].cantidad;
	        menuPrincipal();
	
	    }if(casetas == 3){
	     
	     
	        numValor = libro[libros-1].precio;
	        caseta[casetas-1].total = numValor + caseta[casetas-1].total; 
	        caseta[casetas-1].cantidad = 1 + caseta[casetas-1].cantidad;  
	        libro[libros-1].cantidad = 1 + libro[libros-1].cantidad;
	        menuPrincipal();
	    }else{
	
	    }
	
	}


	void ImprimirVenta(){
	    char opcion;
	    int repetir;
	   do{
	       system("cls");
	       printf("\n Seleccione el libro a comprar:\n");
	       printf("\b [1]. Venta total de cada caseta \n [2]. Filtro por libros  \n [3]. Filtro por caseta \n [4]. Salir \n "); 
	       printf("\n Digite una opcion: ");
	       scanf("%c", &opcion);
	       if(opcion == '1'){
	           VentaCaseta();
	           break;
	       }if(opcion == '2'){            
	           FiltroLibro();  
	           break;
	       } if(opcion == '3'){            
	           FiltroCaseta();        
	           break;
	       }if(opcion == '4'){            
	           menuPrincipal();        
	           break;
	       }else{
	           repetir = 1;
	       }
	   }while(repetir == 1);
	}


	void VentaCaseta(){
	    system("cls");
	    printf("\n\tVENTA POR CASETA");
	    printf("\n\t-----------------");
	    printf("\n\t          CANTIDAD DE LIBRO   TOTAL");
	    printf("\n\t %s        %i           %i", caseta[0].nombre, caseta[0].cantidad, caseta[0].total);
	    printf("\n\t %s        %i           %i", caseta[1].nombre, caseta[1].cantidad, caseta[1].total);
	    printf("\n\t %s        %i           %i", caseta[2].nombre, caseta[2].cantidad, caseta[2].total);
	    printf("\n"); 
	    fflush(stdin);
	    getchar();
	    ImprimirVenta();
	}


	void FiltroLibro(){


	    int x = 0;
	    int i = 0;
	    int k = 0;
	    for (x; x < 6; x++){
	        for (i; i < 6 - 1; i++){
	            int j = i + 1;
	           
	           
	            if (libro[i].cantidad < libro[j].cantidad){
	               
	               
	                memcpy(&numL, &libro[i], sizeof(Libro));
	                memcpy(&libro[i], &libro[j], sizeof(Libro));
	                memcpy(&libro[j], &numL, sizeof(Libro));
	            }
	        }
	    }
	    for (k; k < 6; k++){
	        printf("\n%s",libro[k].nombre);
	        printf("\nCantidad de libros vendidos:%d ", libro[k].cantidad);
	        printf("\n");  
	        fflush(stdin);  
	    }
	    getchar(); 
	    ImprimirVenta();
	}


	void FiltroCaseta(){
		int x = 0;
		int i = 0;
		int k = 0;
	    for (x; x < 3; x++){
	        for (i; i < 3 - 1; i++){
	            int j = i + 1;
	        
	        
	            if (caseta[i].cantidad > caseta[j].cantidad)
	            {
	               
	               
	                memcpy(&numC, &caseta[i], sizeof(Caseta));
	                memcpy(&caseta[i], &caseta[j], sizeof(Caseta));
	                memcpy(&caseta[j], &numC, sizeof(Caseta));
	            }
	        }
	    }
	    for (k ; k < 3; k++){
	        printf("\n%s",caseta[k].nombre);
	        printf("\nCantidad de libros vendidos es :%d ", caseta[k].cantidad);
	        printf("\nTotal de ventas por caseta es : %d",caseta[k].total); 
	        printf("\n");  
	        fflush(stdin);
	          
	    }
	    getchar();  
	    ImprimirVenta();
	}
