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

    char menuSwitch;
    while((int)menuSwitch != 10)
    {
        printf("Press enter to display our menu.\n");
        scanf("%c", &menuSwitch);
    }
    printMenu(menuCategories, MENU_CATEGORIES_LENGTH);

    int appetizersNamesSize = getFileLines("Dishes/appetizers.txt") / 2;
    int appetizersNamesElementSize = 256;
    char appetizersNames[appetizersNamesSize][appetizersNamesElementSize];

    int appetizerPricesSize = getFileLines("Dishes/appetizers.txt") / 2;
    float appetizersPrices[appetizerPricesSize];

    getDishesInfo(appetizersNamesSize, appetizersNamesElementSize, appetizersNames, appetizersPrices, "Dishes/appetizers.txt");

    dish appetizers[getFileLines("Dishes/appetizers.txt") / 2];
    makeDishesArray(appetizers, getFileLines("Dishes/appetizers.txt") / 2, appetizersNames, appetizersPrices);

    for (int i = 0; i < 10; i++)
    {
        printf("Appetizers[%i].name: %s\n", i, appetizers[i].name);
        printf("Appetizers[%i].price: %.2f\n\n", i, appetizers[i].price);
    }
}