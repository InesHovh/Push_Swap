/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:43:24 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/08 17:23:58 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(t_stack *a)
{
	int	i;
	int	min;
	int	index;

	i = 1;
	index = 0;
	min = a->array[0];
	while (i < a->size)
	{
		if (a->array[i] < min)
		{
			min = a->array[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	get_mid(t_stack *stack)
{
	int	*helper;

	helper = initarray(stack->size);
	helper = sortarray(stack->array, stack->size);
	return (helper[stack->size / 4]);
}

int	get_mid_index(t_stack *stack)
{
	int	i;
	int	number;
	int	*helper;

	i = 0;
	helper = initarray(stack->size);
	helper = sortarray(stack->array, stack->size);
	number = get_mid(stack);
	while (i < stack->size)
	{
		if (helper[i] == number)
			return (i);
			i++;
	}
	exit(0);
}

int	array_maxelement(t_stack *stack)
{
	int	i;
	int	max;

	i = 1;
	max = stack->array[0];
	while (i < stack->size)
	{
		if (stack->array[i] > max)
			max = stack->array[i];
		i++;
	}
	return (max);
}

int	get_index(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{	
		if (stack->array[i] == num)
			return (i);
		i++;
	}
	exit(0);
}
