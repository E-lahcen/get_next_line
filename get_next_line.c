/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:35:57 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/09 21:15:58 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    int     ret;
    static char    *buf;
    static int     i = 0;

    buf = (char *)malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
	ret = read(fd, buf, BUFFER_SIZE);
    if (ret == -1 || !ret)
    {
        free(buf);
        return (NULL);
    }
    while (buf[i] && buf[i] != '\n')
        i++;
    buf = buf + i + 1;
    return (buf);
}

int	main(void)
{
	int		fd = open("files/41_with_nl" , O_RDWR);
	char	*line;
	int i = 0;
	//printf("|");
	while(i < 4)
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