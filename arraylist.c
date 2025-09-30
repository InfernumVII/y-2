#include "arraylist.h"
#include <stdlib.h>
#include <string.h>



ArrayList* arrayListNew(size_t element_size) {
    ArrayList* list = malloc(sizeof(ArrayList));
    list->data = malloc(0);
    list->element_size = element_size;
    list->size = 0;
    return list;
}; 

void arrayListAdd(ArrayList* list, void* item) {
    list->size++;
    list->data = realloc(list->data, list->size * sizeof(void*));

    list->data[ list->size - 1 ] = malloc(list->element_size);
    // list->data[list->current_index] = item;
    memcpy(list->data[ list->size - 1 ], item, list->element_size);

    list->size++;
}

void arrayListRemoveByIndex(ArrayList* list, size_t index){
    free(list->data[index]);
    for (size_t i = index; i < list->size - 1; i++)
    {
        list->data[i] = list->data[i+1];
    }
    list->size--;
    list->data = realloc(list->data, list->size * sizeof(void*));
}

// void* arrayListGet(ArrayList* list, size_t index) {
//     return list->data[index];
// }

void arrayListGet(ArrayList* list, size_t index, void* item) {
    memcpy(item, list->data[index], list->element_size);
}
