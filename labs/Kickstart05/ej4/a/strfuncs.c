#include <stdlib.h>

size_t string_length(const char *str){
    size_t size = 0u;
    while (str[size] != '\0'){
        size ++;
    }
    return size;
}
char *string_filter(const char *str, char c){
    size_t len = string_length(str);
    char* new = (char*)malloc(len + 1);
    size_t ocurrencies = 0;
    for (size_t i = 0u; i < len; i++){
        if (str[i] == c){
            ocurrencies ++;
        } else {
            new[i - ocurrencies] = str[i];
        }
    }
    new[len-ocurrencies] = '\0';   
    new = realloc(new, len - ocurrencies + 1);
    return new;
}