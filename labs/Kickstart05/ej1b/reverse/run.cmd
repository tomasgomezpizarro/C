gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c reverse.c ..\stack.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 array_helpers.o reverse.o stack.o -o reverse
reverse input\empty.in