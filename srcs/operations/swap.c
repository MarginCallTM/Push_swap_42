/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:57:40 by acombier          #+#    #+#             */
/*   Updated: 2026/01/09 13:45:41 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push__swap.h"

// sa
void	sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->array[0];
	a->array[0] = a->array[1];
	a->array[1] = temp;
	printf("sa\n");
}
// sb
void	sb(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->array[0];
	b->array[0] = b->array[1];
	b->array[1] = temp;
	printf("sb\n");
}
// ss
void	ss(t_stack *a, t_stack *b)
{
	int temp;

	if (a->size >= 2)
	{
		temp = a->array[0];
		a->array[0] = a->array[1];
		a->array[1] = temp;
	}

	if (b->size >= 2)
	{
		temp = b->array[0];
		b->array[0] = b->array[1];
		b->array[1] = temp;
	}

	printf("ss\n");
}