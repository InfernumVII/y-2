#ifndef UI_H
#define UI_H

#include "headers.h"
#define MAX_INPUT 256
void displayMenu();
void deleteRecipeByName(ArrayList* cookBook);
void searchRecipe(ArrayList* cookBook);
void addRecipe(ArrayList* cookBook);

#endif