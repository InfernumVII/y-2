#include "arraylist.h"
#include "recipe.h"
#include "ui.h"
#include "headers.h"

int main() {
    ArrayList* cookBook = arrayListNew(sizeof(Recipe));
    int choice;
    while (1)
    {
        displayMenu();
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            continue;
        };
        while (getchar() != '\n');

        switch (choice)
        {
            case 1:
                addRecipe(cookBook);
                break;
            case 2:
                deleteRecipeByName(cookBook);
                break;
            case 3:
                searchRecipe(cookBook);
                break;
            case 4:
                return 0;
                break;
            
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    

    return 0;
}