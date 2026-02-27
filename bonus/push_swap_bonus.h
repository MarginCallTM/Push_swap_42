/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:40:51 by adghouai          #+#    #+#             */
/*   Updated: 2026/02/11 12:33:44 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>

typedef struct s_benchmark
{
	int			checker;
	int			enabled;
	float		disorder;
	int			strategy;
	int			total_ops;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}				t_benchmark;

typedef struct s_stack
{
	int			**array;
	size_t		size;
	t_benchmark	*bench;
}				t_stack;

// Bench functions
void			init_benchmark(t_benchmark *bench);

// ft_printf
int				ft_printf(const char *str, int output, ...);

// gnl
char			*get_next_line(int fd);

// Parsing and error handling
int				ft_strcmp(char *s1, const char *s2);
void			error_checker_bonus(char **argv, int argc, t_stack *a);
int				ft_atoi(const char *nptr);
int				ft_atoi_range(const char *nptr);
int				ft_isdigit(int c);
char			**ft_split(char *s, char c);
size_t			compute_tab_len(char **argv, int argc);
int				initialize_stack_array(t_stack *stack, size_t size);

// Memory freeing functions
void			free_stack(t_stack *stack, size_t j);
void			free_double_tab(char **tab);

// Array filling functions
void			fill_array(t_stack *a, char **argv, int argc);
void			fill_array_index(t_stack *a);

// Operations
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			get_ptr_value(int *dst, int *src);

#endif