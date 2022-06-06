#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include "pila.h"

#define DIM 50
#define DIMENSIONFLOAT 100

int cargaArregloNEnteros(int a[], int v);
int cargaAleatoriaEnteros(int a[], int dim, int cant);
void muestraArregloCargado (int a[], int v);
int sumaElementosArreglo(int a[], int v);
void DeArregloAPila(int a[], int v, Pila *p);
void muestraPila (Pila p, char titulo[]);
void muestraArregloCargado (int a[], int v);
int cargaArregloFlotante (float a1[], int dim);
int cargaAleatoriaFlotante(float a[], int dim, int cant);
void muestraArregloFlotanteCargado (float a[], int v);
float sumaElementosArregloFlotante(float a[], int v);
int cargaArregloCaracteres (char a[], int dim, int v);
void muestraArregloCaracteres (char a[], int v);
int buscaElemento (char a[], int v, char elemento);
char InsertaCaracter(char a[], int v);
void Capicua(int a[], int v);
void InvertirElementos(int a[], int v);

int main(){
    srand(time(NULL));

    Pila Pilita;
    inicpila(&Pilita);


    int arreglo[DIM];
    int arregloAleatorio[DIM];
    char arregloCaracteres[DIM];
    float arregloFlotante[DIMENSIONFLOAT];
    float arregloAleatorioFloat[DIMENSIONFLOAT];

    int validos = 0;
    int suma = 0;
    int v = 0;
    int valAleatorios = 0;

    char opcion = 0;
    char elementoABuscar;

    do{
    system("cls");
    printf("\t\t<<TP Arreglos>>");
    printf("\n=========================================================");
    printf("\n 1. <<<Carga arreglo de enteros>>>");
    printf("\n 2. <<<Muestra arreglo de enteros>>>");
    printf("\n 3. <<<Muestra carga de arreglo random>>>");
    printf("\n 4. <<<Suma de elementos de arreglo de enteros>>>");
    printf("\n 5. <<<De arreglo a pila>>>");
    printf("\n 6. <<<Carga de arreglo con numeros flotantes>>>");
    printf("\n 7. <<<Suma de arreglo con numeros flotantes>>>");
    printf("\n 8. <<<Carga de arreglo de caracteres>>>");
    printf("\n 9. <<<Busqueda char en arreglo caracteres>>>");
    printf("\n a. <<<Ordenamiento por insercion>>>");
    printf("\n b. <<<Saber si el arreglo es capicua>>>");
    printf("\n c. <<<Invertir elementos del arreglo, sin usar arreglo auxiliar>>>");
    printf("\n========================================================");

    opcion = getch();
    system("cls");

        switch(opcion){
    case '1':
        validos = cargaArregloNEnteros(arreglo, DIM);
        muestraArregloCargado(arreglo, validos);
        system("cls");
        printf("Se cargo el arreglo\n");

        break;
    case '2':
        printf("\n Arreglo: \n");
        muestraArregloCargado(arreglo, validos);

        break;
    case '3':
        valAleatorios = cargaAleatoriaEnteros(arregloAleatorio, DIM, 60);
        printf("\nArreglo Aleatorio Cargado: \n");
        muestraArregloCargado(arregloAleatorio, valAleatorios);
        break;
    case '4':
        valAleatorios = cargaAleatoriaEnteros(arregloAleatorio, DIM, 60);
        suma = sumaElementosArreglo(arregloAleatorio, valAleatorios);
        printf("\nLa suma de los elementos del arreglo es de: %d\n", suma);
        break;
    case '5':
        valAleatorios = cargaAleatoriaEnteros(arregloAleatorio, DIM, 50);
        DeArregloAPila(arregloAleatorio, valAleatorios, &Pilita);
        muestraPila(Pilita, "Pila cargada");
        break;
    case '6':
        v = cargaArregloFlotante(arregloFlotante, DIMENSIONFLOAT);
        muestraArregloFlotanteCargado(arregloFlotante, v);
        break;
    case '7':
        valAleatorios = cargaAleatoriaFlotante(arregloAleatorioFloat, DIMENSIONFLOAT, 100);
        muestraArregloFlotanteCargado(arregloAleatorioFloat, valAleatorios);
        printf("\n\nLa suma de los elementos es: %.2f", sumaElementosArregloFlotante(arregloAleatorioFloat, valAleatorios));
        break;
    case '8':
        validos = cargaArregloCaracteres(arregloCaracteres, DIM, validos);
        muestraArregloCaracteres(arregloCaracteres, validos);
        break;
    case '9':
        printf("Ingrese un caracter a buscar: \n");
        fflush(stdin);
        scanf("%c", &elementoABuscar);
        if(buscaElemento(arregloCaracteres, validos, elementoABuscar)){
            printf("El elemento ha sido encontrado\n");
        }else{
            printf("El elemento no ha sido hallado en el arreglo\n");
        }
        break;
    case 'a':
        validos = cargaArregloCaracteres(arregloCaracteres, DIM, validos);
        muestraArregloCaracteres(arregloCaracteres, validos);
        InsertaCaracter(arregloCaracteres, validos);
        break;
    case 'b':
        validos = cargaArregloNEnteros(arreglo, DIM);
        muestraArregloCargado(arreglo, validos);
        Capicua(arreglo, validos);
        break;
    case 'c':
        validos = cargaArregloNEnteros(arreglo, DIM);
        muestraArregloCargado(arreglo, validos);
        InvertirElementos(arreglo, validos);
        break;
    default:
        printf("ERROR, no es una opcion valida\n");
        }
    printf("\nPresione cualquier tecla para continuar o ESC para salir");
    opcion = getch();
    system("cls");
    }while(opcion != 27);

return 0;
}

