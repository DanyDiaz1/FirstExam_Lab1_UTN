#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//Daniel Diaz

void fastChargeArray(int A[], int *validos);
void copiarElementosPares (int A[], int validos, Pila *a);
int retornarMayorElementoPila (Pila *a);
void ordenarPila (Pila *a);
float promedioDeArray (int A[],int validos);
int pedirPosicion (int A[],int validos);
void mostrarPosicion (int A[], int validos, int posicion);
void mostrarUnArreglo (int A[],int validos);

int main()
{
    int opcion;
    int array[50];
    int validos=0;
    int mayorElemento=0;
    float promedioDeArreglo;
    int posicionElegida;
    int posicionMostrada;
    Pila pilaA;
    inicpila(&pilaA);


    do
    {
        printf("Estado actual del array\n");
        for(int i=0 ; i<validos ; i++)
        {
            printf("|%i|",array[i]);
        }

        printf("\nEstado Actual de la Pila\n");
        mostrar(&pilaA);


        printf("Que funcion desea revisar? Presione 0 para salir...\n");
        printf("1)Cargar arreglo\n");
        printf("2)Copiar elementos pares a una Pila\n");
        printf("3)Buscar el mayor elemento de la pila cargada en el punto anterior\n");
        printf("4)Ordenar los elementos de la pila anterior\n");
        printf("5)Calcular el promedio del arreglo\n");
        printf("6)Comprobar si existe una posicion en el arreglo\n");
        printf("7)Mostrar una posicion del arreglo\n");
        printf("8)Mostrar un arreglo\n");

        scanf("%i",&opcion);

        switch (opcion)
        {
        case 1:

            fastChargeArray(array,&validos);

            break;

        case 2:

            copiarElementosPares(array,validos,&pilaA);

            break;

        case 3:

            mayorElemento=retornarMayorElementoPila(&pilaA);
            printf("El mayor elemento de la pila es: %i\n",mayorElemento);

            break;

        case 4:

            ordenarPila(&pilaA);

            break;

        case 5:

            promedioDeArreglo=promedioDeArray(array,validos);

            printf("El promedio de los elementos del array es: %.2f\n",promedioDeArreglo);

            break;

        case 6:

            pedirPosicion(array,validos);

            break;

        case 7:

            mostrarPosicion(array,validos,&posicionElegida);

            break;

        case 8:

            mostrarUnArreglo(array,validos);

            break;

        case 0:

            printf("El programa se cerrara...\n");

            break;

        default:

            printf("Numero de funcion incorrecto...\n");

            break;
        }

        system("pause");
        system("cls");

    }
    while(opcion!=0);

    return 0;
}

void fastChargeArray(int A[], int *validos)
{
    int cant;
    printf("Cuantos elementos desea cargar al arreglo?\n");
    scanf("%i",&cant);
    srand(time(NULL));
    *validos=cant;
    if(cant<50)
    {
        for(int i=0 ; i<cant ; i++)
        {
            int numRandom=rand()%50+1;
            A[i]=numRandom;
        }

        for(int i=0 ; i<*validos ; i++)
        {
            printf("|%i|",A[i]);
        }
        printf("\n");

    }
    else
    {
        printf("Debe cargar menos de 50 numeros en el arreglo...\n");
        *validos=0;
    }
}



void copiarElementosPares (int A[], int validos, Pila *a)
{
    for (int i=0 ; i<validos ; i++)
    {
        if (A[i]%2==0)
        {
            apilar(a,A[i]);
        }
    }
    mostrar(a);
}


int retornarMayorElementoPila (Pila *a)
{
    Pila mayor,aux;
    inicpila(&mayor);
    inicpila(&aux);
    apilar(&mayor,desapilar(a));

    while(!pilavacia(a))
    {
        if(tope(&mayor)<tope(a))
        {
            apilar(&aux,desapilar(&mayor));
            apilar(&mayor,desapilar(a));
        }
        else
        {
            apilar(&aux,desapilar(a));
        }
    }

    while(!pilavacia(&aux))
    {
        apilar(a,desapilar(&aux));
    }

    mostrar(a);

    return tope(&mayor);
}


void ordenarPila (Pila *a)
{
    Pila elementoMayor;
    inicpila(&elementoMayor);

    while(!pilavacia (a))
    {
        apilar(&elementoMayor,retornarMayorElementoPila(a));
    }
    printf("Mostrando pila ordenada\n");
    mostrar(&elementoMayor);
}


float promedioDeArray (int A[],int validos)
{
    int suma=0;
    float promedio=0;

    printf("Mostrando array\n");

    for(int i=0; i<validos ; i++)
    {
        printf("|%i|",A[i]);
    }
    printf("\n");
    system("pause");

    for(int i=0 ; i<validos ; i++)
    {
        suma+=A[i];
    }

    promedio=(float)suma/(float) validos;

    return promedio;
}


int pedirPosicion (int A[],int validos)
{
    int posicion;

    printf("Ingrese que posicion quiere buscar\n");
    scanf("%i",&posicion);

    if(posicion<=validos)
    {
        printf("La posicion se encuentra dentro del arreglo\n");
    }
    else
    {
        printf("La posicion no existe en este arreglo\n");
    }

    return posicion;

}


void mostrarPosicion (int A[], int validos,int posicion)
{
    posicion=pedirPosicion(A,validos);

    printf("El elemento en la posicion %i es : %i\n",posicion, A[posicion-1]);

}



void mostrarUnArreglo (int A[],int validos)
{
    int posicion;
    for(int i=0 ; i<validos ; i++)
    {
        mostrarPosicion(A,validos,posicion);
    }
}



