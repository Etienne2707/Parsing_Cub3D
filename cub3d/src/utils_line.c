/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:44:16 by educlos           #+#    #+#             */
/*   Updated: 2024/02/12 13:44:42 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_endlinelen(char *dest, int index)
{
	while (dest[index] != '\0')
	{
		if (dest[index] == 10)
			return (index);
		index++;
	}
	return (index);
}

int	ft_line_count(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			c++;
		i++;
	}
	return (c);
}
