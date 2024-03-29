/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:22:25 by educlos           #+#    #+#             */
/*   Updated: 2024/02/12 14:13:13 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	get_first_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != 0)
	{
		if (skip_string(map[i]) == -1)
			return (i);
		i++;
	}
	return (i);
}

int	get_last_map(char **map, int first)
{
	int	i;

	i = first;
	while (map[i] != 0)
	{
		i++;
	}
	return (i);
}

int	get_map(t_map *m, char **src)
{
	int	i;
	int	k;

	i = m->_first;
	k = 0;
	while (i < m->_last)
	{
		m->_map[k] = strdup(src[i]);
		k++;
		i++;
	}
	m->_map[k] = 0;
	return (1);
}

int	get_map_struct(t_map *map, char **src)
{
	map->_first = get_first_map(src);
	map->_last = get_last_map(src, map->_first);
	map->_map = malloc(sizeof(char *) * map->_last - map->_first + 1);
	if (!map->_map)
		return (-1);
	get_map(map, src);
	return (1);
}

int	parsing_map(t_parsing *p)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (-1);
	get_map_struct(map, p->map);
	if (check_wall(map) == -1)
	{
		free_map(map);
		return (-1);
	}
	printdoubletab(map->_map);
	struct_parsing(p,map);
	free_map(map);
	return (1);
}
