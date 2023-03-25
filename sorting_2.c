/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:25:02 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/08 17:34:18 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sortarray(int *arr, int len)
{
	int	i;
	int	j;
	int	*array;

	i = 0;
	array = initarray(len);
	ft_memcpy(array, arr, len);
	while (i < len)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
			j++;
		}
		i++;
	}
	return (array);
}

int	already_sorted(t_stack *a)
{
	int	len;
	int	i;

	i = 0;
	len = a->size;
	while (i < len - 1 && a->array[i] < a->array[i + 1])
		i++;
	if (i == len - 1)
		return (1);
	return (0);
}

void	sortstack_2number(t_stack *a)
{
	if (!already_sorted(a))
		sa_sb(a, 1);
}

void	sortstack_3number(t_stack *a)
{
	int	min_ind;
	int	min;

	min_ind = min_index(a);
	min = a->array[min_ind];
	if (a->array[0] == min)
	{
		sa_sb(a, 1);
		ra_rb(a, 1);
	}
	else if (a->array[1] == min)
	{
		if (a->array[0] < a->array[2])
			sa_sb(a, 1);
		else
			ra_rb(a, 1);
	}
	else if (a->array[2] == min)
	{
		if (a->array[0] > a->array[1])
			sa_sb(a, 1);
		rra_rrb(a, 1);
	}
}

void	sortstack_5number(t_stack *a, t_stack *b)
{
	int	index;
	int	min;
	int	count;

	count = 0;
	while (a->size > 3)
	{
		index = min_index(a);
		min = a->array[index];
		if (min == a->array[0])
		{
			pa_pb(a, b, 2);
			count++;
		}
		else if (index < a->size / 2)
			while (min != a->array[0])
				ra_rb(a, 1);
		else
			while (min != a->array[0])
				rra_rrb(a, 1);
	}
	if (!already_sorted(a))
		sortstack_3number(a);
	while (count-- != 0)
		pa_pb(b, a, 1);
}
