/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:20:28 by educlos           #+#    #+#             */
/*   Updated: 2024/02/12 13:21:42 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	skip_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 33 && str[i] <= 127)
			return (-1);
		i++;
	}
	return (1);
}

int	check_char(char **map)
{
	int	i;
	int	k;
	int	n_counter;

	i = 0;
	n_counter = 0;
	while (map[i] != 0)
	{
		k = 0;
		while (map[i][k] != '\0')
		{
			if (map[i][k] != 32 && map[i][k] != '1' && map[i][k] != '0'
				&& map[i][k] != 'N')
				return (-1);
			if (map[i][k] == 'N')
				n_counter++;
			k++;
		}
		i++;
	}
	if (n_counter > 1)
		return (-1);
	return (1);
}

int	check_map(char **map)
{
	if (check_char(map) == -1)
		return (-1);
	return (1);
}
