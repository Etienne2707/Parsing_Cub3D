#include "parsing.h"

int recursive(t_pos *pos,char *str,int i,int compteur)
{
    int result;
    int mult;

    result = 0;
    mult = 10;
    if (compteur > 2)
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
    pos->range[compteur] = result;
    if (str[i] == '\0')
        return (1);
    recursive(pos,str,++i,++compteur);
}


int check_range(t_pos *pos,char *str,int max,int min)
{
    char *range;
    int i;
    pos->range = malloc(sizeof(int) * 3);
    if (!pos->range)
        return (-1);
    i = 0;
    if (recursive(pos,str,0,0) != 1)
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
            if (check_range(current,current->arg,255,0) == -1)
                return (-1);
        }
        else if (fd == -1)
        {
            printf("%s\n",current->arg);
            return (-1);
        }
        current = current->next;
    }
    //print_list(pos);
    return (1);
}

