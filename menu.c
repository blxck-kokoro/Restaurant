#include <stdio.h>

void printMenu(char *menu[], int menuSize);


char *menuCategories[5] = {"1. Appetizers", "2. Soups", "3. Main Courses", "4. Desserts", "5. Beverages"};
int menuCategoriesLength = 5;


void printMenu(char *menu[], int menuSize)
{
    for (int i = 0; i < menuSize; i++)
    {
        printf("%s          ", menu[i]);
    }
    printf("\n");
}