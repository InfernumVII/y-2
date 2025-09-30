#include "arraylist.h"
#include <memory.h>



ArrayList* arrayListNew(size_t element_size) {
    ArrayList* list = malloc(sizeof(ArrayList));
    list->element_size = element_size;
    list->current_index = 0;
    list->size = 0;
    return list;
}; 

void arrayListAdd(ArrayList* list, void* item) {
    list->data[ list->current_index ] = malloc(list->element_size);
    memcpy(list->data[ list->current_index ], item, list->element_size);

    list->current_index++;
    list->size++;
}

void* arrayListGet(ArrayList* list, size_t index) {
    return list->data[index];
}