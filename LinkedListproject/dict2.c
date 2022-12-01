#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "array.h"

#define MAXLEN 128
#define MAX_INPUT 512
#define ORI_SIZE 2

int main(int argc, char*argv[]){
    
    list_t *list = make_empty_list();

    array_t *node_arr = make_array();

    FILE *inFile = fopen(argv[2], "r");

    FILE *outFile = fopen(argv[3], "w");

    make_list(list, inFile, outFile);

    traverse_append(node_arr, list);

    array_shrink(node_arr);

    array_sort(node_arr);

    lowest_diff(node_arr, outFile);

    list_free(list);

    array_free(node_arr);
    
    fclose(inFile);

    fclose(outFile);
    
    return 0;
}

