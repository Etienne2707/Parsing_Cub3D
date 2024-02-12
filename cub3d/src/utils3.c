/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:00:21 by educlos           #+#    #+#             */
/*   Updated: 2024/02/12 14:01:02 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int	ft_check_format(char *src, char *format)
{
	char	*str;
	int		i;
	int		k;

	i = ft_strlen(src) - 4;
	k = 0;
	str = malloc(sizeof(char) * 5);
	if (!str)
		return (-1);
	while (src[i] != '\0')
	{
		str[k++] = src[i++];
	}
	str[k] = '\0';
	if (ft_strncmp(str, format, 4) != 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (1);
}

int	only_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (-1);
		i++;
	}
	return (1);
}
