#ifndef TRAIN_H
#define TRAIN_H

#include <stdbool.h>

typedef struct Cargo {
    /* TODO: implement */
} Cargo;

typedef struct Car {
    /* TODO: implement */
} Car;

typedef struct Train {
    /* TODO: implement */
} Train;

/* Lifecycle */
void train_init(Train *t);
void train_destroy(Train *t);

/* Lookups */
Car *train_get(Train *t, int index);
bool train_label_exists(Train *t, const char *label);

/* Insertions */
bool train_append(Train *t, const char *label, int *out_index, int *out_id);
bool train_insert(Train *t, int index, const char *label, int *out_id);

/* Deletions */
bool train_delete(Train *t, int index, int *out_id, char **out_label);

/* Printing */
void train_print(const Train *t);

/* Searching */
void train_search(const Train *t, const char *good);

#endif

