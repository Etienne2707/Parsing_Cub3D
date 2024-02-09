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
    printf("pos = %s\n",tmp->value);
    while (tmp != NULL)
    {
        tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2->arg);
        free(tmp2);
    }
    *pos = NULL;
}

void    printlist(t_pos *pos)
{
    
}

void    free_structs(t_parsing *p)
{
    printf("%s\n",p->begin->arg);
    free_double_array(p->map);
    free_list(&p->begin);
    free(p);
}

void    free_map(t_map *m)
{
    free_double_array(m->_map);
    free(m);
}