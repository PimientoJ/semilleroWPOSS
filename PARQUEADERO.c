	#include <stdio.h>
	#include <time.h>
	#include <string.h>
	#include <conio.h>
	typedef struct parqueadero
	{
	    char placa[10];
	    int horaentrada;
	    int horasalida;
	
	}puesto;
	puesto moto[6],carro[10];
	void menuprincipal();
	void validarDatos();
	void entrada();
	void menucarro();
	void menumoto();
	void salida();
	int fecha();
	void minutos();
	void facturaCarro(int n);
	void facturaMoto(int n);
	void liberar();
	int hxm();
	int main()
	{
	    menuprincipal();
	    return 0;
	}
	void menuprincipal()
	{
	    int opcion;
	    char n;
	    do
	    {
	        printf("\n");
	        printf("\n\t\tBIENVENIDOS AL PARQUEADRO \n\n SELECCIONE LA OPCION QUE REQUIERAS: \n");
	        printf("\n\t 1. Ingresar vehiculo.");
	        printf("\n\t 2. Salida de un vehiculo.");
	        printf("\n");
	        printf("\n Que deseas realizar?: ");
	        scanf("%c",&n);
	        if (n=='1')
	        {
	            entrada();
	        }
	        else if (n=='2')
	        {
	            salida();
	        }
	        else{
	            printf("\nError, opcion erronea");
	            opcion=1;
	        }
	    }while (opcion==1);
	}
	void entrada()
	{
	    int opcion;
	    char n;
	    do
	    {
	        system("cls");
	        printf("\nBIENVENIDOS AL PARQUEADERO");
			printf("\n\t\tMENU");
	        printf("\n1. Un carro: ");
	        printf("\n2. Una moto: ");
	        printf("\n");
	        printf("\nQUE VA A INGRESAR AL PARQUEADERO?");
	        scanf("%c",&n);
	        if (n=='1')
	        {
	            menucarro();
	        }
	        else if (n=='2')
	        {
	            menumoto();
	        }
	        else{
	            printf("\nError, opcion no disponible.");
	            opcion=1;
	        }
	    } while (opcion=1);
	}
	
		void fechayhora(){
		  time_t t = time(NULL);
		  struct tm tiempoLocal = *localtime(&t);
		  char fechaHora[70];
		  char *formato = "%Y-%m-%d %H:%M";
		  int bytesEscritos =strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);
		  if (bytesEscritos != 0) {
		    printf("fecha y Hora: %s\n", fechaHora);
		  } else {
		    printf("Error formateando fecha.");
		  }
		}
	
	int hxm()
	{
	    int h,m,k;
	    time_t t;
	    struct tm *st ;
	    time(&t);
	    st = localtime(&t);
	    h=st-> tm_hour*60;
	    m=st-> tm_min;
	    k=h+m;
	    return k;
	}
	
	void menucarro(){
	    int n;
	    char v[20];
	    fflush(stdin);
	    int i;
	    for (i = 0; i < 10; i++)
	    {
	        if(strcmp(carro[i].placa,"")==0)
	        {
	            printf("\nDispoble Puesto # %i",i+1);
	        }
	        
	    }
	    printf("\nEliga el puesto de estacionamiento disponible: ");
	    scanf("%i",&n);
	    fflush(stdin);
	    printf("\nIngrese la placa del vehiculo. ");
	    scanf("%s",&v);
	    int r;
	    int j;
	    for (j = 0; j < n; j++)
	    {
	        r=strcmp(carro[i].placa,v);
	        if (r==0)
	        {
	            break;
	        }       
	    }
	    if (r==0)
	    {
	        printf("Placa ya registrada, intente de nuevo");
	        menuprincipal();
	    }
	    else
	    {
	        strcpy(carro[n-1].placa,v);
	    }
	    fechayhora();
	    hxm();
	    int m=hxm();
	    carro[n-1].horaentrada=m;
	    getchar();
	    menuprincipal();
	}
	
	void menumoto(){
	    int n;
	    char v[20];
	    fflush(stdin);
	    int i;
	    for (i = 0; i < 6; i++)
	    {
	        if(strcmp(moto[i].placa,"")==0)
	        {
	            printf("\nPuesto %i Disponible",i+1);
	        }
	        
	    }
	    printf("\nEliga el puesto de estacionamiento ");
	    scanf("%i",&n);
	    printf("\nIngrese la placa del vehiculo. ");
	    scanf("%s",&v);
	    int r;
	    int k;
	    for (k = 0; k < 6; k++)
	    {
	        r=strcmp(moto[k].placa,v);
	        if (r==0)
	        {
	            break;
	        }       
	    }
	    if (r==0)
	    {
	        printf("Placa ya registrada, intente de nuevo");
	        menuprincipal();
	    }
	    else
	    {
	        strcpy(moto[n-1].placa,v);
	    }
	    fechayhora();
	    hxm();
	    int m=hxm();
	    moto[n-1].horaentrada=m;
	    getchar();
	    menuprincipal();
	}
	
	void salida()
	{
	    int op, n;
	    char a;
	    do
	    {
	        system("cls");
	        printf("\nBienvenidos al sistema de salida del parqueadero ");
	        printf("\n1 para retirar un carro: ");
	        printf("\n2. para retirar una moto: ");
	        printf("\n");
	        scanf("%c",&a);
	        if (a=='1')
	        {
	        	int l;
	            for (l = 0; l < 10; l++)
	            {
	                if(strcmp(carro[l].placa,"")!=0)
	                {
	                    printf("\nPuesto %i ocupado a facturar",l+1);
	                }
	            }
	            printf("\nEliga el puesto de estacionamiento ");
	            scanf("%i",&n);
	            hxm();
	            int k=hxm();
	            carro[n-1].horasalida=k;
	            facturaCarro(n);
	        }
	        else if (a=='2')
	        {
	            int n;
	            int m;
	            for (m = 0; m < 6; m++)
	            {
	                if(strcmp(moto[m].placa,"")!=0)
	                {
	                    printf("\nPuesto %i ocupado a facturar",m+1);
	                }
	            }
	            printf("\nEliga el puesto de estacionamiento ");
	            scanf("%i",&n);
	            hxm();
	            int k=hxm();
	            moto[n-1].horasalida=k;
	            facturaMoto(n);
	        }
	        else{
	            printf("\nError, por favor digite una opcion valida ");
	            op=1;
	        }
	    } while (op==1);
	}
	
	void facturaCarro(int n){
	    int r,h,m,h1,m1,t;
	    r=carro[n-1].horasalida-carro[n-1].horaentrada;
	    h=r/60;
	    m=r%60;
	    if (m>2)
	    {
	       h1=h*3000;
	       m1=m*200;
	       t=h1+m1;
	    }
	    else{
	        t=h*3000;
	    }
	    printf("\nEl saldo a pagar para el carro de placas %s es de :%i",carro[n-1].placa,t);
	    getchar();
	    memset(&carro[n-1],0,sizeof(&carro[n-1]));
	    getchar();
	    menuprincipal();
	}
	
	void facturaMoto(int n){
	    int r,h,m,h1,m1,t;
	    r=moto[n-1].horasalida-moto[n-1].horaentrada;
	    h=r/60;
	    m=r%60;
	    if (m>2)
	    {
	       h1=h*1000;
	       m1=m*200;
	       t=h1+m1;
	    }
	    else{
	        t=h*1000;
	    }
	    printf("\nEl saldo a pagar para el carro de placas %s es de :%i",moto[n-1].placa,t);
	    memset(&moto[n-1],0,sizeof(&moto[n-1]));
	    getchar();
	    menuprincipal();
	}
