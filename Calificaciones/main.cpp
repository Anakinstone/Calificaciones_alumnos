#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <iostream>

float promedio(int valores[], int cantidad) {
    int i;
    float suma = 0.0;

    for (i = 0; i < cantidad; ++i)
        suma += valores[i];

    return suma / (float) cantidad;
}

using namespace std;
int main() {

    int notas[10];
    char nombre[20];
    char opcion[3];
    int examen[10];
    int n, i;
    ofstream registro;

    registro.open("/Users/andresaguilar/CLionProjects/Calificaciones/alumnos/registro.txt",ios::app);



    do {
        printf("Ingrese nombre del alumno: ");
        scanf("%s", nombre);

        printf("Cuantas notas tiene %s? ", nombre);
        scanf("%d", &n);

        for (i = 0; i < n; ++i) {
            printf("  Nota %d: ", i + 1);
            scanf("%d", &notas[i]);
        }


        printf("El promedio de %s es %.1f\n", nombre, promedio(notas, n));
        registro<<nombre;
        registro<<" ";
        registro<<promedio(notas, n)<<endl;
        printf("Desea calcular mas promedios (si/no)? ");
        scanf("%s", opcion);

    } while (opcion[0] == 's' || opcion[0] == 'S');
    using namespace std;
    string texto;
    ifstream registro_finales;
    registro_finales.open("/Users/andresaguilar/CLionProjects/Calificaciones/alumnos/registro.txt",ios::in);
    if (registro_finales.fail()){
        printf("No se puede abrir el archivo");
        exit(1);
    }
    while(!registro_finales.eof()){
        getline(registro_finales,texto);
        cout<<texto<<endl;

    }


    return 0;
}