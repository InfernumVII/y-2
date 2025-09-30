#include <stddef.h> //size_t
#include <stdbool.h>


typedef struct
{
    void** data;
    size_t size;
    size_t current_index;
    size_t element_size;
} ArrayList;

ArrayList* arrayListNew(size_t element_size);
void arrayListAdd(ArrayList* list, void* item);
void* arrayListGet(ArrayList* list, size_t index);