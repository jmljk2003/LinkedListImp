#include "data.h"
#include "listops.h"

#define MAXLEN 128
#define MAX_INPUT 512
#define ORI_SIZE 2

typedef struct array array_t;

array_t *make_array();

void array_append(array_t *arr, node_t *node);

void array_shrink(array_t *arr);

void array_sort(array_t *arr);

void traverse_append(array_t *arr, list_t* list);

void lowest_diff(array_t *arr, FILE* outfile);

void array_free(array_t* arr);

struct array{
    node_t **ptr_arr;
    int size;
    int n;
};