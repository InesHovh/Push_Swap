/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:36:47 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/08 14:38:26 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*initarray(int size)
{
	int	*array;

	array = (int *)malloc(size * sizeof(int));
	if (!array)
		exit(0);
	return (array);
}

void	creatstack(t_stack *stack1, t_stack *stack2, int argc)
{
	stack1->size = argc - 1;
	stack1->array = initarray(argc - 1);
	stack2->size = 0;
	stack2->array = initarray(argc - 1);
}

void	f_free(t_stack *stack1, t_stack *stack2)
{
	free(stack1->array);
	free(stack2->array);
}

void	init_stack_array(t_stack *A, int argc, char **argv)
{
	A->array[argc - 1] = '\0';
	while (argc != 1)
	{
		A->array[argc - 2] = ft_atoi(argv[argc - 1]);
		argc--;
	}
}
