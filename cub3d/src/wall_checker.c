/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:59:53 by educlos           #+#    #+#             */
/*   Updated: 2024/02/12 14:15:21 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_wall_posx(t_map *m, int y, int x)
{
	int	_x;
	int	result;

	_x = x;
	result = 0;
	while (m->_map[y][x++] != '\0')
	{
		if (m->_map[y][x] == '1')
		{
			result++;
			break ;
		}
	}
	while (_x-- != 0)
	{
		if (m->_map[y][_x] == '1')
		{
			result++;
			break ;
		}
	}
	if (result == 2)
		return (1);
	return (-1);
}

int	check_wall_posy2(t_map *m, int _y, int x, int *result)
{
	while (_y != -1)
	{
		if (x >= ft_strlen(m->_map[_y]))
			return (-1);
		if (m->_map[_y][x] == '1')
		{
			(*result)++;
			break ;
		}
		_y--;
	}
	return ((*result));
}

int	check_wall_posy(t_map *m, int y, int x)
{
	int	_y;
	int	result;
	int	start;

	_y = y;
	start = y;
	result = 0;
	while (m->_map[y] != 0)
	{
		if (x >= ft_strlen(m->_map[y]))
			return (-1);
		if (m->_map[y][x] == '1')
		{
			result++;
			break ;
		}
		y++;
	}
	check_wall_posy2(m, _y, x, &result);
	if (result == 2)
		return (1);
	return (-1);
}

int	check_wall_pos(t_map *m, int y, int x)
{
	if (check_wall_posx(m, y, x) == -1)
		return (-1);
	if (check_wall_posy(m, y, x) == -1)
		return (-1);
	return (1);
}

int	check_wall(t_map *m)
{
	int	i;
	int	k;

	i = 0;
	while (m->_map[i] != 0)
	{
		k = 0;
		while (m->_map[i][k] != '\0')
		{
			if (m->_map[i][k] == '0' || m->_map[i][k] == 'N' || m->_map[i][k]  == 'S' || m->_map[i][k]  == 'E' || m->_map[i][k]  == 'W')
			{
				if (check_wall_pos(m, i, k) == -1)
				{
					printf("%d\n", i);
					return (-1);
				}
			}
			k++;
		}
		i++;
	}
	return (1);
}
