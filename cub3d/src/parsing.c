/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:23:36 by educlos           #+#    #+#             */
/*   Updated: 2024/02/12 13:40:09 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*put_map_line(char *dest, int start, int end)
{
	int		k;
	char	*map;

	k = 0;
	map = malloc(sizeof(char) * (end - start + 1));
	if (!map)
		return (NULL);
	while (dest[start] != '\n' && dest[start] != '\0')
	{
		map[k] = dest[start];
		k++;
		start++;
	}
	map[k] = '\0';
	return (map);
}

int	check_strstr(char *config, char *map)
{
	int	i;
	int	result;

	i = skip_space(map, 0);
	result = ft_strstr(map, config);
	if (result == -1 || result != i)
		return (-1);
	return (result);
}

int	get_info(t_parsing *p, char **config)
{
	int	count;
	int	index;

	count = 0;
	while (config[count] != 0)
	{
		index = 0;
		while (p->map[index] != 0)
		{
			if (check_strstr(config[count], p->map[index]) != -1)
			{
				p->map = get_pos_remove(p, p->map, config[count], index);
				if (!p->map)
					return (-1);
				break ;
			}
			index++;
		}
		if (p->map[index] == 0)
			return (-1);
		count++;
	}
	if (check_path(p->pos) == -1)
		return (-1);
	return (1);
}

int	get_config(t_parsing *p, char *dest)
{
	char	**config;

	config = init_config();
	if (!config)
		return (-1);
	init_map(dest, p);
	if (!p->map)
		return (-1);
	if (get_info(p, config) == -1)
	{
		free(config);
		return (-1);
	}
	free(config);
	if (check_map(p->map) == -1)
		return (-1);
	return (1);
}
