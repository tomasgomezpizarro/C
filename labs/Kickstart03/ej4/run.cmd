gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c weather.c main.c weather_utils.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 array_helpers.o weather.o main.o weather_utils.o -o weather
weather ../input/weather_cordoba.in