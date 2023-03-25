/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:28:49 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/08 17:47:02 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sortstack_2(t_stack *a, t_stack *b, int mid, int size)
{
	if (a->array[0] < mid)
	{
		pa_pb(a, b, 2);
		size--;
	}
	else if (a->array[a->size - 1] < mid)
	{
		rra_rrb(a, 1);
		pa_pb(a, b, 2);
		size--;
	}
	else if (a->array[1] < mid)
	{
		sa_sb(a, 1);
		pa_pb(a, b, 2);
		size--;
	}
	else
		ra_rb(a, 1);
	return (size);
}

void	sortstack(t_stack *a, t_stack *b)
{
	int	mid;
	int	size;

	mid = get_mid(a);
	size = get_mid_index(a);
	while (size != 0)
	{
		size = sortstack_2(a, b, mid, size);
	}
	while (a->size > 4)
		sortstack(a, b);
	sortstack_5number(a, b);
}

void	sort_back_2(t_stack *b, int max)
{
	int	index;

	index = get_index(b, max);
	if (index > b->size / 2)
		while (max != b->array[0])
			rra_rrb(b, 2);
	else
		while (max != b->array[0])
			ra_rb(b, 2);
}

void	sort_back(t_stack *a, t_stack *b)
{
	int	max;

	while (b->size > 0)
	{
		max = array_maxelement(b);
		if (max == b->array[0])
			pa_pb(b, a, 1);
		else if (max == b->array[1])
		{
			sa_sb(b, 2);
			pa_pb(b, a, 1);
		}
		else if (max == b->array[b->size - 1])
			rra_rrb(b, 2);
		else
			sort_back_2(b, max);
	}
}
