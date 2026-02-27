/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:51:39 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/23 16:05:01 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_libft(int nb, int *count_char, int output)
{
	unsigned int	big_nb;
	char			c;

	if (nb < 0)
	{
		write(output, "-", 1);
		(*count_char)++;
		big_nb = nb * -1;
	}
	else
		big_nb = nb;
	if (big_nb / 10 != 0)
		ft_putnbr_fd_libft((big_nb / 10), count_char, output);
	c = (big_nb % 10) + 48;
	write(output, &c, 1);
	(*count_char)++;
}

void	ft_unsigned_putnbr(unsigned int nb, int *count_char, int output)
{
	char	c;

	if (nb / 10 != 0)
		ft_unsigned_putnbr((nb / 10), count_char, output);
	c = (nb % 10) + 48;
	write(output, &c, 1);
	(*count_char)++;
}
