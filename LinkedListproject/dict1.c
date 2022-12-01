#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listops.h"

#define MAX_INPUT 512

int main(int argc, char*argv[]){

    list_t *list = make_empty_list();

    FILE *inFile = fopen(argv[2], "r");

    FILE *outFile = fopen(argv[3], "w");

    make_list(list, inFile, outFile);

    list_search(list, outFile);

    list_free(list);

    fclose(inFile);

    fclose(outFile);
    
    return 0;
}



