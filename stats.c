#include "stats.h"
#include <math.h>

double calculate_mean(const int *data, size_t start, size_t end) {
    double sum = 0.0;
    for (size_t i = start; i <= end; i++) {
        sum += (double)data[i];
    }
    return sum / (double)(end - start + 1);
}

double calculate_standard_deviation(const int *data, size_t start, size_t end, double mean) {
    double sum_squared_diff = 0.0;
    for (size_t i = start; i <= end; i++) {
        sum_squared_diff += pow((double)data[i] - mean, 2);
    }
    return sqrt(sum_squared_diff / (double)(end - start + 1));
}