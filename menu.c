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

// Polutes namesArray with name of dishes from specific category.
void getDishesNames(int arraySize, int elementSize, char namesArray[arraySize][elementSize], char *documentPath);



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

int getFileLines(char *documentPath)
{
    FILE *documentPt = fopen(documentPath, "r");

    if (documentPt == NULL)
    {
        printf("Could not read the file.\n");
        return 1;
    }

    int numOfLines = 1;
    char c;

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

void getDishesNames(int arraySize, int elementSize, char namesArray[arraySize][elementSize], char *documentPath)
{
    FILE *documentPt = fopen(documentPath, "r");

    char line[elementSize];
    int namesCounter = 0;

    while (fgets(line, elementSize, documentPt))
    {
        strcpy(namesArray[namesCounter], line);
        namesCounter++;
    }
    fclose(documentPt);
}