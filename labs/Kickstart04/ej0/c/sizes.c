#include <stdio.h>
#include <stdlib.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {35, 169, "MESSI", "al"};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(name_t), sizeof(unsigned int), sizeof(unsigned int), sizeof(data_t));

    printf("pointer-size: %lu bytes\n", sizeof(&messi));

    return EXIT_SUCCESS;
}

