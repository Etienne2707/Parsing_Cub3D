#include "parsing.h"

int recursive(char *str,int i,int compteur)
{
    int result;
    int mult;

    result = 0;
    mult = 10;
    if (compteur > 3)
        return (-1);
    while (str[i] != '\0' && str[i] != ',')
    {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        result = result * mult;
        result = result +  str[i] - '0';
        i++;
    }
    if (result > 255 || result < 0)
        return (-1);
    if (str[i] == '\0')
        return (1);
    recursive(str,++i,++compteur);
}


int check_range(char *str,int max,int min)
{
    char *range;
    int i;

    i = 0;
    if (recursive(str,0,1) != 1)
        return (-1);
}

int check_path(t_pos *pos)
{
    t_pos *current = pos;
    int fd;

    while (current != NULL)
    {
        fd = open(current->arg,O_RDONLY);
        if (current->value[0] == 'F' || current->value[0] == 'C')
        {
            if (check_range(current->arg,255,0) == -1)
                return (-1);
        }
        else if (fd == -1)
        {
            printf("%s\n",current->arg);
            return (-1);
        }
        current = current->next;
    }
    return (1);
}

