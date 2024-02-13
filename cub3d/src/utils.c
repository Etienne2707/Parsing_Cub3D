/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:50:11 by educlos           #+#    #+#             */
/*   Updated: 2024/02/12 14:15:37 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	skip_space(char *str, int i)
{
	if (!str)
		return (-1);
	while (str[i] == 32 && str[i] != '\0')
		i++;
	return (i);
}

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	check_arg_after(char *str, int last)
{
	if (str[last] == '\n')
		return (0);
	last = skip_space(str, last);
	printf("%d", str[last]);
	if (str[last] != '\n')
		return (-1);
	return (1);
}

int	check_arg_before(char *src, char *find)
{
	int	i;
	int	k;

	k = ft_strstr(src, find);
	i = 0;
	printf("%s et %d et %d\n", find, k, src[i]);
	while (i < k)
	{
		if (src[i] != 32 && (src[i] < 9 || src[i] > 13))
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

int	ft_strlen_double(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != 0)
		i++;
	return (i);
}
