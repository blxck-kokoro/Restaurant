#include <stdio.h>

typedef struct
{
    char *name;
    float price;
} dish;



void printMenu(char *menu[], int menuSize);
dish makeDish(char *dishName, float dishprice);



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

dish makeDish(char *dishName, float dishPrice)
{
    dish currentDish;

    currentDish.name = dishName;
    currentDish.price = dishPrice;

    return currentDish;
}