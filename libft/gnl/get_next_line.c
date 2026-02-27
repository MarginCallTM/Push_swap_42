/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adghouai <adghouai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:06:56 by adghouai          #+#    #+#             */
/*   Updated: 2026/01/23 16:05:54 by adghouai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	found_one_newline(char *buff)
{
	size_t	i;

	i = 0;
	if (!buff)
		return (0);
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*extract_one_line(char *buff)
{
	size_t	len;
	size_t	i;
	char	*result;

	i = 0;
	if (buff[0] == '\0')
		return (NULL);
	else if (found_one_newline(buff))
	{
		len = 1;
		while (buff[i] != '\n')
		{
			len++;
			i++;
		}
	}
	else
		len = ft_strlen(buff);
	result = ft_substr_gnl(buff, 0, len);
	return (result);
}

static void	stock_remainder(char *buff, char *buff2, char *line)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(line);
	j = 0;
	while (buff2[i + j])
	{
		*buff = buff2[i + j];
		buff++;
		j++;
	}
	empty_buffer(buff);
}

static char	*get_bigger_buff(char *buff, char *big_buff, ssize_t bytes, int fd)
{
	char	*line;

	while (!(found_one_newline(big_buff)) && bytes > 0)
	{
		empty_buffer(buff);
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			empty_buffer(buff);
			free(big_buff);
			return (NULL);
		}
		big_buff = ft_strjoin_gnl(big_buff, buff);
		if (!big_buff)
			return (NULL);
	}
	line = extract_one_line(big_buff);
	if (line)
		stock_remainder(buff, big_buff, line);
	free(big_buff);
	return (line);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes;
	static char	buff[BUFFER_SIZE + 1];
	char		*big_buff;
	char		*line;

	big_buff = NULL;
	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		empty_buffer(buff);
		return (NULL);
	}
	if (found_one_newline(buff))
	{
		line = extract_one_line(buff);
		stock_remainder(buff, buff, line);
		return (line);
	}
	big_buff = ft_strjoin_gnl(big_buff, buff);
	if (!big_buff)
		return (NULL);
	line = get_bigger_buff(buff, big_buff, bytes, fd);
	return (line);
}
