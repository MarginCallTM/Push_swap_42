/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:58:13 by acombier          #+#    #+#             */
/*   Updated: 2026/01/09 13:45:28 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push__swap.h"

// pa
void	pa(t_stack *a, t_stack *b)
{
	int	i;
	int	value;

	if (b->size == 0)
		return ;
	value = b->array[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->array[i] = b->array[i + 1];
		i++;
	}
	b->size--;
	i = a->size;
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = value;
	a->size++;
	printf("pa\n");
}

// pb
void	pb(t_stack *a, t_stack *b)
{
	int	i;
	int	value;

	if (a->size == 0)
		return ;
	value = a->array[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->size--;
	i = b->size;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = value;
	b->size++;
	printf("pb\n");
}
