#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "menu.c"

int main(void)
{
    printf("Welcome to the restaurant!\n");

    char menuSwitch;
    while((int)menuSwitch != 10)
    {
        printf("Press enter to display our menu.\n");
        scanf("%c", &menuSwitch);
    }
    printMenu(menuCategories, menuCategoriesLength);

    int appetizersNamesSize = getFileLines("Dishes/appetizers.txt") / 2;
    int appetizersNamesElementSize = 256;

    char appetizersNames[appetizersNamesSize][appetizersNamesElementSize];
    getDishesNames(appetizersNamesSize, appetizersNamesElementSize, appetizersNames, "Dishes/appetizers.txt");
}