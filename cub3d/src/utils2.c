#include "../includes/parsing.h"




static t_pos	*get_info(char *arg,char *value)
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

void	get_list(t_pos **pos, t_parsing *p , char *arg, char *value)
{
	t_pos	*new;

	new = get_info(arg,value);
	if (!new)
		return ;
	push_front_list(pos,new,p);
}

int push_malloc(t_parsing *p,char *str)
{
    t_malloc *new;

    new = malloc(sizeof(t_malloc));
    if (!new)
        return (-1);
    new->pointer = str;
    new->pointer2 = NULL;
    new->next = NULL;
    new->back = NULL;

    printf("nalloc arg : %s\n",new->pointer);
    if(p->_malloc == NULL)
    {
        p->_malloc = new;
        p->_mbegin = new;
    }
    else
    {
        p->_malloc->next = new;
        new->back = p->_malloc;
    }
    return (1);
}

int push_malloc_double(t_parsing *p,char **str)
{
    t_malloc *new;

    new = malloc(sizeof(t_malloc));
    if (!new)
        return (-1);
    new->pointer = NULL;
    new->pointer2 = str;
    new->next = NULL;
    new->back = NULL;

    printf("malloc : %p\n && %p",new->pointer2,str);
    if(p->_malloc == NULL)
    {
        p->_malloc = new;
        p->_mbegin = new;
    }
    else
    {
        p->_malloc->next = new;
        new->back = p->_malloc;
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