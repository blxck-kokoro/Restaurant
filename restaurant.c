#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include "menu.c"
#define MENU_CATEGORIES_LENGTH 5

int main(void)
{
    printf("Welcome to the restaurant!\n");
    printf("Pass 'a' to display our menu. (q to quit)\n");
    char *menuCategories[MENU_CATEGORIES_LENGTH] = {"1. Appetizers", "2. Soups", "3. Main Courses", "4. Desserts", "5. Beverages"};

    dish *order = malloc(sizeof(dish));
    int dishCounter = 0;
    //  ***   MENU SECTION  ***
    int menuSwitch = 1;
    while(menuSwitch == 1)
    {
        char selection;
        scanf("%c", &selection);

        if (selection == 'q')
        {
            menuSwitch = 0;
            printf("See you soon!\n");
        }
        else if (selection == 'a')
        {
            printf("                            ***            CATEGORIES          ***\n");
            printMenu(menuCategories, MENU_CATEGORIES_LENGTH);
            printf("\nPass the number of the specific cateogry to view it's content.\n");
        }
        else if (selection == '1')
        {
            char *appetizersFilePath = "Dishes/appetizers.txt";
            int appetizersSize = getFileLines(appetizersFilePath) / 2;
            dish *appetizers = malloc(appetizersSize * sizeof(dish));
            makeDishesArray(appetizers, appetizersSize, appetizersFilePath, "appetizers");
            printDishes(appetizers, appetizersSize);
            
            order = makeOrder(order, appetizers, appetizersSize, &dishCounter);
            printSelectionButtons();
            freeDishes(appetizers, appetizersSize);
        }
        else if (selection == '2')
        {
            char *soupsFilePath = "Dishes/soups.txt";
            int soupsSize = getFileLines(soupsFilePath) / 2;
            dish *soups = malloc(soupsSize * sizeof(dish));
            makeDishesArray(soups, soupsSize, soupsFilePath, "soups");
            printDishes(soups, soupsSize);

            order = makeOrder(order, soups, soupsSize, &dishCounter);
            printSelectionButtons();
            freeDishes(soups, soupsSize);
        }
        else if (selection == '3')
        {
            char *mainCoursesFilePath = "Dishes/mainCourses.txt";
            int mainCoursesSize = getFileLines(mainCoursesFilePath) / 2;
            dish *mainCourses = malloc(mainCoursesSize * sizeof(dish));
            makeDishesArray(mainCourses, mainCoursesSize, mainCoursesFilePath, "mainCourses");
            printDishes(mainCourses, mainCoursesSize);

            order = makeOrder(order, mainCourses, mainCoursesSize, &dishCounter);
            printSelectionButtons();
            freeDishes(mainCourses, mainCoursesSize);
        }
        else if (selection == '4')
        {
            char *dessertsFilePath = "Dishes/desserts.txt";
            int dessertsSize = getFileLines(dessertsFilePath) / 2;
            dish *desserts = malloc(dessertsSize * sizeof(dish));
            makeDishesArray(desserts, dessertsSize, dessertsFilePath, "desserts");
            printDishes(desserts, dessertsSize);

            order = makeOrder(order, desserts, dessertsSize, &dishCounter);
            printSelectionButtons();
            freeDishes(desserts, dessertsSize);
        }
        else if (selection == '5')
        {
            char *beveragesFilePath = "Dishes/beverages.txt";
            int beveragesSize = getFileLines(beveragesFilePath) / 2;
            dish *beverages = malloc(beveragesSize * sizeof(dish));
            makeDishesArray(beverages, beveragesSize, beveragesFilePath, "beverages");
            printDishes(beverages, beveragesSize);

            order = makeOrder(order, beverages, beveragesSize, &dishCounter);
            printSelectionButtons();
            freeDishes(beverages, beveragesSize);
        }
    }
    freeDishes(order, dishCounter);
}