/*
  @file sort.h
  @brief Sort functions declarations
*/
#ifndef _SORT_H
#define _SORT_H
#include <stdbool.h>
#include "player.h"

#define LENGTH 2185u


bool goes_before(player_t x, player_t y);


bool array_is_sorted(player_t atp[], unsigned int length);



void sort(player_t a[], unsigned int length);

void merge(player_t a[], unsigned int start, unsigned int end);

void print_array(player_t a[], unsigned int length);

#endif
