#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "stats.h"
#include <stddef.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Sequence sequence;
    sequence_init(&sequence);

    int value;
    while (scanf("%d", &value) == 1 && value != -1) {
        sequence_append(&sequence, value);
    }

    int nth_largest = sequence_find_nth_largest(&sequence, n);
    int mth_smallest = sequence_find_mth_smallest(&sequence, m);

    printf("%d %d\n", nth_largest, mth_smallest);

    // Находим индексы для nth_largest и mth_smallest
    size_t start_index = -1, end_index = -1;
    for (size_t i = 0; i < sequence.size; i++) {
        if (sequence.data[i] == mth_smallest) { // mth_smallest теперь первый
            start_index = i;
            break;
        }
    }
    for (size_t i = 0; i < sequence.size; i++) {
        if (sequence.data[i] == nth_largest) { // nth_largest - второй
            end_index = i;
            break;
        }
    }

    // Обеспечиваем правильный порядок индексов
    if (start_index > end_index) {
        size_t temp = start_index;
        start_index = end_index;
        end_index = temp;
    }

    // Вычисление среднего и стандартного отклонения
    double mean = calculate_mean(sequence.data, start_index, end_index);
    double std_dev = calculate_standard_deviation(sequence.data, start_index, end_index, mean);

    printf("%.1f %.1f\n", mean, std_dev);

    sequence_free(&sequence);
    return 0;
}