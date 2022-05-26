#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define TECLA_ENTER 13

void menu(int m1);
void menu2(int m2, int n);
void validarUser(int n);
int Saldo(int n);
int cantUser();
int registro(int n);
int fechaActual();

typedef struct usuario
{
    char cedula[15]; 
    char pass[20];
    int saldo; 
} user ;
user users[5]={{"1092364331","123",100000,},{"1004842387","1234",200000}};
int main()
{   
    cantUser();
    int n=cantUser();
    menu(n);
    return 0;
}
void validarUser(int n){
    char v[15];
    int op,op2,s,k;
    volver:
    do
    {
        fflush(stdin);
        printf("\n\tIngresa la cedula del usuario: ");
        gets(v);
        fflush(stdin);
        int r;
        int i;
        for (i = 0; i < n; i++)
        {
            r=strcmp(users[i].cedula,v);
            if (r==0)
            {
                s=users[i].saldo;
                k=i;
                break;
            }    
        }
        if(r==0)
        {
            fflush(stdin);
            int u=0,e;
            char cliente[15];
            char ca;
            do{
                printf("\n\tIngrese contrasena: ");
                while (ca = getch()) {
                    if (ca==TECLA_ENTER)
                    {
                        cliente[u]='\0';
                        fflush(stdin);
                        break;
                    }
                    else
                    {
                        cliente[u]=ca;
                        printf("*");
                        fflush(stdin);
                        u++;
                    }
                }
                int j;
                for (j = 0; j < n; j++)
                {
                    e=strcmp(users[j].pass,cliente);
                    if (e==0)
                    {
                        break;
                    }
                }
                if(e==0){
                    printf("\nContrasena correcta");
                    break;
                }
                else
                {
                    printf("\nContrasena invalida, vuelva  a intentar",e);
                    memset(cliente,0,sizeof(cliente));
                    op2=1;
                }
                    
                
            }while(op2==1);  
            
        }else{
                int x;
                char d;
                do{
                    printf("\nUsuario no validado. Ingrese 1 para registrar o 2 para volver a validar: ");
                    scanf("%c",&d);
                    if (d=='2')
                    {
                        memset(v,'/0',sizeof(v));
                        goto volver;
                    }
                    else if(d=='1')
                    {
                        cantUser();
                        registro(n);
                    }
                    else
                    {
                        x=1;
                    }
                }while(x==1);
            }
            
    }while (op==1);
    menu2(s,k);
}

void menu(int m1){
    int s;
    do
    {
        char r;
        printf("    \n\t\t    BIENVENIDOS \n");
        printf("\n\tMENU\n");
        printf("\n\t1. Iniciar sesion\n");
        printf("\n\t2. Registrar Usuario \n ");
        printf("\n\tSeleccione la opcion que requieras: ");
        scanf("%c",&r);
        if (r=='1')
        {
           validarUser(m1);

        }
        else if (r=='2')
        {
            registro(m1);
        }
        else{
            printf("Error, ingrese una opcion correcta: \n");
            printf("\n1. iniciar sesion : \n ");
            printf("\n2. Registar usuario: \n");
            s=1;
        }    
    }while (s==1);

}
int registro(int n){
    int u=0,k;
    char c;
    do
    {
        char d[15];
        system("cls");
        fflush(stdin);
        printf("\n\tRegistra la cedula del usuario: ");
        scanf("%s",&d);
        fflush(stdin);
        int o=validadNum(d);
        int j=strlen(d);
        if (o!=0 && j==10 )
        {
            strcpy(users[n].cedula,d);
            k=2;
        }
        else{
            printf("por favor oprima enter para seguir");
            getchar();
            memset(d,0,sizeof(d));
            k=1;
        }    
    } while (k==1);
    fflush(stdin);
    printf("\n\tRegistra la contrasena: ");
    while (c = getch()) {
        if (c==TECLA_ENTER)
        {
            users[n].pass[u]='\0';
            break;
        }
        else
        {
            users[n].pass[u]=c;
            printf("*");
            u++;
        }    
    }
    cantUser();
    int m= cantUser();
    pago(m);
}
int pago(int n){
    int p;
    int op2;
    fflush(stdin);
    do
    {
        fflush(stdin);
        printf("\n\tDigite el valor a depositar, tiene que ser minimo $1000 : ");
        scanf("%d",&p);
        if (p>1000)
        {
            break;
        }
        else{
            printf("\n\tIngrese un monto mayor a 1000");
            op2=1;
        }
    } while (op2==1);
    printf("\n\t\t\tBienvenido   ");
    printf("\n\tSu saldo es el siguiente %d ",p);
    fechaActual();
    cantUser();
    int k;
    k=n-1;
    menu2(p,k);
    return p;
}
int cantUser(){
    int n =sizeof(users)/sizeof(users[0]);
    int e=0;
    int k;
    for(k=0;k<n;k++){
        if(strcmp(users[k].cedula,"")!=0){
            e++;
        }
    }
    return e;
}
void menu2(int m2, int n){
    int o, f;
    char f1[15];
    system("cls");
    printf("\n\tBienvenido %s  su saldo es el siguiente %d: ",users[n].cedula,m2);
    printf("\n");
	fechaActual();
    printf("\n\t1. Para cancelar factura de CENS. ");
    printf("\n\t2. Para cancelar factura de AGUAS KAPITAL. ");
    printf("\n\t3. Para cancelar factura de VEOLIA. ");
    printf("\n\t4. Para cancelar factura de DIRECTV. ");
    printf("\n\t5. Para cancelar factura de CANAL EXITO. ");
    printf("\n\tPor favor digite la opcion para seleccionar el tipo de pago a realizar: ");
    scanf("\n%d",&o);
    system("cls");
    fflush(stdin);
    int t,t2;
    do
    {
        if (o>=1 || o<=5)
        {
            break;
        }
        else{
            t2=1;
    }
    } while (t2==1);
    
    fflush(stdin);
    do
        {
           printf("\n\tDigite el numero de factura:  ");
           scanf("%i",&f);
           if (sizeof(f)>=10 || sizeof(f)<=10 )
           {
               int p2;
               printf("\n\tDigite el saldo a pagar: ");
               scanf("%i",&p2);
               if (m2>=p2)
               {
                   printf("\n\tPago realizado satisfactoriamente ");
                   printf("\n\tA la factura n: %i",f);
                   printf("\n\tSaldo restante : %i",m2-p2);
                   break;
               }
               else{
                   printf("\n\tNo tiene saldo insuficiente, vuelva a intentar ");
                   pago(cantUser());
               }
           }
           else{
               t=1;
           }
        } while (t==1);
}

int fechaActual(){
  time_t t = time(NULL);
  struct tm tiempoLocal = *localtime(&t);
  char fechaHora[70];
  char *formato = "%Y-%m-%d %H:%M:%S";
  int bytesEscritos =
      strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);
  if (bytesEscritos != 0) {
    printf("\n\tFecha y hora de ingreso: %s\n", fechaHora);
  } else {
    printf("Error formateando fecha");
  }
}
int validadNum(char *p)
{
	int h;
    for (h = 0; h < strlen(p); h++)
    {
        if (isdigit(p[h]!=0))
        {
            return 0;
        }  
    }
return 1;
    
}


