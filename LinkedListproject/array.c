#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "array.h"

array_t *make_array(){
    array_t *arr = malloc(sizeof(*arr));
    int temp_size = ORI_SIZE;
    arr->size = temp_size;
    arr->ptr_arr = malloc(temp_size * sizeof(*(arr->ptr_arr)));
    arr->n = 0;
    return arr;
};

void arrayAppend(array_t *arr, node_t *node){
	if(arr->size == arr->n){
		arr->size *= 2;
		arr->ptr_arr = realloc(arr->ptr_arr, arr->size * sizeof(*(arr->ptr_arr)));
	}
    if (arr->n < arr->size){
		arr->ptr_arr[arr->n] = node;
		(arr->n)++;
	}
}

void traverse_append(array_t *arr, list_t* list){
    node_t* curr_node = list->head;
    while(curr_node != NULL){
        arrayAppend(arr, curr_node);
        curr_node = curr_node->next;
    }
}

void array_shrink(array_t *arr){
    if (arr->size != arr->n) {
		arr->size = (arr->n > ORI_SIZE) ? arr->n : ORI_SIZE;
		arr->ptr_arr = realloc(arr->ptr_arr, arr->size * sizeof(*(arr->ptr_arr)));
		assert(arr->ptr_arr);
	}
}


void array_sort(array_t *arr){
    for(int i = 0; i < arr->n; i++){
        for(int j = i + 1; j < arr->n; j++){
            if(arr->ptr_arr[i]->data.gradelin > arr->ptr_arr[j]->data.gradelin){
                node_t* temp = arr->ptr_arr[i];
                arr->ptr_arr[i] = arr->ptr_arr[j];
                arr->ptr_arr[j] = temp;
            }
        }
    }
}

void lowest_diff(array_t *arr, FILE* outfile){
    char key_str[MAXLEN + 1];
    while(fgets(key_str, MAXLEN + 1, stdin)){
        double key;
        sscanf(key_str, "%lf", &key);
        strtok(key_str, "\n");
        double curr_low = fabs(key - (arr->ptr_arr[0]->data.gradelin));
        int curr_low_ind = 0;
        if(arr->n == 1){
            fprintf(outfile, "%s\n",key_str);
            node_print(arr->ptr_arr[0], outfile);

            printf("%s --> %0.1lf\n",key_str,arr->ptr_arr[0]->data.gradelin);
        }  
        else{
            for(int i = 1; i < arr->n; i++){
                double temp = fabs(key - (arr->ptr_arr[i]->data.gradelin));
                if(temp < curr_low){
                    curr_low = temp;
                    curr_low_ind = i;
                }
            }
            fprintf(outfile, "%s\n",key_str);
            node_print(arr->ptr_arr[curr_low_ind], outfile);

            printf("%s --> %0.1f\n",key_str ,arr->ptr_arr[curr_low_ind]->data.gradelin);
        }
    }
}

void array_free(array_t* arr){
    free(arr->ptr_arr);
    free(arr);
}