#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#define DIMENSION 50
#define COLUMNAS 31


typedef struct
{
    char nombre[30];
    char genero;
    int edad;
} persona;

persona cargarPersona();



int main()
{
    /*
        char *s = NULL;

        agregaString(&s, " Algo ");
        printf("\n -- %s", s);

        agregaString(&s, " Otra cosa ");
        printf("\n -- %s", s);

        agregaString(&s, " algo mas ");
        printf("\n -- %s", s);

        char palabra[DIMENSION];
        int validos = cargarArregloChar(palabra, DIMENSION);
        mostrarArregloChar(palabra, validos);
        */


    int x=9;
    float y=44.6;
    char c='a';
    datos(&x, &y, &c);
    printf("%d %f %c",x, y, c);

    return 0;
}

void datos(int *x, float *y, char *c)
{
    printf("%d %f %c\n",x, y, c);
    *x=8;
    *y=4.2;
    *c='g';
}


void inicArreglo(int Arreglo[], int dimension)
{
    for(int i=0; i<dimension; i++)
    {
        Arreglo[i]=-1;
    }
}

void mostrarArreglo(int Arreglo[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("Posicion %d -> %d\n", i, Arreglo[i]);
    }
}

void cargarArreglo(int Arreglo[], int dimension)
{
    int teclaContinuar=13;
    int validos = 0;

    while (teclaContinuar==13 && validos<dimension)
    {
        printf("Ingrese un valor entero para cargar al arreglo\n");
        scanf("%d",&Arreglo[validos]);
        validos++;

        printf("Para continuar presione ENTER. Para terminar presione cualquier otra tecla\n");
        fflush(stdin);
        teclaContinuar = getch();
    }


}

int sumaArreglo(int arreglo[], int dimension)
{
    int suma=0;

    /*for(int i=0; i<dimension && flag == 1 ;i++)
    {
        if(arreglo[i]>=0)
        {
            suma += arreglo[i];
            flag = 1;
        }
        else
        {
         flag = 0;
        }
    }*/
    int i = 0;
    while(arreglo[i]>-1)
    {
        suma+=arreglo[i];
        i++;
    }
    return suma;
}

int cantValoresIngresados(int arreglo[],int dimension)
{
    int cantidad = 0;
    while(arreglo[cantidad]>-1)
    {
        cantidad++;
    }
    return cantidad;
}

//float promedio(int arreglo[])
//{
//    float promedio = (float) sumaArreglo(arreglo, dimension) / (float) cantValoresIngresados(arreglo, dimension);
//    return promedio;
//}


int cargarArregloChar(char arregloChar[], int dimension)
{
    int teclaContinuar=13;
    int validos = 0;

    while (teclaContinuar==13 && validos<dimension)
    {
        printf("Ingrese un caracter para cargar al arreglo\n");
        scanf("%c",&arregloChar[validos]);
        validos++;

        printf("Para continuar presione ENTER. Para terminar presione cualquier otra tecla\n");
        fflush(stdin);
        teclaContinuar = getch();
    }

    return validos;

}


/*void invertirArreglo(char arregloChar[], int validos)
{
    for(int i = 0; i<validos; i++)
    {
        arregloAux[i]= arregloChar[i];
    }

    for(int i = 0; i < validos; i++)
    {
        arregloChar[i] = arregloAux[validos-i];
    }

}
*/
void mostrarArregloChar(char arregloChar[], int validos)
{
    for(int i = 0 ; i<validos ; i++)
    {
        printf("%c", arregloChar[validos]);
    }
}


void agregaString(char **a, char *b)
{
    if(*a)
    {
        (*a) = (char*)realloc((*a), strlen(*a)+strlen(b)+1);
        strcat((*a), b);
    }
    else
    {
        (*a) = (char*)malloc(sizeof(b)+1);
        strcpy((*a), b);
    }
}

int retornarDecimal(int arreglo[], int validos)
{
    int decimal = 0;
    for (int i=0 ; i<validos ; i++)
    {
        decimal += arreglo[i]*pow(10,validos-i-1);
    }
    return decimal;
}

int retornarValorMaximo(int arreglo[], int validos)
{
    int maximo = arreglo[0];
    int posMayor = 0;

    for(int i = 0 ; i<validos ; i++)
    {
        if(arreglo[i]>=maximo)
        {
            maximo = arreglo[i];
            posMayor = i;
        }
    }

    return posMayor;
}

void cargarMatriz(int matriz[][COLUMNAS], int filas, int columnas)
{
    srand(time(NULL));

    for(int i=0 ; i< filas ; i++)
    {
        for(int j = 0 ; j < columnas ; j++)
        {

            matriz[i][j] = rand()%100;

        }
    }
}

void mostrarMatriz(int matriz[][COLUMNAS], int filas, int columnas)
{
    for(int i=0 ; i< filas ; i++)
    {
        for(int j = 0 ; j < columnas ; j++)
        {
            printf("[%d] ", matriz[i][j]);
        }
        printf("\n");
    }
}

int retornaDiaMayorPrecPorMes(int matriz[][COLUMNAS], int fila, int columnas)
{
    int mayor = 0;
    int dia = 0;

    for(int i = 0 ; i<columnas; i++)
    {
        if(matriz[fila][i]>=mayor)
        {
            mayor = matriz[fila][i];
            dia = i;
        }
    }
    return dia;
}

void cargarArregloDias(int matriz[][COLUMNAS], int arregloDias[], int filas, int columnas)
{
    for(int i = 0 ; i<filas ; i++)
    {
        arregloDias[i] = retornaDiaMayorPrecPorMes(matriz, i, columnas);
    }
}

int palindromo(char *cadena)
{
    int length = strlen(cadena);
    int flag = 1;
    int i = 0;
    while (flag == 1 && i<length)
    {
        if(cadena[i] == cadena[length-i-1])
        {
            flag = 1;
            i++;
        }
        else
        {
            flag = 0;
        }

    }

    return flag;
}

void intercambio(int *a, int *b)
{
    int aux = 0;
    aux = *a;
    *a = *b;
    *b = aux;
}

int* juntarArreglos(int A[], int B[], int C[], int valA, int valB)
{
    int contA = 0;
    int contB = 0;
    C = (int*) realloc(C,(sizeof(int)*(valA+valB+2)));

    for (int i = 0 ; contA<valA && contB<valB ; i++)
    {
        if (A[contA]<=B[contB])
        {
            C[i] = A[contA];
            contA++;
        }
        else
        {
            C[i] = B[contB];
            contB++;
        }
        printf("%d\n", C[i]);
    }

    return C;
}


persona cargarPersona()
{
    persona p;
    printf("\nIngrese el nombre de la persona: ");
    gets(p.nombre);

    char genero = 0;
    int flag = 0;
    while(flag == 0)
    {

        printf("\nIngrese el genero de la persona (m/f): ");
        genero = getch();

        if(genero=='m' || genero=='f')
        {
            p.genero = genero;
            flag = 1;
        }
        else
        {
            printf("Ha ingresado un genero incorrecto. Intente nuevamente...\n");
        }
    }

    printf("\n\nIngrese la edad de la persona: ");
    scanf("%d", &p.edad);

    return p;
}

void mostrarPersona(persona p)
{
    printf("\nNOMBRE = %s", p.nombre);
    printf("\nEDAD = %d", p.edad);
    printf("\nGENERO = %c", p.genero);
}
