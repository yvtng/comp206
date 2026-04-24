#include "train.h"
#include "cargo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------ Lifecycle ------------------ */

void train_init(Train *t) {
    /* TODO: implement */
}

void train_destroy(Train *t) {
    /* TODO: implement */
}

/* ------------------ Lookups ------------------ */

Car *train_get(Train *t, int index) {
    /* TODO: implement */
    return NULL;
}

bool train_label_exists(Train *t, const char *label) {
    /* TODO: implement */
    return false;
}

/* ------------------ Insertions ------------------ */

bool train_append(Train *t, const char *label, int *out_index, int *out_id) {
    /* TODO: implement */
    return false;
}

bool train_insert(Train *t, int index, const char *label, int *out_id) {
    /* TODO: implement */
    return false;
}

/* ------------------ Deletions ------------------ */

bool train_delete(Train *t, int index, int *out_id, char **out_label) {
    /* TODO: implement */
    return false;
}

/* ------------------ Printing ------------------ */

void train_print(const Train *t) {
    /* TODO: implement */
}

/* ------------------ Searching ------------------ */

void train_search(const Train *t, const char *good) {
    /* TODO: implement */
}

