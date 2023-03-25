/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:15:01 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/08 17:48:48 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(char **argv, int size)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		if ((dublicate_numeric(argv, size)))
			return (1);
		i++;
	}
	return (0);
}

void	sorting(t_stack *a, t_stack *b, int argc, char **argv)
{
	if (check(argv, argc))
	{
		write_comand("Error");
		return ;
	}
	else
	{
		init_stack_array(a, argc, argv);
		if (already_sorted(a))
			return ;
		else if (argc == 2)
			return ;
		else if (argc == 3)
			sortstack_2number(a);
		else if (argc == 4)
			sortstack_3number(a);
		else if (argc == 5 || argc == 6)
			sortstack_5number(a, b);
		else
		{
			sortstack(a, b);
			sort_back(a, b);
		}
	}
	f_free(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**fake_argv;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		if (isnumber(argv[1]))
			return (0);
		else
		{
			fake_argv = ft_split(argv[1], ' ');
			argc = ft_countword(argv[1], ' ') + 1;
			creatstack(&a, &b, argc);
			sorting(&a, &b, argc, fake_argv);
			free(fake_argv);
		}
	}
	else
	{
		creatstack(&a, &b, argc);
		sorting(&a, &b, argc, argv);
	}
	return (0);
}
