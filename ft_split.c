/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:39:31 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/10 12:39:42 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	nbr_split(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
			while (s[i] == c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_len_word(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*malloc_free(int len)
{
	char	*str;

	str = (char *)ft_calloc(len + 1, 1);
	if (!str)
	{
		free(str);
		return (str = 0);
	}
	str[len] = '\0';
	return (str);
}

char	**ft_free(char	**s, int i)
{
	if (!s)
		return (NULL);
	i--;
	while (i >= 0)
	{
		free(s[i]);
		s[i] = 0;
		i--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**big_arr;
	int			i;
	int			len_word;
	int			cnt_words;

	if (!s)
		return (0);
	cnt_words = nbr_split(s, c);
	big_arr = (char **)ft_calloc((cnt_words + 1), sizeof(char *));
	if (!big_arr)
		return (0);
	i = -1;
	while (++i < cnt_words)
	{
		while (*s == c)
			s++;
		len_word = ft_len_word((char *)s, c);
		big_arr[i] = malloc_free(len_word + 1);
		if (!big_arr[i])
			return (ft_free(big_arr, i));
		ft_strlcpy(big_arr[i], s, len_word + 1);
		s += len_word;
	}
	big_arr[i] = 0;
	return (big_arr);
}
