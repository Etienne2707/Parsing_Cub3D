#include "parsing.h"

void    free_double_array(char **str)
{
    int i;

    i = 0;
    while (str[i] != 0)
    {
        free(str[i++]);
    }
    free(str);
}

void    free_list(t_pos **pos)
{
    t_pos *tmp;
    t_pos *tmp2;

    
    if (!pos)
        return ;
    tmp = *pos;
    while (tmp != NULL)
    {
        tmp2 = tmp;
        tmp = tmp->next;
        if (tmp2->range != NULL)
            free(tmp2->range);
        free(tmp2->arg);
        free(tmp2);
    }
    *pos = NULL;
}

void    free_structs(t_parsing *p)
{
    free_double_array(p->map);
    free_list(&p->begin);
    free(p);
}

void    free_map(t_map *m)
{
    free_double_array(m->_map);
    free(m);
}