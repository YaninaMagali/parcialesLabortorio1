#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validateIsAlpha(char* string)
{//(string[i] == ' ') ||
    int i;
    int result;

    i = 0;
    result = 1;

    if(string != NULL)
    {
        for(i = 0; string[i] != '\n'; i++)
        {
            if(isdigit(string[i])!= 0)
            {
                result = 0;
                break;
            }
        }
    }

    return result;
}

int validateIsNumber(char* string)
{
    int i;
    int result;

    i = 0;
    result = 1;

    if(string != NULL)
    {
        for(i = 0; string[i] != '\n'; i++)
        {
            if(isdigit(string[i])== 0)
            {
                result = 0;
            }
        }
    }

    return result;
}
