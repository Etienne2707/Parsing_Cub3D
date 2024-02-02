#include "../includes/parsing.h"

int push_front_list(t_parsing *p,char *arg, char *value)
{
    t_pos *cell;

    cell = malloc(sizeof(t_pos));
    if (!cell)
        return (-1);
    
    cell->arg = arg;
    cell->value = value;
    cell->next = NULL;
    cell->back = NULL;

    printf("cell arg : %s\n",cell->arg);
    if(p->pos == NULL)
    {
        p->pos = cell;
        p->begin = cell;
    }
    else
    {
        p->pos->next = cell;
        cell->back = p->pos;
    }
    return (1);
}

int check_only_space(char *str,int index)
{

    
    if (str[index] == '\0')
        return (1);
    while (str[++index] != '\0')
    {
        if (str[index] != 32)
            return (-1);
    }
    return (1);
}