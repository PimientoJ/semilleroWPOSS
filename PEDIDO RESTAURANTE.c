	#include <stdio.h>
	#include <string.h>
	#include <conio.h>
	#include <stdbool.h>
	#include <windows.h>
	
	struct Precio{
	    char nombre[20];
	    float precio;
	}
	platoEntrada1 = {"Plato entrada 1", 2.5},
	platoEntrada2 = {"Plato entrada 2", 3.5},
	platoEntrada3 = {"Plato entrada 3", 4.0},
	platoEntrada4 = {"Plato entrada 4", 5.0},
	
	platoFuerte1 = {"Plato fuerte 1", 12.5},
	platoFuerte2 = {"Plato fuerte 2", 13.5},
	platoFuerte3 = {"Plato fuerte 3", 14.0},
	platoFuerte4 = {"Plato fuerte 4", 15.0},
	
	postre1 = {"Postre 1", 6.5},
	postre2 = {"Postre 2", 5.5},
	postre3 = {"Postre 3", 4.0},
	postre4 = {"Postre 4", 3.0},
	
	bebidas1 = {"Bebidas 1", 2.5},
	bebidas2 = {"Bebidas 2", 4.5},
	bebidas3 = {"Bebidad 3", 6.0},
	bebidas4 = {"Bebidas 4", 8.0};
	
	struct menu{
	    char cliente[20];
	    int mesaCode;
	    struct platosPrecio platoEntrada[20];
	    struct platosPrecio platoFuerte[20];
	    struct platosPrecio postre[20];
	    struct platosPrecio bebidas[20];
	} menuPedido[20];
	
	void ingreso();
	void ingresoCliente();
	void visualizacionMenu();
	char menuOpcion();
	void factura();
	void terminarPedido();
	
	//Menú
	void platosEntradas();
	void platosFuertes();
	void postres();
	void bebidas();
	
	//variables
	int numCliente;
	int mesa;
	int plato;
	bool salida = true;
	float total;
	
	
	int main(){
	    printf("\t\t\t BIENVENIDOS AL RESTAURANTE MIL DELICIAS.\n\n");
	    ingreso();    
	    return 0;
	}
	//Login verificador
	void ingreso(){
	    char usuario[10];
	    char clave[4];
	    int i;
	    USER :
	    printf(" Usuario: ");
	    scanf("%s", &usuario);
	    if(strlen(usuario) <3 || strlen(usuario) >10 || strcmp(usuario, "88229967")){
	        printf("Usuario incorrecto\n");
	        goto USER;
	        }
	    CONTRASENA:
	    printf(" Clave: ");
	    for ( i = 0; i < 4; i++){
	    clave[i] = getch();
	    printf("*");
	    }
	    if(strcmp(clave, "2002")) {
	        ingresoCliente();
	        } 
	    printf("\nContrasena incorrecta\n");
	    goto CONTRASENA;
	}
	//Seleccionar mesa y asignarle un cliente
	void ingresoCliente(){
	    int i;
	    printf("\n\t\t\tBienvenido\n"); 
	    printf("\n\tEscriba la mesa del cliente : ");
	    scanf("%i", &numCliente);
	    for ( i = 0; i < 20; i++){
	        if(menuPedido[i].mesaCode == numCliente){
	            printf("\tEl cliente ya tiene una factura\n");
	            menuOpcion();
	        }
	    }    
	    menuPedido[numCliente].mesaCode = numCliente;
	    printf("\tEl nombre el cliente : ");
	    scanf("%s",&menuPedido[numCliente].cliente);
	    menuOpcion();
	 }
	
	char menuOpcion(){
	//Funcion informativa
	system("cls");
	visualizacionMenu();
	int opcion;
	char seguir[2];
	printf("ingrese una opcion: \t");
	scanf("%c", &opcion);
	
	switch (opcion){
	    case '0':
	        platosEntradas();
	        printf("\nDesea continuar con el pedido? si/no >> ");
	        scanf("%s", &seguir);
	        if (!strcmp(seguir,"si")){
	            menuOpcion();
	        }
	        goto SALIDA_CASOS;
	    case '1':
	        platosFuertes();
	        printf("\nDesea continuar con el pedido? si/no >> ");
	        scanf("%s", &seguir);
	        if (!strcmp(seguir,"si")){
	            menuOpcion();
	        };
	        goto SALIDA_CASOS;
	
	    case '2':
	        postres();
	        printf("\nDesea continuar con el pedido? si/no >> ");
	        scanf("%s", &seguir);
	        if (!strcmp(seguir,"si")){
	            menuOpcion();
	        }
	        goto SALIDA_CASOS;
	
	    case '3':
	        bebidas();
	        printf("\nDesea continuar con el pedido? si/no >> ");
	        scanf("%s", &seguir);
	        if (!strcmp(seguir,"si")){
	            menuOpcion();
	        }
	        goto SALIDA_CASOS;
	    
	    case '5':
	        printf("\nDesea finalizar con el pedido? si/no >> ");
	        scanf("%s", &seguir);
	        if (!strcmp(seguir,"no")){
	            menuOpcion();
	        }
	        goto SALIDA_CASOS;
	
	    default:
	        salida = false;
	        break;
	    }
	    SALIDA_CASOS:
	    terminarPedido();
	}
	
	void generarFactura(){
	    total = 0;
	    int mesa;
	    int entradas;
	    int fuertes;
	    int postres;
	    int bebidas;
	    printf("Que mesa desea facturar?");
	    scanf("%i", &mesa);
	    if (!strcmp(menuPedido[mesa].cliente, "\0")){
	        printf("La mesa no tiene pedido");
	    }else{
	    printf("\nEl CLiente %s de la mesa %i pidio:  \n",menuPedido[mesa].cliente, menuPedido[mesa].mesaCode);
	    for ( entradas = 0; entradas < 20; entradas++){
	        if(menuPedido[mesa].platoEntrada[entradas].precio == 0.00) {
	            total = total;
	            continue;
	        }
	        printf("\t%s :\t",menuPedido[mesa].platoEntrada[entradas].nombre);
	        printf("%.2f\n",menuPedido[mesa].platoEntrada[entradas].precio);
	        total = total + menuPedido[mesa].platoEntrada[entradas].precio;
	    }
	    printf("\nEntradas total es: >>  %.2f \n", total);
	    for ( fuertes = 0; fuertes < 20; fuertes++){
	        if(menuPedido[mesa].platoFuerte[fuertes].precio == 0.00) {
	            total = total;
	            continue;
	        }
	        printf("\t%s :\t",menuPedido[mesa].platoFuerte[fuertes].nombre);
	        printf("%.2f\n",menuPedido[mesa].platoFuerte[fuertes].precio);
	        total = total + menuPedido[mesa].platoFuerte[fuertes].precio; 
	    }
	    printf("\nFuertes total es: >>  %.2f \n", total);
	    for ( postres = 0; postres < 20; postres++){
	        if(menuPedido[mesa].postre[postres].precio == 0.00) {
	            total = total;
	            continue;
	        }
	        printf("\t%s :\t",menuPedido[mesa].postre[postres].nombre);
	        printf("%.2f\n",menuPedido[mesa].postre[postres].precio);
	        total = total + menuPedido[mesa].postre[postres].precio;
	    }
	    printf("\nPostres total es: >>  %.2f \n", total);
	    for ( bebidas = 0; bebidas < 20; bebidas++){
	        if(menuPedido[mesa].bebidas[bebidas].precio == 0.00) {
	            total = total;
	            continue;
	        }
	        printf("\t%s :\t",menuPedido[mesa].bebidas[bebidas].nombre);
	        printf("%.2f\n",menuPedido[mesa].bebidas[bebidas].precio);
	        total = total + menuPedido[mesa].bebidas[bebidas].precio;
	    }
	    printf("\nla deuda total es: >>  %.2f \n", total);
	    }
	    menuOpcion();
	}
	
	void terminarPedido(){
	    char seguir[2];
	    char imprimirCLiente[2];
	    char generarFacturaCliente[2];
	    printf("Desea hacer pedido de otro cliente? si/no >> ");
	    scanf("%s", &seguir);
	    if(!strcmp(seguir, "si")){
	        ingresoCliente();
	    }else{
	        printf("Desea ver la mesa de un cliente? si/no >> ");
	        scanf("%s", &imprimirCLiente);
	        if(!strcmp(imprimirCLiente, "si")) factura();
	        printf("Desea ver generar factura de un cliente? si/no >> ");
	        scanf("%s", &generarFacturaCliente);
	        if(!strcmp(generarFacturaCliente, "si")) generarFactura();
	    }
	    terminarPedido();
	};
	//Funciones 
	void platosEntradas(){
	    int cantidad;
	    int seguir;
	    int j;
	    printf("Cuantas entradas necesitas?");
	        scanf("%i", &cantidad);
	        printf("\nSeleccione el plato de entrada que desea: \n");
	        printf("    => 1        %s con precio de $ %.2f \n", platoEntrada1.nombre, platoEntrada1.precio);      
	        printf("    => 2        %s con precio de $ %.2f \n", platoEntrada2.nombre, platoEntrada2.precio);      
	        printf("    => 3        %s con precio de $ %.2f \n", platoEntrada3.nombre, platoEntrada3.precio);      
	        printf("    => 4        %s con precio de $ %.2f \n", platoEntrada4.nombre, platoEntrada4.precio);
	        printf("    => 0   Finaliza pedido     \n"); 
	            for ( j = 0; j < cantidad ; j++){
	            printf("Numero del plato entrada que desea seleccionar \n");
	            scanf("%i",&plato);
	                // if(plato == 0) continue;
	                if(plato == 1) menuPedido[numCliente].platoEntrada[j] =  platoEntrada1;
	                if(plato == 2) menuPedido[numCliente].platoEntrada[j] =  platoEntrada2;
	                if(plato == 3) menuPedido[numCliente].platoEntrada[j] =  platoEntrada3;
	                if(plato == 4) menuPedido[numCliente].platoEntrada[j] =  platoEntrada4;
	            }
	}
	
	void platosFuertes(){
	    int cantidad;
	    int seguir;
	    int j;
	    printf("Cuantos platos fuertes necesitas?");
	        scanf("%i", &cantidad);
	        printf("\nSeleccione el plato fuerte que desea: \n");
	        printf("    => 1        %s con precio de $ %.2f \n", platoFuerte1.nombre, platoFuerte1.precio);      
	        printf("    => 2        %s con precio de $ %.2f \n", platoFuerte2.nombre, platoFuerte2.precio);      
	        printf("    => 3        %s con precio de $ %.2f \n", platoFuerte3.nombre, platoFuerte3.precio);      
	        printf("    => 4        %s con precio de $ %.2f \n", platoFuerte4.nombre, platoFuerte4.precio);
	        printf("<= Atras        \n");
	        for (j = 0; j < cantidad; j++){
	            // if(!strcmp(&menuPedido[k].platoFuerte, '\0')) break;
	             printf("Numero del plato fuerte que desea seleccionar \n");
	            scanf("%i",&plato);
	                if(plato == 1)menuPedido[numCliente].platoFuerte[j] =  platoFuerte1;
	                if(plato == 2)menuPedido[numCliente].platoFuerte[j] =  platoFuerte2;
	                if(plato == 3)menuPedido[numCliente].platoFuerte[j] =  platoFuerte3;
	                if(plato == 4)menuPedido[numCliente].platoFuerte[j] =  platoFuerte4;
	        }
	}
	
	void postres(){
	    int cantidad;
	    int seguir;
	    int j;
	    printf("Cuantos postres necesitas?");
	    scanf("%i", &cantidad);
	    printf("\nSeleccione el postre que desea: \n");
	    printf("    => 1        %s con precio de $ %.2f \n", postre1.nombre, postre1.precio);      
	    printf("    => 2        %s con precio de $ %.2f \n", postre2.nombre, postre2.precio);      
	    printf("    => 3        %s con precio de $ %.2f \n", postre3.nombre, postre3.precio);      
	    printf("    => 4        %s con precio de $ %.2f \n", postre4.nombre, postre4.precio);
	    printf("<= Atras        \n");
	    for (j = 0; j < cantidad; j++){
	        // if(!strcmp(&menuPedido[k].platoFuerte, '\0')) break;
	            printf("Numero del postre que desea seleccionar \n");
	        scanf("%i",&plato);
	            if(plato == 1)menuPedido[numCliente].postre[j] =  postre1;
	            if(plato == 2)menuPedido[numCliente].postre[j] =  postre2;
	            if(plato == 3)menuPedido[numCliente].postre[j] =  postre3;
	            if(plato == 4)menuPedido[numCliente].postre[j] =  postre4;
	    }
	}
	
	void bebidas(){
	    int cantidad;
	    int seguir;
	    int j;
	    printf("Cuantas bebidas necesitas?");
	    scanf("%i", &cantidad);
	    printf("\nSeleccione la bebida que desea: \n");
	    printf("    => 1        %s con precio de $ %.2f \n", bebidas1.nombre, bebidas1.precio);      
	    printf("    => 2        %s con precio de $ %.2f \n", bebidas2.nombre, bebidas2.precio);      
	    printf("    => 3        %s con precio de $ %.2f \n", bebidas3.nombre, bebidas3.precio);      
	    printf("    => 4        %s con precio de $ %.2f \n", bebidas4.nombre, bebidas4.precio);
	    printf("<= Atras        \n");
	    for (j = 0; j < cantidad; j++){
	        // if(!strcmp(&menuPedido[k].platoFuerte, '\0')) break;
	            printf("Numero de la bebida que desea seleccionar \n");
	        scanf("%i",&plato);
	            if(plato == 1)menuPedido[numCliente].bebidas[j] =  bebidas1;
	            if(plato == 2)menuPedido[numCliente].bebidas[j] =  bebidas2;
	            if(plato == 3)menuPedido[numCliente].bebidas[j] =  bebidas3;
	            if(plato == 4)menuPedido[numCliente].bebidas[j] =  bebidas4;
	    }
	}
	//Funciones informativas
	void visualizacionMenu(){
	    printf("\n\nCLiente: %s en la mesa: %i\n\n", menuPedido[numCliente].cliente, numCliente);
	    //Opciones del menu
	    printf("    ________Menu________\n");
	    printf("    Plato entrada   => 0\n");
	    printf("    Plato fuerte    => 1\n");
	    printf("    Postre          => 2\n");
	    printf("    Bebidas         => 3\n");
	    printf("    Finalizar       => 5\n");
	}
	
	void factura(){
	    char volver[2];
	    int clienteNum;
	    int entradas;
	    int fuertes;
	    int postres;
	    int bebidas;
	    VISUALIZAR:
	    printf("Que mesa desea conocer?    ");
	    scanf("%i", &clienteNum);
	    printf("\n\tCLiente %s mesa: %i \n",menuPedido[clienteNum].cliente, menuPedido[clienteNum].mesaCode);
	    for ( entradas = 0; entradas < 20; entradas++){
	        if(menuPedido[clienteNum].platoEntrada[entradas].precio == 0.00) continue;
	        printf("\t%s :\t",menuPedido[clienteNum].platoEntrada[entradas].nombre);
	        printf("%.2f\n",menuPedido[clienteNum].platoEntrada[entradas].precio);
	    }
	    for ( fuertes = 0; fuertes < 20; fuertes++){
	        if(menuPedido[clienteNum].platoFuerte[fuertes].precio == 0.00) continue;
	        printf("\t%s :\t",menuPedido[clienteNum].platoFuerte[fuertes].nombre);
	        printf("%.2f\n",menuPedido[clienteNum].platoFuerte[fuertes].precio);
	    }
	    for ( postres = 0; postres < 20; postres++){
	        if(menuPedido[clienteNum].postre[postres].precio == 0.00) continue;
	        printf("\t%s :\t",menuPedido[clienteNum].postre[postres].nombre);
	        printf("%.2f\n",menuPedido[clienteNum].postre[postres].precio);
	    }
	    for ( bebidas = 0; bebidas < 20; bebidas++){
	        if(menuPedido[clienteNum].bebidas[bebidas].precio == 0.00) continue;
	        printf("\t%s :\t",menuPedido[clienteNum].bebidas[bebidas].nombre);
	        printf("%.2f\n",menuPedido[clienteNum].bebidas[bebidas].precio);
	    }
	    printf("\n");
	    printf("Desea ver otra mesa? si/no >> ");
	    scanf("%s", &volver);
	    if(!strcmp(volver, "si")) goto VISUALIZAR;
	}
