gcc -Wall -Wextra -pedantic -std=c99 -c helpers.c sort.c main.c
gcc -Wall -Wextra -pedantic -std=c99 helpers.o sort.o main.o -o mysort
mysort ../input/atp-players2022.in > sorted.out