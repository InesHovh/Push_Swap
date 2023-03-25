/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:50:05 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/08 14:50:06 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack *stack, int value)
{
	if (stack->size == 0 || stack->size == 1)
		return ;
	swap(&stack->array[0], &stack->array[1]);
	if (value == 1)
		write_comand("sa");
	else if (value == 2)
		write_comand("sb");
}

void	ra_rb(t_stack *stack, int value)
{
	int	temp;
	int	i;

	temp = stack->array[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->size - 1] = temp;
	if (value == 1)
		write_comand("ra");
	else if (value == 2)
		write_comand("rb");
}

void	rra_rrb(t_stack *stack, int value)
{
	int	temp;
	int	size;

	size = stack->size;
	temp = stack->array[stack->size - 1];
	while (size)
	{
		stack->array[size - 1] = stack->array[size - 2];
		size--;
	}
	stack->array[0] = temp;
	if (value == 1)
		write_comand("rra");
	else if (value == 2)
		write_comand("rrb");
}

void	pa_pb(t_stack *stack1, t_stack *stack2, int value)
{
	int	tmp;

	tmp = stack1->array[0];
	ra_rb(stack1, 3);
	stack1->array[stack1->size - 1] = '\0';
	stack1->size--;
	stack2->size++;
	stack2->array[stack2->size - 1] = tmp;
	stack2->array[stack2->size] = '\0';
	rra_rrb(stack2, 3);
	if (value == 1)
		write_comand("pa");
	else if (value == 2)
		write_comand("pb");
}
