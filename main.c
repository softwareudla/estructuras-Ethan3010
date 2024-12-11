#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {

    struct Libro libros[20];
    int opc;
    int i=0;
    do{
    opc = menu();
    switch (opc)
    {
        case 1:
            registrarLibros(libros, i);
            i++;
            break;
        case 2:
            mostrarLibros(libros, i);     
            break;
       
        case 3:
        {    int id;
            printf("Ingrese el id del libro a buscar: ");
            scanf("%d", &id);
            buscarLibroId(libros, id, i);
            break;
        }
        case 4:
        {    char titulo[100];
            printf("Ingrese el titulo del libro a buscar: ");
            buscarLibroTitulo(libros, titulo, i);
            break;
        }    
        case 5:
            cambiarEstado(libros, i); // Llamada a la nueva función
            break;   
        case 6:
            eliminarLibro(libros, &i); // Llamada a la nueva función
            break;
    
    }
    }while(opc != 7);


    return 0;
}