/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:22:52 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/11 17:20:39 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *save)
{
    char    *s;
    int     i;

    i = 0;
    if (!save[i])
        return (NULL);
    while (save[i] && save[i] != '\n')
        i++;
    s = ft_substr(save, 0, i + 2);
    if (!s)
        return (NULL);
    free (save);    //free first version of save
    if (save[i] == '\n')
        save = ft_strdup(s + i + 1); //initialise save with the next lines
    if (!save[i])
        save = NULL;
    return (s);
}

char	*get_next_line(int fd)
{
    char            *buf;
    char            *line;
    static char     *save = NULL;
    int             rd;
    
    printf("here");
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    rd = 1;
    buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    while (!ft_strchr(save, '\n') && rd)
    {
        rd = read(fd, buf, BUFFER_SIZE);
        if (rd <= 0)
        {
            free(buf);
            return (NULL);
        }
        buf[BUFFER_SIZE] = '\0';
        save = ft_strjoin(save, buf);
        if (!save) //if the copy didn't happened return NULL
        {
            free(save);
            return (NULL);
        }
    }
    free(buf); //on vide buffer
    line = ft_getline(save);
    return (line);
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
		i++;
	}
	free(line);
	//printf("|\n");
	//system("leaks a.out");
    return (0);
}
