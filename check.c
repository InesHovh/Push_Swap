/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:18:18 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/08 17:48:00 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	i = -1;
	sign = 1;
	result = 0;
	while (str[++i] == '\t'
		|| str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ');
	if (str[i] == '-' && ++i)
		sign *= -1;
	if (str[i] == '+' && str[i - 1] != '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result *= 10;
		if (str[i] >= '0' && str[i] <= '9')
			result += (str[i++] - '0');
		else
			return (result * sign);
	}
	return (result * sign);
}

int	isnumber(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == 45)
		{
			if (arg[i + 1] == 48)
				return (0);
			i++;
		}
		if (arg[i] < 48 || arg[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	operation(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len - 1)
		{
			if (array[i] == array[j])
			{
				free(array);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	dublicate_numeric(char **argv, int len)
{
	int	i;
	int	j;
	int	*array;

	i = 1;
	j = 0;
	array = initarray(len);
	while (i < len)
	{
		if (!(isnumber(argv[i])))
			return (1);
		array[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	if (operation(array, len))
		return (1);
	free(array);
	return (0);
}

int	ft_countword(char *s, char c)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (is_word == 0 && *s != c)
		{
			is_word = 1;
			count++;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (count);
}
