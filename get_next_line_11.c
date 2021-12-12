#include "get_next_line.h"

char	*ft_strldup(char *s1, int len)
{
	char	*p;
	int		i;

	p = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!p)
		return (NULL);
	while (s1[i] && i < len - 1)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
char	*get_line(char *s1, int rd)
{
	int		i;
	char	*p;

	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i] && s1[i] != '\n')
		i++;
	p = ft_strldup(s1, i + 2);
	if (!p)
		return (NULL);
	if (rd == 0 && ft_strlen(p) == 0)
	{
		free(p);
		return (NULL);
	}
	return (p);
}

char	*get_remember(char *s1)
{
	int		i;
	char	*p;

	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
	{
		free(s1);
		return (NULL);
	}
	i++;
	p = ft_strldup(s1 + i, ft_strlen(s1) - i + 1);
	free(s1);
	return (p);
}

char	*ft_free(char *buffer, char *save)
{
	free(save);
	free(buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static char		*save;
	int				rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (rd != 0 && !ft_strchr(buffer, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (ft_free(buffer, save));
		buffer[rd] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	line = get_line(save, rd);
	save = get_remember(save);
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