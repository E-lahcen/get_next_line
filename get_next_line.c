/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:22:52 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/12 17:06:05 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *save)
{
	char	*s;
	int		i;
	char	*tmp;

	i = 0;
	tmp = save;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = ft_substr(save, 0, i + 1);
	if (!s)
		return (NULL);
	return (s);
}

char	*save_next_lines(char *save)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
	{
		tmp = ft_strdup(save);
		free(save);
		save = ft_strdup(tmp + i + 1);
		return (save);
	}
	free(save);
	return (NULL);
}

void	*free_up(char *save, char *buf)
{
	free(save);
	free(buf);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*save = NULL;
	int			rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd = 1;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	while (!ft_strchr(buf, '\n') && rd)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
			return (free_up(save, buf));
		buf[rd] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	buf = ft_getline(save);
	save = save_next_lines(save);
	return (buf);
}
