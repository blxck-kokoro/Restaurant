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

    dish *order = malloc(sizeof(dish));
    order[0].name = NULL;
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
            printMenu(dishCategories, DISH_CATEGORIES_LENGTH);
            printf("\nPass the number of the specific cateogry to view it's content.\n");
        }
        else if (selection == 's')
        {
            printOrder(order, dishCounter);
            printSelectionButtons();
        }
        else if (selection == 'r')
        {
            char category = selectCategoryToRemove();

            if (category == '1')
            {
                char *appetizersFilePath = "Dishes/appetizers.txt";
                int appetizersSize = getFileLines(appetizersFilePath) / 2;
                dish *appetizers = malloc(appetizersSize * sizeof(dish));
                makeDishesArray(appetizers, appetizersSize, appetizersFilePath, "Appetizers");

                order = removeDish(order, &dishCounter, appetizers, appetizersSize, category - '0');
                freeDishes(appetizers, appetizersSize);
            }
            else if (category == '2')
            {
                char *soupsFilePath = "Dishes/soups.txt";
                int soupsSize = getFileLines(soupsFilePath) / 2;
                dish *soups = malloc(soupsSize * sizeof(dish));
                makeDishesArray(soups, soupsSize, soupsFilePath, "Soups");

                order = removeDish(order, &dishCounter, soups, soupsSize, category - '0');
                freeDishes(soups, soupsSize);
            }
            else if (category == '3')
            {
                char *mainCoursesFilePath = "Dishes/mainCourses.txt";
                int mainCoursesSize = getFileLines(mainCoursesFilePath) / 2;
                dish *mainCourses = malloc(mainCoursesSize * sizeof(dish));
                makeDishesArray(mainCourses, mainCoursesSize, mainCoursesFilePath, "Main Courses");

                order = removeDish(order, &dishCounter, mainCourses, mainCoursesSize, category - '0');
                freeDishes(mainCourses, mainCoursesSize);
            }
            else if (category == '4')
            {
                char *dessertsFilePath = "Dishes/desserts.txt";
                int dessertsSize = getFileLines(dessertsFilePath) / 2;
                dish *desserts = malloc(dessertsSize * sizeof(dish));
                makeDishesArray(desserts, dessertsSize, dessertsFilePath, "Desserts");

                order = removeDish(order, &dishCounter, desserts, dessertsSize, category - '0');
                freeDishes(desserts, dessertsSize);
            }
            else if (category == '5')
            {
                char *beveragesFilePath = "Dishes/beverages.txt";
                int beveragesSize = getFileLines(beveragesFilePath) / 2;
                dish *beverages = malloc(beveragesSize * sizeof(dish));
                makeDishesArray(beverages, beveragesSize, beveragesFilePath, "Beverages");

                order = removeDish(order, &dishCounter, beverages, beveragesSize, category - '0');
                freeDishes(beverages, beveragesSize);
            }
            else
            {
                printf("Category not found.\n");
            }
            printSelectionButtons();
        }
        else if (selection == '1')
        {
            char *appetizersFilePath = "Dishes/appetizers.txt";
            int appetizersSize = getFileLines(appetizersFilePath) / 2;
            dish *appetizers = malloc(appetizersSize * sizeof(dish));
            makeDishesArray(appetizers, appetizersSize, appetizersFilePath, "Appetizers");
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
            makeDishesArray(soups, soupsSize, soupsFilePath, "Soups");
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
            makeDishesArray(mainCourses, mainCoursesSize, mainCoursesFilePath, "Main Courses");
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
            makeDishesArray(desserts, dessertsSize, dessertsFilePath, "Desserts");
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
            makeDishesArray(beverages, beveragesSize, beveragesFilePath, "Beverages");
            printDishes(beverages, beveragesSize);

            order = makeOrder(order, beverages, beveragesSize, &dishCounter);
            printSelectionButtons();
            freeDishes(beverages, beveragesSize);
        }
    }
    freeDishes(order, dishCounter);
}