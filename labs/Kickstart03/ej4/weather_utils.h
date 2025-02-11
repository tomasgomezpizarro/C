#ifndef WEATHER_UTILS_H
#define WEATHER_UTILS_H

#include "weather.h"
#include "array_helpers.h"

int min_temp(WeatherTable t);

void max_temp_per_year(WeatherTable a, int output[YEARS]);

void months_of_max_precps_per_year(WeatherTable a, int output[YEARS]);

#endif
