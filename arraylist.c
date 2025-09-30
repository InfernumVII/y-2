#include "arraylist.h"
#include <stdlib.h>



ArrayList* arrayListNew(size_t element_size) {
    ArrayList* list = malloc(sizeof(ArrayList));
    list->capacity = 0;
    list->data = malloc(0);
    list->element_size = element_size;
    list->current_index = 0;
    list->size = 0;
    return list;
}; 

void arrayListAdd(ArrayList* list, void* item) {
    list->capacity++;
    list->data = realloc(list->data, list->capacity * sizeof(void*));

    list->data[ list->current_index ] = malloc(list->element_size);
    // list->data[list->current_index] = item;
    memcpy(list->data[ list->current_index ], item, list->element_size);

    list->current_index++;
    list->size++;
}

void* arrayListGet(ArrayList* list, size_t index) {
    return list->data[index];
}

void arrayListMyGet(ArrayList* list, size_t index, void* item) {
    memcpy(item, list->data[index], list->element_size);
}
