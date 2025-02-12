#include "sequence.h"
#include <stddef.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

void sequence_init(Sequence *seq) {
    seq->data = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    seq->size = 0;
    seq->capacity = INITIAL_CAPACITY;
}

void sequence_append(Sequence *seq, int value) {
    if (seq->size == seq->capacity) {
        size_t new_capacity = seq->capacity * 2;
        seq->data = (int*)realloc(seq->data, new_capacity * sizeof(int));
        seq->capacity = new_capacity;
    }
    seq->data[seq->size] = value;
    seq->size++;
}

void sequence_free(Sequence *seq) {
    free(seq->data);
}

int sequence_get(const Sequence *seq, size_t index) {
    return seq->data[index];
}

// Функция сортировки (пузырьком)
void sequence_sort(Sequence *seq) {
    for (size_t i = 0; i < seq->size - 1; i++) {
        for (size_t j = 0; j < seq->size - i - 1; j++) {
            if (seq->data[j] > seq->data[j + 1]) {
                int temp = seq->data[j];
                seq->data[j] = seq->data[j + 1];
                seq->data[j + 1] = temp;
            }
        }
    }
}

int sequence_find_nth_largest(const Sequence *seq, int n) {
    // 1. Создаем КОПИЮ последовательности.
    Sequence temp_seq;
    sequence_init(&temp_seq);
    temp_seq.size = seq->size;
    temp_seq.capacity = seq->capacity;
    temp_seq.data = (int*)malloc(temp_seq.capacity * sizeof(int));
    for (size_t i = 0; i < seq->size; i++) {
        temp_seq.data[i] = seq->data[i];
    }

    // 2. Сортируем копию.
    sequence_sort(&temp_seq);

    // 3. Создаем массив уникальных значений.
    int *unique_values = (int*)malloc(temp_seq.size * sizeof(int));
    size_t unique_count = 0;

    for (size_t i = 0; i < temp_seq.size; i++) {
        int found = 0;
        for (size_t j = 0; j < unique_count; j++) {
            if (unique_values[j] == temp_seq.data[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unique_values[unique_count++] = temp_seq.data[i];
        }
    }

    if (n > 0 && n <= (int)unique_count) { // Преобразуем unique_count к int
        int result = unique_values[unique_count - n];
        free(unique_values);
        sequence_free(&temp_seq); // Освобождаем память, выделенную для копии
        return result;
    } else {
        free(unique_values);
        sequence_free(&temp_seq); // Освобождаем память, выделенную для копии
        return -1;
    }
}

int sequence_find_mth_smallest(const Sequence *seq, int m) {
    // 1. Создаем КОПИЮ последовательности.
    Sequence temp_seq;
    sequence_init(&temp_seq);
    temp_seq.size = seq->size;
    temp_seq.capacity = seq->capacity;
    temp_seq.data = (int*)malloc(temp_seq.capacity * sizeof(int));
    for (size_t i = 0; i < seq->size; i++) {
        temp_seq.data[i] = seq->data[i];
    }

    // 2. Сортируем копию.
    sequence_sort(&temp_seq);

    // 3. Создаем массив уникальных значений.
    int *unique_values = (int*)malloc(temp_seq.size * sizeof(int));
    size_t unique_count = 0;

    for (size_t i = 0; i < temp_seq.size; i++) {
        int found = 0;
        for (size_t j = 0; j < unique_count; j++) {
            if (unique_values[j] == temp_seq.data[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unique_values[unique_count++] = temp_seq.data[i];
        }
    }

    if (m > 0 && m <= (int)unique_count) { // Преобразуем unique_count к int
        int result = unique_values[m - 1];
        free(unique_values);
        sequence_free(&temp_seq); // Освобождаем память, выделенную для копии
        return result;
    } else {
        free(unique_values);
        sequence_free(&temp_seq); // Освобождаем память, выделенную для копии
        return -1;
    }
}

void sequence_print(const Sequence *seq) {
    printf("Sequence: ");
    for (size_t i = 0; i < seq->size; i++) {
        printf("%d ", seq->data[i]);
    }
    printf("n");
}