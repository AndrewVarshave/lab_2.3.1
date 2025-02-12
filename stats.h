#ifndef STATS_H
#define STATS_H

#include <stddef.h>

double calculate_mean(const int *data, size_t start, size_t end);
double calculate_standard_deviation(const int *data, size_t start, size_t end, double mean);

#endif