#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    char **data;
    size_t size;
    size_t capacity;
} Vector;

void vector_init(Vector *vec) {
    vec->size = 0;
    vec->capacity = 4;
    vec->data = malloc(vec->capacity * sizeof(char *));
}

void vector_push_back(Vector *vec, const char* str) {
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(char *));
    }
    vec->data[vec->size] = malloc(strlen(str) + 1);
    strcpy(vec->data[vec->size++], str);
}

void vector_free(Vector *vec) {
    for (size_t i = 0; i < vec->size; i++) {
        free(vec->data[i]);
    }
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

void vector_remove(Vector *vec, size_t index) {
    if (index >= vec->size) {
        fprintf(stderr, "Index out of bounds\n");
        return;
    }

    free(vec->data[index]);

    for (size_t i = index; i < vec->size - 1; i++) {
        vec->data[i] = vec->data[i + 1];
    }

    vec->size--;
}
