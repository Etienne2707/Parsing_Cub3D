/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:40:50 by educlos           #+#    #+#             */
/*   Updated: 2024/02/12 13:43:05 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*get_pos(char *map, char *config)
{
	int		i;
	int		k;
	char	*tmp;

	i = ft_strstr(map, config) + ft_strlen(config);
	i = skip_space(map, i);
	k = i;
	while (map[k] != 32 && map[k] != '\0')
		k++;
	if (check_only_space(map, k) == -1)
		return (NULL);
	tmp = get_nmalloc(map, i, k);
	if (!tmp)
		return (NULL);
	return (tmp);
}

int	set_pos(t_parsing *p, char *map, char *config)
{
	map = get_pos(map, config);
	if (!map)
		return (-1);
	if ((get_list(&p->pos, p, map, config) == -1))
		return (-1);
	return (1);
}

char	**free_return(char **map, char **dest, int k)
{
	free_double_array_dest(dest, k);
	free_double_array(map);
	return (NULL);
}

char	**get_pos_remove(t_parsing *p, char **map, char *config, int index)
{
	char	**dest;
	int		i;
	int		k;

	i = 0;
	k = 0;
	dest = malloc(sizeof(char *) * ft_strlen_double(map));
	if (!dest)
		return (NULL);
	dest[ft_strlen_double(map) - 1] = 0;
	while (map[i] != 0)
	{
		if (i == index)
		{
			if (set_pos(p, p->map[i], config) == -1)
				return (free_return(p->map, dest, k));
			i++;
		}
		if (map[i] == 0)
			break ;
		dest[k++] = strdup(map[i++]);
	}
	free_double_array(p->map);
	return (dest);
}
