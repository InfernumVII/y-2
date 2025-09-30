#include "recipe.h"


Recipe* recipeNew(const char* title, const char* description, const int numberOfSteps){
    Recipe* recipe = malloc(sizeof(Recipe));
    recipe->title = malloc(strlen(title) + 1);
    strcpy(recipe->title, title);
    recipe->description = malloc(strlen(description) + 1);
    strcpy(recipe->description, description);
    recipe->numberOfSteps = numberOfSteps;
    return recipe;
}

void recipePrintDetailed(Recipe* recipe) {
    printf("\n----------------------------------------\n");
    printf("Title: %s\n", recipe->title);
    printf("Description: %s\n", recipe->description);
    printf("Number of Steps: %d\n", recipe->numberOfSteps);
    printf("----------------------------------------\n");
}