gcc -Wall -Werror -Wextra -pedantic -std=c99 -c hanoi.c main.c stack.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 hanoi.o main.o stack.o -o hanoi
hanoi 10