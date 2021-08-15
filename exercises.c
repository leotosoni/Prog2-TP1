#define DIMENSION 50
#define FILAS 12
#define COLUMNAS 31

void ejercicio1()
{
    int arreglo[DIMENSION];

    inicArreglo(arreglo, DIMENSION);
    mostrarArreglo(arreglo, DIMENSION);

}

void ejercicio2()
{
    int arreglo[DIMENSION];
    inicArreglo(arreglo,DIMENSION);
    cargarArreglo(arreglo, DIMENSION);
    int suma = sumaArreglo(arreglo,DIMENSION);
    printf("Suma del arreglo: %d\n", suma);
    mostrarArreglo(arreglo, DIMENSION);
}

void ejercicio3()
{
    int arreglo[] = {1,2,3,4};

    int decimal = retornarDecimal(arreglo, 4);

    printf("Decimal de arreglo: %d\n", decimal);

}

void ejercicio4()
{
    int arreglo[] = {1,10,3,4,40,1,2,6,3,45};
    int posMayor = retornarValorMaximo(arreglo, 10);
    printf("Posicion del valor mayor es: %d\n",posMayor);

}

void ejercicio5()
{
    int matriz[FILAS][COLUMNAS];

    cargarMatriz(matriz, FILAS, COLUMNAS);

    mostrarMatriz(matriz, FILAS, COLUMNAS);

//    int dia = retornaDiaMayorPrecPorMes(matriz, 5,31);

//    printf("Dia de mayor precipitacion del mes 5 es: %d\n", dia);
    int arregloDias[FILAS];
    cargarArregloDias(matriz, arregloDias, FILAS, COLUMNAS);
    mostrarArreglo(arregloDias, FILAS);
}

void ejercicio6()
{
    char *cadena = "hola";

    int resultado = palindromo(cadena);

    if (resultado==1)
    {
        printf("%s es un palindromo", cadena);
    }
    else
    {
        printf("%s NO es un palindromo", cadena);
    }
}

void ejercicio7()
{

    int *a = (int*) malloc(sizeof(int));
    int *b = (int*) malloc(sizeof(int));

    scanf("%d", a);
    scanf("%d", b);

    intercambio(a, b);
    printf("Valor de a: %d | Valor de b: %d", *a, *b);

    free(a);
    free(b);


}

void ejercicio8()
{
    /*Dados dos arreglos de números enteros ordenados de menor a mayor, hacer una función que los reciba como
parámetros y retorne un tercer arreglo que contenga los datos de los arreglos anteriores, también ordenados. Se los
debe intercalar.*/

int arreglo1[] = {1,3,5,7,9};
int arreglo2[] = {2,4,6,8};

int *arreglo3 = (int*) malloc(sizeof(int));
for(int i = 0 ; i< 10 ; i++)
{
    printf("%d\n", arreglo3[i]);
}

arreglo3 = juntarArreglos(arreglo1, arreglo2, 5, 4);

}
