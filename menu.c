#include <stdio.h>
#include <string.h>

typedef struct
{
    char *name;
    float price;
} dish;


// Prints out menu categories to the terminal
void printMenu(char *menu[], int menuSize);

// Makes a new dish
dish makeDish(char *dishName, float dishprice);

// Gets the total number of lines of the file.
int getFileLines(char *documentPath);

// Polutes namesArray and pricesArray with name of dishes from specific category.
void getDishesInfo(int arraySize, int elementSize, char namesArray[arraySize][elementSize], float pricesArray[arraySize], char *documentPath);

// Polutes dishesArray with dish objects
void makeDishesArray(dish *dishesArray, int dishesArraySize, char *documentPath);

// Frees dynamic allocated memory used in makeDishArray()
void freeDishes(dish *dishesArray, int dishesArraySize);



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

void makeDishesArray(dish *dishesArray, int dishesArraySize, char *documentPath)
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
        dishesArray[i].price = dishesPrices[i];
    }
}

void freeDishes(dish *dishesArray, int dishesArraySize)
{
    for (int i = 0; i < dishesArraySize; i++)
    {
        free(dishesArray[i].name);
    }
    free(dishesArray);
}