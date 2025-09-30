#include "headers.h"
typedef struct 
{
    char *title;
    char *description;
    int numberOfSteps;
} Recipe;

Recipe* recipeNew(const char* title, const char* description, const int numberOfSteps);
void recipePrintDetailed(Recipe* recipe);