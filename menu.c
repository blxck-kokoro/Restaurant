#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    char *category;
    float price;
} dish;


// Possible dish categories
#define DISH_CATEGORIES_LENGTH 5
char *dishCategories[DISH_CATEGORIES_LENGTH] = {"Appetizers", "Soups", "Main Courses", "Desserts", "Beverages"};

// Prints out menu categories to the terminal
void printMenu(char *menu[], int menuSize);

// Prints the dishes to user
void printDishes(dish *dishes, int dishesSize);

// Prints selection buttons, which tell user how to navigate across the progam
void printSelectionButtons(void);

// Prints all the dishes from orderArray, which belong to the specific category.
void printOrderCategory(dish *orderArray, int counter, char *category);

// Pints the orderArray
void printOrder(dish *orderArray, int counter);

// Makes a new dish
dish makeDish(char *dishName, float dishprice);

// Gets the total number of lines of the file.
int getFileLines(char *documentPath);

// Polutes namesArray and pricesArray with name of dishes from specific category.
void getDishesInfo(int arraySize, int elementSize, char namesArray[arraySize][elementSize], float pricesArray[arraySize], char *documentPath);

// Polutes dishesArray with dish objects
void makeDishesArray(dish *dishesArray, int dishesArraySize, char *documentPath, char *dishesCategory);

// Frees dynamic allocated memory used in makeDishesArray()
void freeDishes(dish *dishesArray, int dishesArraySize);

// Returns updated, dynamically allocated dish array of order
dish *makeOrder(dish *orderArray, dish *dishesArray, int dishesArraySize, int *counter);



void printMenu(char *menu[], int menuSize)
{
    for (int i = 0; i < menuSize; i++)
    {
        printf("%i. %s          ", i + 1, menu[i]);
    }
    printf("\n");
}

void printDishes(dish *dishes, int dishesSize)
{
    for (int i = 0; i < dishesSize; i++)
    {
        printf("%s  %.2f$\n\n", dishes[i].name, dishes[i].price);
    }
}

void printSelectionButtons(void)
{
    printf("'a' MENU    'q' QUIT    's' SHOW ORDER\n");
}

dish makeDish(char *dishName, float dishPrice)
{
    dish currentDish;

    currentDish.name = dishName;
    currentDish.price = dishPrice;

    return currentDish;
}

int getFileLines(char *documentPath)
{
    FILE *documentPt = fopen(documentPath, "r");

    if (documentPt == NULL)
    {
        printf("Could not read the file.\n");
        return 1;
    }

    int numOfLines = 1;
    char c = 'a';

    while (c != EOF)
    {
        c = fgetc(documentPt);
        if (c == '\n')
        {
            numOfLines++;
        }
    }
    fclose(documentPt);
    return numOfLines;
}

void getDishesInfo(int arraySize, int elementSize, char namesArray[arraySize][elementSize], float pricesArray[arraySize], char *documentPath)
{
    FILE *documentPt = fopen(documentPath, "r");

    char line[elementSize];
    int lines = 0;
    int namesCounter = 0;
    int pricesCounter = 0;

    while (fgets(line, elementSize, documentPt))
    {
        lines++;
        if (lines % 2 == 1)
        {
            strcpy(namesArray[namesCounter], line);
            namesCounter++;
        }
        else
        {
            pricesArray[pricesCounter] = atof(line);
            pricesCounter++;
        }
    }
    fclose(documentPt);
}

void makeDishesArray(dish *dishesArray, int dishesArraySize, char *documentPath, char *dishesCategory)
{
    int dishesNamesSize = dishesArraySize;
    int dishesNamesElementSize = 256;
    char dishesNames[dishesNamesSize][dishesNamesElementSize];

    int dishesPricesSize = dishesArraySize;
    float dishesPrices[dishesPricesSize];

    getDishesInfo(dishesNamesSize, dishesNamesElementSize, dishesNames, dishesPrices, documentPath);

    for (int i = 0; i < dishesArraySize; i++)
    {
        dishesArray[i].name = malloc(256 * sizeof(char));
        strcpy(dishesArray[i].name, dishesNames[i]);
        dishesArray[i].category = malloc(256 * sizeof(char));
        strcpy(dishesArray[i].category, dishesCategory);
        dishesArray[i].price = dishesPrices[i];
    }
}

void freeDishes(dish *dishesArray, int dishesArraySize)
{
    for (int i = 0; i < dishesArraySize; i++)
    {
        free(dishesArray[i].name);
        free(dishesArray[i].category);
    }
    free(dishesArray);
}

dish *makeOrder(dish *orderArray, dish *dishesArray, int dishesArraySize, int *counter)
{
    while (true)
    {
        printf("Pass the number of the dish to add it to the order.\n");
        printf("'q' QUIT\n");
        char addToOrder[256];
        scanf("%s", addToOrder);

        if (*addToOrder == 'q')
        {
            break;
        }

        for (int i = 0; i < dishesArraySize; i++)
        {
            if (atoi(addToOrder) - 1 == i)
            {
                printf("%s", dishesArray[i].name);
                printf("Added to the order.\n");

                *counter = *counter + 1;
                orderArray = realloc(orderArray, *counter * sizeof(dish));
                orderArray[*counter - 1].name = malloc(256 * sizeof(char));
                strcpy(orderArray[*counter - 1].name, dishesArray[i].name);
                orderArray[*counter - 1].category = malloc(256 * sizeof(char));
                strcpy(orderArray[*counter - 1].category, dishesArray[i].category);
                orderArray[*counter - 1].price = dishesArray[i].price;
                break;
            }
        }
    }
    return orderArray;
}

void printOrderCategory(dish *orderArray, int counter, char *category)
{
    printf("%s: \n", category);
    int isEmpty = 1;
    for (int i = 0; i < counter; i++)
    {
        if (strcmp(orderArray[i].category, category) == 0)
        {
            isEmpty = 0;
            if (isEmpty == 0)
            {
                printf("%s, %.2f$\n", orderArray[i].name, orderArray[i].price);
            }
        }
    }
    if (isEmpty == 1)
    {
        printf("There are no %s in the order.\n", category);
    }
}

void printOrder(dish *orderArray, int counter)
{
    for (int i = 0; i < DISH_CATEGORIES_LENGTH; i++)
    {
        printOrderCategory(orderArray, counter, dishCategories[i]);
    }
}