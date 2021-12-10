/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:12:01 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/10 11:44:17 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = (size_t)ft_strlen(s1);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1, len);
	str[len] = '\0';
	return (str);
}
