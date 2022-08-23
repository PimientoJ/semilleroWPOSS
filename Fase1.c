#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <ctype.h> 

/*Estructuras de la frase*/
typedef struct fraseCompleta{
    char sentence[50];
}Frase;
Frase frase;

/*Estructuras para dividir la frase*/
typedef struct DividirPalabra{
    char word[20];
}Words;
Words words[20];

/*Variables globales*/
int vocal, consonante, a, e, i, o, u;

/*Funciones declaradas*/
int maximoCaracteres();
int Espacios();
int Palindrome(char *palabra);
int CantidadPalabras();
void PalabrasIguales(int m);
int contador( char *palabra);
void VocalConsonante();
void VocalUtilizasa();

/*principal*/
int main(){
    int numPalabras;

    system("cls");
    printf("\n\t\tBIENVENIDOS A LA FRASE\n");
    printf("\t\t======================\n");
    printf("\n Ingrese una frase: ");
    scanf("%[^\n]", &frase);

    maximoCaracteres();
    VocalConsonante();
    numPalabras = Espacios(); 
    printf("Numero de palabras en la frese: %d\n", numPalabras);
    // PalabrasIguales(numPalabras);

    for (int i=0; i < numPalabras; i++){
     Palindrome(words[i].word); 
     contador(words[i].word);
    //  printf("numero de letras: %d\n", nuevaPalabra);
    // myStrcpy(nuevaPalabra, words[i].word);
    } 
    printf("Cantidad de vocales: %i\n", vocal);
    VocalUtilizasa();
    printf("Cantidad de consonantes: %i\n", consonante);
          
    return 0;
}
/*funcion que me calcula maximo 50 carcateres en la frase*/
int maximoCaracteres(){
    int contador = 0;   

    while (frase.sentence[contador] != 0){
        contador++;
    }

    if(contador > 50){
      printf("La frase tiene que ser menor a 50 caracteres!!!");  
      getchar();
      main();
    }
    return contador;
}
/*Numero de espacios y divide la frase*/
int Espacios(){
    int h=0;
    int j = 0;
    int espacios= 0;
    int CantPalabras = 1;
    for( int i=0, h=0; i < 50; i++){
        if(frase.sentence[i] == '\0')
        break;

        if(frase.sentence[i] == ' '){
            espacios++;
            h=0;
            j++;
            CantPalabras++;
            continue;
        }
    words[j].word[h]=frase.sentence[i];    
    h++;
    }
    printf("\nCantidad de Espacio: %d\n", espacios);   

    return CantPalabras; 
}
/*funcion de mirar si las palabras registradas son polindromes*/
int Palindrome(char *palabra){ 
   int start, end, ckeck;
   int contador = 0; 
   char *nuevaPalabras;  

    while (palabra[contador] != 0){
        contador++;
    } 
    // printf("contador: %d\n", contador);
    start = 0;
    end = contador-1;

    while(start<end && palabra[start] == palabra[end]){
        start ++;
        end --;
    }      
    if(start>=end){
        printf("Palabra polindrome: %s\n", palabra);
    } 

}
/*funcion de mirar si las palabras registradas son iguales*/
int contador(char *palabra){
   int contador = 0;  
  for(int i=0; i < 20; i++){
    while (palabra[contador] != 0){
        contador++;
    }
  }
   return contador;
}
/*funcion de mirar si las palabras registradas son iguales*/
void PalabrasIguales(int m){
    int i=0, j=0, k=0;
    m = m-1;
    bool l = false;
    printf("Palabras repetidas\n");
    for ( i = 0; i < m; i++){
        for ( j = i + 1; j < m; j++){   
            if(i == j)continue;
            int cont = contador(words[i].word);
            printf("contador: %d\n", cont);
            for ( k = 0; k < cont; k++){
                if(words[i].word[k] != words[j].word[k]) break;
                l = true;
            }
        if(l)printf("%s\n", words[i]);
        l = false;
        }
    }
}
/*funcion para validar la cantidad de vocales en la frase*/
void VocalConsonante(){
    int contador = maximoCaracteres();
     //Convertir la cadena en minusculas
      for (int indice = 0; frase.sentence[indice] != '\0'; ++indice){
		frase.sentence[indice] = tolower(frase.sentence[indice]);
	   }

    for (int i = 0; i < contador; i++){
        if(frase.sentence[i]== '\0') {
            break;
        }
        if(frase.sentence[i] == ' '){
            continue;;
        }
        else if( frase.sentence[i] == 'a') {
            a++;
            vocal++;
        }
        else if( frase.sentence[i] == 'e') {
            e++;
            vocal++;
        }
        else if(frase.sentence[i] == 'i') {
            i++;
            vocal++;
        }
        else if(frase.sentence[i] == 'o') {
            o++;
            vocal++;
        }
        else if(frase.sentence[i] == 'u') {
            u++;
            vocal++;
        }
        else{
            consonante++;
        }
    }

}
/*funcion para ver cual vocal es mas utilizada*/
void VocalUtilizasa(){
    if(a>e && a>i && a>o && a>u){
        printf("La votal mas utilizada: a\n");
    }if(e>a && e>i && e>o && e>u){
         printf("La votal mas utilizada: e\n");
    }if(i>a && i>e && i>o && i>u){
         printf("La votal mas utilizada: i\n");
    }if(o>a && o>e && o>i && o>u){
         printf("La votal mas utilizada: o\n");
    }if(u>a && u>e && u>i && u>o){
         printf("La votal mas utilizada: u\n");
    }
}