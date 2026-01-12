/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push__swap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombier <acombier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:59:22 by acombier          #+#    #+#             */
/*   Updated: 2026/01/09 12:23:48 by acombier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int		*array;
	int size;
	int capacity;
	
} t_stack;

// Swap operation
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);


// Push Operation
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
#endif