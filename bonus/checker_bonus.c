/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:24:43 by adghouai          #+#    #+#             */
/*   Updated: 2026/02/11 12:34:41 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	parse_op(char *op, t_stack *a, t_stack *b)
{
	if (!(ft_strcmp(op, "sa\n")))
		sa(a);
	else if (!(ft_strcmp(op, "sb\n")))
		sb(b);
	else if (!(ft_strcmp(op, "ss\n")))
		ss(a, b);
	else if (!(ft_strcmp(op, "pa\n")))
		pa(a, b);
	else if (!(ft_strcmp(op, "pb\n")))
		pb(a, b);
	else if (!(ft_strcmp(op, "ra\n")))
		ra(a);
	else if (!(ft_strcmp(op, "rb\n")))
		rb(b);
	else if (!(ft_strcmp(op, "rr\n")))
		rr(a, b);
	else if (!(ft_strcmp(op, "rra\n")))
		rra(a);
	else if (!(ft_strcmp(op, "rrb\n")))
		rrb(b);
	else if (!(ft_strcmp(op, "rrr\n")))
		rrr(a, b);
	else if (op)
		return (0);
	return (1);
}

void	read_stdin(t_stack *a, t_stack *b, t_benchmark bench)
{
	char		*op;

	a->bench = &bench;
	b->bench = &bench;
	b->size = 0;
	op = get_next_line(0);
	while (op)
	{
		if (parse_op(op, a, b) == 0)
		{
			ft_printf("Error\n", 2);
			free(op);
			free_stack(a, a->size + b->size);
			free_stack(b, a->size + b->size);
			exit(EXIT_FAILURE);
		}
		free(op);
		op = get_next_line(0);
	}
}

void	check_stack(t_stack *a, t_stack *b)
{
	size_t	i;

	i = 0;
	if (b->size != 0)
	{
		ft_printf("KO\n", 1);
		return ;
	}
	while (i < a->size)
	{
		if (a->array[i][1] != (int)i)
		{
			ft_printf("KO\n", 1);
			return ;
		}
		i++;
	}
	ft_printf("OK\n", 1);
}

int	main(int argc, char **argv)
{
	t_benchmark	bench;
	t_stack		a;
	t_stack		b;

	if (argc == 1)
		return (0);
	init_benchmark(&bench);
	bench.checker = 1;
	error_checker_bonus(argv, argc, &a);
	if (initialize_stack_array(&b, a.size) == 0)
	{
		free_stack(&a, a.size);
		exit(EXIT_FAILURE);
	}
	read_stdin(&a, &b, bench);
	check_stack(&a, &b);
	free_stack(&a, a.size + b.size);
	free_stack(&b, a.size + b.size);
	return (0);
}
