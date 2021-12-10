/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:35:57 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/10 21:45:46 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//essai 1 :recursive
char	*get_next_line(int fd)
{
    int     ret;
    char    *buf;
    char            *save;
    static int     i = 0;
    static int      j = 0;

    buf = (char *)malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    if (!i)
	    ret = read(fd, buf, 1);
    else
        ret = read(fd, buf, i);
     printf("\n here function i = %d \t j = %d \tbuf = %c\t strlen(buf) = %lu \n", i, j, buf[i], strlen(buf));
    if (ret == -1 || !ret)
    {
        printf("no ret\n");
        free(buf);
        return (NULL);
    }
    save = buf +(i - j - 1);
    printf("save = %s\n", buf);
    if (buf[i] == '\n')
    {
        j = i;
        return (save);
    }
    i++; // bescause buf[i] == '\0' in first case
    if (buf[i] == '\0')
    {
        free(buf);
        return (NULL);
    }
    return (get_next_line(fd));
}
// essai 2 : iterative
char	*get_next_line(int fd)
{
    int             ret=1;
    char     *buf;
    static char     *save;
    static int      i = 0;
    static int      j = 0;

    buf = (char *)malloc(BUFFER_SIZE);
    if (!buf)
        return (NULL);
	while (ret)
    {
        ret = read(fd, buf, BUFFER_SIZE);
        buf[ret] = '\0';
    }
        printf("here : buf = %s\n", buf);
    if (ret == -1 || !ret)
    {
        free(buf);
        return (NULL);
    }
    j = i;
    while (buf[i] && buf[i] != '\n')
        i++;
    save = ft_substr(buf, j, i - j + 1);
    free(buf);
    return (save);
}

//essai 3 : ft_split
char	*get_next_line(int fd)
{
    static char **lines;
    static char *buf;
    static int red;
    static int i = -1;
	// static char	*s;

    buf = (char *)malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
	if (i == -1)
	{
    	red = read(fd, buf, BUFFER_SIZE);
    	lines = ft_split(buf, '\n');
	}
	i = i + 1;
	printf("%s", lines[i]);
	// free(lines[i]);
    return ("tes");
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