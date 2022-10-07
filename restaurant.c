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
            makeDishesArray(appetizers, appetizersSize, appetizersFilePath);
            printDishes(appetizers, appetizersSize);

            printf("'a' MENU    'q' QUIT\n");
            freeDishes(appetizers, appetizersSize);
        }
        else if (selection == '2')
        {
            char *soupsFilePath = "Dishes/soups.txt";
            int soupsSize = getFileLines(soupsFilePath) / 2;
            dish *soups = malloc(soupsSize * sizeof(dish));
            makeDishesArray(soups, soupsSize, soupsFilePath);
            printDishes(soups, soupsSize);

            printf("'a' MENU    'q' QUIT\n");
            freeDishes(soups, soupsSize);
        }
        else if (selection == '3')
        {
            char *mainCoursesFilePath = "Dishes/mainCourses.txt";
            int mainCoursesSize = getFileLines(mainCoursesFilePath) / 2;
            dish *mainCourses = malloc(mainCoursesSize * sizeof(dish));
            makeDishesArray(mainCourses, mainCoursesSize, mainCoursesFilePath);
            printDishes(mainCourses, mainCoursesSize);

            printf("'a' MENU    'q' QUIT\n");
            freeDishes(mainCourses, mainCoursesSize);
        }
        else if (selection == '4')
        {
            char *dessertsFilePath = "Dishes/desserts.txt";
            int dessertsSize = getFileLines(dessertsFilePath) / 2;
            dish *desserts = malloc(dessertsSize * sizeof(dish));
            makeDishesArray(desserts, dessertsSize, dessertsFilePath);
            printDishes(desserts, dessertsSize);

            printf("'a' MENU    'q' QUIT\n");
            freeDishes(desserts, dessertsSize);
        }
        else if (selection == '5')
        {
            char *beveragesFilePath = "Dishes/beverages.txt";
            int beveragesSize = getFileLines(beveragesFilePath) / 2;
            dish *beverages = malloc(beveragesSize * sizeof(dish));
            makeDishesArray(beverages, beveragesSize, beveragesFilePath);
            printDishes(beverages, beveragesSize);

            printf("'a' MENU    'q' QUIT\n");
            freeDishes(beverages, beveragesSize);
        }
    }
}