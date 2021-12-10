/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:35:57 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/10 18:35:51 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int red;
	char *buf;
	static char *save;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	while (red = read(fd, buf, BUFFER_SIZE))
	{
		if (ft_strchr(buf, '\n'))
			break;
		buf[red] = '\0';
		save = ft_strjoin(save, buf);
	}
	return (save);
}

int	main(void)
{
	int		fd = open("files/test" , O_RDWR);
	char	*line;
	int     i = 0;
	while(i < 10)
	{
		line = get_next_line(fd);
		printf("%s", line);
		// free(line);
		i++;
	}
	//printf("|\n");
	//system("leaks a.out");
    return (0);
}