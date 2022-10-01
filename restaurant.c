#include <stdio.h>

int main(void)
{
    printf("Welcome to the restaurant!\n");

    char menuSwitch;
    while((int)menuSwitch != 10)
    {
        printf("Press enter to display our menu.");
        scanf("%c", &menuSwitch);
    }
    
}