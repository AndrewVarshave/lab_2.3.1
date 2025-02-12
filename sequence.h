#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Sequence;

void sequence_init(Sequence *seq);
void sequence_append(Sequence *seq, int value);
void sequence_free(Sequence *seq);
int sequence_get(const Sequence *seq, size_t index);
void sequence_sort(Sequence *seq);
int sequence_find_nth_largest(const Sequence *seq, int n);
int sequence_find_mth_smallest(const Sequence *seq, int m);
void sequence_print(const Sequence *seq);

#endif