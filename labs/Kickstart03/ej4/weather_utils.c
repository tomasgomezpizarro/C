
#include "weather.h"
#include "array_helpers.h"

int min_temp(WeatherTable t){
    int min = 1000000, temp;
    for (unsigned int y = 0u; y<YEARS; y++){
        for (unsigned int m = 0u; m < MONTHS; m++){
            for (unsigned int d = 0u; d < DAYS; d++){
                temp = t[y][m][d]._min_temp;
                if (temp < min){
                    min = temp;
                }
            }
        }
    }
    return min;
}

void max_temp_per_year(WeatherTable t, int output[YEARS]){
    int temp;
    for (unsigned int y = 0u; y<YEARS; y++){
        output[y] = -10000000;
        for (unsigned int m = 0u; m < MONTHS; m++){
            for (unsigned int d = 0u; d < DAYS; d++){
                temp = t[y][m][d]._max_temp;
                if (temp > output[y]){
                    output[y] = temp;
                }
            }
        }
    }    
}

void months_of_max_precps_per_year(WeatherTable t, unsigned int output[YEARS]){
    unsigned int temporal, suma;
    for (unsigned int y = 0u; y<YEARS; y++){
        temporal = 0u;
        for (unsigned int m = 0u; m < MONTHS; m++){
            suma = 0u;
            for (unsigned int d = 0u; d < DAYS; d++){
                suma += t[y][m][d]._rainfall;
            }
            if (suma > temporal){
                output[y] = m;
                temporal = suma;
            }
        }
    }    

}