///4.1.Hacer una función que reciba como parámetro un arreglo de números enteros
///y permita que el usuario ingrese valores al mismo por teclado.
///La función debe retornar la cantidad de elementos cargados en el arreglo
///(o pueden utilizar como puntero válidos).
int cargaArregloNEnteros(int a[], int dimension){
    int i = 0;
    char opcion = 0;
    while(i<dimension && opcion != 27){
        system("cls");
        printf("Ingrese un numero\n");
        fflush(stdin);
        scanf("%d", &a[i]);
        i++;
        printf("Ingrese cualquier tecla para continuar o ESC para salir\n");
        opcion = getch();
    }

    return i;

}
//carga aleatoria
int cargaAleatoriaEnteros(int a[], int dim, int cant){
    int i = 0;

    while(i<dim && i<cant){
    a[i] = rand()%100;
    i++;
}

return i;
}
///Hacer una función que reciba como parámetro un arreglo
///y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.
void muestraArregloCargado (int a[], int v){

    for(int i=0; i<v; i++){
        printf("%d-", a[i]);
    }
}
///Hacer una función que reciba como parámetro un arreglo
///y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos.
int sumaElementosArreglo(int a[], int v){
    int i = 0;
    int s = 0;

    for(i=0; i<v; i++){
        s += a[i];
    }

    return s;
}


///Hacer una función que reciba como parámetro un arreglo,
///la cantidad de elementos (válidos) cargados en él y una Pila.
///La función debe copiar los elementos del arreglo en la pila.
void DeArregloAPila(int a[], int v, Pila *p){
int i = 0;

for(i = 0; i< v; i++){
    apilar(p, a[i]);
}


}
//muestra pila
void muestraPila (Pila p, char titulo[])
{
    Pila AUX;

    inicpila(&AUX);
    int i = 0;

    printf("\n\n\t\t%s", titulo);
    printf("\n");
    while (!pilavacia(&p))
        {
            {
            printf(" %02d |", tope(&p));
            apilar(&AUX, desapilar(&p));

        i++;
        if (i%12 == 0)
            {
            printf("\n");
            }
        }
}
  printf("\n");
}
///Realizar una función que sume los elementos de un arreglo
///de números reales (float) de dimensión 100.
///(se recomienda hacer una función para cargar y otra para mostrar
    ///para este tipo de dato asociado al arreglo)
int cargaArregloFlotante (float a1[], int dimension1){
    int i = 0;
    char opcion = 0;

    while(i < dimension1 && opcion != 27){
        printf("\nIngrese un numero flotante: \n");
        fflush(stdin);
        scanf("%f", &a1[i]);
        i++;
        printf("\nIngrese cualquier tecla para continuar o ESC para salir\n");
        opcion = getch();
    }

    return i;
}
//carga aleatoria flotante
int cargaAleatoriaFlotante(float a[], int dim, int cant){
    int i = 0;

    while(i<dim && i<cant){
        a[i] = (float)((rand()%100) +1)/1.3;
        i++;
        }

return i;
}
void muestraArregloFlotanteCargado (float a[], int v){
    int i = 0;

    for(i=0; i<v; i++){
        if (i%10 ==0){
            printf("\n");
        }
        printf(" [%02.2f] - ", a[i]);
    }
}



float sumaElementosArregloFlotante(float a[], int v){
    int i = 0;
    float s = 0;

    while(i<v)
        {
        s = (float) s + a[i];
        i++;
        }
    return s;
}
/// carga arreglo de caracteres
int cargaArregloCaracteres (char a[], int dim, int v){
    int i = v;
    char opcion = 0;

    while(i<dim && opcion != 27){
        system("cls");
        printf("Ingrese un caracter: \n");
        fflush(stdin);
        scanf("%c", &a[i]);
        printf("Presione cualquier tecla para continuar o ESC para salir\n");
        opcion = getch();
        i++;
    }

return i;


}
///muestra arreglo de caracteres
void muestraArregloCaracteres (char a[], int v){
    int i = 0;

    for(i=0; i<v; i++){
        if (i%10 ==0){
            printf("\n");
        }
        printf(" [%c] - ", a[i]);
    }
}
///Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.
int buscaElemento (char a[], int v, char elemento){
    int i = 0;
    int flag = 0;
    while(i<v && !flag){
        if(a[i] == elemento){
            flag = 1;
        }
        i++;
    }
return flag;

}

///Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.
char InsertaCaracter(char a[], int v){
    char caracter;
    char aux;
    int i = 0;
    printf("\nIngrese un caracter a insertar\n");
    fflush(stdin);
    scanf("%c", &caracter);
    while(i<v){
    if(caracter<a[i]){
        aux = a[i];
        printf("%c", aux);
        a[i] = caracter;
        caracter = aux;
        i++;
    }else{
    i++;
    }
    }
    a[i] = caracter;
    muestraArregloCaracteres(a, v+1);
return caracter;
}

///Realizar una función que determine si un arreglo es capicúa.
void Capicua(int a[], int v){
    int i = 0;
    int index = v-1;
    int flag = 0;

    while(i<v && flag == 0){
        if(a[i]==a[index]){
            index--;
            i++;
        }else{
            flag = 1;
        }
    }
    if(flag==0){
        printf("\nEl arreglo es capicua\n");
    }else{
        printf("\nEl arreglo NO es capicua\n");
    }

}
///Realizar una función que invierta los elementos de un arreglo.  (sin utilizar un arreglo auxiliar)
void InvertirElementos(int a[], int v){
    int i = 0;
    int index = v-1;
    int aux;

    for(i=0; i<v/2; i++){
        aux = a[i];
        a[i] = a[index];
        a[index]= aux;

        index--;
    }
    muestraArregloCargado(a, v);
}
