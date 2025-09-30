#include "arraylist.h"
#include "ui.h"
#include "recipe.h"


void displayMenu() {
    printf("========================================\n");
    printf("            COOKBOOK MENU\n");
    printf("========================================\n");
    printf("1. Add new recipe\n");
    printf("2. Delete recipe by name\n");
    printf("3. Search for recipe\n");
    printf("4. Exit\n");
    printf("========================================\n");
}

void addRecipe(ArrayList* cookBook) {
    char title[MAX_INPUT];
    char description[MAX_INPUT];
    
    printf("\n--- Add New Recipe ---\n");
    
    printf("Enter recipe title: ");
    if (fgets(title, MAX_INPUT, stdin) == NULL) return;
    title[strcspn(title, "\n")] = 0;
    
    if (strlen(title) == 0) {
        printf("Title cannot be empty.\n\n");
        return;
    }
    
    printf("Enter recipe description: ");
    if (fgets(description, MAX_INPUT, stdin) == NULL) return;
    description[strcspn(description, "\n")] = 0;
    
    
    printf("Enter the num of steps: ");
    
    int numOfSteps;
    if (scanf("%d", &numOfSteps) != 1) {
        printf("Invalid number of steps.\n\n");
        while (getchar() != '\n');
        return 1;
    }

    Recipe* recipe = recipeNew(title, description, numOfSteps);
    
    arrayListAdd(cookBook, recipe);
    
    printf("\nRecipe added successfully!\n\n");
}


void deleteRecipeByName(ArrayList* cookBook){
    char name[MAX_INPUT];
        
    printf("\n--- Delete Recipe ---\n");
    
    if (cookBook->size == 0) {
        printf("Cookbook is empty. No recipes to delete.\n\n");
        return;
    }

    printf("Enter recipe name to delete: ");
    if (fgets(name, MAX_INPUT, stdin) == NULL) return;
    name[strcspn(name, "\n")] = 0;
    
    for (size_t i = 0; i < cookBook->size; i++) {
        Recipe recipe;
        arrayListGet(cookBook, i, &recipe);
        
        if (strcmp(recipe.title, name) == 0) {
            arrayListRemoveByIndex(cookBook, i);
            printf("Recipe '%s' deleted successfully!\n\n", name);
            return;
        }
    }
}
void searchRecipe(ArrayList* cookBook) {
    char searchTerm[MAX_INPUT];
    int found = 0;
    
    printf("\n--- Search Recipe ---\n");
    
    if (cookBook->size == 0) {
        printf("Cookbook is empty. No recipes to search.\n\n");
        return;
    }
    
    printf("Enter search term: ");
    if (fgets(searchTerm, MAX_INPUT, stdin) == NULL) return;
    searchTerm[strcspn(searchTerm, "\n")] = 0;
    
    if (strlen(searchTerm) == 0) {
        printf("Search term cannot be empty.\n\n");
        return;
    }

    for (size_t i = 0; i < cookBook->size; i++) {
        Recipe recipe;
        arrayListGet(cookBook, i, &recipe);
        if (strstr(recipe.title, searchTerm) || 
            strstr(recipe.description, searchTerm) || 
            (atoi(searchTerm) > 0 && atoi(searchTerm) == recipe.numberOfSteps)) {
            recipePrintDetailed(&recipe);
            found++;
        }
    }

    if (found == 0) {
        printf("No recipes found matching '%s'.\n", searchTerm);
    }
    printf("\n");
}
