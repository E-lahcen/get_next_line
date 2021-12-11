/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:35:57 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/11 12:14:35 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     ft_check(int fd, char **str, char **line)
{
    if (fd < 0 || line == NULL || (read(fd, *line, 0) == -1))
        return (-1);
 
    if (!*str) // 2. str n'est pas encore initalise ici, il peut valoir n'importe quoi
    {
        // 3. Tu malloc str, je suppose que tu vas y stocker quelque chose
        if (!(*str = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
            return (-1);
    }
    return (0);
}
  
char *readline(char *str, int fd)
{
    char        buff[BUFFER_SIZE + 1];
    int         ret;
	char		*temp;
  
    while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        buff[ret] = '\0';
		temp = str;
        strcpy(str, buff); // 4. Au premier tour de boucle, tu n'as rien assigne a str, meme pas un \0
		free(temp);
        //5. A chaque fois tu malloc dans strjoin mais ne free pas le pointeur precedent, tu as besoin d'une variable intermediaire
        // pour stocker ton pointeur avant le strjoin, puis le free ensuite
    }
    return (str);
}
  
int     get_next_line(int const fd, char **line)
{
    static char *str = NULL; // 1. tu n'initialises pas str, je te dis que la norme t'autorise a mettre un = dans le cas des static, donc init le a NULL ici
    int         i;
  
    if (ft_check(fd, &str, line) == -1)
        return (-1);
    str = readline(str, fd);
    i = 0;
    if (str[i])
    {
        while (str[i] != '\n' && str[i])
            i++;
        if (i == 0)
            (*line) = ft_strdup("");
        else
        {
            (*line) = ft_substr(str, 0, i + 1);
        }
        str = &str[i + 1];
        return (1);
    }
    else
        (*line) = ft_strdup("");
    return (0);
}
 
char    *ft_strjoinn(char const *s1, char const *s2)
{
    int     i;
    char    *str;
  
    i = 0;
    str = NULL;
    if (s1 != NULL && s2 != NULL)
    {
        str = (char*)malloc(sizeof(str) * ft_strlen(s1) + ft_strlen(s2) + 1);
        if (str != NULL)
        {
            while (*s1 != '\0')
            {
                str[i] = *s1++;
                i++;
            }
            while (*s2 != '\0')
            {
                str[i] = *s2++;
                i++;
            }
            str[i] = '\0';
        }
    }
    return (str);
}

int	main(void)
{
	int		fd = open("files/test" , O_RDWR);
	char	*line;
	int     i = 0;
	while(i < 10)
	{
		get_next_line(fd, &line);
		printf("%s", line);
		i++;
	}
	free(line);
	//printf("|\n");
	//system("leaks a.out");
    return (0);
}