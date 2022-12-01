#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

int empty_field(int count, char* input){
    if (input[count] == ','){
        return 1;
    }
    return 0;
}

int case_quotation(int count, char* input){
    if(input[count] == '\"'){
        return 1;
    }
    return 0;
}

int str_scan(char* src, char* location, int count){
    int char_q;
    if (empty_field(count, src)){
            strcpy(location, "");
            char_q = 0;
            char_q++;
        }
        else if (case_quotation(count, src)){
            count += 1;
            sscanf(src + count, "%[^\"]%n,", location, &char_q);
            char_q += 3;
        }
        else{
            sscanf(src + count, "%[^,],%n", location, &char_q);
        }
    return char_q;
}

int double_scan(char* src, double* location, int count){
    int char_q;
    sscanf(src + count, "%128lf,%n)", location, &char_q);
    return char_q;
}

int int_scan(char* src, int* location, int count){
    int char_q;
    double temp_store;
    sscanf(src + count, "%lf,%n)", &temp_store, &char_q);
    *location = (int) temp_store;
    return char_q;
}
