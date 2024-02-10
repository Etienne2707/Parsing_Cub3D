#include "parsing.h"

void    printtab(char *str)
{
    int i;
    i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '1')
            printf("%s%c%s",RED,str[i],RESET);
        else if (str[i] == '0')
            printf("%s%c%s",GREEN,str[i],RESET);
        else if (str[i] == 'N')
            printf("%s%c%s",YELLOW,str[i],RESET);
        else
            printf("%c",str[i]);
        i++;
    }
    printf("\n");
}

void    printdoubletab(char **str)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while (str[k] != 0)
    {
        printtab(str[k]);
        k++;
    }
} 
