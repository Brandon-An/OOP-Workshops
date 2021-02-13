#include <iostream>
#include <string>
#include "cstring.h"

int main()
{
    char name[20];
    char one;

    for (int i = 0; i < 2; i++)
    {
        printf("Please, enter your full name: ");
        scanf("%[^\n]%c", name, &one);
        printf("%s", name);
    }

    return 0;
}