#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "menu.c"

#define MENU_CATEGORIES_LENGTH 5

int main(void)
{
    printf("Welcome to the restaurant!\n");

    char *menuCategories[MENU_CATEGORIES_LENGTH] = {"1. Appetizers", "2. Soups", "3. Main Courses", "4. Desserts", "5. Beverages"};

    char menuSwitch = 'a';
    while((int)menuSwitch != 10)
    {
        printf("Press enter to display our menu.\n");
        scanf("%c", &menuSwitch);
    }

    int appetizersSize = getFileLines("Dishes/appetizers.txt") / 2;
    dish *appetizers = malloc(appetizersSize * sizeof(dish));
    makeDishesArray(appetizers, appetizersSize, "Dishes/appetizers.txt");
}