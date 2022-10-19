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
            printf("\nSee you soon!\n");
        }
        else if (selection == 'a')
        {
            printf("\n                                      ***   CATEGORIES  ***\n\n");
            printMenu(dishCategories, DISH_CATEGORIES_LENGTH);
            printf("\nPass the number of the specific cateogry to view it's content.\n");
        }
        else if (selection == 's')
        {
            printOrder(order, dishCounter);
            float bill = calculateBill(order, dishCounter);
            printf("\nOverall bill: %.2f$\n\n", bill);
            printSelectionButtons();
        }
        else if (selection == 'r')
        {
            char category = selectCategoryToRemove();

            if (category == '1')
            {
                dish *appetizers = makeDishesArray("Dishes/appetizers.txt", "Appetizers");
                int appetizersSize = getDishesArraySize("Dishes/appetizers.txt");

                order = removeDish(order, &dishCounter, appetizers, appetizersSize, category - '0');
                freeDishes(appetizers, appetizersSize);
            }
            else if (category == '2')
            {
                dish *soups = makeDishesArray("Dishes/soups.txt", "Soups");
                int soupsSize = getDishesArraySize("Dishes/soups.txt");

                order = removeDish(order, &dishCounter, soups, soupsSize, category - '0');
                freeDishes(soups, soupsSize);
            }
            else if (category == '3')
            {
                dish *mainCourses = makeDishesArray("Dishes/mainCourses.txt", "Main Courses");
                int mainCoursesSize = getDishesArraySize("Dishes/mainCourses.txt");

                order = removeDish(order, &dishCounter, mainCourses, mainCoursesSize, category - '0');
                freeDishes(mainCourses, mainCoursesSize);
            }
            else if (category == '4')
            {
                dish *desserts = makeDishesArray("Dishes/desserts.txt", "Desserts");
                int dessertsSize = getDishesArraySize("Dishes/desserts.txt");

                order = removeDish(order, &dishCounter, desserts, dessertsSize, category - '0');
                freeDishes(desserts, dessertsSize);
            }
            else if (category == '5')
            {
                dish *beverages = makeDishesArray("Dishes/beverages.txt", "Beverages");
                int beveragesSize = getDishesArraySize("Dishes/beverages.txt");

                order = removeDish(order, &dishCounter, beverages, beveragesSize, category - '0');
                freeDishes(beverages, beveragesSize);
            }
            else
            {
                printf("Category not found.\n");
            }
            printSelectionButtons();
        }
        else if (selection == 'e')
        {
            printOrder(order, dishCounter);
            float bill = calculateBill(order, dishCounter);
            printf("\nOverall bill: %.2f$\n\n", bill);

            printf("Are you sure you want to make this order?\n");
            printf("'y' YES     'n' NO\n");

            while (true)
            {
                char choice;
                scanf("%c", &choice);

                if (choice == 'y')
                {
                    printf("\nOrder has been made succesfuly.\n");
                    printf("Thank you for choosing our restaurant!\n");
                    menuSwitch = 0;
                    break;
                }
                else if (choice == 'n')
                {
                    printSelectionButtons();
                    break;
                }
            }
        }
        else if (selection == '1')
        {
            dish *appetizers = makeDishesArray("Dishes/appetizers.txt", "Appetizers");
            int appetizersSize = getDishesArraySize("Dishes/appetizers.txt");
            printDishes(appetizers, appetizersSize);
            
            order = makeOrder(order, appetizers, appetizersSize, &dishCounter);
            printSelectionButtons();
            freeDishes(appetizers, appetizersSize);
        }
        else if (selection == '2')
        {
            dish *soups = makeDishesArray("Dishes/soups.txt", "Soups");
            int soupsSize = getDishesArraySize("Dishes/soups.txt");
            printDishes(soups, soupsSize);

            order = makeOrder(order, soups, soupsSize, &dishCounter);
            printSelectionButtons();
            freeDishes(soups, soupsSize);
        }
        else if (selection == '3')
        {
            dish *mainCourses = makeDishesArray("Dishes/mainCourses.txt", "Main Courses");
            int mainCoursesSize = getDishesArraySize("Dishes/mainCourses.txt");
            printDishes(mainCourses, mainCoursesSize);

            order = makeOrder(order, mainCourses, mainCoursesSize, &dishCounter);
            printSelectionButtons();
            freeDishes(mainCourses, mainCoursesSize);
        }
        else if (selection == '4')
        {
            dish *desserts = makeDishesArray("Dishes/desserts.txt", "Desserts");
            int dessertsSize = getDishesArraySize("Dishes/desserts.txt");
            printDishes(desserts, dessertsSize);

            order = makeOrder(order, desserts, dessertsSize, &dishCounter);
            printSelectionButtons();
            freeDishes(desserts, dessertsSize);
        }
        else if (selection == '5')
        {
            dish *beverages = makeDishesArray("Dishes/beverages.txt", "Beverages");
            int beveragesSize = getDishesArraySize("Dishes/beverages.txt");
            printDishes(beverages, beveragesSize);

            order = makeOrder(order, beverages, beveragesSize, &dishCounter);
            printSelectionButtons();
            freeDishes(beverages, beveragesSize);
        }
    }
    freeDishes(order, dishCounter);
}