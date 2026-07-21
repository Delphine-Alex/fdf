/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaiva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:56:22 by dpaiva            #+#    #+#             */
/*   Updated: 2024/12/05 20:09:19 by dpaiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst && !src)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && (dst_len + i + 1) < siz)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (i < siz)
		dst[dst_len + i] = '\0';
	if (siz <= dst_len)
		return (src_len + siz);
	else
		return (src_len + dst_len);
}
