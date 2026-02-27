/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:13:21 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/23 16:05:49 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

char	*get_next_line(int fd);
void	empty_buffer(char *buff);
char	*ft_substr_gnl(char *s, size_t start, size_t len);
char	*ft_strjoin_gnl(char *buff, char *buff2);

#endif