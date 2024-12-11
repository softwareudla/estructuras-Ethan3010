#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu(){
    int opc;
    printf("1. Registrar libros\n");
    printf("2. Mostrar libros\n");
    printf("3. Buscar libro por id\n");
    printf("4. Buscar libro por titulo\n");
    printf("5. Cambiar estado\n");
    printf("6. Eliminar libro\n");
    printf("7. Salir\n");
    printf("Ingrese una opcion: ");

    scanf("%d", &opc);
    return opc;
}

int idExistente(struct Libro libros[20], int id, int n){
    for (int i = 0; i < n; i++)
    {
        if (libros[i].id==id)
        {
            return 1;
        }
        
    }
    return 0;
}

void registrarLibros(struct Libro libros[20], int i){

    int len;
    int id, anio;

    do
    {
        printf("Ingrese el id del libro %d: ", i + 1);
        scanf("%d", &libros[i].id);
        if (libros[i].id<0)
        {
            printf("El ID debe ser un numero positivo.\n");

        }else if (idExistente(libros, id, i))
        {
            printf("El ID %d ya esta registrado, ingrese un ID diferente.\n", id);
        }
        
    } while (libros[i].id<0||idExistente(libros, id, i));
    
    
    libros[i].id = id;

    printf("Ingrese el titulo del libro %d: ", i+1);
    fflush(stdin);
    fgets(libros[i].titulo,100, stdin);
    len = strlen(libros[i].titulo)-1;
    libros[i].titulo[len] = '\0';

    printf("Ingrese el autor del libro %d: ", i+1);
    fflush(stdin);
    fgets(libros[i].autor,50, stdin);
    len = strlen(libros[i].autor)-1;
    libros[i].autor[len] = '\0';

    do
    {
        printf("Ingrese el anio del libro %d: ", i+1);
        scanf("%d", &libros[i].anio);
        if (libros[i].anio <0 || libros[i].anio>2024)
        {
            printf("El anio debe ser un numero positivo y no posterior a 2024.\n");
        }
        
    } while (libros[i].anio <0 || libros[i].anio>2024);

    libros[i].anio=anio;

    strcpy(libros[i].estado, "Disponible");


}


void mostrarLibros(struct Libro libros[20], int n){
    printf("-------------------------------------------\n");
    printf("ID\t\tTitulo\t\t\tAutor\t\t\tAnio\t\tEstado\n");
 
    for (int i = 0; i < n; i++)
    {
        if (libros[i].id != 0) {
            printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n", libros[i].id, 
                                                   libros[i].titulo, 
                                                   libros[i].autor, 
                                                   libros[i].anio, 
                                                   libros[i].estado);
        
    printf("--------------------------------------------\n");
        }
    }  
}

void buscarLibroId(struct Libro libros[20], int id, int n) {
    for (int i = 0; i < n; i++) {
        if (libros[i].id == id) {
            printf("-------------\n");
            printf("Libro encontrado:\nID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
            printf("-------------\n");
            return;
        }
    }
    printf("No se encontró un libro con el ID %d.\n", id);
}

void buscarLibroTitulo(struct Libro libros[20], char titulo[], int n) {
    
    int len;

    
    getchar(); 
    fgets(titulo, 100, stdin);
    len = strlen(titulo) - 1;
    if (titulo[len] == '\n') {
        titulo[len] = '\0'; 
    }

    for (int i = 0; i < n; i++) {
        if (strcmp(libros[i].titulo, titulo) == 0) {
            printf("-----------------------\n");
            printf("Libro encontrado:\nID: %d\nTitulo: %s\nAutor: %s\nAnio: %d\nEstado: %s\n",
                   libros[i].id, libros[i].titulo, libros[i].autor, libros[i].anio, libros[i].estado);
            printf("-----------------------\n");
            return;
        }
    }
    printf("No se encontró un libro con el titulo '%s'.\n", titulo);
}

void cambiarEstado(struct Libro libros[20], int n) {
    int id;
    printf("Ingrese el ID del libro para cambiar su estado: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++) {
        if (libros[i].id == id) {
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                strcpy(libros[i].estado, "Prestado");
                printf("El libro con ID %d ahora esta marcado como Prestado.\n", id);
            } else if (strcmp(libros[i].estado, "Prestado") == 0) {
                strcpy(libros[i].estado, "Disponible");
                printf("El libro con ID %d ahora está marcado como Disponible.\n", id);
            }
            return;
        }
    }
    printf("No se encontró un libro con el ID %d.\n", id);
}

void eliminarLibro(struct Libro libros[20], int *n) {
    int opcion, id, len;
    char titulo[100];

    printf("Desea eliminar un libro por ID (1) o por Titulo (2)? ");
    scanf("%d", &opcion);
    
    if (opcion == 1) {
    
        printf("Ingrese el ID del libro a eliminar: ");
        scanf("%d", &id);

        for (int i = 0; i < *n; i++) {
            if (libros[i].id == id) {

                for (int j = i; j < *n - 1; j++) {
                    libros[j] = libros[j + 1];
                }
                (*n)--; 
                printf("El libro con ID %d ha sido eliminado.\n", id);
                return;
            }
        }
        printf("No se encontró un libro con el ID %d.\n", id);
    } else if (opcion == 2) {
    
        printf("Ingrese el titulo del libro a eliminar: ");
        getchar(); 
        fgets(titulo, 100, stdin);
        len = strlen(titulo) - 1;
        if (titulo[len] == '\n') {
            titulo[len] = '\0'; 
        }

        for (int i = 0; i < *n; i++) {
            if (strcmp(libros[i].titulo, titulo) == 0) {
                for (int j = i; j < *n - 1; j++) {
                    libros[j] = libros[j + 1];
                }
                (*n)--; 
                printf("El libro con titulo '%s' ha sido eliminado.\n", titulo);
                return;
            }
        }
        printf("No se encontró un libro con el título '%s'.\n", titulo);
    } else {
        printf("Opcion no válida.\n");
    }
}