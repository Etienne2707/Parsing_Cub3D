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

    //printf("cell arg : %s\n",cell->arg);
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

int push_malloc(t_parsing *p,char *str)
{
    t_malloc *cell;

    cell = malloc(sizeof(t_malloc));
    if (!cell)
        return (-1);
    cell->pointer = str;
    cell->pointer2 = NULL;
    cell->next = NULL;
    cell->back = NULL;

    printf("nalloc arg : %s\n",cell->pointer);
    if(p->_malloc == NULL)
    {
        p->_malloc = cell;
        p->_mbegin = cell;
    }
    else
    {
        p->_malloc->next = cell;
        cell->back = p->_malloc;
    }
    return (1);
}

int push_malloc_double(t_parsing *p,char **str)
{
    t_malloc *cell;

    cell = malloc(sizeof(t_malloc));
    if (!cell)
        return (-1);
    cell->pointer = NULL;
    cell->pointer2 = str;
    cell->next = NULL;
    cell->back = NULL;

    printf("malloc : %p\n && %p",cell->pointer2,str);
    if(p->_malloc == NULL)
    {
        p->_malloc = cell;
        p->_mbegin = cell;
    }
    else
    {
        p->_malloc->next = cell;
        cell->back = p->_malloc;
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