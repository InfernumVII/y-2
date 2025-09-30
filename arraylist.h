#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "headers.h"
//32
typedef struct
{
    void** data;
    size_t size;
    size_t element_size;
} ArrayList;

ArrayList* arrayListNew(size_t element_size);
void arrayListAdd(ArrayList* list, void* item);
void arrayListGet(ArrayList* list, size_t index, void* item);
void arrayListRemoveByIndex(ArrayList* list, size_t index);

#endif