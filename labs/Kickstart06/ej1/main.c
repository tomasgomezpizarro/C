/* First, the standard lib includes, alphabetically ordered */
#include <stdbool.h> // Para usar el tipo bool
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abb.h" /* TAD abb */


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

abb abb_from_file(const char *filepath) {
    FILE *file = NULL;
    abb read_tree;
    read_tree = abb_empty();
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid format.\n");
        exit(EXIT_FAILURE);
    }
    
    while (i < size) {
        abb_elem elem;
        res = fscanf(file," %d ", &(elem));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        read_tree = abb_add(read_tree, elem);

       ++i;
    }
    fclose(file);
    return read_tree;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* parse the file to obtain an abb with the elements */
    abb tree = abb_from_file(filepath);

    /* dumping the tree */
    abb_dump(tree);
    if (!abb_is_empty(tree)) {
        printf("\n");
        printf("raiz: %d\nminimo: %d\nmaximo: %d\n", abb_root(tree),
                                                       abb_min(tree),
                                                       abb_max(tree));
    } else {
        printf("\nÁrbol vacío\n");
    }

    /* Interactive menu */
    bool exit = false;
    while (!exit) {
        printf("\nOpciones:\n");
        printf("1 ........ Mostrar árbol por pantalla\n");
        printf("2 ........ Agregar un elemento\n");
        printf("3 ........ Eliminar un elemento\n");
        printf("4 ........ Chequear existencia de elemento\n");
        printf("5 ........ Mostrar longitud del árbol\n");
        printf("6 ........ Mostrar raiz, máximo y mínimo del árbol\n");
        printf("7 ........ Salir\n");
        printf("Ingrese una opción: ");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1: // Mostrar árbol por pantalla
                abb_dump(tree);
                break;

            case 2: { // Agregar un elemento
                abb_elem elem;
                printf("Ingrese el elemento a agregar: ");
                scanf("%d", &elem);
                tree = abb_add(tree, elem);
                printf("Elemento %d agregado.\n", elem);
                break;
            }

            case 3: { // Eliminar un elemento
                abb_elem elem;
                printf("Ingrese el elemento a eliminar: ");
                scanf("%d", &elem);
                if (abb_exists(tree, elem)) {
                    printf("Elemento %d eliminado.\n", elem);
                } else {
                    printf("El elemento %d no existe en el árbol.\n", elem);
                }
                break;
            }

            case 4: { // Chequear existencia de elemento
                abb_elem elem;
                printf("Ingrese el elemento a chequear: ");
                scanf("%d", &elem);
                if (abb_exists(tree, elem)) {
                    printf("El elemento %d existe en el árbol.\n", elem);
                } else {
                    printf("El elemento %d no existe en el árbol.\n", elem);
                }
                break;
            }

            case 5: // Mostrar longitud del árbol
                printf("Longitud del árbol: %u\n", abb_length(tree));
                break;

            case 6: // Mostrar raiz, máximo y mínimo del árbol
                if (!abb_is_empty(tree)) {
                    printf("raiz: %d\nminimo: %d\nmaximo: %d\n", abb_root(tree),
                                                                   abb_min(tree),
                                                                   abb_max(tree));
                } else {
                    printf("Árbol vacío\n");
                }
                break;

            case 7: // Salir
                exit = true;
                break;

            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    }

    /* Destroy the tree */
    tree = abb_destroy(tree);

    return EXIT_SUCCESS;
}