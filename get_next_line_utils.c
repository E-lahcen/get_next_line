/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:39:57 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/12 16:22:00 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	int		i;

	i = 0;
	len = (size_t)ft_strlen(s1);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1, len);
	str[len] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}	
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *)s + i);
	}	
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (!src && !dst)
		return (0);
	if (dst1 > src1)
	{
		while (len)
		{
			*(dst1 + len - 1) = *(src1 + len - 1);
			len--;
		}
		return (dst);
	}
	while (len--)
		*dst1++ = *src1++;
	return (dst);
}

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	char		*dst1;
	const char	*src1;

	dst1 = (char *)dst;
	src1 = (const char *)src;
	if (!dst && !src)
		return (0);
	while (n--)
	{
		*dst1++ = *src1++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		len2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
		return (0);
	ft_memmove(str, s1, len1);
	ft_memmove(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}
