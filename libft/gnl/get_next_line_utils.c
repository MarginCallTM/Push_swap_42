/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:36:50 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/23 16:05:56 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	empty_buffer(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i])
	{
		buff[i] = '\0';
		i++;
	}
}

char	*ft_substr_gnl(char *s, size_t start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (s[start] && i < len)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}

static char	*free_function(char *buff)
{
	if (buff)
		free(buff);
	return (NULL);
}

char	*ft_strjoin_gnl(char *buff, char *buff2)
{
	size_t	i;
	size_t	j;
	char	*new_buff;

	i = 0;
	j = 0;
	new_buff = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(buff2) + 1));
	if (!new_buff)
		return (free_function(buff));
	if (buff)
	{
		while (buff[i])
		{
			new_buff[i] = buff[i];
			i++;
		}
		free(buff);
	}
	while (buff2[j])
	{
		new_buff[i + j] = buff2[j];
		j++;
	}
	new_buff[i + j] = '\0';
	return (new_buff);
}
