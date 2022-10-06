#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "menu.c"

#define MENU_CATEGORIES_LENGTH 5

int main(void)
{
    printf("Welcome to the restaurant!\n");
    printf("Pass 'a' to display our menu. (q to quit)\n");
    char *menuCategories[MENU_CATEGORIES_LENGTH] = {"1. Appetizers", "2. Soups", "3. Main Courses", "4. Desserts", "5. Beverages"};

    //  ***     DISHES' OBJECTS SECTION      ***
    //  Appetizers objects
    char *appetizersFilePath = "Dishes/appetizers.txt";
    int appetizersSize = getFileLines(appetizersFilePath) / 2;
    dish *appetizers = malloc(appetizersSize * sizeof(dish));
    makeDishesArray(appetizers, appetizersSize, appetizersFilePath);
    // freeDishes(appetizers, appetizersSize);

    // Soups objects
    char *soupsFilePath = "Dishes/soups.txt";
    int soupsSize = getFileLines(soupsFilePath) / 2;
    dish *soups = malloc(soupsSize * sizeof(dish));
    makeDishesArray(soups, soupsSize, soupsFilePath);
    freeDishes(soups, soupsSize);

    // Main Courses objects
    char *mainCoursesFilePath = "Dishes/mainCourses.txt";
    int mainCoursesSize = getFileLines(mainCoursesFilePath) / 2;
    dish *mainCourses = malloc(mainCoursesSize * sizeof(dish));
    makeDishesArray(mainCourses, mainCoursesSize, mainCoursesFilePath);
    freeDishes(mainCourses, mainCoursesSize);

    //  Desserts
    char *dessertsFilePath = "Dishes/desserts.txt";
    int dessertsSize = getFileLines(dessertsFilePath) / 2;
    dish *desserts = malloc(dessertsSize * sizeof(dish));
    makeDishesArray(desserts, dessertsSize, dessertsFilePath);
    freeDishes(desserts, dessertsSize);

    //  Beverages
    char *beveragesFilePath = "Dishes/beverages.txt";
    int beveragesSize = getFileLines(beveragesFilePath) / 2;
    dish *beverages = malloc(beveragesSize * sizeof(dish));
    makeDishesArray(beverages, beveragesSize, beveragesFilePath);
    freeDishes(beverages, beveragesSize);

    char menuSwitch = 1;
    while(menuSwitch == 1)
    {
        char selection;
        scanf("%c", &selection);

        if ((int)selection == 'q')
        {
            menuSwitch = 0;
        }
        else if ((int)selection == 'a')
        {
            printf("                            ***            CATEGORIES          ***\n");
            printMenu(menuCategories, MENU_CATEGORIES_LENGTH);
            printf("\nPass the number of the specific cateogry to view it's content.\n");
        }
        else if ((int)selection == '1')
        {
            printDishes(appetizers, appetizersSize);
            printf("'a' MENU    'q' QUIT\n");
            freeDishes(appetizers, appetizersSize);
        }
    }
}