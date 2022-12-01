#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "listops.h"
#include "data.h"


list_t *make_empty_list(void) {
	list_t *list;
	list = (list_t*)malloc(sizeof(*list));
	list->head = list->foot = NULL;
	return list;
}

list_t* insert_at_head(list_t *list, data_t element) {
	node_t *new_node;
	new_node = (node_t*)malloc(sizeof(*new_node));
	new_node->data = element;
	new_node->next = list->head;
	list->head = new_node;
	if (list->foot==NULL) {
		list->foot = new_node;
	}
	return list;
}

list_t* insert_at_foot(list_t *list, data_t element) {
	node_t *new_node;
	new_node = (node_t*)malloc(sizeof(*new_node));
	new_node->data = element;
	new_node->next = NULL;
	if (list->foot==NULL) {
		list->head = list->foot = new_node;
	} else {
		list->foot->next = new_node;
		list->foot = new_node;
	}
	return list;
}

void make_list(list_t* list, FILE* inFile, FILE* outFile){

    char redundant[MAX_INPUT + 1];

    char input[MAX_INPUT + 1];

    int element_no = 0;

    data_t *temp = (data_t*)malloc(sizeof(data_t));
    
    fscanf(inFile, "%s\n", redundant);
    while(fgets(input, MAX_INPUT + 1, inFile)){
        
        int true_count = 0;
        true_count += int_scan(input, &temp->footpath_id, true_count);
        true_count += str_scan(input, temp->address, true_count);
        true_count += str_scan(input, temp->clue_sa, true_count);
        true_count += str_scan(input, temp->asset_type, true_count);
        true_count += double_scan(input, &temp->deltaz, true_count);
        true_count += double_scan(input, &temp->distance, true_count);
        true_count += double_scan(input, &temp->gradelin, true_count);
        true_count += int_scan(input, &temp->mcc_id, true_count);
        true_count += int_scan(input, &temp->mccid_int, true_count);
        true_count += double_scan(input, &temp->rlmax, true_count);
        true_count += double_scan(input, &temp->rlmin, true_count);
        true_count += str_scan(input, temp->segside, true_count);
        true_count += int_scan(input, &temp->statusid, true_count);
        true_count += int_scan(input, &temp->streetid, true_count);
        true_count += int_scan(input, &temp->street_grp, true_count);
        true_count += double_scan(input, &temp->start_lat, true_count);
        true_count += double_scan(input, &temp->start_lon, true_count);
        true_count += double_scan(input, &temp->end_lat, true_count);
        true_count += double_scan(input, &temp->end_lon, true_count);
        
        if (element_no == 0){
            insert_at_head(list, *temp);
        }
        else{
            traverse_add(list, temp);
        }
        element_no += 1;
    }
    free(temp);
}

void traverse_add(list_t* list, data_t* element){
    node_t* curr_node = list->head;
    while(curr_node != NULL){
        curr_node = curr_node->next;
    }
    list = insert_at_foot(list, *element);
}

void list_search(list_t* list, FILE* outFile){
    char take[MAXLEN + 1];
    char key[MAXLEN + 1];
    while(fgets(take, MAXLEN + 1, stdin)){
        sscanf(take, "%129[^\n]", key);
        traverse_search(list, key, outFile);
    }
}

void traverse_search(list_t* list, char* key, FILE* outFile){
    int sim_count = 0;
    fprintf(outFile, "%s\n", key);
    node_t* curr_node = list->head;
    while (curr_node != NULL){
        if(strcmp(key, curr_node->data.address) == 0){
            node_print(curr_node, outFile);
            sim_count += 1;
        }
        curr_node = curr_node->next;
    }
    if(sim_count == 0){
        printf("%s --> NOTFOUND\n", key);
    }
    else{
        printf("%s --> %d\n", key, sim_count);
    }
}

void list_free(list_t* list){
    node_t *curr_node, *last_node;
    curr_node = list->head;
    while(curr_node){
        last_node = curr_node;
        curr_node = curr_node->next;
        free(last_node);
    }
    free(list);
}

void node_print(node_t* node_in, FILE* out){
    fprintf(out,"--> footpath_id: %d || address: %s || "
            "clue_sa: %s || asset_type: %s || deltaz: %.2lf || "
            "distance: %.2lf || grade1in: %.1lf || mcc_id: %d || "
            "mccid_int: %d || rlmax: %.2lf || rlmin: %.2lf || "
            "segside: %s || statusid: %d || streetid: %d || "
            "street_group: %d || start_lat: %lf || start_lon: %lf || "
            "end_lat: %lf || end_lon: %lf || \n",node_in->data.footpath_id,
            node_in->data.address,node_in->data.clue_sa,node_in->data.asset_type,
            node_in->data.deltaz,node_in->data.distance,node_in->data.gradelin,
            node_in->data.mcc_id,node_in->data.mccid_int,node_in->data.rlmax,
            node_in->data.rlmin,node_in->data.segside,node_in->data.statusid,
            node_in->data.streetid,node_in->data.street_grp,node_in->data.start_lat,
            node_in->data.start_lon,node_in->data.end_lat,node_in->data.end_lon);
} 