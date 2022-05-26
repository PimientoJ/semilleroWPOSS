#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define ENTER 13
#define RETROCESO 8
#define NUMERO_USUARIO 1
#define MAX 10
#define MIN 12
#define MONTO_MINIMO 1000

	typedef struct datos_usuario{
	    char email[50];
	    char password[10];
	}Usuario;
	
	Usuario user[10]={{"yecid", "0123"}};
	
	//Declaracíon de funciones
	void Menu();
	void opciones();
	void Iniciar_Sesion();
	void Registro_Usuario();
	void IngresoSistema();
	void seleccionOperador();
	
	//Variables globales del proyecto
	int opcion = -1;
	char repite = 1;
	char correo[50];
	char contrasena [8];
	

	int main(){
	    Menu();
	    return 0;
	}
	
	//Menu principal
	void Menu(){
	    system("cls");
	    printf("\t\t-------RECARGAS PARA CELULAR");
	    printf("\n");
	    printf("1.  Iniciar sesion\n");
	    printf("2.  Registrar usuario nuevo\n");
	    printf("0.  Salir");
	    printf("\n");
	    printf("Ingrese una opcion: ");
	    scanf ("%d", &opcion);
	    opciones();
	
	}
	
	void opciones(){
	   	
		switch (opcion) {
	                case 1:
	                        Iniciar_Sesion();
	                        break;
	
	                case 2: 
	                        Registro_Usuario();
	                        IngresoSistema();
	                        break;
	                
	                case 0:
	                        exit;
	                        break;
								                
	                default:		 			
	                		printf("OPCION INCORRECTA, ");
	                		system("pause");
							Menu();
	                		break;
	            }
	        

	}
	 
	//funcion inicio de sesión
	void Iniciar_Sesion(){
	    int intentos = 0;
	    int ingreso = 0;
	    char caracter;
	    int i=0;
	
	    do{  
	        i=0;     
	        system("cls");
	        printf("\n\t\tINICIAR SESION\n");
	        printf("\n\tUsuario: ");
	        fflush(stdin);
	        gets(correo);
	        printf("\n\tContrasena: ");
	         //conersión de letras a astericos
	        while(caracter = getch()){
	            if(caracter == ENTER){
	                contrasena[i] = '\0';
	                break;
	            }else if(caracter == RETROCESO){
	                if(i>0){
	                i--;
	                printf("\b \b");
	                }
	            }else{
	                if(i<8){
	                printf("*");
	                contrasena[i] = caracter;
	                i++;
	                }
	            }
	       }         
	        //Validar si el usuario ya esta registrado en el sistema
	        int j;
	       for(j=0; j<NUMERO_USUARIO; j++){
	           if(strcmp(correo, user[j].email) == 0 && strcmp(contrasena, user[j].password) == 0){
	                ingreso = 1;
	            }else{
	                printf("\n");
	                printf("\n\tUsuario y/o contrasena son incorrectas");
	                intentos ++;
	                getchar();
	            }
	       }
	    }while(intentos<3 && ingreso==0);
	     //Direcciona al sistema o al menu 
	    if (ingreso == 1){
	        IngresoSistema();
	    }else{
	        Menu();
	    }
	}
	
	//funcion de registro de usuario
	void Registro_Usuario(){
	int repite = 1;
	char caracter;
	int i=0;
	
	        system("cls");
	        printf("\n\t\tREGISTRAR USUARIO\n");
	        printf("\n");
	        printf("\n\tUsuario: ");
	        fflush(stdin);
	        gets(correo);
	        
	        int j;
	        for(j=0; j<NUMERO_USUARIO; j++){
	            if(strcmp(correo, user[j].email) == 0){
	                printf("\n\tusuario %s ya registrado", correo); 
	                  
	
	            }else{
	                strcpy(user[NUMERO_USUARIO + 1].email, correo);
	                printf("\n\tContrasena: ");
	                 //convertir contraseña en asteriscos
	                while(caracter = getch()){
	                    if(caracter == 13){
	                        contrasena[i] = '\0';
	                        break;
	                    }else if(caracter == 8){
	                        if(i>0){
	                        i--;
	                        printf("\b \b");
	                        }
	                    }else{
	                        if(i<8){
	                        printf("*");
	                        contrasena[i] = caracter;
	                        i++;
	                        }
	                    }
	            }
	                strcpy(user[NUMERO_USUARIO + 1].password, contrasena);
	                printf("\n\tUsuario registrado correctamente ");
	                IngresoSistema();      
	            }
	                        
	       }          
	}
	
	//Ingreso al sistema 
	void IngresoSistema(){
	 char celular[10];
	 int monto;
	
	    system("cls");
	    printf("\n\t\t***SISTEMA DE RECARGAS***");
	    printf("\n");
	    printf("\n\t Bienvenido %s! \n\t", correo);
	    
	    //valida que el numero de diez digitos
	      fflush(stdin);
	    do{
	        printf("\n\tDigite el numero de celular: ");
	        gets(celular);
	        if(strlen(celular) !=10){
	             printf("\n\t\tMonto Incorrecto! Ingrese un celular de 10 digitos* ");
	        }
	    }while(strlen(celular) !=10);
	
	    fflush(stdin);
	   do{
	        printf("\n\tDigite el monto de la recargar: ");
	        scanf("%d", &monto);
	        //|| (monto%1000) != 0
	        //hacer validaciones....
	        if(monto >= MONTO_MINIMO){
	        printf("\tSelecciones tipo de operador: ");
	        printf("\n");
	        printf("1.  Claro\n");
	        printf("2.  Movistar\n");
	        printf("3.  Tigo");
	        printf("\n");
	        printf("Ingrese una opcion: ");
	        scanf ("%d", &opcion);
	        switch (opcion) {
	            case 1:
	                printf("Claro \n");
	                break;
	            case 2: 
	                printf("Movistar \n");
	                break;
	            case 3:
	                printf("Tigo \n");
	                break;  
//	            default:
//	            	printf("OPCION INCORRECTA, ");
//	                system("pause");
//					(opcion);
//	                break;
	        }
		          break;
	        }
	    }while( monto <= MONTO_MINIMO  );
	    
	    	printf("\n\t\tMonto Incorrecto! Ingrese un monto valido ");
	        
	      
	      Menu(); 
}
