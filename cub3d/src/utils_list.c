/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:45:05 by educlos           #+#    #+#             */
/*   Updated: 2024/02/12 14:14:21 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_list(t_pos *pos)
{
	int		i;
	t_pos	*current;

	i = 0;
	current = pos;
	while (current != NULL)
	{
		printf("liste chaine arg: %s value : %s\n", current->arg,
			current->value);
		if (current->range != NULL)
		{
			while (i < 2)
			{
				printf("tab[%d] = %d \n", i, pos->range[i]);
				i++;
			}
		}
		current = current->next;
	}
}

static t_pos	*get_info_list(char *arg, char *value)
{
	t_pos	*new;

	new = (t_pos *)malloc(sizeof(t_pos));
	if (!new)
		return (NULL);
	new->arg = arg;
	new->value = value;
	new->range = NULL;
	new->next = NULL;
	new->back = NULL;
	return (new);
}

int	push_front_list(t_pos **pos, t_pos *new, t_parsing *p)
{
	t_pos	*tmp;

	tmp = *pos;
	if (*pos == NULL)
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

int	get_list(t_pos **pos, t_parsing *p, char *arg, char *value)
{
	t_pos	*new;

	if (arg[0] == '\0')
		return (-1);
	new = get_info_list(arg, value);
	if (!new)
		return (-1);
	push_front_list(pos, new, p);
	return (1);
}
