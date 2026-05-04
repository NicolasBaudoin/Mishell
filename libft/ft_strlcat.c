/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:07:47 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/13 13:33:36 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dest;

	len_src = 0;
	len_dest = 0;
	len_src = (size_t)ft_strlen(src);
	if (!size)
		return (len_src);
	len_dest = (size_t)ft_strlen(dst);
	i = 0;
	if (len_dest >= size)
		return (len_src + size);
	while (i < (size - 1 - len_dest) && src[i])
	{
		dst[len_dest + i] = src[i];
		i++;
	}
	dst[len_dest + i] = '\0';
	return (len_src + len_dest);
}
