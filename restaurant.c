#include <stdio.h>
#include "menu.c"

int main(void)
{
    printf("Welcome to the restaurant!\n");

    char menuSwitch;
    while((int)menuSwitch != 10)
    {
        printf("Press enter to display our menu.\n");
        scanf("%c", &menuSwitch);
    }
        printMenu(menuCategories, menuCategoriesLength);
}