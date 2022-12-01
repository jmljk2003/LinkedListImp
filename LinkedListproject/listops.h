#include "data.h"

#define MAXLEN 128
#define MAX_INPUT 512

typedef struct node node_t;
typedef struct info_t data_t;

struct info_t{
    int footpath_id;
    char address[MAXLEN + 1];
    char clue_sa[MAXLEN + 1];
    char asset_type[MAXLEN + 1];
    double deltaz;
    double distance;
    double gradelin;
    int mcc_id;
    int mccid_int;
    double rlmax;
    double rlmin;
    char segside[MAXLEN + 1];
    int statusid;
    int streetid;
    int street_grp;
    double start_lat;
    double start_lon;
    double end_lat;
    double end_lon;
};
struct node {
	data_t data;
	node_t *next;
};

typedef struct {
	node_t *head;
	node_t *foot;
} list_t;

void list_free(list_t* list);

list_t *make_empty_list(void);

list_t* insert_at_head(list_t *list, data_t element);

list_t* insert_at_foot(list_t *list, data_t element);

void traverse_add(list_t* list, data_t* element);

void make_list(list_t* list, FILE* inFile, FILE* outFile);

void list_search(list_t* list, FILE* outFile);

void traverse_search(list_t* list, char* key, FILE* outFile);

void node_print(node_t* node_in, FILE* out);
