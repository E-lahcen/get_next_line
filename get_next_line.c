/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:22:52 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/11 23:25:15 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *save)
{
    char    *s;
    int     i;
    char    *tmp;

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

char    *save_next_lines(char *save)
{
    int i;
    char *tmp;
    
    i = 0;
    if (!save)
    {   
        free(save);
        return (NULL);
    }
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
    return (save);
}
char	*get_next_line(int fd)
{
    char            *buf;
    char            *line;
    static char     *save = NULL;
    int             rd;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    rd = 1;
    buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    buf[0] = '\0'; //avoid freeing without initialising
    while (!ft_strchr(buf, '\n') && rd)
    {
        rd = read(fd, buf, BUFFER_SIZE);
        if (rd < 0)
        {
            free(buf);
            return (NULL);
        }
        buf[rd] = '\0';
		save = ft_strjoin(save, buf);  //strjoin because the while loop until rd = 0 => buf = '\0' => nothing to strdup to save
    }
    free(buf); //on vide buffer
    line = ft_getline(save);
    save = save_next_lines(save);
    return (line);
}


int	main(void)
{
	int		fd = open("files/41_with_nl" , O_RDWR);
	char	*line;
	int     i = 0;
	while(i < 5)
	{
		line = get_next_line(fd);
        printf("%s", line);
		i++;
	}
	free(line);
    return (0);
}
