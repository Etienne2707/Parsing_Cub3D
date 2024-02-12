/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisartion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:15:39 by educlos           #+#    #+#             */
/*   Updated: 2024/02/12 13:18:39 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**init_config(void)
{
	char	**config;

	config = malloc(sizeof(char *) * 7);
	if (!config)
		return (NULL);
	config[0] = "NO ";
	config[1] = "SO ";
	config[2] = "WE ";
	config[3] = "EA ";
	config[4] = "F ";
	config[5] = "C ";
	config[6] = 0;
	return (config);
}

int	init_map(char *dest, t_parsing *p)
{
	int	i;
	int	k;
	int	index;

	i = 0;
	index = 0;
	p->map = malloc(sizeof(char *) * (ft_line_count(dest) + 2));
	if (!p->map)
		return (-1);
	while (i < ft_strlen(dest))
	{
		k = i;
		i = ft_endlinelen(dest, i);
		p->map[index] = put_map_line(dest, k, i);
		i++;
		index++;
	}
	free(dest);
	p->map[index] = 0;
	return (1);
}
