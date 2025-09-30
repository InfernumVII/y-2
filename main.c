#include <stdio.h>
#include "arraylist.h"

//collection ui domain  



int main() {
    ArrayList* list = arrayListNew(sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        arrayListAdd(list, &i);
    }
    
    for (size_t i = 0; i < list->size; i++)
    {
        int* retrieved = arrayListGet(list, i);
        printf("%d\n", *retrieved);
    }
    
    
    
    printf("Hello World");
    return 0;
}