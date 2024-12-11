struct Libro
{
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[20];
};

int menu();
int idExistente(struct Libro libros[20], int id, int n);
void registrarLibros(struct Libro libros[20], int i);
void mostrarLibros(struct Libro libros[20], int n);
void buscarLibroId(struct Libro libros[20], int id, int n);
void buscarLibroTitulo(struct Libro libros[20], char titulo[], int n);
void cambiarEstado(struct Libro libros[20], int n);
void eliminarLibro(struct Libro libros[20], int *n);