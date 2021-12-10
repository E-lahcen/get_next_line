/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:55:08 by lelhlami          #+#    #+#             */
/*   Updated: 2021/12/10 12:39:33 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	size_src;
	size_t	res;

	res = ft_strlen(src);
	if (!src)
		return (0);
	if (!dstsize)
		return (res);
		size_src = 0;
	while (src[size_src] != '\0' && size_src < dstsize - 1)
	{
		dst[size_src] = src[size_src];
		size_src++;
	}
	dst[size_src] = '\0';
	return (res);
}
