/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihovhann <ihovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:27:28 by ihovhann          #+#    #+#             */
/*   Updated: 2022/07/08 17:47:02 by ihovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	int	size;
	int	*array;
}	t_stack;

int		*initarray(int size);
int		*sortarray(int *arr, int len);
int		ft_atoi(const char *str);
int		isnumber(char *arg);
int		dublicate_numeric(char **argv, int len);
int		min_index(t_stack *a);
int		get_mid(t_stack *stack);
int		get_mid_index(t_stack *stack);
int		get_index(t_stack *stack, int num);
int		already_sorted(t_stack *a);
int		array_maxelement(t_stack *stack);
int		ft_countword(char *s, char c);
int		ft_wordlen(char *s, char c);

char	*ft_free(char **a);
char	**ft_split(char const *s, char c);
char	*ft_strncpy(char *dest, const char *src, size_t n);

void	creatstack(t_stack *stack1, t_stack *stack2, int argc);
void	f_free(t_stack *stack1, t_stack *stack2);
void	init_stack_array(t_stack *a, int argc, char **argv);
void	write_comand(char *str);
void	swap(int *a, int *b);
void	sa_sb(t_stack *stack, int value);
void	ra_rb(t_stack *stack, int value);
void	rra_rrb(t_stack *stack, int value);
void	pa_pb(t_stack *stack1, t_stack *stack2, int value);
void	sortstack_2number(t_stack *a);
void	sortstack_3number(t_stack *a);
void	sortstack_5number(t_stack *a, t_stack *b);
void	sortstack(t_stack *a, t_stack *b);
void	sort_back(t_stack *a, t_stack *b);
void	sorting(t_stack *a, t_stack *b, int argc, char **argv);
void	*ft_memcpy(int *dest, int *src, int num);

#endif