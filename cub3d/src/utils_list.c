#include "parsing.h"

int	get_list(t_pos **pos, t_parsing *p , char *arg, char *value)
{
	t_pos	*new;

	new = get_info_list(arg,value);
	if (!new)
		return -1 ;
	push_front_list(pos,new,p);
       return (1);
}

void print_list(t_pos *pos) 
{
    t_pos *current = pos;
    while (current != NULL) {
        printf("liste chaine arg: %s value : %s\n", current->arg, current->value);
        current = current->next;
    }
}

static t_pos	*get_info_list(char *arg,char *value)
{
    t_pos *new;

    new = (t_pos *)malloc(sizeof(t_pos));
    if (!new)
        return (-1);
    new->arg = arg;
    new->value = value;
    new->next = NULL;
    new->back = NULL;
	return (new);
}

int push_front_list(t_pos **pos,t_pos *new,t_parsing *p)
{
    t_pos *tmp;

    tmp = *pos;
    //printf("new arg : %s\n",new->arg);
    if(*pos == NULL)
    {
        *pos = new;
        p->begin = new;
        return (1);
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    new->back = tmp;
    return (1);
}